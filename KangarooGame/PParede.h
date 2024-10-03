#ifndef PPAREDE_H_
#define PPAREDE_H_

#include "PBibliotecas.h"

class Parede {
public:
	sf::RectangleShape retanguloCenario;

	Parede(int inputLargura, int inputAltura, int inputPosicaoX,
			int inputPosicaoY, sf::Color inputCor, sf::Color inputCorBorda);
};

#endif
