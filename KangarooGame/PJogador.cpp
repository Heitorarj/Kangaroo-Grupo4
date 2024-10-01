#include "PJogador.h"

//Funcoes privadas
void Jogador::inicializaVariaveisJogador() {
	this->velocidadeMovimento = 5.f;
	this->escalaJogador = sf::Vector2f(0.1, 0.1);
	pontos = 0;
	vidas = 3;
}

void Jogador::inicializaHitboxJogador() {
	this->hitboxJogador.setFillColor(sf::Color::Green);
	this->hitboxJogador.setSize(sf::Vector2f(60.f, 100.f));
}

void Jogador::inicializaTexturaJogador() {
	this->texturaJogador.loadFromFile("assets/kangaroo.png");
	this->texturaJogadorAgachado.loadFromFile("assets/kangarooAgachado.png");
	this->corpoJogador.setTexture(texturaJogador);
	this->corpoJogador.setScale(escalaJogador);
	this->corpoJogador.setPosition(hitboxJogador.getPosition());
	vidaTextura.loadFromFile("assets/fruta.png");
	for (int i = 0; i < 3; i++) {
		vida[i].setScale(0.02, 0.02);
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

//Construtores / Destrutores
Jogador::Jogador(float x, float y) {
	this->hitboxJogador.setPosition(x, y);

	this->inicializaVariaveisJogador();
	this->inicializaHitboxJogador();
	this->inicializaTexturaJogador();
	this->inicializaVidas();
}

Jogador::~Jogador() {

}

//Funcoes
sf::RectangleShape Jogador::getHitboxJogador() {
	return hitboxJogador;
}

void Jogador::atualizaInput() {
	//Entrada do teclado
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		this->hitboxJogador.move(-this->velocidadeMovimento, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		this->hitboxJogador.move(this->velocidadeMovimento, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		this->hitboxJogador.move(0.f, -this->velocidadeMovimento);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		this->hitboxJogador.move(0.f, this->velocidadeMovimento);
		this->corpoJogador.setTexture(texturaJogadorAgachado);
		this->hitboxJogador.setSize(sf::Vector2f(60.f, 60.f));
	} else {
		this->corpoJogador.setTexture(texturaJogador);
		this->hitboxJogador.setSize(sf::Vector2f(60.f, 100.f));
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F1)) {
		corpoJogador.rotate(5); // Transforma o kanguru em um sharingan, apenas um easter egg engraçadinho
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F2)) {
		for (int i = 0; i < 1000; i++) {
			std::cout << i << std::endl; // Fps debug
		}
	}

	corpoJogador.setPosition(hitboxJogador.getPosition());
}

void Jogador::atualizaColisaoBorda(const sf::RenderTarget *target) {

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
	if (this->hitboxJogador.getGlobalBounds().top <= 0.f) {
		this->hitboxJogador.setPosition(
				this->hitboxJogador.getGlobalBounds().left, 0.f);
	} else if (this->hitboxJogador.getGlobalBounds().top
			+ this->hitboxJogador.getGlobalBounds().height
			>= target->getSize().y) {
		this->hitboxJogador.setPosition(
				this->hitboxJogador.getGlobalBounds().left,
				target->getSize().y
						- this->hitboxJogador.getGlobalBounds().height);
	}

}

void Jogador::atualizaVidas() {
	if (vidas == 2) {
		vida[2].setPosition(-50, -50);
	} else if (vidas == 1) {
		vida[1].setPosition(-50, -50);
	}
}

void Jogador::atualizaJogador(const sf::RenderTarget *target) {
	this->atualizaInput();
	this->atualizaColisaoBorda(target);
}

void Jogador::desenhaJogador(sf::RenderTarget *target) {
	target->draw(this->hitboxJogador);
	target->draw(this->corpoJogador);
	target->draw(vidasMoldura);
	target->draw(vidasTexto);
	for (int i; i < 3; i++) {
		target->draw(this->vida[i]);
	}

}
