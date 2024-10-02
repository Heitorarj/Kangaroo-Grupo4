
#ifndef PINIMIGO_H_
#define PINIMIGO_H_

#include "PJogador.h"

class Inimigo {
protected:
	sf::RectangleShape hitboxInimigo;
	sf::Texture texturaInimigo;
	sf::Sprite corpoInimigo;
	sf::Vector2f escalaInimigo;
	float velocidadeMovimento;
	float persegueJogadorX, persegueJogadorY;

	Jogador jogador;

	//Funcoes privadas
	void inicializaVariaveisInimigo();
	void inicializaHitboxInimigo();
	void inicializaTexturaInimigo();

public:
	//Construtores / Destrutores
	Inimigo();
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
	void nuvemAtacar(Jogador &inputJogador, float inputDeltaTime,
			sf::RenderWindow *inputJanela);
};

#endif
