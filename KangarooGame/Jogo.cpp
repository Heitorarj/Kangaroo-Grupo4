#include "Jogo.h"

//Funcoes privadas
void Jogo::inicializaVariaveis() {
	this->janela = nullptr;
}

void Jogo::inicializaJanela() {
	this->janela = new sf::RenderWindow(sf::VideoMode(1100, 800),
			"Kangaroo Game", sf::Style::Titlebar | sf::Style::Close);

	this->janela->setFramerateLimit(60);
}

//Construtores / Destrutores
Jogo::Jogo() {
	this->inicializaVariaveis();
	this->inicializaJanela();
}

Jogo::~Jogo() {
	delete this->janela;
}

const bool Jogo::jogoRodando() const {
	return this->janela->isOpen();
}

//Funcoes
void Jogo::pollEventos() {
	while (this->janela->pollEvent(this->evento)) {
		if (evento.type == sf::Event::Closed)
			this->janela->close();
	}
}

//Onde o jogo acontece
void Jogo::atualiza() {
	this->pollEventos();

	this->inimigo.atualizaInimigo(this->janela);
	this->jogador.atualizaJogador(this->janela);
}

void Jogo::desenha() {
	this->janela->clear(sf::Color(168, 231, 240));

	//Desenha objetos do jogo
	this->inimigo.desenhaInimigo(this->janela);
	this->jogador.desenhaJogador(this->janela);

	this->janela->display();
}
