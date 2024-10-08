#include "../Declaracao/Mapa.h"

void Mapa::criarParede(int inputNumeroFase, std::vector<Parede> *inputParede) { // Cria e posiciona objetos
	if (inputNumeroFase == 1) {
		std::vector<Parede> minhasParedes(13,
				Parede(800, 25, 0, 0, sf::Color(122, 77, 31),
						sf::Color(0, 0, 0)));

		minhasParedes[0].retanguloCenario.setFillColor(sf::Color(113, 175, 41));
		minhasParedes[0].retanguloCenario.setPosition(100, 750);
		minhasParedes[1].retanguloCenario.setPosition(100, 550);
		minhasParedes[2].retanguloCenario.setPosition(100, 350);
		minhasParedes[3].retanguloCenario.setPosition(100, 150);
		minhasParedes[4].retanguloCenario.setPosition(0, 0);
		minhasParedes[5].retanguloCenario.setPosition(900, 0);

		minhasParedes[6].retanguloCenario.setFillColor(sf::Color::Transparent);
		minhasParedes[6].retanguloCenario.setOutlineColor(
				sf::Color::Transparent);
		for (int i = 6; i < 13; i++) {
			minhasParedes[i].retanguloCenario =
					minhasParedes[6].retanguloCenario;
		}

		minhasParedes[6].retanguloCenario.setPosition(0, 615); // Hitbox das paredes do primeiro andar
		minhasParedes[7].retanguloCenario.setPosition(0, 415); // Hitbox das paredes do segundo andar
		minhasParedes[8].retanguloCenario.setPosition(0, 215); // Hitbox das paredes do terceiro andar
		minhasParedes[9].retanguloCenario.setPosition(0, 0); // Hitbox das paredes do quarto andar

		minhasParedes[10].retanguloCenario.setPosition(809, 560); // Hitboxes das escadas
		minhasParedes[11].retanguloCenario.setPosition(184, 360);
		minhasParedes[12].retanguloCenario.setPosition(809, 160);

		minhasParedes[0].retanguloCenario.setSize(sf::Vector2f(800, 50));
		minhasParedes[4].retanguloCenario.setSize(sf::Vector2f(100, 800));
		minhasParedes[5].retanguloCenario.setSize(sf::Vector2f(200, 800));

		minhasParedes[6].retanguloCenario.setSize(sf::Vector2f(1100, 130)); // Hitboxes das paredes
		minhasParedes[7].retanguloCenario.setSize(sf::Vector2f(1100, 130));
		minhasParedes[8].retanguloCenario.setSize(sf::Vector2f(1100, 130));
		minhasParedes[9].retanguloCenario.setSize(sf::Vector2f(1100, 130));

		minhasParedes[10].retanguloCenario.setSize(sf::Vector2f(10, 70)); // Hitboxes das escadas
		minhasParedes[11].retanguloCenario.setSize(sf::Vector2f(10, 70));
		minhasParedes[12].retanguloCenario.setSize(sf::Vector2f(10, 70));

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

		meuFilhote.filhoteCorpo.setPosition(800, 122);

		*inputFilhote = meuFilhote;
	}
}

void Mapa::criarSino(int inputNumeroFase, Sino *inputSino) {
	if (inputNumeroFase == 1) {
		Sino meuSino;

		meuSino.sinoCorpo.setPosition(550, 200);

		*inputSino = meuSino;
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
	Sino meuSino;
}

void Mapa::criarMapa(int inputNumeroFase,
		std::vector<Parede> *inputParede, // Chama as funões de que criam os objetos do mapa
		std::vector<Escada> *inputEscada, std::vector<Fruta> *inputFruta,
		std::vector<Arvore> *inputArvore, std::vector<Flor> *inputFlor,
		std::vector<Nuvem> *inputNuvem, Filhote *inputFilhote,
		NuvemInimiga *inputNuvemInimiga, Sino *inputSino,
		sf::RenderWindow *janela) {
	if (inputNumeroFase == 1) {
		criarParede(inputNumeroFase, inputParede);
		criarEscada(inputNumeroFase, inputEscada);
		criarFruta(inputNumeroFase, inputFruta);
		criarArvore(inputNumeroFase, inputArvore);
		criarFlor(inputNumeroFase, inputFlor);
		criarNuvem(inputNumeroFase, inputNuvem);
		criarNuvemInimiga(inputNumeroFase, inputNuvemInimiga);
		criarFilhote(inputNumeroFase, inputFilhote);
		criarSino(inputNumeroFase, inputSino);
	}

}

void Mapa::desenharMapa(int inputNumeroFase, std::vector<Parede> &inputParede,
		std::vector<Escada> &inputEscada, std::vector<Fruta> &inputFruta,
		std::vector<Arvore> &inputArvore, std::vector<Flor> &inputFlor,
		std::vector<Nuvem> &inputNuvem, Filhote *inputFilhote,
		NuvemInimiga *inputNuvemInimiga, Texto *inputTexto, Sino *inputSino,
		sf::RenderWindow *janela) {
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

		inputNuvemInimiga->nuvemTiro.setTexture(
				inputNuvemInimiga->nuvemTiroTextura);
		janela->draw(inputNuvemInimiga->nuvemTiro);
		inputNuvemInimiga->nuvemCorpo.setTexture(
				inputNuvemInimiga->nuvemTextura);
		janela->draw(inputNuvemInimiga->nuvemCorpo);
		janela->draw(inputNuvemInimiga->hitboxNuvemInimiga);

		janela->draw(inputTexto->retanguloCenario);
		janela->draw(inputTexto->texto);

		janela->draw(inputFilhote->filhoteCorpo);
		janela->draw(inputFilhote->filhoteHitbox);

		inputSino->sinoCorpo.setTexture(inputSino->sinoTextura);
		janela->draw(inputSino->sinoCorpo);
	}
}

void Mapa::checarColisaoFruta(Jogador *inputJogador,
		std::vector<Fruta> &inputFruta, Texto *inputTexto, Som *inputSom) {
	for (unsigned int i = 0; i < inputFruta.size(); i++) {
		if (inputJogador->corpoJogador.getGlobalBounds().intersects(
				inputFruta[i].frutaCorpo.getGlobalBounds())) {
			inputJogador->pontos +=
					inputFruta[i].valorPontos[inputFruta[i].numeroTextura];
			inputFruta[i].frutaCorpo.setPosition(-50, -50);

			inputSom->frutaSom.play();

			char textoContador[5];
			sprintf(textoContador, "Pontos:\t%d", inputJogador->pontos); // Código pego do ChuvaGame
			inputTexto->texto.setString(textoContador);
		}
	}
}

void Mapa::checarColisaoSino(Jogador *inputJogador, Sino *inputSino,
		std::vector<Fruta> &inputFruta, NuvemInimiga *inputNuvemInimiga,
		Som *inputSom) {
	if (inputJogador->hitboxJogador.getGlobalBounds().intersects(
			inputSino->sinoCorpo.getGlobalBounds())) {

		inputSom->sinoSom.play();
		for (unsigned int i = 0; i < inputFruta.size(); i++) {

			if (inputFruta[i].numeroTextura > 2) {
				inputSino->sinoCorpo.setPosition(-50, -50);
			}

			if (inputFruta[i].frutaCorpo.getPosition().x == -50) {
				switch (i) {

				case 0:

					inputFruta[i].frutaCorpo.setPosition(750, 515);

					if (inputFruta[i].numeroTextura == 0) {
						inputFruta[i].frutaTextura.loadFromFile(
								"assets/banana.png");
						inputFruta[i].frutaCorpo.setTexture(
								inputFruta[i].frutaTextura);
					} else if (inputFruta[i].numeroTextura == 1) {
						inputFruta[i].frutaTextura.loadFromFile(
								"assets/cereja.png");
						inputFruta[i].frutaCorpo.setTexture(
								inputFruta[i].frutaTextura);
					} else if (inputFruta[i].numeroTextura == 2) {
						inputFruta[i].frutaTextura.loadFromFile(
								"assets/abacaxi.png");
						inputFruta[i].frutaCorpo.setTexture(
								inputFruta[i].frutaTextura);
						inputFruta[i].frutaCorpo.setScale(0.04, 0.08);
					}

					inputFruta[i].numeroTextura++;
					break;

				case 1:

					inputFruta[i].frutaCorpo.setPosition(280, 420);

					if (inputFruta[i].numeroTextura == 0) {
						inputFruta[i].frutaTextura.loadFromFile(
								"assets/banana.png");
						inputFruta[i].frutaCorpo.setTexture(
								inputFruta[i].frutaTextura);
					} else if (inputFruta[i].numeroTextura == 1) {
						inputFruta[i].frutaTextura.loadFromFile(
								"assets/cereja.png");
						inputFruta[i].frutaCorpo.setTexture(
								inputFruta[i].frutaTextura);
					} else if (inputFruta[i].numeroTextura == 2) {
						inputFruta[i].frutaTextura.loadFromFile(
								"assets/abacaxi.png");
						inputFruta[i].frutaCorpo.setTexture(
								inputFruta[i].frutaTextura);
						inputFruta[i].frutaCorpo.setScale(0.04, 0.08);
					}

					inputFruta[i].numeroTextura++;
					break;

				case 2:

					inputFruta[i].frutaCorpo.setPosition(680, 270);

					if (inputFruta[i].numeroTextura == 0) {
						inputFruta[i].frutaTextura.loadFromFile(
								"assets/banana.png");
						inputFruta[i].frutaCorpo.setTexture(
								inputFruta[i].frutaTextura);
					} else if (inputFruta[i].numeroTextura == 1) {
						inputFruta[i].frutaTextura.loadFromFile(
								"assets/cereja.png");
						inputFruta[i].frutaCorpo.setTexture(
								inputFruta[i].frutaTextura);
					} else if (inputFruta[i].numeroTextura == 2) {
						inputFruta[i].frutaTextura.loadFromFile(
								"assets/abacaxi.png");
						inputFruta[i].frutaCorpo.setTexture(
								inputFruta[i].frutaTextura);
						inputFruta[i].frutaCorpo.setScale(0.04, 0.08);
					}

					inputFruta[i].numeroTextura++;
					break;

				}
			}
		}
	}
}

void Mapa::nivelDificuldade(Jogador *inputJogador,
		NuvemInimiga *inputNuvemInimiga, sf::Color *inputCor, Som *inputSom,
		std::vector<Nuvem> &inputNuvens, std::vector<Parede> &inputParedes,
		std::vector<Flor> &inputFlores, std::vector<Arvore> &inputArvores,
		Filhote *inputFilhote, std::vector<Escada> &inputEscadas,
		Sino *inputSino, Inimigo *inputInimigo) {
	if (inputJogador->pontos >= 300 and inputJogador->pontos < 900) {
		inputNuvemInimiga->tiroVelocidadeY = 60;
	} else if (inputJogador->pontos >= 900 and inputJogador->pontos < 2000) {
		inputNuvemInimiga->tiroVelocidadeY = 80;
		*inputCor = sf::Color(120, 2, 2);
		inputNuvemInimiga->nuvemTiro.setColor(sf::Color::Red);
		inputFilhote->filhoteCorpo.setColor(sf::Color::Red);
		inputJogador->corpoJogador.setColor(sf::Color::Red);
		inputNuvemInimiga->nuvemTiro.setScale(0.06, 0.06);
		if (inputSom->musicaPrincipalDificilOn == false) {
			inputSom->musicaPrincipalDificilOn = true;
		}
	} else if (inputJogador->pontos >= 2000 and inputJogador->pontos < 4000) {
		inputNuvemInimiga->tiroVelocidadeY = 90;
		inputInimigo->corpoInimigo.setColor(sf::Color::Black);
		inputInimigo->tiroInimigo.setColor(sf::Color::Black);
		inputNuvemInimiga->nuvemCorpo.setColor(sf::Color::Black);
		inputSino->sinoCorpo.setColor(sf::Color::Black);
		for (unsigned int i = 0; i < inputNuvens.size(); i++) {
			inputNuvens[i].nuvemCorpo.setColor(sf::Color::Black);
		}
		for (unsigned int i = 0; i < inputFlores.size(); i++) {
			inputFlores[i].florCorpo.setColor(sf::Color::Black);
		}
		for (unsigned int i = 0; i < inputArvores.size(); i++) {
			inputArvores[i].arvoreCorpo.setColor(sf::Color::Black);
		}
		for (unsigned int i = 0; i < inputEscadas.size(); i++) {
			inputEscadas[i].retanguloCenario.setFillColor(sf::Color::Black);
		}
		for (unsigned int i = 0; i < 6; i++) {
			inputParedes[i].retanguloCenario.setFillColor(sf::Color::Black);
		}
		inputNuvemInimiga->nuvemTiro.setScale(0.1, 0.1);
	} else if (inputJogador->pontos >= 4000) {
		inputSom->cenarioRaio = true;
		inputSom->gotaSom.setBuffer(inputSom->raioSomBuffer);
		inputNuvemInimiga->tiroVelocidadeY = 120;
		inputNuvemInimiga->nuvemTiroTextura.loadFromFile("assets/raio.png");
		inputNuvemInimiga->nuvemTiro.setTexture(
				inputNuvemInimiga->nuvemTiroTextura);
		inputNuvemInimiga->nuvemTiro.setColor(sf::Color::White);
		inputNuvemInimiga->nuvemTiro.setScale(0.1, 0.1);
	}
}

void Mapa::checarFimJogo(Jogador *inputJogador, Filhote *inputFilhote,
		int *inputFim, sf::RenderWindow *inputJanela) {
	if (inputJogador->hitboxJogador.getGlobalBounds().intersects(
			inputFilhote->filhoteHitbox.getGlobalBounds()) == true) {
		*inputFim = 1;
	}
	if (inputJogador->vidas <= 0) {
		*inputFim = 2;
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
		if ((inputFilhote->filhoteCorpo.getPosition().x <= 600)) {
			inputFilhote->velocidadeX *= -1;

		} else if (inputFilhote->filhoteCorpo.getPosition().x >= 850) {
			inputFilhote->velocidadeX *= -1;
		}

		if (inputFilhote->velocidadeX <= 0) {
			inputFilhote->filhoteCorpo.setTexture(
					inputFilhote->filhoteTexturaGirado);
		} else if (inputFilhote->velocidadeX >= 0) {
			inputFilhote->filhoteCorpo.setTexture(inputFilhote->filhoteTextura);
		}

		inputFilhote->filhoteHitbox.setPosition(
				inputFilhote->filhoteCorpo.getPosition().x,
				inputFilhote->filhoteCorpo.getPosition().y);
		inputFilhote->filhoteCorpo.setPosition(
				inputFilhote->filhoteCorpo.getPosition().x
						+ inputFilhote->velocidadeX * inputDeltaTime,
				inputFilhote->filhoteCorpo.getPosition().y);
	}
}

void Mapa::atualizaVisibilidadeHitbox(Jogador *inputJogador,
		std::vector<Parede> &inputParedes, NuvemInimiga *inputNuvemInimiga,
		Inimigo *inputInimigo, Filhote *inputFilhote) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F3)) {

		inputJogador->hitboxJogador.setFillColor(sf::Color::Green);
		inputJogador->hitboxSoco.setOutlineColor(sf::Color::Cyan);
		inputNuvemInimiga->hitboxNuvemInimiga.setOutlineColor(sf::Color::Red);
		inputFilhote->filhoteHitbox.setOutlineColor(sf::Color::Green);
		inputInimigo->hitboxInimigo.setFillColor(sf::Color::Red);
		inputInimigo->hitboxTiro.setOutlineColor(sf::Color::Red);
		inputParedes[6].retanguloCenario.setOutlineColor(sf::Color::Blue);
		inputParedes[7].retanguloCenario.setOutlineColor(sf::Color::Blue);
		inputParedes[8].retanguloCenario.setOutlineColor(sf::Color::Blue);
		inputParedes[9].retanguloCenario.setOutlineColor(sf::Color::Blue);
		inputParedes[10].retanguloCenario.setOutlineColor(sf::Color::Blue);
		inputParedes[11].retanguloCenario.setOutlineColor(sf::Color::Blue);
		inputParedes[12].retanguloCenario.setOutlineColor(sf::Color::Blue);
	} else {
		inputInimigo->hitboxTiro.setOutlineColor(sf::Color::Transparent);
		inputInimigo->hitboxInimigo.setFillColor(sf::Color::Transparent);
		inputJogador->hitboxJogador.setFillColor(sf::Color::Transparent);
		inputJogador->hitboxSoco.setOutlineColor(sf::Color::Transparent);
		inputNuvemInimiga->hitboxNuvemInimiga.setOutlineColor(
				sf::Color::Transparent);
		inputFilhote->filhoteHitbox.setOutlineColor(sf::Color::Transparent);
		inputParedes[6].retanguloCenario.setOutlineColor(
				sf::Color::Transparent);
		inputParedes[7].retanguloCenario.setOutlineColor(
				sf::Color::Transparent);
		inputParedes[8].retanguloCenario.setOutlineColor(
				sf::Color::Transparent);
		inputParedes[9].retanguloCenario.setOutlineColor(
				sf::Color::Transparent);
		inputParedes[10].retanguloCenario.setOutlineColor(
				sf::Color::Transparent);
		inputParedes[11].retanguloCenario.setOutlineColor(
				sf::Color::Transparent);
		inputParedes[12].retanguloCenario.setOutlineColor(
				sf::Color::Transparent);
	}
}

void Mapa::mapaUpdate(int inputNumeroFase, Jogador *inputJogador,
		std::vector<Fruta> &inputFrutas, Texto *inputTexto,
		Filhote *inputFilhote, std::vector<Nuvem> &inputNuvens,
		NuvemInimiga *inputNuvemInimiga, Sino *inputSino,
		std::vector<Parede> &inputParedes, Inimigo *inputInimigo,
		float inputTempo, int *inputTelaCodigo, sf::Color *inputCor,
		Som *inputSom, std::vector<Flor> &inputFlores,
		std::vector<Arvore> &inputArvores, std::vector<Escada> &inputEscadas,
		sf::RenderWindow *janela) {

	atualizaVisibilidadeHitbox(inputJogador, inputParedes, inputNuvemInimiga,
			inputInimigo, inputFilhote);
	nivelDificuldade(inputJogador, inputNuvemInimiga, inputCor, inputSom,
			inputNuvens, inputParedes, inputFlores, inputArvores, inputFilhote,
			inputEscadas, inputSino, inputInimigo);
	checarColisaoSino(inputJogador, inputSino, inputFrutas, inputNuvemInimiga,
			inputSom);
	checarColisaoFruta(inputJogador, inputFrutas, inputTexto, inputSom);
	moverFilhote(inputNumeroFase, inputFilhote, inputTempo);
	checarFimJogo(inputJogador, inputFilhote, inputTelaCodigo, janela);
	moverNuvem(1, inputNuvens, inputTempo);
	moverNuvemInimiga(1, inputNuvemInimiga, inputTempo);
	inputNuvemInimiga->nuvemAtacar(*inputJogador, inputTempo, inputSom, janela,
			inputNuvens, inputParedes, inputFlores, inputArvores, inputEscadas,
			inputSino, inputInimigo);
}
