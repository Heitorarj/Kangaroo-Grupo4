#include "PJogo.h"

int main(int argc, char **argv) {

	//Inicia o Jogo
	Jogo jogo(1);

	while (jogo.jogoRodando()) {
		//Atualiza o jogo
		jogo.atualiza(); //Fazer as acoes do jogo aqui, Jogo.cpp
		//Desenha o jogo
		jogo.desenha(1); //Fazer os desenhos do jogo aqui, Jogo.cpp
	}

	return 0;
}

