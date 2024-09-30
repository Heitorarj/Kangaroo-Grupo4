#ifndef PMAPA_H_
#define PMAPA_H_

#include "PInimigo.h"
#include "PTempo.h"

class Parede {
public:
	sf::RectangleShape retanguloCenario;

	Parede(int inputLargura, int inputAltura, int inputPosicaoX,
			int inputPosicaoY, sf::Color inputCor, sf::Color inputCorBorda);
};

class Escada {
public:
	sf::RectangleShape retanguloCenario;

	Escada(int inputLargura, int inputAltura, int inputPosicaoX,
			int inputPosicaoY, sf::Color inputCor, sf::Color inputCorBorda);
};

class Fruta {
public:
	sf::Texture frutaTextura;
	sf::Sprite frutaCorpo;

	Fruta();
};

class Arvore {
public:
	sf::Texture arvoreTextura;
	sf::Sprite arvoreCorpo;

	Arvore();
};

class Flor {
public:
	sf::Texture florTextura;
	sf::Sprite florCorpo;

	Flor();
};

class Nuvem {
public:
	float velocidadeX;
	sf::Texture nuvemTextura;
	sf::Sprite nuvemCorpo;

	Nuvem();
};

class Filhote {
public:
	sf::Texture filhoteTextura;
	sf::Sprite filhoteCorpo;
	sf::RectangleShape filhoteHitbox;
	float velocidadeX;

	Filhote();
};

class Texto {
public:
	sf::RectangleShape retanguloCenario;
	sf::Font fonte;
	sf::Text texto;

	Texto();
};

class Mapa {
public:

	std::vector<Parede> minhasParedes;
	std::vector<Escada> minhasEscadas;
	std::vector<Fruta> minhasFrutas;
	std::vector<Arvore> minhasArvores;
	std::vector<Flor> minhasFlores;
	std::vector<Nuvem> minhasNuvens;
	Filhote meuFilhote;
	NuvemInimiga minhaNuvemInimiga;
	Texto meuTexto;

	Mapa();

	void criarParede(int inputNumeroFase, std::vector<Parede> *inputParede); // Cria e posiciona objetos
	void criarEscada(int inputNumeroFase, std::vector<Escada> *inputEscada);
	void criarFruta(int inputNumeroFase, std::vector<Fruta> *inputFruta);
	void criarArvore(int inputNumeroFase, std::vector<Arvore> *inputArvore);
	void criarFlor(int inputNumeroFase, std::vector<Flor> *inputFlor);
	void criarNuvem(int inputNumeroFase, std::vector<Nuvem> *inputNuvem);
	void criarFilhote(int inputNumeroFase, Filhote *inputFilhote);
	void criarNuvemInimiga(int inputNumeroFase,
			NuvemInimiga *inputNuvemInimiga);

	void criarMapa(int inputNumeroFase,
			std::vector<Parede> *inputParede, // Chama as funções de que criam os objetos do mapa
			std::vector<Escada> *inputEscada, std::vector<Fruta> *inputFruta,
			std::vector<Arvore> *inputArvore, std::vector<Flor> *inputFlor,
			std::vector<Nuvem> *inputNuvem, Filhote *inputFilhote,
			NuvemInimiga *inputNuvemInimiga, sf::RenderWindow *janela);

	void desenharMapa(int inputNumeroFase, std::vector<Parede> &inputParede,
			std::vector<Escada> &inputEscada, std::vector<Fruta> &inputFruta,
			std::vector<Arvore> &inputArvore, std::vector<Flor> &inputFlor,
			std::vector<Nuvem> &inputNuvem, Filhote *inputFilhote,
			NuvemInimiga *inputNuvemInimiga, Texto *inputTexto,
			sf::RenderWindow *janela);

	void checarColisaoFruta(Jogador *inputJogador,
			std::vector<Fruta> &inputFruta, Texto *inputTexto);

	void checarFimJogo(Jogador *inputJogador, Filhote *inputFilhote,
			sf::RenderWindow *inputJanela);

	void moverNuvem(int inputNumeroFase, std::vector<Nuvem> &inputNuvem,
			float inputDeltaTime);
	void moverNuvemInimiga(int inputNumeroFase, NuvemInimiga *inputNuvemInimiga,
			float inputDeltaTime);
	void moverFilhote(int inputNumeroFase, Filhote *inputFilhote,
			float inputDeltaTime);

	void mapaUpdate(int inputNumeroFase, Jogador *inputJogador,
			std::vector<Fruta> &inputFrutas, Texto *inputTexto,
			Filhote *inputFilhote, std::vector<Nuvem> &inputNuvens,
			NuvemInimiga *inputNuvemInimiga, float inputTempo,
			sf::RenderWindow *janela);

};

#endif
