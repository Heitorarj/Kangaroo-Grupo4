#ifndef JOGADOR_H_
#define JOGADOR_H_

#include "Bibliotecas.h"
#include "Parede.h"
#include "Som.h"
#include "Tempo.h"

class Jogador {
public:
	float velocidadeMovimento, velocidadePulo, velocidadeVertical, gravidade;
	int pontos, vidas;
	bool jogadorColideEscada, jogadorGiradoEsquerda, jogadorAgachado,
			jogadorSoco, noChao;

	sf::RectangleShape hitboxJogador, hitboxSoco;
	sf::Texture texturaJogador, texturaJogadorAgachado,
			texturaJogadorAgachadoGirado, vidaTextura, texturaJogadorEscada,
			texturaJogadorGirado, texturaJogadorSoco, texturaJogadorSocoGirado;
	sf::Sprite corpoJogador;
	sf::Vector2f escalaJogador;
	sf::Sprite vida[3];
	sf::RectangleShape vidasMoldura;
	sf::Text vidasTexto;
	sf::Font fonteTexto;

	Som meuSom;

	//Funcoes privadas
	void inicializaVariaveisJogador();
	void inicializaHitboxJogador();
	void inicializaTexturaJogador();
	void inicializaVidas();

	Jogador(float x = 200.f, float y = 650.f);
	virtual ~Jogador();

	//Funcoes
	sf::RectangleShape getHitboxJogador();
	void atualizaInput(float meuTempo);
	void atualizaTexturas(Som *inputSom);
	void atualizaColisaoBorda(const sf::RenderTarget *target);
	void atualizaColisaoParede(std::vector<Parede> &inputParedes);
	void atualizaVidas();
	void atualizaJogador(const sf::RenderTarget *target,
			std::vector<Parede> &inputParedes, Som *inputSom, float meuTempo);
	void desenhaJogador(sf::RenderTarget *target);
};

#endif
