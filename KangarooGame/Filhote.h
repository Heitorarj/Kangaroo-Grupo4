#ifndef FILHOTE_H_
#define FILHOTE_H_

#include "Bibliotecas.h"

class Filhote {
public:
	sf::Texture filhoteTextura, filhoteTexturaGirado;
	sf::Sprite filhoteCorpo;
	sf::RectangleShape filhoteHitbox;
	float velocidadeX;

	Filhote();

};

#endif
