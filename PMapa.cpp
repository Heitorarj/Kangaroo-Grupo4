
#include "PMapa.h"
#include "PJogador.h"

Parede::Parede(int inputLargura, int inputAltura, int inputPosicaoX,
		int inputPosicaoY, sf::Color inputCor, sf::Color inputCorBorda) {

	retanguloCenario.setOutlineColor(inputCorBorda);
	retanguloCenario.setOutlineThickness(5);
	retanguloCenario.setFillColor(inputCor);
	retanguloCenario.setSize(sf::Vector2f(inputLargura, inputAltura));
	retanguloCenario.setPosition(inputPosicaoX, inputPosicaoY);
}

Escada::Escada(int inputLargura, int inputAltura, int inputPosicaoX,
		int inputPosicaoY, sf::Color inputCor, sf::Color inputCorBorda) {

	retanguloCenario.setOutlineColor(inputCorBorda);
	retanguloCenario.setOutlineThickness(5);
	retanguloCenario.setFillColor(inputCor);
	retanguloCenario.setSize(sf::Vector2f(inputLargura, inputAltura));
	retanguloCenario.setPosition(inputPosicaoX, inputPosicaoY);
}

Fruta::Fruta() {
	frutaTextura.loadFromFile("assets/fruta.png");
	frutaCorpo.setTexture(frutaTextura);
	frutaCorpo.setScale(0.04, 0.04);
	frutaCorpo.setOrigin(frutaCorpo.getLocalBounds().width / 2,
			frutaCorpo.getLocalBounds().height / 2);
}

Arvore::Arvore() {
	arvoreTextura.loadFromFile("assets/arvore.png");
	arvoreCorpo.setTexture(arvoreTextura);
	arvoreCorpo.setScale(4, 4);
	arvoreCorpo.setOrigin(arvoreCorpo.getLocalBounds().width / 2,
			arvoreCorpo.getLocalBounds().height / 2);
}

Flor::Flor() {
	florTextura.loadFromFile("assets/flor.png");
	florCorpo.setTexture(florTextura);
	florCorpo.setScale(3, 3);
	florCorpo.setOrigin(florCorpo.getLocalBounds().width / 2,
			florCorpo.getLocalBounds().height / 2);
}
Nuvem::Nuvem() {

	nuvemTextura.loadFromFile("assets/nuvem.png");
	nuvemCorpo.setTexture(nuvemTextura);
	nuvemCorpo.setScale(5, 5);
	nuvemCorpo.setOrigin(nuvemCorpo.getLocalBounds().width / 2,
			nuvemCorpo.getLocalBounds().height / 2);
	velocidadeX = 3;
}

Filhote::Filhote() {
	filhoteTextura.loadFromFile("assets/kangaroo.png");
	filhoteCorpo.setTexture(filhoteTextura);
	filhoteCorpo.setOrigin(filhoteCorpo.getLocalBounds().width / 2,
			filhoteCorpo.getLocalBounds().height / 2);
	filhoteCorpo.setScale(0.05, 0.05);
	filhoteHitbox.setSize(
			sf::Vector2f(filhoteCorpo.getLocalBounds().width / 20,
					filhoteCorpo.getLocalBounds().height / 20));
	filhoteHitbox.setOrigin(filhoteHitbox.getLocalBounds().width / 2,
			filhoteHitbox.getLocalBounds().height / 2);
	filhoteHitbox.setFillColor(sf::Color::Transparent);
	filhoteHitbox.setOutlineColor(sf::Color::Green);
	filhoteHitbox.setOutlineThickness(5);
	velocidadeX = 2;
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

void Mapa::criarParede(int inputNumeroFase, std::vector<Parede> *inputParede) { // Cria e posiciona objetos
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

void Mapa::criarEscada(int inputNumeroFase, std::vector<Escada> *inputEscada) {
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

void Mapa::criarFruta(int inputNumeroFase, std::vector<Fruta> *inputFruta) {
	if (inputNumeroFase == 1) {
		std::vector<Fruta> minhasFrutas(3);

		minhasFrutas[0].frutaCorpo.setPosition(750, 515);
		minhasFrutas[1].frutaCorpo.setPosition(280, 420);
		minhasFrutas[2].frutaCorpo.setPosition(680, 270);

		*inputFruta = minhasFrutas;

	}
}

void Mapa::criarArvore(int inputNumeroFase, std::vector<Arvore> *inputArvore) {
	if (inputNumeroFase == 1) {
		std::vector<Arvore> minhasArvores(3);

		minhasArvores[0].arvoreCorpo.setPosition(700, 483);
		minhasArvores[1].arvoreCorpo.setPosition(600, 286);
		minhasArvores[2].arvoreCorpo.setPosition(150, 86);

		*inputArvore = minhasArvores;
	}
}

void Mapa::criarFlor(int inputNumeroFase, std::vector<Flor> *inputFlor) {
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

void Mapa::criarNuvem(int inputNumeroFase, std::vector<Nuvem> *inputNuvem) {
	if (inputNumeroFase == 1) {

		std::vector<Nuvem> minhasNuvens(4);

		minhasNuvens[0].nuvemCorpo.setPosition(950 + (rand() % 10),
				rand() % 100);
		minhasNuvens[1].nuvemCorpo.setPosition(950 + (rand() % 10),
				rand() % 200 + 50);
		minhasNuvens[2].nuvemCorpo.setPosition((rand() % 100) + (rand() % 100),
				rand() % 200 + 50);
		minhasNuvens[3].nuvemCorpo.setPosition((rand() % 100) + (rand() % 100),
				rand() % 400 + 50);

		*inputNuvem = minhasNuvens;
	}
}

void Mapa::criarNuvemInimiga(int inputNumeroFase,
		NuvemInimiga *inputNuvemInimiga) {
	if (inputNumeroFase == 1) {

		NuvemInimiga minhaNuvemInimiga;

		minhaNuvemInimiga.nuvemCorpo.setPosition(150, 50);
		minhaNuvemInimiga.nuvemTiro.setPosition(-100, -100);
		*inputNuvemInimiga = minhaNuvemInimiga;
	}
}

void Mapa::criarFilhote(int inputNumeroFase, Filhote *inputFilhote) {
	if (inputNumeroFase == 1) {
		Filhote meuFilhote;

		meuFilhote.filhoteCorpo.setPosition(800, 120);

		*inputFilhote = meuFilhote;
	}
}

Mapa::Mapa() {
	std::vector<Parede> minhasParedes;
	std::vector<Escada> minhasEscadas;
	std::vector<Fruta> minhasFrutas;
	std::vector<Arvore> minhasArvores;
	std::vector<Flor> minhasFlores;
	std::vector<Nuvem> minhasNuvens;
	NuvemInimiga minhaNuvemInimiga;
	Filhote meuFilhote;
	Jogador meuJogador;
	Texto meuTexto;
}

void Mapa::criarMapa(int inputNumeroFase,
		std::vector<Parede> *inputParede, // Chama as funões de que criam os objetos do mapa
		std::vector<Escada> *inputEscada, std::vector<Fruta> *inputFruta,
		std::vector<Arvore> *inputArvore, std::vector<Flor> *inputFlor,
		std::vector<Nuvem> *inputNuvem, Filhote *inputFilhote,
		NuvemInimiga *inputNuvemInimiga, sf::RenderWindow *janela) {
	if (inputNumeroFase == 1) {
		criarParede(inputNumeroFase, inputParede);
		criarEscada(inputNumeroFase, inputEscada);
		criarFruta(inputNumeroFase, inputFruta);
		criarArvore(inputNumeroFase, inputArvore);
		criarFlor(inputNumeroFase, inputFlor);
		criarNuvem(inputNumeroFase, inputNuvem);
		criarNuvemInimiga(inputNumeroFase, inputNuvemInimiga);
		criarFilhote(inputNumeroFase, inputFilhote);
	}

}

void Mapa::desenharMapa(int inputNumeroFase, std::vector<Parede> &inputParede,
		std::vector<Escada> &inputEscada, std::vector<Fruta> &inputFruta,
		std::vector<Arvore> &inputArvore, std::vector<Flor> &inputFlor,
		std::vector<Nuvem> &inputNuvem, Filhote *inputFilhote,
		NuvemInimiga *inputNuvemInimiga, Texto *inputTexto,
		sf::RenderWindow *janela) {
	if (inputNumeroFase == 1) {

		for (unsigned int i = 0; i < inputNuvem.size(); i++) {
			inputNuvem[i].nuvemCorpo.setTexture(inputNuvem[i].nuvemTextura);
			janela->draw(inputNuvem[i].nuvemCorpo);
		}

		inputNuvemInimiga->nuvemTiro.setTexture(
				inputNuvemInimiga->nuvemTiroTextura);
		janela->draw(inputNuvemInimiga->nuvemTiro);
		inputNuvemInimiga->nuvemCorpo.setTexture(
				inputNuvemInimiga->nuvemTextura);
		janela->draw(inputNuvemInimiga->nuvemCorpo);
		janela->draw(inputNuvemInimiga->hitboxNuvemInimiga);

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
		janela->draw(inputTexto->retanguloCenario);
		janela->draw(inputTexto->texto);

		inputFilhote->filhoteCorpo.setTexture(inputFilhote->filhoteTextura);
		janela->draw(inputFilhote->filhoteCorpo);
		janela->draw(inputFilhote->filhoteHitbox);
	}
}

void Mapa::checarColisaoFruta(Jogador *inputJogador,
		std::vector<Fruta> &inputFruta, Texto *inputTexto) {
	for (unsigned int i = 0; i < inputFruta.size(); i++) {
		if (inputJogador->corpoJogador.getGlobalBounds().intersects(
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

void Mapa::checarFimJogo(Jogador *inputJogador, Filhote *inputFilhote,
		sf::RenderWindow *inputJanela) {
	if (inputJogador->hitboxJogador.getGlobalBounds().intersects(
			inputFilhote->filhoteHitbox.getGlobalBounds()) == true) {
		inputJanela->close();
	}
}

void Mapa::moverNuvem(int inputNumeroFase, std::vector<Nuvem> &inputNuvem,
		float inputDeltaTime) {
	if (inputNumeroFase == 1) {
		for (unsigned int i = 0; i < inputNuvem.size(); i++) {
			if ((inputNuvem[i].nuvemCorpo.getPosition().x <= 0)
					or (inputNuvem[i].nuvemCorpo.getPosition().x >= 1000)) {
				inputNuvem[i].nuvemCorpo.setPosition(
						inputNuvem[i].nuvemCorpo.getPosition().x, rand() % 500);
				inputNuvem[i].velocidadeX *= -1;
			}
			inputNuvem[i].nuvemCorpo.setPosition(
					inputNuvem[i].nuvemCorpo.getPosition().x
							+ inputNuvem[i].velocidadeX * inputDeltaTime,
					inputNuvem[i].nuvemCorpo.getPosition().y);
		}
	}
}

void Mapa::moverNuvemInimiga(int inputNumeroFase,
		NuvemInimiga *inputNuvemInimiga, float inputDeltaTime) {
	if (inputNumeroFase == 1) {
		if ((inputNuvemInimiga->nuvemCorpo.getPosition().x <= 140)
				or (inputNuvemInimiga->nuvemCorpo.getPosition().x >= 850)) {
			inputNuvemInimiga->velocidadeX *= -1;
		}
		inputNuvemInimiga->nuvemCorpo.setPosition(
				inputNuvemInimiga->nuvemCorpo.getPosition().x
						+ inputNuvemInimiga->velocidadeX * inputDeltaTime,
				inputNuvemInimiga->nuvemCorpo.getPosition().y);

	}

}

void Mapa::moverFilhote(int inputNumeroFase, Filhote *inputFilhote,
		float inputDeltaTime) {
	if (inputNumeroFase == 1) {
		if ((inputFilhote->filhoteCorpo.getPosition().x <= 600)
				or (inputFilhote->filhoteCorpo.getPosition().x >= 850)) {
			inputFilhote->velocidadeX *= -1;
		}
		inputFilhote->filhoteHitbox.setPosition(
				inputFilhote->filhoteCorpo.getPosition().x,
				inputFilhote->filhoteCorpo.getPosition().y);
		inputFilhote->filhoteCorpo.setPosition(
				inputFilhote->filhoteCorpo.getPosition().x
						+ inputFilhote->velocidadeX,
				inputFilhote->filhoteCorpo.getPosition().y);
	}
}

void Mapa::mapaUpdate(int inputNumeroFase, Jogador *inputJogador,
		std::vector<Fruta> &inputFrutas, Texto *inputTexto,
		Filhote *inputFilhote, std::vector<Nuvem> &inputNuvens,
		NuvemInimiga *inputNuvemInimiga, float inputTempo,
		sf::RenderWindow *janela) {

	checarColisaoFruta(inputJogador, inputFrutas, inputTexto);
	moverFilhote(inputNumeroFase, inputFilhote, inputTempo);
	checarFimJogo(inputJogador, inputFilhote, janela);
	moverNuvem(1, inputNuvens, inputTempo);
	moverNuvemInimiga(1, inputNuvemInimiga, inputTempo);
	inputNuvemInimiga->nuvemAtacar(*inputJogador, inputTempo, janela);

}
