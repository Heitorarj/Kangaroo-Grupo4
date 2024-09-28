#include "Cenario.h"

Parede::Parede(int inputLargura, int inputAltura, int inputPosicaoX,
		int inputPosicaoY, sf::Color inputCor, sf::Color inputCorBorda) {
	retanguloParede.setOutlineColor(inputCorBorda);
	retanguloParede.setOutlineThickness(5);
	retanguloParede.setFillColor(inputCor);
	retanguloParede.setSize(sf::Vector2f(inputLargura, inputAltura));
	retanguloParede.setPosition(inputPosicaoX, inputPosicaoY);
}

void Parede::criaParede(int inputNumeroFase, std::vector<Parede> *inputParede) {
	if (inputNumeroFase == 1) {
		std::vector<Parede> minhasParedes(6,
				Parede(800, 25, 0, 0, sf::Color(122, 77, 31),
						sf::Color(0, 0, 0)));

		minhasParedes[0].retanguloParede.setFillColor(sf::Color(113, 175, 41));
		minhasParedes[0].retanguloParede.setPosition(100, 750);
		minhasParedes[1].retanguloParede.setPosition(100, 550);
		minhasParedes[2].retanguloParede.setPosition(100, 350);
		minhasParedes[3].retanguloParede.setPosition(100, 150);
		minhasParedes[4].retanguloParede.setPosition(0, 0);
		minhasParedes[5].retanguloParede.setPosition(900, 0);

		minhasParedes[0].retanguloParede.setSize(sf::Vector2f(800, 50));
		minhasParedes[4].retanguloParede.setSize(sf::Vector2f(100, 800));
		minhasParedes[5].retanguloParede.setSize(sf::Vector2f(200, 800));

		*inputParede = minhasParedes;

	}
}

Escada::Escada(int inputLargura, int inputAltura, int inputPosicaoX,
		int inputPosicaoY, sf::Color inputCor, sf::Color inputCorBorda) {
	retanguloEscada.setOutlineColor(inputCorBorda);
	retanguloEscada.setOutlineThickness(5);
	retanguloEscada.setFillColor(inputCor);
	retanguloEscada.setSize(sf::Vector2f(inputLargura, inputAltura));
	retanguloEscada.setPosition(inputPosicaoX, inputPosicaoY);
}

void Escada::criaEscada(int inputNumeroFase, std::vector<Escada> *inputEscada) {
	if (inputNumeroFase == 1) {
		std::vector<Escada> minhasEscadas(12,
				Escada(75, 15, 0, 0, sf::Color(122, 77, 31),
						sf::Color(0, 0, 0)));

		minhasEscadas[0].retanguloEscada.setPosition(775, 715); // Primeiro andar 0, 1, 2 e 3
		minhasEscadas[1].retanguloEscada.setPosition(775,
				minhasEscadas[0].retanguloEscada.getPosition().y - 40);
		minhasEscadas[2].retanguloEscada.setPosition(775,
				minhasEscadas[1].retanguloEscada.getPosition().y - 40);
		minhasEscadas[3].retanguloEscada.setPosition(775,
				minhasEscadas[2].retanguloEscada.getPosition().y - 40); //	Primeiro andar
		minhasEscadas[4].retanguloEscada.setPosition(150,
				minhasEscadas[3].retanguloEscada.getPosition().y - 80); //  Segundo andar 4, 5, 6 e 7
		minhasEscadas[5].retanguloEscada.setPosition(150,
				minhasEscadas[4].retanguloEscada.getPosition().y - 40);
		minhasEscadas[6].retanguloEscada.setPosition(150,
				minhasEscadas[5].retanguloEscada.getPosition().y - 40);
		minhasEscadas[7].retanguloEscada.setPosition(150,
				minhasEscadas[6].retanguloEscada.getPosition().y - 40); // Segundo andar
		minhasEscadas[8].retanguloEscada.setPosition(775,
				minhasEscadas[7].retanguloEscada.getPosition().y - 80); // Terceiro andar 8, 9, 10 e 11
		minhasEscadas[9].retanguloEscada.setPosition(775,
				minhasEscadas[8].retanguloEscada.getPosition().y - 40);
		minhasEscadas[10].retanguloEscada.setPosition(775,
				minhasEscadas[9].retanguloEscada.getPosition().y - 40);
		minhasEscadas[11].retanguloEscada.setPosition(775,
				minhasEscadas[10].retanguloEscada.getPosition().y - 40); // Terceiro andar

		*inputEscada = minhasEscadas;

	}
}

Fruta::Fruta() {
	frutaTextura.loadFromFile("assets/fruta.png");
	frutaCorpo.setTexture(frutaTextura);
	frutaCorpo.setScale(0.04, 0.04);
	frutaCorpo.setOrigin(frutaCorpo.getLocalBounds().width / 2,
			frutaCorpo.getLocalBounds().height / 2);
}

void Fruta::criaFruta(int inputNumeroFase, std::vector<Fruta> *inputFruta) {
	if (inputNumeroFase == 1) {
		std::vector<Fruta> minhasFrutas(3);

		minhasFrutas[0].frutaCorpo.setPosition(750, 515);
		minhasFrutas[1].frutaCorpo.setPosition(280, 420);
		minhasFrutas[2].frutaCorpo.setPosition(680, 270);

		*inputFruta = minhasFrutas;

	}
}

Arvore::Arvore() {
	arvoreTextura.loadFromFile("assets/arvore.png");
	arvoreCorpo.setTexture(arvoreTextura);
	arvoreCorpo.setScale(4, 4);
	arvoreCorpo.setOrigin(arvoreCorpo.getLocalBounds().width / 2,
			arvoreCorpo.getLocalBounds().height / 2);
}

void Arvore::criaArvore(int inputNumeroFase, std::vector<Arvore> *inputArvore) {
	if (inputNumeroFase == 1) {
		std::vector<Arvore> minhasArvores(3);

		minhasArvores[0].arvoreCorpo.setPosition(700, 483);
		minhasArvores[1].arvoreCorpo.setPosition(600, 286);
		minhasArvores[2].arvoreCorpo.setPosition(150, 86);

		*inputArvore = minhasArvores;
	}
}

Flor::Flor() {
	florTextura.loadFromFile("assets/flor.png");
	florCorpo.setTexture(florTextura);
	florCorpo.setScale(3, 3);
	florCorpo.setOrigin(florCorpo.getLocalBounds().width / 2,
			florCorpo.getLocalBounds().height / 2);
}

void Flor::criaFlor(int inputNumeroFase, std::vector<Flor> *inputFlor) {
	if (inputNumeroFase == 1) {
		std::vector<Flor> minhasFlores(5);

		minhasFlores[0].florCorpo.setPosition(150, 722);
		minhasFlores[1].florCorpo.setPosition(300, 722);
		minhasFlores[2].florCorpo.setPosition(500, 522);
		minhasFlores[3].florCorpo.setPosition(300, 322);
		minhasFlores[4].florCorpo.setPosition(700, 122);

		*inputFlor = minhasFlores;
	}
}

Texto::Texto() {
	retanguloCenario.setFillColor(sf::Color::Black);
	retanguloCenario.setOutlineColor(sf::Color::Blue);
	retanguloCenario.setOutlineThickness(5);
	retanguloCenario.setSize(sf::Vector2f(200, 25));

	fonte.loadFromFile("assets/arial_narrow_7.ttf");
	sf::Text meuTexto("Pontos:\t", fonte, 24);
	texto = meuTexto;
	texto.setPosition(sf::Vector2f(400, 760));
	retanguloCenario.setPosition(395, 762);
}
//Consertar isso tambem
//void Cenario::criaMapa(int inputNumeroFase, std::vector<Parede> *inputParede,
//		std::vector<Escada> *inputEscada, std::vector<Fruta> *inputFruta,
//		std::vector<Arvore> *inputArvore, std::vector<Flor> *inputFlor,
//		sf::RenderWindow *janela) {
//	if (inputNumeroFase == 1) {
//		criaParede(inputNumeroFase, inputParede);
//		criaEscada(inputNumeroFase, inputEscada);
//		criaFruta(inputNumeroFase, inputFruta);
//		criaArvore(inputNumeroFase, inputArvore);
//		criaFlor(inputNumeroFase, inputFlor);
//	}
//}
//
//void Cenario::desenhaMapa(int inputNumeroFase, std::vector<Parede> &inputParede,
//		std::vector<Escada> &inputEscada, std::vector<Fruta> &inputFruta,
//		std::vector<Arvore> &inputArvore, std::vector<Flor> &inputFlor,
//		sf::RenderWindow *janela) {
//	if (inputNumeroFase == 1) {
//		for (unsigned int i = 0; i < inputArvore.size(); i++) {
//			inputArvore[i].arvoreCorpo.setTexture(inputArvore[i].arvoreTextura);
//			janela->draw(inputArvore[i].arvoreCorpo);
//		}
//		for (unsigned int i = 0; i < inputFruta.size(); i++) {
//			inputFruta[i].frutaCorpo.setTexture(inputFruta[i].frutaTextura);
//			janela->draw(inputFruta[i].frutaCorpo);
//		}
//		for (unsigned int i = 0; i < inputFlor.size(); i++) {
//			inputFlor[i].florCorpo.setTexture(inputFlor[i].florTextura);
//			janela->draw(inputFlor[i].florCorpo);
//		}
//		for (unsigned int i = 0; i < inputParede.size(); i++) {
//			janela->draw(inputParede[i].retanguloParede);
//		}
//		for (unsigned int i = 0; i < inputEscada.size(); i++) {
//			janela->draw(inputEscada[i].retanguloEscada);
//		}
//	}
//}
//
//Cenario::Cenario() {
//	std::vector<Parede> paredes;
//	std::vector<Escada> escadas;
//	std::vector<Fruta> frutas;
//	std::vector<Arvore> arvores;
//	std::vector<Flor> flores;
//
//	this->criaMapa(1, &paredes, &escadas, &frutas, &arvores, &flores, &target);
//}
