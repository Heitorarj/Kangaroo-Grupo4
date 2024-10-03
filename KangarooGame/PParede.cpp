#include "PParede.h"

Parede::Parede(int inputLargura, int inputAltura, int inputPosicaoX,
		int inputPosicaoY, sf::Color inputCor, sf::Color inputCorBorda) {

	retanguloCenario.setOutlineColor(inputCorBorda);
	retanguloCenario.setOutlineThickness(5);
	retanguloCenario.setFillColor(inputCor);
	retanguloCenario.setSize(sf::Vector2f(inputLargura, inputAltura));
	retanguloCenario.setPosition(inputPosicaoX, inputPosicaoY);
}


