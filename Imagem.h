//TPR1 INF112 UFV - 11/24. Pedro S. Teixeira | 116224. Mais informacoes em github.com/pedrot00
#ifndef IMAGEM_H
#define IMAGEM_H

#include <stdexcept>
#include <iostream>  

class Imagem{
private:
	int _ordem; 		// ordem da matriz
	int ** _matriz;
	
public:
	Imagem(int ordem);
	~Imagem();
	
	// funcoes auxiliares
	void verificarOrdem(int ordem);
	void compararOrdem(const Imagem &img1, const Imagem &img2);
	
	// getters
	int getOrdem() const; // const para garantir que os dados privados nao serao modificados
	int getPixel(int i, int j) const;	
	
	// bloco funcoes TAD	// const para nao alterar acidentalmente img1 e img2
	void leImagem();
	void soma(const Imagem &img1, const Imagem &img2, Imagem &imgSomada); 
	void subtrai(const Imagem &img1, const Imagem &img2, Imagem &imgSubtraida); 
	void criaImagemPreta(int ordem, Imagem &imgPreta);
	void inverteImagem(Imagem &img);
	bool compara(const Imagem &img1, const Imagem &img2);
	void imprimeImagem(const Imagem &img) const;	
	void adicionaBorda(Imagem &img);
		
};
#endif
