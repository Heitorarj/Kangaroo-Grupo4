#ifndef CENARIO_HPP_
#define CENARIO_HPP_

#include "Jogo.hpp"
class Cenario {
public:
	sf::RectangleShape retanguloCenario;
};

class Parede: public Cenario {
public:
	sf::RectangleShape retanguloCenario[10];
	Parede();
	Parede(int inputLargura, int inputAltura, sf::Color inputCor,
			sf::Color inputCorBorda, int inputNumeroFase);
	void girar();
};
class Escada: public Cenario {
public:
	sf::RectangleShape retanguloCenario[15];
	Escada();
	Escada(int inputLargura, int inputAltura, sf::Color inputCor,
			sf::Color inputCorBorda, int inputNumeroFase);
	void girar();
};

class Fruta {
public:
	sf::Texture frutaTextura;
	sf::Sprite frutaCorpo[3];

	Fruta();
	Fruta(int inputNumeroFase);
	void girar();
};

class Arvore {
public:
	sf::Texture arvoreTextura;
	sf::Sprite arvoreCorpo[3];

	Arvore();
	Arvore(int inputNumeroFase);
	void girar();
};

class Flor {
public:
	sf::Texture florTextura;
	sf::Sprite florCorpo[5];

	Flor();
	Flor(int inputNumeroFase);
	void girar();
};

class Texto: public Cenario {
public:
	sf::Font fonte;
	sf::Text texto;

	Texto();
};
#endif
