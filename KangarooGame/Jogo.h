#ifndef JOGO_H_
#define JOGO_H_

#include "Bibliotecas.h"
#include "Inimigo.h"
#include "Mapa.h"
#include "Tempo.h"
#include "Menu.h"

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
	TelasJogo minhaTela;
	int telaCodigo;

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
