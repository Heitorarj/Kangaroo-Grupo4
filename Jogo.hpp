
#ifndef JOGO_HPP_
#define JOGO_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <ctime>
#include <vector>
#include "Cenario.hpp"
#include "Moveis.hpp"

void criarParede(int inputNumeroFase, std::vector<Parede> *inputParede); // Cria e posiciona objetos
void criarEscada(int inputNumeroFase, std::vector<Escada> *inputEscada);
void criarFruta(int inputNumeroFase, std::vector<Fruta> *inputFruta);
void criarArvore(int inputNumeroFase, std::vector<Arvore> *inputArvore);
void criarFlor(int inputNumeroFase, std::vector<Flor> *inputFlor);
void criarNuvem(int inputNumeroFase, std::vector<Nuvem> *inputNuvem);

void criarMapa(int inputNumeroFase, std::vector<Parede> *inputParede, // Chama as funões de que criam os objetos do mapa
		std::vector<Escada> *inputEscada, std::vector<Fruta> *inputFruta,
		std::vector<Arvore> *inputArvore, std::vector<Flor> *inputFlor,
		std::vector<Nuvem> *inputNuvem, sf::RenderWindow *janela);
void desenharMapa(int inputNumeroFase, std::vector<Parede> &inputParede,
		std::vector<Escada> &inputEscada, std::vector<Fruta> &inputFruta,
		std::vector<Arvore> &inputArvore, std::vector<Flor> &inputFlor,
		std::vector<Nuvem> &inputNuvem, sf::RenderWindow *janela);

void checarColisaoFruta(Jogador *inputJogador, std::vector<Fruta> &inputFruta, // Desenha o mapa
		Texto *inputTexto);

void moverNuvem(int inputNumeroFase, std::vector<Nuvem> &inputNuvem);
#endif
