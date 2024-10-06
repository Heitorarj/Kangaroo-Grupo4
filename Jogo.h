#ifndef JOGO_H_
#define JOGO_H_

#include "Bibliotecas.h"
#include "Inimigo.h"
#include "Mapa.h"
#include "Tempo.h"
#include "Som.h"

class Jogo {
public:
	//Variaveis
	//Janela
	sf::RenderWindow *janela;
	sf::Event evento;
	sf::Color corFundo;

	Jogador jogador;
	Inimigo inimigo;
	Mapa meuMapa;
	Tempo meuTempo;
	TelasJogo minhaTela;
	Som meuSom;
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
