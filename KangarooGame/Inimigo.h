#ifndef INIMIGO_H_
#define INIMIGO_H_

#include "Jogador.h"

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

#endif
