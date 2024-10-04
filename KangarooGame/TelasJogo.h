#ifndef TELASJOGO_H_
#define TELASJOGO_H_

#include "Bibliotecas.h"
#include "Jogador.h"
#include "Texto.h"

class TelasJogo {
public:
	sf::RectangleShape tela, botao;
	sf::CircleShape click;
	sf::Text texto;
	sf::Font fonteTexto;
	int codigoDesenho;

	TelasJogo();
	void clickMouse(sf::RenderWindow *inputJanela, int *inputTelaCodigo,
			Jogador *inputJogador);
	void desenhaVitoria(sf::RenderWindow *inputJanela, Jogador *inputJogador,
			Texto *inputTexto);
	void desenhaDerrota(sf::RenderWindow *inputJanela, Jogador *inputJogador,
			Texto *inputTexto);
	void desenhaMenu(sf::RenderWindow *inputJanela, Jogador *inputJogador,
			int *inputTelaCodigo);
};

#endif
