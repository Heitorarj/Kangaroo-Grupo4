#include "../Declaracao/Texto.h"

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
