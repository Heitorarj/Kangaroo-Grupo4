#include "Jogo.hpp"
#include "Cenario.hpp"

void criaFase(int inputNumeroFase, Parede *inputParede, Escada *inputEscada,
		Fruta *inputFruta, Arvore *inputArvore, Flor *inputFlor,
		Nuvem *inputNuvem) {
	if (inputNumeroFase == 1) {
		Parede minhasParedes(800, 25, sf::Color(122, 77, 31),
				sf::Color(0, 0, 0), inputNumeroFase);
		Escada minhasEscadas(75, 15, sf::Color(122, 77, 31), sf::Color(0, 0, 0),
				inputNumeroFase);
		Fruta minhasFrutas(inputNumeroFase);
		Arvore minhasArvores(inputNumeroFase);
		Flor minhasFlores(inputNumeroFase);
		Nuvem minhasNuvens(inputNumeroFase);

		*inputParede = minhasParedes;
		*inputEscada = minhasEscadas;
		*inputFruta = minhasFrutas;
		*inputArvore = minhasArvores;
		*inputFlor = minhasFlores;
		*inputNuvem = minhasNuvens;
	}
}

void desenhaFase(Parede inputParede, Escada inputEscada, Fruta *inputFruta,
		Arvore *inputArvore, Flor *inputFlor, Nuvem *inputNuvem,
		sf::RenderWindow *inputJanela, int inputNumeroFase) {
	if (inputNumeroFase == 1) {
		for (int i = 0; i < 3; ++i) {
			inputArvore->arvoreCorpo[i].setTexture(inputArvore->arvoreTextura); // Por algum motivo, se eu tirar essa linha, as frutas viram quadrados brancos. Foram algumas horas até chegar nessa conclusão
			inputJanela->draw(inputArvore->arvoreCorpo[i]);
		}
		for (int i = 0; i < 3; ++i) {
			inputFruta->frutaCorpo[i].setTexture(inputFruta->frutaTextura);
			inputJanela->draw(inputFruta->frutaCorpo[i]);
		}
		for (int i = 0; i < 5; ++i) {
			inputFlor->florCorpo[i].setTexture(inputFlor->florTextura);
			inputJanela->draw(inputFlor->florCorpo[i]);
		}
		for (int i = 0; i < 5; ++i) {
			inputNuvem->nuvemCorpo[i].setTexture(inputNuvem->nuvemTextura);
			inputJanela->draw(inputNuvem->nuvemCorpo[i]);
		}
		for (int i = 0; i < 6; ++i) {
			inputJanela->draw(inputParede.retanguloCenario[i]);
		}
		for (int i = 0; i < 15; ++i) {
			inputJanela->draw(inputEscada.retanguloCenario[i]);
		}

	}
}

void checarColisaoFruta(Jogador *inputJogador, Fruta *inputFruta,
		Texto *inputTexto) {
	for (int i = 0; i < 3; i++) {
		if (inputJogador->jogadorCorpo.getGlobalBounds().intersects(
				inputFruta->frutaCorpo[i].getGlobalBounds())) {
			inputJogador->pontos += 100;
			inputFruta->frutaCorpo[i].setPosition(-50, -50);
			char textoContador[5];
			sprintf(textoContador, "Pontos:\t%d", inputJogador->pontos); // Código pego do ChuvaGame
			inputTexto->texto.setString(textoContador);
			std::cout << "Pontos: " << inputJogador->pontos << std::endl;
		}
	}
}

void girar(Parede *inputParede, Escada *inputEscada, Fruta *inputFruta,
		Arvore *inputArvore, Flor *inputFlor, Nuvem *inputNuvem) {
	inputParede->girar();
	inputEscada->girar();
	inputFruta->girar();
	inputArvore->girar();
	inputFlor->girar();
	inputNuvem->girar();
}
