#include <iostream>
#include "Imagem.h"
#define space std::cout <<std::endl;		//comando muito repetido no codigo

int main() {
    // instanciando os objetos
    Imagem img1(5), img2(5), imgSomada(5), imgSubtraida(5), imgInvertida(5), imgPreta(5), imgBranca(5);

    // leitura das imagens utilizadas no processo
    img1.leImagem(); 
    img2.leImagem();
    space

    // somando as imagens
    img1.soma(img1, img2, imgSomada); 
    std::cout << "Imagem Somada:" << std::endl;
    imgSomada.imprimeImagem(imgSomada);
    space

    // subtraindo as imagens
    img1.subtrai(img1, img2, imgSubtraida);
    std::cout << "Imagem Subtraida:" << std::endl;
    imgSubtraida.imprimeImagem(imgSubtraida);
    space

    // invertendo img1
    img1.inverteImagem(img1); 
    std::cout << "Imagem Invertida:" << std::endl;
    img1.imprimeImagem(img1);
    space

    // comparando as duas imagens
    if (img1.compara(img1, img2)) {
        std::cout << "Imagens iguais." << std::endl;
    } else {
        std::cout << "Imagens diferentes." << std::endl;
    }
    space

    // criando uma imagem preta
    imgPreta.criaImagemPreta(5, imgPreta); 
    std::cout << "Imagem Preta:" << std::endl;
    imgPreta.imprimeImagem(imgPreta);
    space	
    
	// adicionando borda a imagem preta
    imgPreta.adicionaBorda(imgPreta); 
    std::cout << "Imagem Preta com Borda:" << std::endl;
    imgPreta.imprimeImagem(imgPreta);
    space

    // criando uma imagem branca atraves de uma imagem preta e invertendo-a
    imgBranca.criaImagemPreta(5, imgBranca); 
    imgBranca.inverteImagem(imgBranca); 
    std::cout << "Imagem Branca:" << std::endl;
    imgBranca.imprimeImagem(imgBranca);
    space
    
    //adicionando borda a imagem branca
    imgBranca.adicionaBorda(imgBranca);
    std::cout << "Imagem Branca com Borda:" << std::endl;
    imgBranca.imprimeImagem(imgBranca);
    space

    return 0;
}

