#include "TelasJogo.h"
#include "Jogador.h"
#include "Texto.h"

TelasJogo::TelasJogo() {
	fonteTexto.loadFromFile("assets/arial_narrow_7.ttf");
	texto.setFont(fonteTexto);
	tela.setFillColor(sf::Color::Black);
	tela.setSize(sf::Vector2f(1100, 800));
	tela.setPosition(sf::Vector2f(-1100, 0));
	botao.setFillColor(sf::Color(113, 175, 41));
	botao.setOutlineColor(sf::Color::Black);
	botao.setOutlineThickness(5);
	botao.setSize(sf::Vector2f(250, 100));
	botao.setPosition(sf::Vector2f(-1100, 0));
	click.setPosition(sf::Vector2f(-1100, 0));
	click.setRadius(0.1);
	codigoDesenho = 0;
}

void TelasJogo::desenhaVitoria(sf::RenderWindow *inputJanela,
		Jogador *inputJogador, Texto *inputTexto) {
	tela.setPosition(sf::Vector2f(0, 0));
	sf::Text meuTexto("Vitoria", fonteTexto, 100);
	texto = meuTexto;
	texto.setPosition(sf::Vector2f(550, 400));
	texto.setOrigin(texto.getLocalBounds().width / 2,
			texto.getLocalBounds().height);
	texto.setFillColor(sf::Color::Yellow);

	inputJogador->vida[0].setPosition(490, 517);
	inputJogador->vida[1].setPosition(515, 517);
	inputJogador->vida[2].setPosition(540, 517);

	if (inputJogador->vidas == 2) {
		inputJogador->vida[2].setPosition(-50, -50);
	} else if (inputJogador->vidas == 1) {
		inputJogador->vida[2].setPosition(-50, -50);
		inputJogador->vida[1].setPosition(-50, -50);
	}

	inputTexto->texto.setPosition(425, 475);
	inputJogador->vidasTexto.setPosition(425, 510);
	inputJogador->hitboxJogador.setPosition(0, 0);
	inputJanela->draw(tela);
	inputJanela->draw(texto);
	inputJanela->draw(inputTexto->texto);
	inputJanela->draw(inputJogador->vidasTexto);
	for (int i; i < 3; i++) {
		inputJanela->draw(inputJogador->vida[i]);
	}
	inputJanela->display();

}

void TelasJogo::desenhaDerrota(sf::RenderWindow *inputJanela,
		Jogador *inputJogador, Texto *inputTexto) {
	tela.setPosition(sf::Vector2f(0, 0));
	sf::Text meuTexto("Derrota", fonteTexto, 100);
	texto = meuTexto;
	texto.setPosition(sf::Vector2f(550, 400));
	texto.setOrigin(texto.getLocalBounds().width / 2,
			texto.getLocalBounds().height);
	texto.setFillColor(sf::Color::Red);

	inputTexto->texto.setPosition(425, 475);
	inputJogador->vidasTexto.setPosition(425, 510);
	inputJogador->hitboxJogador.setPosition(0, 0);
	inputJanela->draw(tela);
	inputJanela->draw(texto);
	inputJanela->draw(inputTexto->texto);
	inputJanela->draw(inputJogador->vidasTexto);
	inputJanela->display();

}

void TelasJogo::clickMouse(sf::RenderWindow *inputJanela, int *inputTelaCodigo,
		Jogador *inputJogador) {
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)
			or sf::Keyboard::isKeyPressed(sf::Keyboard::Return)
			or sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		click.setPosition(sf::Mouse::getPosition(*inputJanela).x,
				sf::Mouse::getPosition(*inputJanela).y);
		if (click.getGlobalBounds().intersects(botao.getGlobalBounds())
				or sf::Keyboard::isKeyPressed(sf::Keyboard::Return)
				or sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			botao.setFillColor(sf::Color(168, 231, 240));
			tela.setFillColor(sf::Color::Black);
			inputJogador->hitboxJogador.setPosition(200, 650);
			*inputTelaCodigo = 0;
		}
	} else {
		click.setPosition(-50, -50);
	}

}
void TelasJogo::desenhaMenu(sf::RenderWindow *inputJanela,
		Jogador *inputJogador, int *inputTelaCodigo) {
	tela.setPosition(sf::Vector2f(0, 0));
	tela.setFillColor(sf::Color(168, 231, 240));
	sf::Text meuTexto("Jogar", fonteTexto, 100);
	texto = meuTexto;
	texto.setPosition(sf::Vector2f(540, 400));
	texto.setOrigin(texto.getLocalBounds().width / 2,
			texto.getLocalBounds().height);
	botao.setOrigin(botao.getLocalBounds().width / 2,
			botao.getLocalBounds().height);
	botao.setPosition(sf::Vector2f(545, 445));

	inputJogador->hitboxJogador.setPosition(0, 0);
	clickMouse(inputJanela, inputTelaCodigo, inputJogador);
	inputJanela->draw(tela);
	inputJanela->draw(botao);
	inputJanela->draw(texto);
	inputJanela->display();

}
