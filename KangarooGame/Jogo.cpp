#include "Jogo.hpp"
#include "Cenario.hpp"

void criarParede(int inputNumeroFase, std::vector<Parede> *inputParede) {
	if (inputNumeroFase == 1) {
		std::vector<Parede> minhasParedes(6,
				Parede(800, 25, 0, 0, sf::Color(122, 77, 31),
						sf::Color(0, 0, 0)));

		minhasParedes[0].retanguloCenario.setFillColor(sf::Color(113, 175, 41));
		minhasParedes[0].retanguloCenario.setPosition(100, 750);
		minhasParedes[1].retanguloCenario.setPosition(100, 550);
		minhasParedes[2].retanguloCenario.setPosition(100, 350);
		minhasParedes[3].retanguloCenario.setPosition(100, 150);
		minhasParedes[4].retanguloCenario.setPosition(0, 0);
		minhasParedes[5].retanguloCenario.setPosition(900, 0);

		minhasParedes[0].retanguloCenario.setSize(sf::Vector2f(800, 50));
		minhasParedes[4].retanguloCenario.setSize(sf::Vector2f(100, 800));
		minhasParedes[5].retanguloCenario.setSize(sf::Vector2f(200, 800));

		*inputParede = minhasParedes;

	}
}

void criarEscada(int inputNumeroFase, std::vector<Escada> *inputEscada) {
	if (inputNumeroFase == 1) {
		std::vector<Escada> minhasEscadas(12,
				Escada(75, 15, 0, 0, sf::Color(122, 77, 31),
						sf::Color(0, 0, 0)));

		minhasEscadas[0].retanguloCenario.setPosition(775, 715); // Primeiro andar 0, 1, 2 e 3
		minhasEscadas[1].retanguloCenario.setPosition(775,
				minhasEscadas[0].retanguloCenario.getPosition().y - 40);
		minhasEscadas[2].retanguloCenario.setPosition(775,
				minhasEscadas[1].retanguloCenario.getPosition().y - 40);
		minhasEscadas[3].retanguloCenario.setPosition(775,
				minhasEscadas[2].retanguloCenario.getPosition().y - 40); //	Primeiro andar
		minhasEscadas[4].retanguloCenario.setPosition(150,
				minhasEscadas[3].retanguloCenario.getPosition().y - 80); //  Segundo andar 4, 5, 6 e 7
		minhasEscadas[5].retanguloCenario.setPosition(150,
				minhasEscadas[4].retanguloCenario.getPosition().y - 40);
		minhasEscadas[6].retanguloCenario.setPosition(150,
				minhasEscadas[5].retanguloCenario.getPosition().y - 40);
		minhasEscadas[7].retanguloCenario.setPosition(150,
				minhasEscadas[6].retanguloCenario.getPosition().y - 40); // Segundo andar
		minhasEscadas[8].retanguloCenario.setPosition(775,
				minhasEscadas[7].retanguloCenario.getPosition().y - 80); // Terceiro andar 8, 9, 10 e 11
		minhasEscadas[9].retanguloCenario.setPosition(775,
				minhasEscadas[8].retanguloCenario.getPosition().y - 40);
		minhasEscadas[10].retanguloCenario.setPosition(775,
				minhasEscadas[9].retanguloCenario.getPosition().y - 40);
		minhasEscadas[11].retanguloCenario.setPosition(775,
				minhasEscadas[10].retanguloCenario.getPosition().y - 40); // Terceiro andar

		*inputEscada = minhasEscadas;

	}
}

void criarFruta(int inputNumeroFase, std::vector<Fruta> *inputFruta) {
	if (inputNumeroFase == 1) {
		std::vector<Fruta> minhasFrutas(3);

		minhasFrutas[0].frutaCorpo.setPosition(735, 465);
		minhasFrutas[1].frutaCorpo.setPosition(280, 400);
		minhasFrutas[2].frutaCorpo.setPosition(630, 220);

		*inputFruta = minhasFrutas;

	}
}

void criarArvore(int inputNumeroFase, std::vector<Arvore> *inputArvore) {
	if (inputNumeroFase == 1) {
		std::vector<Arvore> minhasArvores(3);

		minhasArvores[0].arvoreCorpo.setPosition(700, 470);
		minhasArvores[1].arvoreCorpo.setPosition(300, 470);
		minhasArvores[2].arvoreCorpo.setPosition(600, 270);

		*inputArvore = minhasArvores;
	}
}

void criarFlor(int inputNumeroFase, std::vector<Flor> *inputFlor) {
	if (inputNumeroFase == 1) {
		std::vector<Flor> minhasFlores(5);

		minhasFlores[0].florCorpo.setPosition(150, 710);
		minhasFlores[1].florCorpo.setPosition(300, 710);
		minhasFlores[2].florCorpo.setPosition(500, 510);
		minhasFlores[3].florCorpo.setPosition(300, 310);
		minhasFlores[4].florCorpo.setPosition(700, 110);

		*inputFlor = minhasFlores;
	}
}

void criarNuvem(int inputNumeroFase, std::vector<Nuvem> *inputNuvem) {
	if (inputNumeroFase == 1) {

		std::vector<Nuvem> minhasNuvens(5);

		minhasNuvens[0].nuvemCorpo.setPosition(150, 710);
		minhasNuvens[0].nuvemCorpo.setPosition(950 + (rand() % 10),
				rand() % 100);
		minhasNuvens[1].nuvemCorpo.setPosition(950 + (rand() % 10),
				rand() % 200 + 50);
		minhasNuvens[2].nuvemCorpo.setPosition((rand() % 100) + (rand() % 100),
				rand() % 200 + 50);
		minhasNuvens[3].nuvemCorpo.setPosition((rand() % 100) + (rand() % 100),
				rand() % 230 + 50);
		minhasNuvens[4].nuvemCorpo.setPosition((rand() % 100) + (rand() % 100),
				rand() % 400 + 50);

		*inputNuvem = minhasNuvens;
	}
}

void criarMapa(int inputNumeroFase, std::vector<Parede> *inputParede,
		std::vector<Escada> *inputEscada, std::vector<Fruta> *inputFruta,
		std::vector<Arvore> *inputArvore, std::vector<Flor> *inputFlor,
		std::vector<Nuvem> *inputNuvem, sf::RenderWindow *janela) {
	if (inputNumeroFase == 1) {
		criarParede(inputNumeroFase, inputParede);
		criarEscada(inputNumeroFase, inputEscada);
		criarFruta(inputNumeroFase, inputFruta);
		criarArvore(inputNumeroFase, inputArvore);
		criarFlor(inputNumeroFase, inputFlor);
		criarNuvem(inputNumeroFase, inputNuvem);

	}
}

void desenharMapa(int inputNumeroFase, std::vector<Parede> &inputParede,
		std::vector<Escada> &inputEscada, std::vector<Fruta> &inputFruta,
		std::vector<Arvore> &inputArvore, std::vector<Flor> &inputFlor,
		std::vector<Nuvem> &inputNuvem, sf::RenderWindow *janela) {
	if (inputNumeroFase == 1) {
		for (unsigned int i = 0; i < inputNuvem.size(); i++) {
			inputNuvem[i].nuvemCorpo.setTexture(inputNuvem[i].nuvemTextura);
			janela->draw(inputNuvem[i].nuvemCorpo);
		}
		for (unsigned int i = 0; i < inputArvore.size(); i++) {
			inputArvore[i].arvoreCorpo.setTexture(inputArvore[i].arvoreTextura);
			janela->draw(inputArvore[i].arvoreCorpo);
		}
		for (unsigned int i = 0; i < inputFruta.size(); i++) {
			inputFruta[i].frutaCorpo.setTexture(inputFruta[i].frutaTextura);
			janela->draw(inputFruta[i].frutaCorpo);
		}
		for (unsigned int i = 0; i < inputFlor.size(); i++) {
			inputFlor[i].florCorpo.setTexture(inputFlor[i].florTextura);
			janela->draw(inputFlor[i].florCorpo);
		}
		for (unsigned int i = 0; i < inputParede.size(); i++) {
			janela->draw(inputParede[i].retanguloCenario);
		}
		for (unsigned int i = 0; i < inputEscada.size(); i++) {
			janela->draw(inputEscada[i].retanguloCenario);
		}
	}
}

void checarColisaoFruta(Jogador *inputJogador, std::vector<Fruta> &inputFruta,
		Texto *inputTexto) {
	for (unsigned int i = 0; i < inputFruta.size(); i++) {
		if (inputJogador->jogadorCorpo.getGlobalBounds().intersects(
				inputFruta[i].frutaCorpo.getGlobalBounds())) {
			inputJogador->pontos += 100;
			inputFruta[i].frutaCorpo.setPosition(-50, -50);

			char textoContador[5];
			sprintf(textoContador, "Pontos:\t%d", inputJogador->pontos); // Código pego do ChuvaGame
			inputTexto->texto.setString(textoContador);
			std::cout << "Pontos: " << inputJogador->pontos << std::endl;
		}
	}
}

void moverNuvem(int inputNumeroFase, std::vector<Nuvem> &inputNuvem) {
	if (inputNumeroFase == 1) {
		for (unsigned int i = 0; i < inputNuvem.size(); i++) {
			inputNuvem[i].moverNuvem();
		}
	}

}

