#include "PInimigo.h"

//Funcoes privadas
void Inimigo::inicializaVariaveisInimigo() {
	this->velocidadeMovimento = 5.f;
	this->escalaInimigo = sf::Vector2f(0.1, 0.1);
	this->persegueJogadorX = 200.f;
	this->persegueJogadorY = 200.f;
}
void Inimigo::inicializaHitboxInimigo() {
	this->hitboxInimigo.setFillColor(sf::Color::Red);
	this->hitboxInimigo.setSize(sf::Vector2f(60.f, 100.f));
	this->hitboxInimigo.setPosition(sf::Vector2f(900.f, 20.f));
}
void Inimigo::inicializaTexturaInimigo() {
	this->corpoInimigo.setTexture(texturaInimigo);
	this->corpoInimigo.setScale(escalaInimigo);
	this->corpoInimigo.setPosition(hitboxInimigo.getPosition());
}

//Construtores / Destrutores
Inimigo::Inimigo() {
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

//MOVIMENTACAO NAO FUNCIONA, RESOLVER ISSO
void Inimigo::persegueJogador() {
	if (this->jogador.getHitboxJogador().getPosition().x
			- hitboxInimigo.getPosition().x > 0.f) {
		hitboxInimigo.move(velocidadeMovimento, 0.f);
	} else {
		hitboxInimigo.move(-velocidadeMovimento, 0.f);
	}
	if (this->jogador.getHitboxJogador().getPosition().y
			- hitboxInimigo.getPosition().y > 0.f) {
		hitboxInimigo.move(0.f, velocidadeMovimento);
	} else {
		hitboxInimigo.move(0.f, -velocidadeMovimento);
	}
}

void Inimigo::movimentoAleatorioInimigo() {
	if (this->jogador.getHitboxJogador().getPosition().x
			- this->hitboxInimigo.getPosition().x <= persegueJogadorX
			&& this->jogador.getHitboxJogador().getPosition().y
					- this->hitboxInimigo.getPosition().y <= persegueJogadorY) {
		this->persegueJogador();
	}
}

void Inimigo::atualizaColisaoBorda(const sf::RenderTarget *target) {
	if (this->hitboxInimigo.getGlobalBounds().left <= 0.f) {
		this->hitboxInimigo.setPosition(0.f,
				this->hitboxInimigo.getGlobalBounds().top);
	} else if (this->hitboxInimigo.getGlobalBounds().left
			+ this->hitboxInimigo.getGlobalBounds().width
			>= target->getSize().x) {
		this->hitboxInimigo.setPosition(
				target->getSize().x
						- this->hitboxInimigo.getGlobalBounds().width,
				this->hitboxInimigo.getGlobalBounds().top);
	}
	if (this->hitboxInimigo.getGlobalBounds().top <= 0.f) {
		this->hitboxInimigo.setPosition(
				this->hitboxInimigo.getGlobalBounds().left, 0.f);
	} else if (this->hitboxInimigo.getGlobalBounds().top
			+ this->hitboxInimigo.getGlobalBounds().height
			>= target->getSize().y) {
		this->hitboxInimigo.setPosition(
				this->hitboxInimigo.getGlobalBounds().left,
				target->getSize().y
						- this->hitboxInimigo.getGlobalBounds().height);
	}
}

void Inimigo::atualizaInimigo(const sf::RenderTarget *target) {
	this->movimentoAleatorioInimigo();
	this->atualizaColisaoBorda(target);

}

void Inimigo::desenhaInimigo(sf::RenderTarget *target) {
	target->draw(this->hitboxInimigo);
	target->draw(this->corpoInimigo);
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
	hitboxNuvemInimiga.setOutlineColor(sf::Color::Green);
	hitboxNuvemInimiga.setOutlineThickness(5);
	hitboxNuvemInimiga.setOrigin(hitboxNuvemInimiga.getLocalBounds().width / 2,
			hitboxNuvemInimiga.getLocalBounds().height / 2);
	hitboxNuvemInimiga.setSize(sf::Vector2f(100, 800));
	tiroVelocidadeY = 50;
	velocidadeX = 15;
}

void NuvemInimiga::nuvemAtacar(Jogador &inputJogador, float inputDeltaTime,
		sf::RenderWindow *inputJanela) {

	if (!inputJogador.hitboxJogador.getGlobalBounds().intersects(
			hitboxNuvemInimiga.getGlobalBounds())) {
		nuvemTiro.setPosition(nuvemCorpo.getPosition());
		hitboxNuvemInimiga.setSize(sf::Vector2f(100, 800));
		hitboxNuvemInimiga.setPosition(nuvemCorpo.getPosition().x - 50,
				nuvemCorpo.getPosition().y);

	} else {
		if (nuvemTiro.getPosition().y > 1000) {
			nuvemTiro.setPosition(nuvemTiro.getPosition().x,
					nuvemTiro.getPosition().y - 1000);
			nuvemTiro.setPosition(nuvemCorpo.getPosition());
			hitboxNuvemInimiga.setSize(sf::Vector2f(100, 800));

		} else {
			hitboxNuvemInimiga.setSize(sf::Vector2f(1000, 800));
			hitboxNuvemInimiga.setPosition(
					inputJogador.hitboxJogador.getPosition().x - 500,
					inputJogador.hitboxJogador.getPosition().y - 500);

			nuvemTiro.setPosition(nuvemTiro.getPosition().x,
					nuvemTiro.getPosition().y
							+ tiroVelocidadeY * inputDeltaTime);

			if (inputJogador.hitboxJogador.getGlobalBounds().intersects(
					nuvemTiro.getGlobalBounds())) {
				inputJogador.vidas--;
				inputJogador.hitboxJogador.setPosition(sf::Vector2f(200, 650));
				nuvemTiro.setPosition(sf::Vector2f(1000, 1000));
				inputJogador.atualizaVidas();
			} else if (inputJogador.vidas <= 0) {
				inputJanela->close();
			}
		}
	}
}
