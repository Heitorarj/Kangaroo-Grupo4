
#ifndef PJOGADOR_H_
#define PJOGADOR_H_

#include "PBibliotecas.h"

class Jogador {
public:
	float velocidadeMovimento;
	int pontos;
	int vidas;

	sf::RectangleShape hitboxJogador;
	sf::Texture texturaJogador;
	sf::Texture texturaJogadorAgachado;
	sf::Texture texturaJogadorSoco;
	sf::Sprite corpoJogador;
	sf::Vector2f escalaJogador;
	sf::Texture vidaTextura;
	sf::Sprite vida[3];
	sf::RectangleShape vidasMoldura;
	sf::Text vidasTexto;
	sf::Font fonteTexto;

	//Funcoes privadas
	void inicializaVariaveisJogador();
	void inicializaHitboxJogador();
	void inicializaTexturaJogador();
	void inicializaVidas();

	Jogador(float x = 200.f, float y = 650.f);
	virtual ~Jogador();

	//Funcoes
	sf::RectangleShape getHitboxJogador();
	void atualizaInput();
	void atualizaColisaoBorda(const sf::RenderTarget *target);
	void atualizaVidas();
	void atualizaJogador(const sf::RenderTarget *target);
	void desenhaJogador(sf::RenderTarget *target);
};

#endif
