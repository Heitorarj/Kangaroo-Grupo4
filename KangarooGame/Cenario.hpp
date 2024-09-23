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
};
class Escada: public Cenario {
public:
	sf::RectangleShape retanguloCenario[15];
	Escada();
	Escada(int inputLargura, int inputAltura, sf::Color inputCor,
			sf::Color inputCorBorda, int inputNumeroFase);
};

class Hitbox: public Cenario {
public:
	Hitbox();
};

class HitboxTester: public Cenario {
public:
	HitboxTester();
};

class Fruta {
public:
	sf::Texture frutaTextura;
	sf::Sprite frutaCorpo[3];

	Fruta();
};

class Texto: public Cenario {
public:
	sf::Font fonte;
	sf::Text texto;

	Texto();
};
#endif
