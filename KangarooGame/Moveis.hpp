#ifndef MOVEIS_HPP_
#define MOVEIS_HPP_

class Movel {
public:
	float velocidadeX, velocidadeY;
};

class Jogador: public Movel {
public:
	sf::Texture jogadorTextura;
	sf::Sprite jogadorCorpo;

	Jogador() {
		jogadorTextura.loadFromFile("assets/kangaroo.png");
		jogadorCorpo.setTexture(jogadorTextura);
		jogadorCorpo.setScale(sf::Vector2f(0.05, 0.05));
		jogadorCorpo.setPosition(sf::Vector2f(200, 600));
	}

	void moveJogador() {

		velocidadeX = 0;
		velocidadeY = 0;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			velocidadeX = 0.12;
			jogadorCorpo.setPosition(
					sf::Vector2f(jogadorCorpo.getPosition().x + velocidadeX,
							jogadorCorpo.getPosition().y));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			velocidadeX = 0.12;
			jogadorCorpo.setPosition(
					sf::Vector2f(jogadorCorpo.getPosition().x - velocidadeX,
							jogadorCorpo.getPosition().y));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			velocidadeY = 0.12;
			jogadorCorpo.setPosition(
					sf::Vector2f(jogadorCorpo.getPosition().x,
							jogadorCorpo.getPosition().y - velocidadeY));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			velocidadeY = 0.12;
			jogadorCorpo.setPosition(
					sf::Vector2f(jogadorCorpo.getPosition().x,
							jogadorCorpo.getPosition().y + velocidadeY));
		}
	}

};

#endif
