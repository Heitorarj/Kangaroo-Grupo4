#include "PMenu.h"

Menu::Menu() {

	butao.setFillColor(sf::Color(113, 175, 41));
	butao.setOutlineColor(sf::Color::Black);
	butao.setOutlineThickness(5);
	butao.setOrigin(butao.getLocalBounds().width / 2,
			butao.getGlobalBounds().height / 2);

	butao.setSize(sf::Vector2f(400, 100));
	butao.setPosition(350, 300);

	click.setOrigin(click.getLocalBounds().width / 2,
			click.getGlobalBounds().height / 2);
	click.setFillColor(sf::Color::White);
	click.setRadius(20);
}

bool Menu::menuRodando() {
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
		click.setPosition(sf::Mouse::getPosition().x - 430,
				sf::Mouse::getPosition().y - 190);

		if (click.getGlobalBounds().intersects(butao.getGlobalBounds())) {
			return false;
		}
	}
	return true;
}

void Menu::desenhaMenu(sf::RenderWindow *inputJanela) {
	inputJanela->draw(butao);
	inputJanela->draw(click);
}

