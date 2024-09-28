#ifndef JOGO_H_
#define JOGO_H_

#include "Jogador.h"
#include "Inimigo.h"

class Jogo {
private:
	//Variaveis
	//Janela
	sf::RenderWindow *janela;
	sf::Event evento;

	Jogador jogador;
	Inimigo inimigo;

	//Funcoes privadas
	void inicializaVariaveis();
	void inicializaJanela();

public:
	//Construtores / Destrtutores
	Jogo();
	~Jogo();

	//
	const bool jogoRodando() const;

	//Funcoes
	void pollEventos();
	void atualiza();
	void desenha();
};

#endif
