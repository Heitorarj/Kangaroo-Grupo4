#ifndef PMENU_H_
#define PMENU_H_

#include "PBibliotecas.h"

class Menu {
public:

	sf::RectangleShape butao;
	sf::CircleShape click;
	sf::Text texto;

	Menu();
	bool menuRodando();
	void desenhaMenu(sf::RenderWindow *inputJanela);
};

#endif
