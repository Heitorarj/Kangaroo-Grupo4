#include "../Declaracao/Inimigo.h"
//Funcoes privadas
void Inimigo::inicializaVariaveisInimigo() {
	this->velocidadeVertical = 2.f;
	this->velocidadeHorizontal = 2.f;
	this->escalaInimigo = sf::Vector2f(0.15, 0.15);
	this->persegueJogadorX = 200.f;
	this->persegueJogadorY = 200.f;
	this->colidiuDireita = false;
	this->colidiuEsquerda = false;
	this->colidiuPlataforma = false;
	this->podeDescer = false;
}
void Inimigo::inicializaHitboxInimigo() {
	this->hitboxInimigo.setFillColor(sf::Color::Transparent);
	this->hitboxInimigo.setSize(sf::Vector2f(60.f, 100.f));
	this->hitboxInimigo.setPosition(sf::Vector2f(900.f, 50.f));
	this->hitboxTiro.setSize(sf::Vector2f(1100, 1));
	this->hitboxTiro.setPosition(2000, 2000);
	this->hitboxTiro.setFillColor(sf::Color::Transparent);
	this->hitboxTiro.setOutlineColor(sf::Color::Transparent);
	this->hitboxTiro.setOutlineThickness(5);
}
void Inimigo::inicializaTexturaInimigo() {
	this->texturaInimigo.loadFromFile("assets/macaco.png");
	this->corpoInimigo.setTexture(texturaInimigo);
	this->corpoInimigo.setScale(escalaInimigo);
	this->corpoInimigo.setPosition(hitboxInimigo.getPosition());
	this->texturaTiroInimigo.loadFromFile("assets/pedra.png");
	this->texturaInimigoPedraAlta.loadFromFile("assets/macacoPedra.png");
	this->texturaInimigoGirada.loadFromFile("assets/macacoGirado.png");
	this->tiroInimigo.setTexture(texturaTiroInimigo);
	this->tiroInimigo.setOrigin(tiroInimigo.getLocalBounds().width / 2,
			tiroInimigo.getLocalBounds().height / 2);
	this->tiroInimigo.setScale(0.015, 0.015);
}

//Construtores / Destrutores
Inimigo::Inimigo(Jogador &jogador) :
		jogador(jogador) {
	this->inicializaVariaveisInimigo();
	this->inicializaHitboxInimigo();
	this->inicializaTexturaInimigo();
}

Inimigo::~Inimigo() {
}

//Funcoes
sf::RectangleShape Inimigo::getHitboxInimigo() {
	return hitboxInimigo;
}

void Inimigo::atacarJogador(Jogador &inputJogador, Som *inputSom) {

	srand(time(NULL));

	if (!inputJogador.hitboxJogador.getGlobalBounds().intersects(
			hitboxTiro.getGlobalBounds())) {
		tipoTiro = rand() % 2;

		if (tipoTiro == 1) {
			tiroInimigo.setPosition(hitboxInimigo.getPosition().x + 30,
					hitboxInimigo.getPosition().y + 25);
		} else if (tipoTiro == 0) {
			tiroInimigo.setPosition(hitboxInimigo.getPosition().x + 30,
					hitboxInimigo.getPosition().y + 80);
		}
		hitboxTiro.setSize(sf::Vector2f(1100, 1));
		hitboxTiro.setPosition(hitboxInimigo.getPosition().x - 1100,
				hitboxInimigo.getPosition().y + 50);

		if (!colidiuEsquerda) {
			corpoInimigo.setTexture(texturaInimigo);
		} else if (colidiuEsquerda) {
			corpoInimigo.setTexture(texturaInimigoGirada);
		}

	} else {

		if (tiroInimigo.getPosition().x <= hitboxInimigo.getPosition().x) {
			inputSom->gotaSom.play();
		}

		if (tiroInimigo.getPosition().x <= -1000) {
			tiroInimigo.setPosition(hitboxInimigo.getPosition().x - 1100,
					hitboxInimigo.getPosition().y + 80);
			hitboxTiro.setSize(sf::Vector2f(1100, 1));
		} else {
			inputSom->danoSom.play();
			corpoInimigo.setTexture(texturaInimigoPedraAlta);
			tiroInimigo.rotate(45);
			hitboxTiro.setSize(sf::Vector2f(1100, 800));
			hitboxTiro.setPosition(0, 0);

			tiroInimigo.setPosition(tiroInimigo.getPosition().x - 10,
					tiroInimigo.getPosition().y);

			if (inputJogador.hitboxJogador.getGlobalBounds().intersects(
					tiroInimigo.getGlobalBounds())) {
				tipoTiro = rand() % 5;

				if (tipoTiro == 4) {
					inputSom->QOTASom.play();
				} else {
					inputSom->danoSom.play();
				}

				tiroInimigo.setPosition(sf::Vector2f(-10000, 0));
				inputJogador.atualizaVidas();

				if (inputJogador.godMode == false) {
					inputJogador.vidas--;
					inputJogador.hitboxJogador.setPosition(
							sf::Vector2f(200, 650));
				}
			}
		}
	}
}

void Inimigo::colisaoJogador(Jogador *inputJogador, Som *inputSom,
		Texto *inputTexto) {

	if ((inputJogador->jogadorSoco)
			and (inputJogador->hitboxSoco.getGlobalBounds().intersects(
					hitboxInimigo.getGlobalBounds()))) {
		hitboxInimigo.setPosition(sf::Vector2f(900.f, 50.f));
		inputJogador->pontos += 500;
		inputSom->danoSom.play();
		char textoContador[5];
		sprintf(textoContador, "Pontos:\t%d", inputJogador->pontos); // Código pego do ChuvaGame
		inputTexto->texto.setString(textoContador);
	} else if (inputJogador->hitboxJogador.getGlobalBounds().intersects(
			hitboxInimigo.getGlobalBounds())) {
		inputSom->danoSom.play();

		if (inputJogador->godMode == false) {
			inputJogador->vidas--;
			inputJogador->hitboxJogador.setPosition(sf::Vector2f(200, 650));
		}
	}
}

void Inimigo::movimentoInimigo() {
	if (colidiuPlataforma) {
		// Movimento horizontal
		if (!colidiuEsquerda && !colidiuDireita) {
			this->hitboxInimigo.move(-velocidadeHorizontal, 0.f);
		}
		if (colidiuEsquerda) {
			this->hitboxInimigo.move(velocidadeHorizontal, 0.f);
		}
		if (colidiuDireita) {
			this->hitboxInimigo.setPosition(hitboxInimigo.getPosition().x,
					hitboxInimigo.getPosition().y + 200.f);
			colidiuDireita = false;
		}

	}
	this->corpoInimigo.setPosition(hitboxInimigo.getPosition().x,
			hitboxInimigo.getPosition().y + 30);
}

void Inimigo::atualizaColisaoPlataforma(std::vector<Parede> &inputParedes) {
	if (hitboxInimigo.getGlobalBounds().intersects(
			inputParedes[6].retanguloCenario.getGlobalBounds())) {
		this->colidiuPlataforma = true;
	}
	if (hitboxInimigo.getGlobalBounds().intersects(
			inputParedes[7].retanguloCenario.getGlobalBounds())) {
		this->colidiuPlataforma = true;
	}
	if (hitboxInimigo.getGlobalBounds().intersects(
			inputParedes[8].retanguloCenario.getGlobalBounds())) {
		this->colidiuPlataforma = true;
	}
	if (hitboxInimigo.getGlobalBounds().intersects(
			inputParedes[9].retanguloCenario.getGlobalBounds())) {
		this->colidiuPlataforma = true;
	}

}

void Inimigo::atualizaColisaoBorda(const sf::RenderTarget *target) {
	// Verifica se o inimigo ultrapassou o limite esquerdo da tela
	if (this->hitboxInimigo.getGlobalBounds().left <= 0.f) {
		// Se a hitbox passou da borda esquerda, reposiciona na posição zero no eixo X
		this->hitboxInimigo.setPosition(0.f,
				this->hitboxInimigo.getGlobalBounds().top);
		this->colidiuEsquerda = true;
		this->colidiuDireita = false;

	}
	// Verifica se o inimigo ultrapassou o limite direito da tela
	else if (this->hitboxInimigo.getGlobalBounds().left
			+ this->hitboxInimigo.getGlobalBounds().width
			>= target->getSize().x) {
		// Se a hitbox passou da borda direita, reposiciona para o máximo permitido no eixo X
		this->hitboxInimigo.setPosition(
				target->getSize().x
						- this->hitboxInimigo.getGlobalBounds().width - 10,
				this->hitboxInimigo.getGlobalBounds().top);
		this->colidiuDireita = true;
		this->colidiuEsquerda = false;
	}

	// Verifica se o inimigo ultrapassou o limite superior da tela
	if (this->hitboxInimigo.getGlobalBounds().top <= 0.f) {
		// Se a hitbox passou da borda superior, reposiciona na posição zero no eixo Y
		this->hitboxInimigo.setPosition(
				this->hitboxInimigo.getGlobalBounds().left, 0.f);
	}
	// Verifica se o inimigo ultrapassou o limite inferior da tela
	else if (this->hitboxInimigo.getGlobalBounds().top
			+ this->hitboxInimigo.getGlobalBounds().height
			>= target->getSize().y) {
		// Se a hitbox passou da borda inferior, reposiciona para o máximo permitido no eixo Y
		this->hitboxInimigo.setPosition(sf::Vector2f(900.f, 50.f));
	}
}

void Inimigo::atualizaInimigo(const sf::RenderTarget *target,
		std::vector<Parede> &inputParedes, Jogador *inputJogador, Som *inputSom,
		Texto *inputTexto) {
	this->atualizaColisaoBorda(target);
	this->atualizaColisaoPlataforma(inputParedes);
	this->movimentoInimigo();
	this->colisaoJogador(inputJogador, inputSom, inputTexto);
	this->atacarJogador(*inputJogador, inputSom);
}

void Inimigo::desenhaInimigo(sf::RenderTarget *target) {
	target->draw(this->hitboxInimigo);
	target->draw(this->corpoInimigo);
	target->draw(this->hitboxTiro);
	target->draw(this->tiroInimigo);
}

NuvemInimiga::NuvemInimiga() {
	nuvemTextura.loadFromFile("assets/nuvembrava.png");
	nuvemCorpo.setTexture(nuvemTextura);
	nuvemCorpo.setScale(0.2, 0.2);
	nuvemCorpo.setOrigin(nuvemCorpo.getLocalBounds().width / 2,
			nuvemCorpo.getLocalBounds().height / 2);
	nuvemTiroTextura.loadFromFile("assets/gota.png");
	nuvemTiro.setTexture(nuvemTiroTextura);
	nuvemTiro.setScale(0.05, 0.05);
	nuvemTiro.setOrigin(nuvemTiro.getLocalBounds().width / 2,
			nuvemTiro.getLocalBounds().height / 2);
	hitboxNuvemInimiga.setFillColor(sf::Color::Transparent);
	hitboxNuvemInimiga.setOutlineColor(sf::Color::Transparent);
	hitboxNuvemInimiga.setOutlineThickness(5);
	hitboxNuvemInimiga.setOrigin(hitboxNuvemInimiga.getLocalBounds().width / 2,
			hitboxNuvemInimiga.getLocalBounds().height / 2);
	hitboxNuvemInimiga.setSize(sf::Vector2f(100, 800));
	tiroVelocidadeY = 50;
	velocidadeX = 15;
}

void NuvemInimiga::nuvemAtacar(Jogador &inputJogador, float inputDeltaTime,
		Som *inputSom, sf::RenderWindow *inputJanela,
		std::vector<Nuvem> &inputNuvens, std::vector<Parede> &inputParedes,
		std::vector<Flor> &inputFlores, std::vector<Arvore> &inputArvores,
		std::vector<Escada> &inputEscadas, Sino *inputSino,
		Inimigo *inputInimigo) {

	if (!inputJogador.hitboxJogador.getGlobalBounds().intersects(
			hitboxNuvemInimiga.getGlobalBounds())) {
		nuvemTiro.setPosition(nuvemCorpo.getPosition());
		hitboxNuvemInimiga.setSize(sf::Vector2f(100, 800));
		hitboxNuvemInimiga.setPosition(nuvemCorpo.getPosition().x - 50,
				nuvemCorpo.getPosition().y);

		if (inputSom->musicaPrincipalDificilOnCerteza == true) {
			inputSino->sinoCorpo.setColor(sf::Color::Black);
			nuvemCorpo.setColor(sf::Color::Black);
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
			inputInimigo->corpoInimigo.setColor(sf::Color::Black);
			inputInimigo->tiroInimigo.setColor(sf::Color::Black);
		}

	} else {
		if (nuvemTiro.getPosition().y <= 100) {
			inputSom->gotaSom.play();
		} else if (inputSom->musicaPrincipalDificilOnCerteza) {
			inputSom->gotaSom.play();
		}

		if (nuvemTiro.getPosition().y > 1000) {
			nuvemTiro.setPosition(nuvemTiro.getPosition().x,
					nuvemTiro.getPosition().y - 1000);
			nuvemTiro.setPosition(nuvemCorpo.getPosition());
			hitboxNuvemInimiga.setSize(sf::Vector2f(100, 800));

		} else {

			if ((inputSom->musicaPrincipalDificilOnCerteza == true)
					and (inputSom->cenarioRaio)) {
				inputSino->sinoCorpo.setColor(sf::Color::White);
				nuvemCorpo.setColor(sf::Color::White);
				for (unsigned int i = 0; i < inputNuvens.size(); i++) {
					inputNuvens[i].nuvemCorpo.setColor(sf::Color::White);
				}
				for (unsigned int i = 0; i < inputFlores.size(); i++) {
					inputFlores[i].florCorpo.setColor(sf::Color::White);
				}
				for (unsigned int i = 0; i < inputArvores.size(); i++) {
					inputArvores[i].arvoreCorpo.setColor(sf::Color::White);
				}
				for (unsigned int i = 0; i < inputEscadas.size(); i++) {
					inputEscadas[i].retanguloCenario.setFillColor(
							sf::Color(122, 77, 31));
				}
				for (unsigned int i = 0; i < 6; i++) {
					if (i == 0) {
						inputParedes[i].retanguloCenario.setFillColor(
								sf::Color(113, 175, 41));
					} else {
						inputParedes[i].retanguloCenario.setFillColor(
								sf::Color(122, 77, 31));
					}
				}
				inputInimigo->corpoInimigo.setColor(sf::Color::White);
				inputInimigo->tiroInimigo.setColor(sf::Color::White);
			}

			hitboxNuvemInimiga.setSize(sf::Vector2f(1000, 800));
			hitboxNuvemInimiga.setPosition(
					inputJogador.hitboxJogador.getPosition().x - 500,
					inputJogador.hitboxJogador.getPosition().y - 500);

			nuvemTiro.setPosition(nuvemTiro.getPosition().x,
					nuvemTiro.getPosition().y
							+ tiroVelocidadeY * inputDeltaTime);

			if (inputJogador.hitboxJogador.getGlobalBounds().intersects(
					nuvemTiro.getGlobalBounds())) {
				inputSom->danoSom.play();
				nuvemTiro.setPosition(sf::Vector2f(1000, 1000));
				inputJogador.atualizaVidas();

				if (inputJogador.godMode == false) {
					inputJogador.vidas--;
					inputJogador.hitboxJogador.setPosition(
							sf::Vector2f(200, 650));
				}
			}
		}
	}
}
