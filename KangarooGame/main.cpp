#include "Jogo.h"

int main(int argc, char **argv) {

	std::srand(static_cast<unsigned>(time(NULL))); //Será usado para randomizar o movimento dos inimigos

	//Inicia o Jogo
	Jogo jogo;

	while (jogo.jogoRodando()) {
		//Atualiza o jogo
		jogo.atualiza(); //Fazer as acoes do jogo aqui, Jogo.cpp

		//Desenha o jogo
		jogo.desenha(); //Fazer os desenhos do jogo aqui, Jogo.cpp
	}

	return 0;
}

