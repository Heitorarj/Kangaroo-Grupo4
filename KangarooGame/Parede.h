#ifndef PAREDE_H_
#define PAREDE_H_

#include "Bibliotecas.h"

class Parede {
public:
	sf::RectangleShape retanguloCenario;

	Parede(int inputLargura, int inputAltura, int inputPosicaoX,
			int inputPosicaoY, sf::Color inputCor, sf::Color inputCorBorda);
};

#endif
