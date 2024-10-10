#include "../Declaracao/Jogo.h"

//Funcoes privadas
void Jogo::inicializaVariaveis() {
	this->janela = nullptr;
	this->telaCodigo = -1;
	this->corFundo = sf::Color(168, 231, 240);
}

void Jogo::inicializaJanela() {
	this->janela = new sf::RenderWindow(sf::VideoMode(1100, 800),
			"Kangaroo Game");
	this->janela->setFramerateLimit(60);
}

//Construtores / Destrutores
Jogo::Jogo(int inputNumeroFase) :
		jogador(),  // Exemplo de posição inicial
		inimigo(jogador) {
	this->inicializaVariaveis();
	meuMapa.criarMapa(inputNumeroFase, &meuMapa.minhasParedes,
			&meuMapa.minhasEscadas, &meuMapa.minhasFrutas,
			&meuMapa.minhasArvores, &meuMapa.minhasFlores,
			&meuMapa.minhasNuvens, &meuMapa.meuFilhote,
			&meuMapa.minhaNuvemInimiga, &meuMapa.meuSino, janela);
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
	//std::cout << meuTempo.deltaTime << "\n";
	meuMapa.mapaUpdate(1, &jogador, meuMapa.minhasFrutas, &meuMapa.meuTexto,
			&meuMapa.meuFilhote, meuMapa.minhasNuvens,
			&meuMapa.minhaNuvemInimiga, &meuMapa.meuSino, meuMapa.minhasParedes,
			&inimigo, meuTempo.deltaTime, &telaCodigo, &corFundo, &meuSom,
			meuMapa.minhasFlores, meuMapa.minhasArvores, meuMapa.minhasEscadas,
			janela);

	this->inimigo.atualizaInimigo(this->janela, meuMapa.minhasParedes, &jogador,
			&meuSom, &meuMapa.meuTexto);
	this->jogador.atualizaJogador(this->janela, meuMapa.minhasParedes, &meuSom,
			meuTempo.deltaTime);
	this->jogador.atualizaVidas();

	meuSom.somMusica(telaCodigo);
}

void Jogo::desenha(int inputNumeroFase) {
	this->janela->clear(corFundo);

	if (telaCodigo == -1) {
		minhaTela.desenhaMenu(janela, &jogador, &telaCodigo);
	} else if (telaCodigo == 0) {

		this->inimigo.desenhaInimigo(this->janela);
		meuMapa.desenharMapa(inputNumeroFase, meuMapa.minhasParedes,
				meuMapa.minhasEscadas, meuMapa.minhasFrutas,
				meuMapa.minhasArvores, meuMapa.minhasFlores,
				meuMapa.minhasNuvens, &meuMapa.meuFilhote,
				&meuMapa.minhaNuvemInimiga, &meuMapa.meuTexto, &meuMapa.meuSino,
				janela);

		this->jogador.desenhaJogador(this->janela);
		this->janela->display();

	} else if (telaCodigo == 1) {
		minhaTela.desenhaVitoria(janela, &jogador, &meuMapa.meuTexto);
	} else if (telaCodigo == 2) {
		minhaTela.desenhaDerrota(janela, &jogador, &meuMapa.meuTexto);
	}

}
