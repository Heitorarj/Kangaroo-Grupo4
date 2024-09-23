#include "Jogo.hpp"
#include "Cenario.hpp"

void criaFase(int numeroFase, Parede *inputParede, Escada *inputEscada) {
	if (numeroFase == 1) {
		Parede minhasParedes(800, 25, sf::Color(168, 106, 12),
				sf::Color(0, 0, 0), numeroFase);
		Escada minhasEscadas(75, 15, sf::Color(168, 106, 12),
				sf::Color(0, 0, 0), numeroFase);
		*inputParede = minhasParedes;
		*inputEscada = minhasEscadas;
	}
}

void desenhaFase(Parede inputParede, Escada inputEscada,
		sf::RenderWindow *inputJanela) {
	for (int i = 0; i < 6; ++i) {
		inputJanela->draw(inputParede.retanguloCenario[i]);
	}
	for (int i = 0; i < 15; ++i) {
		inputJanela->draw(inputEscada.retanguloCenario[i]);
	}
}

