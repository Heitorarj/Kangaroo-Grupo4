#ifndef JOGO_HPP_
#define JOGO_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <ctime>
#include "Cenario.hpp"
#include "Moveis.hpp"

void criaFase(int inputNumeroFase, Parede *inputParede, Escada *inputEscada,
		Fruta *inputFruta, Arvore *inputArvore, Flor *inputFlor, Nuvem *inputNuvem);
void desenhaFase(Parede inputParede, Escada inputEscada, Fruta *inputFruta,
		Arvore *inputArvore, Flor *inputFlor, Nuvem *inputNuvem, sf::RenderWindow *inputJanela,
		int inputNumeroFase);
void checarColisaoFruta(Jogador *inputJogador, Fruta *inputFruta,
		Texto *inputTexto);
void girar(Parede *inputParede, Escada *inputEscada, Fruta *inputFruta,
		Arvore *inputArvore, Flor *inputFlor, Nuvem *inputNuvem);

#endif
