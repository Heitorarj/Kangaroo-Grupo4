
#include "Jogo.hpp"
#include "Cenario.hpp"

Parede::Parede(int inputLargura, int inputAltura, int inputPosicaoX,
		int inputPosicaoY, sf::Color inputCor, sf::Color inputCorBorda) {

	retanguloCenario.setOutlineColor(inputCorBorda);
	retanguloCenario.setOutlineThickness(5);
	retanguloCenario.setFillColor(inputCor);
	retanguloCenario.setSize(sf::Vector2f(inputLargura, inputAltura));
	retanguloCenario.setPosition(inputPosicaoX, inputPosicaoY);
}

Escada::Escada(int inputLargura, int inputAltura, int inputPosicaoX,
		int inputPosicaoY, sf::Color inputCor, sf::Color inputCorBorda) {

	retanguloCenario.setOutlineColor(inputCorBorda);
	retanguloCenario.setOutlineThickness(5);
	retanguloCenario.setFillColor(inputCor);
	retanguloCenario.setSize(sf::Vector2f(inputLargura, inputAltura));
	retanguloCenario.setPosition(inputPosicaoX, inputPosicaoY);
}

Fruta::Fruta() {
	frutaTextura.loadFromFile("assets/fruta.png");
	frutaCorpo.setTexture(frutaTextura);
	frutaCorpo.setScale(0.04, 0.04);
	frutaCorpo.setOrigin(frutaCorpo.getLocalBounds().width / 2,
			frutaCorpo.getLocalBounds().height / 2);
}

Arvore::Arvore() {
	arvoreTextura.loadFromFile("assets/arvore.png");
	arvoreCorpo.setTexture(arvoreTextura);
	arvoreCorpo.setScale(4, 4);
	arvoreCorpo.setOrigin(arvoreCorpo.getLocalBounds().width / 2,
			arvoreCorpo.getLocalBounds().height / 2);
}

Flor::Flor() {
	florTextura.loadFromFile("assets/flor.png");
	florCorpo.setTexture(florTextura);
	florCorpo.setScale(3, 3);
	florCorpo.setOrigin(florCorpo.getLocalBounds().width / 2,
			florCorpo.getLocalBounds().height / 2);
}

Texto::Texto() {
	retanguloCenario.setFillColor(sf::Color::Black);
	retanguloCenario.setOutlineColor(sf::Color::Blue);
	retanguloCenario.setOutlineThickness(5);
	retanguloCenario.setSize(sf::Vector2f(200, 25));

	fonte.loadFromFile("assets/arial_narrow_7.ttf");
	sf::Text meuTexto("Pontos:\t", fonte, 24);
	texto = meuTexto;
	texto.setPosition(sf::Vector2f(400, 760));
	retanguloCenario.setPosition(395, 762);
}

