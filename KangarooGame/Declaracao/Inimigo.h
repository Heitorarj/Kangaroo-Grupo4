#ifndef INIMIGO_H_
#define INIMIGO_H_

#include "Jogador.h"

class Inimigo {
public:
	sf::RectangleShape hitboxInimigo, hitboxTiro;
	sf::Sprite corpoInimigo, tiroInimigo;
	sf::Texture texturaInimigo, texturaTiroInimigo, texturaInimigoPedraAlta, texturaInimigoGirada;

	float velocidadeVertical, velocidadeHorizontal, persegueJogadorX,
			persegueJogadorY;
	sf::Vector2f escalaInimigo;

	bool colidiuChao, colidiuTopo, colidiuDireita, colidiuEsquerda,
			colidiuPlataforma, podeDescer;
	int direcaoMovimento, tipoTiro;
	sf::Vector2f posicaoInicial;

	void inicializaVariaveisInimigo();
	void inicializaHitboxInimigo();
	void inicializaTexturaInimigo();

	void movimentoInimigo();
	void descer();

	Jogador &jogador;

	Inimigo(Jogador &jogador);
	~Inimigo();

	// Funções
	sf::RectangleShape getHitboxInimigo();
	void colisaoJogador(Jogador *inputJogador, Som *inputSom,
			Texto *inputTexto);
	void atualizaColisaoPlataforma(std::vector<Parede> &inputParedes);
	void atualizaColisaoBorda(const sf::RenderTarget *target);
	void atacarJogador(Jogador &inputJogador, Som *inputSom);
	void atualizaInimigo(const sf::RenderTarget *target,
			std::vector<Parede> &inputParedes, Jogador *inputJogador,
			Som *inputSom, Texto *inputTexto);
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
			std::vector<Escada> &inputEscadas, Sino *inputSino, Inimigo *inputInimigo);
};

#endif
