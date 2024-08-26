/*
 * Classes.hpp
 *
 *  Created on: 26 de ago. de 2024
 *      Author: danie
 */

#ifndef CLASSESFUNCOES_HPP_
#define CLASSESFUNCOES_HPP_

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
class Cenario {
public:
	sf::RectangleShape retanguloCenario;
	int largura, altura;
};

class Parede: public Cenario {
public:

	sf::RectangleShape retanguloCenario[10];

	Parede(int inputLargura, int inputAltura, sf::Color inputCor,
			sf::Color inputCorBorda) {

		for (int i = 0; i < 6; i++) {
			if (i == 0) {
				retanguloCenario[i].setOutlineColor(inputCorBorda);
				retanguloCenario[i].setOutlineThickness(5);
				retanguloCenario[i].setFillColor(inputCor);
				retanguloCenario[i].setSize(sf::Vector2f(inputLargura, 50));
			} else if (i == 4) {
				retanguloCenario[i].setOutlineColor(inputCorBorda);
				retanguloCenario[i].setOutlineThickness(5);
				retanguloCenario[i].setFillColor(inputCor);
				retanguloCenario[i].setSize(sf::Vector2f(100, 800));
			} else if (i == 5) {
				retanguloCenario[i].setOutlineColor(inputCorBorda);
				retanguloCenario[i].setOutlineThickness(5);
				retanguloCenario[i].setFillColor(inputCor);
				retanguloCenario[i].setSize(sf::Vector2f(200, 800));
			} else {
				retanguloCenario[i].setOutlineColor(inputCorBorda);
				retanguloCenario[i].setOutlineThickness(5);
				retanguloCenario[i].setFillColor(inputCor);
				retanguloCenario[i].setSize(
						sf::Vector2f(inputLargura, inputAltura));
			}

		}
		retanguloCenario[0].setPosition(100, 750);
		retanguloCenario[1].setPosition(100, 550);
		retanguloCenario[2].setPosition(100, 350);
		retanguloCenario[3].setPosition(100, 150);
		retanguloCenario[4].setPosition(0, 0);
		retanguloCenario[5].setPosition(900, 0);

	}

};

class Escada: public Cenario {
public:

	sf::RectangleShape retanguloCenario[15];

	Escada(int inputLargura, int inputAltura, sf::Color inputCor,
			sf::Color inputCorBorda) {

		for (int i = 0; i < 15; i++) {
			if (i == 12 or i == 13 or i == 14) {
				retanguloCenario[i].setOutlineColor(sf::Color::Red);
				retanguloCenario[i].setFillColor(sf::Color::Transparent);
				retanguloCenario[i].setOutlineThickness(5);
				retanguloCenario[i].setSize(
						sf::Vector2f(inputLargura + 20, 190));
			} else {
				retanguloCenario[i].setOutlineColor(inputCorBorda);
				retanguloCenario[i].setOutlineThickness(5);
				retanguloCenario[i].setFillColor(inputCor);
				retanguloCenario[i].setSize(
						sf::Vector2f(inputLargura, inputAltura));
			}

		}
		retanguloCenario[0].setPosition(775, 715); // Primeiro andar 0, 1, 2 e 3
		retanguloCenario[1].setPosition(775,
				retanguloCenario[0].getPosition().y - 40);
		retanguloCenario[2].setPosition(775,
				retanguloCenario[1].getPosition().y - 40);
		retanguloCenario[3].setPosition(775,
				retanguloCenario[2].getPosition().y - 40);	//	Primeiro andar
		retanguloCenario[4].setPosition(150,
				retanguloCenario[3].getPosition().y - 80);//  Segundo andar 4, 5, 6 e 7
		retanguloCenario[5].setPosition(150,
				retanguloCenario[4].getPosition().y - 40);
		retanguloCenario[6].setPosition(150,
				retanguloCenario[5].getPosition().y - 40);
		retanguloCenario[7].setPosition(150,
				retanguloCenario[6].getPosition().y - 40);		// Segundo andar
		retanguloCenario[8].setPosition(775,
				retanguloCenario[7].getPosition().y - 80);// Terceiro andar 8, 9, 10 e 11
		retanguloCenario[9].setPosition(775,
				retanguloCenario[8].getPosition().y - 40);
		retanguloCenario[10].setPosition(775,
				retanguloCenario[9].getPosition().y - 40);
		retanguloCenario[11].setPosition(775,
				retanguloCenario[10].getPosition().y - 40);	// Terceiro andar
		retanguloCenario[12].setPosition(765,// Escada invisíveis que irão colidir com o jogador 12, 13 e 14
				retanguloCenario[0].getPosition().y - 160);
		retanguloCenario[13].setPosition(140,
				retanguloCenario[4].getPosition().y - 160);
		retanguloCenario[14].setPosition(765,
				retanguloCenario[8].getPosition().y - 160);	// Escada invisíveis que irão colidir com o jogador

	}

};

#endif /* CLASSESFUNCOES_HPP_ */
