#include "PJogador.h"

//Funcoes privadas
void Jogador::inicializaVariaveisJogador() {
	this->velocidadeMovimento = 5.f;
	this->escalaJogador = sf::Vector2f(0.1, 0.1);
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
}

//Construtores / Destrutores
Jogador::Jogador(float x, float y) {
	this->hitboxJogador.setPosition(x, y);

	this->inicializaVariaveisJogador();
	this->inicializaHitboxJogador();
	this->inicializaTexturaJogador();
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

void Jogador::atualizaJogador(const sf::RenderTarget *target) {
	this->atualizaInput();
	this->atualizaColisaoBorda(target);
}

void Jogador::desenhaJogador(sf::RenderTarget *target) {
	target->draw(this->hitboxJogador);
	target->draw(this->corpoJogador);
}
