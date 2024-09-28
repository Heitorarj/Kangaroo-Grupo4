#ifndef CENARIO_H_
#define CENARIO_H_

#include "Jogador.h"

class Parede {
private:
	sf::RectangleShape retanguloParede;

public:
	Parede(int inputLargura, int inputAltura, int inputPosicaoX,
			int inputPosicaoY, sf::Color inputCor, sf::Color inputCorBorda);

	void criaParede(int inputNumeroFase, std::vector<Parede> *inputParede);
};

class Escada {
private:
	sf::RectangleShape retanguloEscada;

public:
	Escada(int inputLargura, int inputAltura, int inputPosicaoX,
			int inputPosicaoY, sf::Color inputCor, sf::Color inputCorBorda);

	void criaEscada(int inputNumeroFase, std::vector<Escada> *inputEscada);
};

class Fruta {
private:
	sf::Texture frutaTextura;
	sf::Sprite frutaCorpo;

	//Funcoes privadas

public:
	Fruta();

	void criaFruta(int inputNumeroFase, std::vector<Fruta> *inputFruta);
};

class Arvore {
private:
	sf::Texture arvoreTextura;
	sf::Sprite arvoreCorpo;

	//Funcoes privadas

public:
	Arvore();

	void criaArvore(int inputNumeroFase, std::vector<Arvore> *inputArvore);
};

class Flor {
private:
	sf::Texture florTextura;
	sf::Sprite florCorpo;

	//Funcoes privadas

public:
	Flor();

	void criaFlor(int inputNumeroFase, std::vector<Flor> *inputFlor);
};

class Texto {
private:
	sf::RectangleShape retanguloCenario;
	sf::Font fonte;
	sf::Text texto;

	//Funcoes privadas

public:
	Texto();
};

class Cenario {
private:

	//Funcoes privadas
	void criaMapa(int inputNumeroFase, std::vector<Parede> *inputParede,
			std::vector<Escada> *inputEscada, std::vector<Fruta> *inputFruta,
			std::vector<Arvore> *inputArvore, std::vector<Flor> *inputFlor,
			sf::RenderWindow *janela);

	void desenhaMapa(int inputNumeroFase, std::vector<Parede> &inputParede,
			std::vector<Escada> &inputEscada, std::vector<Fruta> &inputFruta,
			std::vector<Arvore> &inputArvore, std::vector<Flor> &inputFlor,
			sf::RenderTarget *target);

public:
	Cenario();
	virtual ~Cenario();
};

#endif
