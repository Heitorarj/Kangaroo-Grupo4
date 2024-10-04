#include "Filhote.h"

Filhote::Filhote() {
	filhoteTextura.loadFromFile("assets/Filhote1.png");
	filhoteCorpo.setTexture(filhoteTextura);
	filhoteCorpo.setOrigin(filhoteCorpo.getLocalBounds().width / 2,
			filhoteCorpo.getLocalBounds().height / 2);
	filhoteCorpo.setScale(0.08, 0.08);
	filhoteHitbox.setSize(
			sf::Vector2f(filhoteCorpo.getLocalBounds().width / 20,
					filhoteCorpo.getLocalBounds().height / 20));
	filhoteHitbox.setOrigin(filhoteHitbox.getLocalBounds().width / 2,
			filhoteHitbox.getLocalBounds().height / 2);
	filhoteHitbox.setFillColor(sf::Color::Transparent);
	filhoteHitbox.setOutlineColor(sf::Color::Green);
	filhoteHitbox.setOutlineThickness(5);
	velocidadeX = 2;
}
