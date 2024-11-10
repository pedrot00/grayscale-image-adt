#include "Imagem.h"
#include <stdexcept>
#include <iostream>

//bloco funcoes auxiliares -> operacao muito repetida no codigo, por isso transformei em funcao
void Imagem::compararOrdem(const Imagem &img1, const Imagem &img2){
	if(img1._ordem != img2._ordem){
		throw std::invalid_argument ("Erro: Imagens possuem dimensoes incompativeis.");
	}
}

void Imagem::verificarOrdem(int ordem){
	if(ordem <= 0){
		throw std::invalid_argument ("Erro: a ordem nao e valida");
	}
}

//bloco getters
int Imagem::getOrdem() const{
	return _ordem;
}
int Imagem::getPixel(int i, int j) const{
	return _matriz[i][j];
}

// bloco funcoes TAD
Imagem::Imagem(int ordem){ //construtor
	try{
		verificarOrdem(ordem);
		this->_ordem = ordem;
	
		_matriz = new int *[ordem];
		for(int i = 0; i <_ordem; i++){
			_matriz[i] = new int[_ordem];
		}	
	}
	catch(const std::invalid_argument &e){		//bloco try catch pra capturar excessao/erro
		std::cerr << e.what() <<std::endl;
	}
}

Imagem::~Imagem(){ //desconstrutor
	if(_matriz !=nullptr){
		for(int i = 0; i<_ordem; i++){
			delete[] _matriz[i];
		}
		delete [] _matriz;
	}
}

void Imagem::leImagem(){	//leitura de imagem

	for(int i = 0; i<_ordem; i++){
		for(int j = 0; j<_ordem; j++){
			int valor;
			std::cin >> valor;
					
			if(valor < 0){
				valor = 0;
			}
			else if(valor >255){
				valor = 255;
			}
			_matriz[i][j] = valor;
		}
	}
}

void Imagem::soma(const Imagem &img1, const Imagem &img2, Imagem &imgSomada) {
    try {
        compararOrdem(img1, img2);  // tratamento de excessao
        compararOrdem(img1, imgSomada);  
        
        // se ja foi alocado desaloca primeiro
        if (imgSomada._matriz != nullptr) {
            for (int i = 0; i < imgSomada._ordem; i++) {
                delete[] imgSomada._matriz[i];
            }
            delete[] imgSomada._matriz;
        }

        // alocacao da nova matriz
        imgSomada._matriz = new int*[img1._ordem];
        for (int i = 0; i < img1._ordem; i++) {
            imgSomada._matriz[i] = new int[img1._ordem];
        }
	
		// alocando valores da soma, verificando o limite 255px
        for (int i = 0; i < img1._ordem; i++) {
            for (int j = 0; j < img1._ordem; j++) {
                imgSomada._matriz[i][j] = img1._matriz[i][j] + img2._matriz[i][j];
                if (imgSomada._matriz[i][j] > 255) {
                    imgSomada._matriz[i][j] = 255;
                }
            }
        }
    }
    catch (const std::invalid_argument &e) {	// bloco try catch para capturar excessoes/erro
        std::cerr << e.what() << std::endl;
    }
}


void Imagem::subtrai(const Imagem &img1, const Imagem &img2, Imagem &imgSubtraida) {
    try {
        compararOrdem(img1, img2);  // tratamento de excessao
        compararOrdem(img1, imgSubtraida);   // mesmas operacoes da soma, mas alterando alguns sinais

        
        if (imgSubtraida._matriz != nullptr) {
            for (int i = 0; i < imgSubtraida._ordem; i++) {
                delete[] imgSubtraida._matriz[i];
            }
            delete[] imgSubtraida._matriz;
        }

        
        imgSubtraida._matriz = new int*[img1._ordem];
        for (int i = 0; i < img1._ordem; i++) {
            imgSubtraida._matriz[i] = new int[img1._ordem];
        }

		//alocando valores da soma, verificando o limite 0px
        for (int i = 0; i < img1._ordem; i++) {
            for (int j = 0; j < img1._ordem; j++) {
                imgSubtraida._matriz[i][j] = img1._matriz[i][j] - img2._matriz[i][j];
                if (imgSubtraida._matriz[i][j] < 0) {
                    imgSubtraida._matriz[i][j] = 0;
                }
            }
        }
    }
    catch (const std::invalid_argument &e) {	// bloco try catch para capturar excessoes/erro
        std::cerr << e.what() << std::endl;
    }
}

void Imagem::criaImagemPreta(int ordem, Imagem &imgPreta) {
    if (imgPreta._matriz != nullptr) {	// tratamento de excessao se imgPreta ja foi alocado
        if (imgPreta._ordem != ordem) {
        	
            // desaloca matriz existente
            for (int i = 0; i < imgPreta._ordem; i++) {
                delete[] imgPreta._matriz[i];
            }
            delete[] imgPreta._matriz;

            // aloca nova matriz
            imgPreta._ordem = ordem;
            imgPreta._matriz = new int*[ordem];
            for (int i = 0; i < ordem; i++) {
                imgPreta._matriz[i] = new int[ordem];
            }
        }
    } else {	// se nao foi alocado ele so aloca a nova ordem
        imgPreta._ordem = ordem;
        imgPreta._matriz = new int*[ordem];
        for (int i = 0; i < ordem; i++) {
            imgPreta._matriz[i] = new int[ordem];
        }
    }

    // preenche com a cor preta (0)
    for (int i = 0; i < imgPreta._ordem; i++) {
        for (int j = 0; j < imgPreta._ordem; j++) {
            imgPreta._matriz[i][j] = 0;
        }
    }
}

void Imagem::inverteImagem(Imagem &img){
	if(img._matriz !=nullptr){
		for(int i = 0; i < img._ordem; i++){
			for(int j = 0; j<img._ordem; j++){
				img._matriz[i][j] = 255 - img._matriz[i][j];
			}
		}
	}
}

bool Imagem::compara(const Imagem &img1, const Imagem &img2) {
    if (img1.getOrdem() != img2.getOrdem()) {	
        return false;	//se a ordem for diferente retorna false, poupando tempo de execucao
    }

    for (int i = 0; i < img1.getOrdem(); i++) {
        for (int j = 0; j < img2.getOrdem(); j++) {
            if (img1.getPixel(i, j) != img2.getPixel(i, j)) {
                return false; 	// o primeiro elemento distinto ja quebra o ciclo, poupando tempo de execucao
            }
        }
    }
    return true;
}

void Imagem::imprimeImagem(const Imagem &img) const{
	for(int i = 0; i<img._ordem; i++){
		for(int j = 0; j<img._ordem; j++){
			std::cout << img._matriz[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void Imagem::adicionaBorda(Imagem &img) {
    bool bordaBranca = true;	//variavel para controle da borda branca
    
    for (int i = 0; i < img._ordem; i++) {
        if (img._matriz[0][i] != 255 || img._matriz[img._ordem - 1][i] != 255 ||
            img._matriz[i][0] != 255 || img._matriz[i][img._ordem - 1] != 255) {
            bordaBranca = false;
            break;
        }
    }

    // define a nova ordem da imagem com base na borda existente
    int novaOrdem = bordaBranca ? img._ordem + 2 : img._ordem + 4;

    // aloca a nova matriz
    int **novaMatriz = new int*[novaOrdem];
    for (int i = 0; i < novaOrdem; i++) {
        novaMatriz[i] = new int[novaOrdem];
        for (int j = 0; j < novaOrdem; j++) {
            novaMatriz[i][j] = 0; // inicializa com preto
        }
    }

    // adiciona a borda branca, se a imagem nao possui
    if (!bordaBranca) {
        for (int i = 1; i < novaOrdem - 1; i++) {
            novaMatriz[1][i] = 255; 				//  superior
            novaMatriz[novaOrdem - 2][i] = 255; 	//  inferior
            novaMatriz[i][1] = 255; 				//  esquerda
            novaMatriz[i][novaOrdem - 2] = 255; 	//  direita
        }
    }

    // copia a imagem original para o centro da nova matriz
    int offset = bordaBranca ? 1 : 2;		// variavel caso ja tenha borda ou nao
    for (int i = 0; i < img._ordem; i++) {
        for (int j = 0; j < img._ordem; j++) {
            novaMatriz[i + offset][j + offset] = img._matriz[i][j];
        }
    }

    // liberacao memoria
    for (int i = 0; i < img._ordem; i++) {
        delete[] img._matriz[i];
    }
    delete[] img._matriz;

    // atualiza a matriz da imagem para a nova matriz
    img._matriz = novaMatriz;
    img._ordem = novaOrdem;
}
