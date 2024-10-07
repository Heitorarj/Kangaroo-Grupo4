#ifndef MAPA_H_
#define MAPA_H_

#include "Inimigo.h"
#include "Tempo.h"
#include "Jogador.h"
#include "Parede.h"
#include "Escada.h"
#include "Fruta.h"
#include "Arvore.h"
#include "Sino.h"
#include "Flor.h"
#include "Nuvem.h"
#include "Filhote.h"
#include "Sino.h"
#include "Texto.h"
#include "TelasJogo.h"

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
	Sino meuSino;

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
	void criarSino(int inputNumeroFase, Sino *inputSino);

	void criarMapa(int inputNumeroFase,
			std::vector<Parede> *inputParede, // Chama as funções de que criam os objetos do mapa
			std::vector<Escada> *inputEscada, std::vector<Fruta> *inputFruta,
			std::vector<Arvore> *inputArvore, std::vector<Flor> *inputFlor,
			std::vector<Nuvem> *inputNuvem, Filhote *inputFilhote,
			NuvemInimiga *inputNuvemInimiga, Sino *inputSino,
			sf::RenderWindow *janela);

	void desenharMapa(int inputNumeroFase, std::vector<Parede> &inputParede,
			std::vector<Escada> &inputEscada, std::vector<Fruta> &inputFruta,
			std::vector<Arvore> &inputArvore, std::vector<Flor> &inputFlor,
			std::vector<Nuvem> &inputNuvem, Filhote *inputFilhote,
			NuvemInimiga *inputNuvemInimiga, Texto *inputTexto, Sino *inputSino,
			sf::RenderWindow *janela);

	void checarColisaoFruta(Jogador *inputJogador,
			std::vector<Fruta> &inputFruta, Texto *inputTexto, Som *inputSom);

	void checarColisaoSino(Jogador *inputJogador, Sino *inputSino,
			std::vector<Fruta> &inputFruta, NuvemInimiga *inputNuvemInimiga,
			Som *inputSom);

	void nivelDificuldade(Jogador *inputJogador,
			NuvemInimiga *inputNuvemInimiga, sf::Color *inputCor, Som *inputSom,
			std::vector<Nuvem> &inputNuvens, std::vector<Parede> &inputParedes,
			std::vector<Flor> &inputFlores, std::vector<Arvore> &inputArvores,
			Filhote *inputFilhote, std::vector<Escada> &inputEscadas, Sino *inputSino);

	void checarFimJogo(Jogador *inputJogador, Filhote *inputFilhote,
			int *inputFim, sf::RenderWindow *inputJanela);

	void moverNuvem(int inputNumeroFase, std::vector<Nuvem> &inputNuvem,
			float inputDeltaTime);
	void moverNuvemInimiga(int inputNumeroFase, NuvemInimiga *inputNuvemInimiga,
			float inputDeltaTime);
	void moverFilhote(int inputNumeroFase, Filhote *inputFilhote,
			float inputDeltaTime);

	void atualizaVisibilidadeHitbox(Jogador *inputJogador,
			std::vector<Parede> &inputParedes, NuvemInimiga *inputNuvemInimiga,
			Inimigo *inputInimigo, Filhote *inputFilhote);

	void mapaUpdate(int inputNumeroFase, Jogador *inputJogador,
			std::vector<Fruta> &inputFrutas, Texto *inputTexto,
			Filhote *inputFilhote, std::vector<Nuvem> &inputNuvens,
			NuvemInimiga *inputNuvemInimiga, Sino *inputSino,
			std::vector<Parede> &inputParede, Inimigo *inputInimigo,
			float inputTempo, int *inputTelaCodigo, sf::Color *inputCor,
			Som *inputSom, std::vector<Flor> &inputFlores,
			std::vector<Arvore> &inputArvores,
			std::vector<Escada> &inputEscadas, sf::RenderWindow *janela);
};

#endif
