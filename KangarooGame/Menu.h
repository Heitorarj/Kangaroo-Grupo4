#ifndef MENU_H_
#define MENU_H_

#include "Bibliotecas.h"

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
