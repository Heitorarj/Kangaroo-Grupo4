#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "ClassesFuncoes.hpp"

int main() {

	sf::RenderWindow janela(sf::VideoMode(1100, 800), "Kangaroo Game");

	Parede minhasParedes(800, 25, sf::Color::Yellow, sf::Color::Blue);
	Escada minhasEscadas(75, 15, sf::Color::Yellow, sf::Color::Blue);
	Jogador meuJogador;

	while (janela.isOpen()) {

		sf::Event evento;

		while (janela.pollEvent(evento)) {
			if (evento.type == sf::Event::Closed) {
				janela.close();
			}
		}

		meuJogador.moveJogador();
		janela.clear();
		for (int i = 0; i < 6; ++i) {
			janela.draw(minhasParedes.retanguloCenario[i]);
		}
		for (int i = 0; i < 15; ++i) {
			janela.draw(minhasEscadas.retanguloCenario[i]);
		}
		janela.draw(meuJogador.jogadorCorpo);
		janela.display();
	}
}
