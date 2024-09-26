#ifndef CENARIO_HPP_
#define CENARIO_HPP_

#include "Jogo.hpp"

class Parede {
public:
	sf::RectangleShape retanguloCenario;

	Parede(int inputLargura, int inputAltura, int inputPosicaoX,
			int inputPosicaoY, sf::Color inputCor, sf::Color inputCorBorda);
};

class Escada {
public:
	sf::RectangleShape retanguloCenario;

	Escada(int inputLargura, int inputAltura, int inputPosicaoX,
			int inputPosicaoY, sf::Color inputCor, sf::Color inputCorBorda);
};

class Fruta {
public:
	sf::Texture frutaTextura;
	sf::Sprite frutaCorpo;

	Fruta();
};

class Arvore {
public:
	sf::Texture arvoreTextura;
	sf::Sprite arvoreCorpo;

	Arvore();
};

class Flor {
public:
	sf::Texture florTextura;
	sf::Sprite florCorpo;

	Flor();
};

class Texto {
public:
	sf::RectangleShape retanguloCenario;
	sf::Font fonte;
	sf::Text texto;

	Texto();
};
#endif
