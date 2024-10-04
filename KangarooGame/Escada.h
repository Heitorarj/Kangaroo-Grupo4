#ifndef ESCADA_H_
#define ESCADA_H_

#include "Bibliotecas.h"

class Escada {
public:
	sf::RectangleShape retanguloCenario;

	Escada(int inputLargura, int inputAltura, int inputPosicaoX,
			int inputPosicaoY, sf::Color inputCor, sf::Color inputCorBorda);
};

#endif
