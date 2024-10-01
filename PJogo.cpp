#include "PJogo.h"
#include "PInimigo.h"

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
Jogo::Jogo(int inputNumeroFase) :
		jogador(100.f, 300.f),  // Exemplo de posição inicial
		inimigo(jogador) {
	this->inicializaVariaveis();
	meuMapa.criarMapa(inputNumeroFase, &meuMapa.minhasParedes,
			&meuMapa.minhasEscadas, &meuMapa.minhasFrutas,
			&meuMapa.minhasArvores, &meuMapa.minhasFlores,
			&meuMapa.minhasNuvens, &meuMapa.meuFilhote,
			&meuMapa.minhaNuvemInimiga, janela);
	meuTempo.updateDeltaTime();
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
	meuTempo.updateDeltaTime();
	this->inimigo.atualizaInimigo(this->janela);
	this->jogador.atualizaJogador(this->janela);
}

void Jogo::desenha(int inputNumeroFase) {
	this->janela->clear(sf::Color(168, 231, 240));

	//Desenha objetos do jogo
	meuMapa.desenharMapa(inputNumeroFase, meuMapa.minhasParedes,
			meuMapa.minhasEscadas, meuMapa.minhasFrutas, meuMapa.minhasArvores,
			meuMapa.minhasFlores, meuMapa.minhasNuvens, &meuMapa.meuFilhote,
			&meuMapa.minhaNuvemInimiga, &meuMapa.meuTexto, janela);

	this->inimigo.desenhaInimigo(this->janela);
	this->jogador.desenhaJogador(this->janela);

	this->janela->display();
}
