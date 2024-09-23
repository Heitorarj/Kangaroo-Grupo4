#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

#include "Moveis.hpp"
#include "Cenario.hpp"

int main() {

	sf::RenderWindow janela(sf::VideoMode(1100, 800), "Kangaroo Game");

	Parede minhasParedes(800, 25, sf::Color(168, 106, 12),
			sf::Color(0, 0, 0));
	Escada minhasEscadas(75, 15, sf::Color(168, 106, 12),
			sf::Color(0, 0, 0));
	Jogador meuJogador;
	Hitbox kangarooHitbox;
	HitboxTester testadorHitbox;
	Fruta minhaFruta;
	Texto meuTexto;

	while (janela.isOpen()) {

		sf::Event evento;

		while (janela.pollEvent(evento)) {
			if (evento.type == sf::Event::Closed) {
				janela.close();
			}
		}

		meuJogador.moveJogador();
		kangarooHitbox.retanguloCenario.setPosition(
				meuJogador.jogadorCorpo.getPosition().x,
				meuJogador.jogadorCorpo.getPosition().y);

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			testadorHitbox.retanguloCenario.setPosition(
					sf::Vector2f(sf::Mouse::getPosition(janela).x,
							sf::Mouse::getPosition(janela).y));
		}

		janela.clear(sf::Color(83, 0, 138));

		if (testadorHitbox.retanguloCenario.getGlobalBounds().intersects(
				meuJogador.jogadorCorpo.getGlobalBounds())) {
			testadorHitbox.retanguloCenario.setOutlineColor(sf::Color::Blue);
		} else {
			testadorHitbox.retanguloCenario.setOutlineColor(sf::Color::Red);
		} // If para testar colisões temporariamente

		if (meuJogador.jogadorCorpo.getGlobalBounds().intersects(
				minhasParedes.retanguloCenario[0].getGlobalBounds())) {
			meuJogador.jogadorCorpo.setPosition(
					sf::Vector2f(meuJogador.jogadorCorpo.getPosition().x,
							meuJogador.jogadorCorpo.getPosition().y - 1));
		} // Estava testando o agachamento do canguru, if temporario
		for (int i = 0; i < 6; ++i) {
			janela.draw(minhasParedes.retanguloCenario[i]);
		}
		for (int i = 0; i < 15; ++i) {
			janela.draw(minhasEscadas.retanguloCenario[i]);
		}

		for (int i = 0; i < 3; ++i) {
			janela.draw(minhaFruta.frutaCorpo[i]);

			if (meuJogador.jogadorCorpo.getGlobalBounds().intersects(
					minhaFruta.frutaCorpo[i].getGlobalBounds())) {
				meuJogador.pontos += 100;
				minhaFruta.frutaCorpo[i].setPosition(-50, -50);
				char textoContador[5];
				sprintf(textoContador, "Pontos:\t%d", meuJogador.pontos); // Código pego do ChuvaGame
				meuTexto.texto.setString(textoContador);
			}
			std::cout << "Pontos: " << meuJogador.pontos << std::endl;
		}

		janela.draw(meuJogador.jogadorCorpo);
		janela.draw(meuTexto.retanguloCenario);
		janela.draw(meuTexto.texto);
		janela.draw(kangarooHitbox.retanguloCenario);
		janela.draw(testadorHitbox.retanguloCenario);
		janela.display();
	}
}
