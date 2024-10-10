#include "../Declaracao/Jogador.h"

void Jogador::inicializaVariaveisJogador() {
	this->velocidadeMovimento = 3.f;
	this->velocidadePulo = 10.f;
	this->gravidade = 0.5f;
	this->velocidadeVertical = 0.f;
	this->escalaJogador = sf::Vector2f(0.1, 0.1);
	pontos = 0;
	vidas = 3;
	jogadorGiradoEsquerda = false;
	jogadorColideEscada = false;
	jogadorAgachado = false;
	jogadorSoco = false;
	jogadorPulo = false;
	jogadorAndando = false;
	noChao = false;
	godMode = false;
}

void Jogador::inicializaHitboxJogador() {
	this->hitboxJogador.setFillColor(sf::Color::Transparent);
	this->hitboxJogador.setSize(sf::Vector2f(60.f, 90.f));
	this->hitboxSoco.setSize(sf::Vector2f(30, 30));
	this->hitboxSoco.setFillColor(sf::Color::Transparent);
	this->hitboxSoco.setOutlineColor(sf::Color::Transparent);
	this->hitboxSoco.setOutlineThickness(5);
	this->hitboxSoco.setPosition(-50, -50);
}

void Jogador::inicializaTexturaJogador() {
	this->texturaJogador.loadFromFile("assets/kangaroo.png");
	this->texturaJogadorAgachado.loadFromFile("assets/kangarooAgachado.png");
	this->texturaJogadorEscada.loadFromFile("assets/kangarooEscada.png");
	this->texturaJogadorGirado.loadFromFile("assets/kangarooGirado.png");
	this->texturaJogadorAgachadoGirado.loadFromFile(
			"assets/kangarooAgachadoGirado.png");
	this->texturaJogadorSoco.loadFromFile("assets/kangarooSoco.png");
	this->texturaJogadorSocoGirado.loadFromFile(
			"assets/kangarooSocoGirado.png");
	this->texturaJogadorPulo.loadFromFile("assets/kangarooPulando.png");
	this->texturaJogadorPuloGirado.loadFromFile(
			"assets/kangarooPulandoGirado.png");
	this->corpoJogador.setOrigin(corpoJogador.getLocalBounds().width / 2,
			corpoJogador.getLocalBounds().height / 2);
	this->corpoJogador.setTexture(texturaJogador);
	this->corpoJogador.setScale(escalaJogador);
	this->corpoJogador.setPosition(hitboxJogador.getPosition());
	vidaTextura.loadFromFile("assets/coracao.png");
	for (int i = 0; i < 3; i++) {
		vida[i].setScale(0.03, 0.03);
		vida[i].setTexture(vidaTextura);
	}
}

void Jogador::inicializaVidas() {
	vida[0].setPosition(220, 765);
	vida[1].setPosition(245, 765);
	vida[2].setPosition(270, 765);
	fonteTexto.loadFromFile("assets/arial_narrow_7.ttf");
	sf::Text meuTexto("Vidas:\t", fonteTexto, 24);
	vidasTexto = meuTexto;
	vidasTexto.setPosition(sf::Vector2f(155, 760));

	vidasMoldura.setSize(sf::Vector2f(150, 25));
	vidasMoldura.setOutlineThickness(5);
	vidasMoldura.setFillColor(sf::Color::Black);
	vidasMoldura.setOutlineColor(sf::Color::Blue);
	vidasMoldura.setPosition(sf::Vector2f(150, 762));
}

Jogador::Jogador(float x, float y) {
	this->hitboxJogador.setPosition(x, y);

	this->inicializaVariaveisJogador();
	this->inicializaHitboxJogador();
	this->inicializaTexturaJogador();
	this->inicializaVidas();
}

Jogador::~Jogador() {

}

sf::RectangleShape Jogador::getHitboxJogador() {
	return hitboxJogador;
}

void Jogador::atualizaVidas() {
	if (vidas == 2) {
		vida[2].setPosition(-50, -50);
	} else if (vidas == 1) {
		vida[1].setPosition(-50, -50);
	}
}

void Jogador::atualizaInput(float meuTempo) {
	// Movimentação para cima quando estiver em uma escada
	if (jogadorColideEscada) {
		noChao = true;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			this->hitboxJogador.setPosition(
					hitboxJogador.getPosition().x + velocidadeMovimento,
					hitboxJogador.getPosition().y);
		} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			this->hitboxJogador.setPosition(
					hitboxJogador.getPosition().x - velocidadeMovimento,
					hitboxJogador.getPosition().y);
		} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			this->hitboxJogador.move(0.f, -this->velocidadeMovimento * 2); // Sobe escada
		} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			this->hitboxJogador.move(0.f, this->velocidadeMovimento); // Desce escada
		}
	}
	// Aplicar gravidade
	if (!noChao) {
		this->velocidadeVertical += gravidade; // Aumenta a velocidade vertical com a gravidade
		this->hitboxJogador.move(0.f, this->velocidadeVertical); // Aplica a velocidade vertical ao jogador
	}

	// Tecla para pular
	if (noChao) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			this->velocidadeVertical = -this->velocidadePulo; // Aplica força para o pulo
			jogadorPulo = true;
			noChao = false; // O jogador não está mais no chão
		} else {
			jogadorPulo = false;
		}
	}

	// Movimento para a esquerda
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		this->hitboxJogador.move(-this->velocidadeMovimento, 0.f);
		jogadorGiradoEsquerda = true;
		jogadorAndando = true;
	} else {
		jogadorAndando = false;
	}

	// Movimento para a direitaF
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		this->hitboxJogador.move(this->velocidadeMovimento, 0.f);
		jogadorGiradoEsquerda = false;
		jogadorAndando = true;
	} else {
		jogadorAndando = false;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)
			and (jogadorSoco == true)) {
		jogadorAgachado = false;
		this->hitboxJogador.setSize(sf::Vector2f(60.f, 100.f));

	} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		this->hitboxJogador.move(0.f, this->velocidadeMovimento);
		this->hitboxJogador.setSize(sf::Vector2f(60.f, 60.f));
		jogadorAgachado = true;
	} else {
		jogadorAgachado = false;
		this->hitboxJogador.setSize(sf::Vector2f(60.f, 100.f));
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)
			and (jogadorGiradoEsquerda == true)
			and ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left) == false))
			and ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right) == false))
			and ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up) == false))) {
		jogadorSoco = true;
		hitboxSoco.setPosition(hitboxJogador.getPosition().x - 33,
				hitboxJogador.getPosition().y + 40);
	} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)
			and ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left) == false))
			and ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right) == false))
			and ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up) == false))) {
		jogadorSoco = true;
		hitboxSoco.setPosition(hitboxJogador.getPosition().x + 60,
				hitboxJogador.getPosition().y + 40);
	} else {
		jogadorSoco = false;
		hitboxSoco.setPosition(-50, -50);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F1)) {
		corpoJogador.rotate(45); // Transforma o kanguru em um sharingan, apenas um easter egg engraçadinho
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F2)) {

		if (godMode == false) {
			godMode = true;
			corpoJogador.setColor(sf::Color::Cyan);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::F2)
				and (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))) {
			godMode = false;
			corpoJogador.setColor(sf::Color::White);
		}
	}

	if (jogadorAgachado == true) {
		corpoJogador.setPosition(hitboxJogador.getPosition().x,
				hitboxJogador.getPosition().y);
	} else {
		corpoJogador.setPosition(hitboxJogador.getPosition().x,
				hitboxJogador.getPosition().y + 10);
	}

}

void Jogador::atualizaColisaoBorda(const sf::RenderTarget *target) {
	// Verificar colisão com as bordas laterais
	if (this->hitboxJogador.getGlobalBounds().left <= 0.f) {
		this->hitboxJogador.setPosition(0.f,
				this->hitboxJogador.getGlobalBounds().top);
	} else if (this->hitboxJogador.getGlobalBounds().left
			+ this->hitboxJogador.getGlobalBounds().width
			>= target->getSize().x) {
		this->hitboxJogador.setPosition(
				target->getSize().x
						- this->hitboxJogador.getGlobalBounds().width,
				this->hitboxJogador.getGlobalBounds().top);
	}

	// Verificar colisão com o topo
	if (this->hitboxJogador.getGlobalBounds().top <= 0.f) {
		this->hitboxJogador.setPosition(
				this->hitboxJogador.getGlobalBounds().left, 0.f);
		this->velocidadeVertical = 0.f;
	}

	// Verificar colisão com o chão
	if (this->hitboxJogador.getGlobalBounds().top
			+ this->hitboxJogador.getGlobalBounds().height
			>= target->getSize().y) {
		this->hitboxJogador.setPosition(
				this->hitboxJogador.getGlobalBounds().left,
				target->getSize().y
						- this->hitboxJogador.getGlobalBounds().height);
		this->velocidadeVertical = 0.f; // Reseta a velocidade vertical ao atingir o chão
		noChao = true; // Jogador está no chão
	}
}

void Jogador::atualizaColisaoParede(std::vector<Parede> &inputParedes) {
	if (hitboxJogador.getGlobalBounds().intersects(
			inputParedes[0].retanguloCenario.getGlobalBounds())) {
		hitboxJogador.setPosition(
				sf::Vector2f(hitboxJogador.getPosition().x,
						hitboxJogador.getPosition().y - velocidadeMovimento));
		jogadorColideEscada = false;
		noChao = true;
	}
	if (hitboxJogador.getGlobalBounds().intersects(
			inputParedes[4].retanguloCenario.getGlobalBounds())) {
		hitboxJogador.setPosition(
				sf::Vector2f(
						hitboxJogador.getPosition().x + velocidadeMovimento,
						hitboxJogador.getPosition().y));
	}
	if (hitboxJogador.getGlobalBounds().intersects(
			inputParedes[5].retanguloCenario.getGlobalBounds())) {
		hitboxJogador.setPosition(
				sf::Vector2f(
						hitboxJogador.getPosition().x - velocidadeMovimento,
						hitboxJogador.getPosition().y));
	} // Colisões com o chão e as paredes da esquerda e direita

	if (hitboxJogador.getGlobalBounds().intersects(
			inputParedes[6].retanguloCenario.getGlobalBounds())) {
		if (hitboxJogador.getGlobalBounds().intersects(
				inputParedes[6].retanguloCenario.getGlobalBounds())
				and hitboxJogador.getGlobalBounds().intersects(
						inputParedes[10].retanguloCenario.getGlobalBounds())) {
			hitboxJogador.setPosition(
					sf::Vector2f(hitboxJogador.getPosition().x,
							hitboxJogador.getPosition().y));
			jogadorColideEscada = true;
		} else if (hitboxJogador.getGlobalBounds().intersects(
				inputParedes[1].retanguloCenario.getGlobalBounds())) {
			hitboxJogador.setPosition(
					sf::Vector2f(hitboxJogador.getPosition().x,
							hitboxJogador.getPosition().y
									+ velocidadeMovimento));
			jogadorColideEscada = false;
			noChao = false;
		}
	} // Colisão do primeiro andar

	if (hitboxJogador.getGlobalBounds().intersects(
			inputParedes[7].retanguloCenario.getGlobalBounds())) {
		if (hitboxJogador.getGlobalBounds().intersects(
				inputParedes[7].retanguloCenario.getGlobalBounds())
				and hitboxJogador.getGlobalBounds().intersects(
						inputParedes[10].retanguloCenario.getGlobalBounds())) {
			hitboxJogador.setPosition(
					sf::Vector2f(hitboxJogador.getPosition().x,
							hitboxJogador.getPosition().y));
			jogadorColideEscada = true;
		} else if (hitboxJogador.getGlobalBounds().intersects(
				inputParedes[1].retanguloCenario.getGlobalBounds())) {
			hitboxJogador.setPosition(
					sf::Vector2f(hitboxJogador.getPosition().x,
							hitboxJogador.getPosition().y
									- velocidadeMovimento));
			jogadorColideEscada = false;
			noChao = true;
		}

		if (hitboxJogador.getGlobalBounds().intersects(
				inputParedes[7].retanguloCenario.getGlobalBounds())
				and hitboxJogador.getGlobalBounds().intersects(
						inputParedes[11].retanguloCenario.getGlobalBounds())) {
			hitboxJogador.setPosition(
					sf::Vector2f(hitboxJogador.getPosition().x,
							hitboxJogador.getPosition().y));
			jogadorColideEscada = true;
		} else if (hitboxJogador.getGlobalBounds().intersects(
				inputParedes[2].retanguloCenario.getGlobalBounds())) {
			hitboxJogador.setPosition(
					sf::Vector2f(hitboxJogador.getPosition().x,
							hitboxJogador.getPosition().y
									+ velocidadeMovimento));
			jogadorColideEscada = false;
			noChao = false;
		}
	} // Colisão do segundo andar

	else if (hitboxJogador.getGlobalBounds().intersects(
			inputParedes[8].retanguloCenario.getGlobalBounds())) {
		if (hitboxJogador.getGlobalBounds().intersects(
				inputParedes[8].retanguloCenario.getGlobalBounds())
				and hitboxJogador.getGlobalBounds().intersects(
						inputParedes[11].retanguloCenario.getGlobalBounds())) {
			hitboxJogador.setPosition(
					sf::Vector2f(hitboxJogador.getPosition().x,
							hitboxJogador.getPosition().y));
			jogadorColideEscada = true;
		} else if (hitboxJogador.getGlobalBounds().intersects(
				inputParedes[2].retanguloCenario.getGlobalBounds())) {
			hitboxJogador.setPosition(
					sf::Vector2f(hitboxJogador.getPosition().x,
							hitboxJogador.getPosition().y
									- velocidadeMovimento));
			jogadorColideEscada = false;
			noChao = true;
		}

		if (hitboxJogador.getGlobalBounds().intersects(
				inputParedes[8].retanguloCenario.getGlobalBounds())
				and hitboxJogador.getGlobalBounds().intersects(
						inputParedes[12].retanguloCenario.getGlobalBounds())) {
			hitboxJogador.setPosition(
					sf::Vector2f(hitboxJogador.getPosition().x,
							hitboxJogador.getPosition().y));
			jogadorColideEscada = true;
		} else if (hitboxJogador.getGlobalBounds().intersects(
				inputParedes[3].retanguloCenario.getGlobalBounds())) {
			hitboxJogador.setPosition(
					sf::Vector2f(hitboxJogador.getPosition().x,
							hitboxJogador.getPosition().y
									+ velocidadeMovimento));
			jogadorColideEscada = false;
			noChao = false;
		}
	} // Colisão do terceiro andar

	else if (hitboxJogador.getGlobalBounds().intersects(
			inputParedes[9].retanguloCenario.getGlobalBounds())) {
		if (hitboxJogador.getGlobalBounds().intersects(
				inputParedes[9].retanguloCenario.getGlobalBounds())
				and hitboxJogador.getGlobalBounds().intersects(
						inputParedes[12].retanguloCenario.getGlobalBounds())) {
			hitboxJogador.setPosition(
					sf::Vector2f(hitboxJogador.getPosition().x,
							hitboxJogador.getPosition().y));
			jogadorColideEscada = true;
		} else if (hitboxJogador.getGlobalBounds().intersects(
				inputParedes[3].retanguloCenario.getGlobalBounds())) {
			hitboxJogador.setPosition(
					sf::Vector2f(hitboxJogador.getPosition().x,
							hitboxJogador.getPosition().y
									- velocidadeMovimento));
			jogadorColideEscada = false;
			noChao = true;
		}
	} // Colisão do quarto andar

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		inputParedes[10].retanguloCenario.setPosition(809, 550); // Hitboxes das escadas
		inputParedes[11].retanguloCenario.setPosition(184, 350);
		inputParedes[12].retanguloCenario.setPosition(809, 150);
	} else {
		inputParedes[10].retanguloCenario.setPosition(809, 560);
		inputParedes[11].retanguloCenario.setPosition(184, 360);
		inputParedes[12].retanguloCenario.setPosition(809, 160);
	}
}

void Jogador::atualizaTexturas(Som *inputSom) {

	if (jogadorGiradoEsquerda == true) {
		corpoJogador.setTexture(texturaJogadorGirado);
	} else if (jogadorGiradoEsquerda == false) {
		corpoJogador.setTexture(texturaJogador);
	}

	if (jogadorColideEscada == true) {
		corpoJogador.setTexture(texturaJogadorEscada);
		jogadorAgachado = false;
	} else if ((jogadorGiradoEsquerda == true)
			and (jogadorColideEscada == false)) {
		corpoJogador.setTexture((texturaJogadorGirado));
	} else if ((jogadorGiradoEsquerda == false)
			and (jogadorColideEscada == false)) {
		corpoJogador.setTexture(texturaJogador);
	}

	if (jogadorAgachado == true) {
		if ((jogadorAgachado == true) and (jogadorGiradoEsquerda == true)) {
			corpoJogador.setTexture(texturaJogadorAgachadoGirado);
			inputSom->agacharSom.play();
		} else {
			inputSom->agacharSom.play();
			corpoJogador.setTexture(texturaJogadorAgachado);
		}
	}

	if ((jogadorSoco == true) and (jogadorGiradoEsquerda == true)) {
		corpoJogador.setTexture(texturaJogadorSocoGirado);
		inputSom->socoSom.play();
	} else if (jogadorSoco == true) {
		corpoJogador.setTexture(texturaJogadorSoco);
		inputSom->socoSom.play();
	}

	if ((jogadorPulo == true) and (jogadorColideEscada == true)) {
		corpoJogador.setTexture(texturaJogadorEscada);
		inputSom->pularSom.play();
	} else if ((jogadorPulo == true) and (jogadorGiradoEsquerda == true)
			and (jogadorColideEscada == true)) {
		corpoJogador.setTexture(texturaJogadorEscada);
		inputSom->pularSom.play();
	} else if ((jogadorPulo == true) and (jogadorGiradoEsquerda == true)) {
		corpoJogador.setTexture(texturaJogadorPuloGirado);
		inputSom->pularSom.play();
	} else if (jogadorPulo == true) {
		corpoJogador.setTexture(texturaJogadorPulo);
		inputSom->pularSom.play();
	} else if ((jogadorPulo == false) and (jogadorGiradoEsquerda == true)
			and (jogadorAgachado == false) and (jogadorSoco == false)
			and (jogadorColideEscada == false) and (jogadorAndando == true)) {
		corpoJogador.setTexture(texturaJogadorGirado);
	} else if ((jogadorPulo == false) and (jogadorGiradoEsquerda == false)
			and (jogadorAgachado == false) and (jogadorSoco == false)
			and (jogadorColideEscada == false) and (jogadorAndando == true)) {
		corpoJogador.setTexture(texturaJogador);
	}

}

void Jogador::atualizaJogador(const sf::RenderTarget *target,
		std::vector<Parede> &inputParedes, Som *inputSom, float meuTempo) {
	this->atualizaTexturas(inputSom);
	this->atualizaColisaoBorda(target);
	this->atualizaColisaoParede(inputParedes);
	this->atualizaInput(meuTempo);
}

void Jogador::desenhaJogador(sf::RenderTarget *target) {
	target->draw(this->hitboxJogador);
	target->draw(this->corpoJogador);
	target->draw(this->hitboxSoco);
	target->draw(vidasMoldura);
	target->draw(vidasTexto);
	for (int i; i < 3; i++) {
		target->draw(this->vida[i]);
	}

}
