#ifndef PJOGO_H_
#define PJOGO_H_

#include "PInimigo.h"
#include "PJogador.h"
#include "PMapa.h"
#include "PTempo.h"

class Jogo {
public:
	//Variaveis
	//Janela
	sf::RenderWindow *janela;
	sf::Event evento;

	Jogador jogador;
	Inimigo inimigo;
	Mapa meuMapa;
	Tempo meuTempo;

	//Funcoes privadas
	void inicializaVariaveis();
	void inicializaJanela();

public:
	//Construtores / Destrtutores
	Jogo(int inputNumeroFase);
	~Jogo();

	//
	const bool jogoRodando() const;

	//Funcoes
	void pollEventos();
	void atualiza();
	void desenha(int inputNumeroFase);
};

#endif
