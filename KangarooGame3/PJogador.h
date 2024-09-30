#ifndef PJOGADOR_H_
#define PJOGADOR_H_

#include <iostream>
#include <vector>
#include <ctime>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

class Jogador {
private:
	sf::RectangleShape hitboxJogador;
	sf::Texture texturaJogador;
	sf::Texture texturaJogadorAgachado;
	sf::Sprite corpoJogador;
	sf::Vector2f escalaJogador;
	float velocidadeMovimento;

	//Funcoes privadas
	void inicializaVariaveisJogador();
	void inicializaHitboxJogador();
	void inicializaTexturaJogador();

public:
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
