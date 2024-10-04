#ifndef JOGADOR_H_
#define JOGADOR_H_

#include "Bibliotecas.h"
#include "Parede.h"

class Jogador {
public:
	float velocidadeMovimento;
	int pontos, vidas;

	sf::RectangleShape hitboxJogador;
	sf::Texture texturaJogador;
	sf::Texture texturaJogadorAgachado;
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
	void atualizaColisaoParede(std::vector <Parede> &inputParedes);
	void atualizaVidas();
	void atualizaJogador(const sf::RenderTarget *target, std::vector <Parede> &inputParedes);
	void desenhaJogador(sf::RenderTarget *target);
};

#endif
