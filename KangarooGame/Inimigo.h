#ifndef INIMIGO_H_
#define INIMIGO_H_

#include "Jogador.h"

class Inimigo {
public:
	sf::RectangleShape hitboxInimigo;
	sf::Texture texturaInimigo;
	sf::Sprite corpoInimigo;
	sf::Vector2f escalaInimigo, direcaoAleatoria;
	float velocidadeMovimento, persegueJogadorX, persegueJogadorY;
	int tempoMudancaDirecao, frameAtual;

	Jogador &jogador;

	//Funcoes privadas
	void inicializaVariaveisInimigo();
	void inicializaHitboxInimigo();
	void inicializaTexturaInimigo();

public:
	//Construtores / Destrutores
	Inimigo(Jogador &jogador);
	virtual ~Inimigo();

	//Funcoes
	sf::RectangleShape getHitboxInimigo();
	void persegueJogador();
	void movimentoAleatorioInimigo();
	void atualizaColisaoBorda(const sf::RenderTarget *target);
	void atualizaInimigo(const sf::RenderTarget *target);
	void desenhaInimigo(sf::RenderTarget *target);
};

class NuvemInimiga {
public:
	float velocidadeX, tiroVelocidadeY;
	sf::Texture nuvemTextura;
	sf::Sprite nuvemCorpo;
	sf::Texture nuvemTiroTextura;
	sf::Sprite nuvemTiro;
	sf::RectangleShape hitboxNuvemInimiga;

	NuvemInimiga();
	void nuvemAtacar(Jogador &inputJogador, float inputDeltaTime, Som *inputSom,
			sf::RenderWindow *inputJanela, std::vector<Nuvem> &inputNuvens,
			std::vector<Parede> &inputParedes, std::vector<Flor> &inputFlores,
			std::vector<Arvore> &inputArvores,
			std::vector<Escada> &inputEscadas, Sino *inputSino);
};

#endif
