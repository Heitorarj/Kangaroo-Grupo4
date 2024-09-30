#ifndef PJOGADOR_H_
#define PJOGADOR_H_

#include "PBibliotecas.h"

class Jogador {
public:
	sf::RectangleShape hitboxJogador;
	sf::Texture texturaJogador;
	sf::Texture texturaJogadorAgachado;
	sf::Sprite corpoJogador;
	sf::Vector2f escalaJogador;
	float velocidadeMovimento;
	int pontos;

	//Funcoes privadas
	void inicializaVariaveisJogador();
	void inicializaHitboxJogador();
	void inicializaTexturaJogador();

	Jogador(float x = 225.f, float y = 700.f);
	virtual ~Jogador();

	//Funcoes
	sf::RectangleShape getHitboxJogador();
	void atualizaInput();
	void atualizaColisaoBorda(const sf::RenderTarget* target);
	void atualizaJogador(const sf::RenderTarget* target);
	void desenhaJogador(sf::RenderTarget* target);
};

#endif
