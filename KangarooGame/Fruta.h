#ifndef FRUTA_H_
#define FRUTA_H_

#include "Bibliotecas.h"

class Fruta {
public:
	sf::Texture frutaTextura;
	sf::Sprite frutaCorpo;
	int valorPontos[4], numeroTextura;

	Fruta();
};

#endif
