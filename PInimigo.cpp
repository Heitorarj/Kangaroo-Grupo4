#include "PInimigo.h"

// Funções privadas
void Inimigo::inicializaVariaveisInimigo() {
	this->velocidadeMovimento = 5.f;
	this->escalaInimigo = sf::Vector2f(0.1f, 0.1f);
	this->persegueJogadorX = 200.f;
	this->persegueJogadorY = 200.f;
	this->direcaoAleatoria = sf::Vector2f(0.f, 0.f);
	this->tempoMudancaDirecao = 100; // Quantidade de frames até mudar de direção
	this->frameAtual = 0;
	srand(static_cast<unsigned>(time(0)));  // Seed para números aleatórios
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

// Construtores / Destrutores
Inimigo::Inimigo(Jogador &jogador) :
		jogador(jogador) {
	this->inicializaVariaveisInimigo();
	this->inicializaHitboxInimigo();
	this->inicializaTexturaInimigo();
}

Inimigo::~Inimigo() {

}

// Funções
sf::RectangleShape Inimigo::getHitboxInimigo() {
	return hitboxInimigo;
}

void Inimigo::persegueJogador() {
	// Obtém a posição atual do jogador
	sf::Vector2f posicaoJogador =
			this->jogador.getHitboxJogador().getPosition();

	// Calcula a diferença de posição entre o inimigo e o jogador
	float deltaX = posicaoJogador.x - hitboxInimigo.getPosition().x;
	float deltaY = posicaoJogador.y - hitboxInimigo.getPosition().y;

	// Calcula a magnitude da diferença de posição
	float magnitude = sqrt(deltaX * deltaX + deltaY * deltaY);

	// Verifica se a magnitude não é zero para evitar divisões por zero
	if (magnitude != 0) {
		// Normaliza o vetor de movimento
		float moveX = (deltaX / magnitude) * velocidadeMovimento;
		float moveY = (deltaY / magnitude) * velocidadeMovimento;

		// Move a hitbox do inimigo na direção do jogador
		hitboxInimigo.move(moveX, moveY);

		// Atualiza a posição do corpo do inimigo para seguir a hitbox
		corpoInimigo.setPosition(hitboxInimigo.getPosition());
	}
}

void Inimigo::movimentoAleatorioInimigo() {
	// Distância entre o jogador e o inimigo
	float distanciaX = abs(
			this->jogador.getHitboxJogador().getPosition().x
					- this->hitboxInimigo.getPosition().x);
	float distanciaY = abs(
			this->jogador.getHitboxJogador().getPosition().y
					- this->hitboxInimigo.getPosition().y);

	// Se o jogador estiver dentro do raio de perseguição, persegue o jogador
	if (distanciaX <= persegueJogadorX && distanciaY <= persegueJogadorY) {
		this->persegueJogador();
	} else {
		// Movimento aleatório quando não está perseguindo o jogador

		// Verifica se é hora de mudar a direção
		if (frameAtual >= tempoMudancaDirecao) {
			// Gera uma direção aleatória (x, y) entre -1 e 1
			float direcaoX = static_cast<float>(rand() % 3 - 1);  // -1, 0 ou 1
			float direcaoY = static_cast<float>(rand() % 3 - 1);  // -1, 0 ou 1

			// Atualiza a direção
			this->direcaoAleatoria = sf::Vector2f(direcaoX, direcaoY);

			// Reinicia o contador de frames
			frameAtual = 0;
		}

		// Aplica o movimento com a direção atual e a velocidade
		hitboxInimigo.move(direcaoAleatoria.x * velocidadeMovimento,
				direcaoAleatoria.y * velocidadeMovimento);

		// Atualiza o corpo do inimigo
		corpoInimigo.setPosition(hitboxInimigo.getPosition());

		// Incrementa o contador de frames
		frameAtual++;
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

	// Atualiza a posição do corpo do inimigo para seguir a hitbox
	corpoInimigo.setPosition(hitboxInimigo.getPosition());
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
	nuvemTextura.loadFromFile("assets/nuvem.png");
	nuvemCorpo.setTexture(nuvemTextura);
	nuvemCorpo.setScale(7, 7);
	nuvemCorpo.setOrigin(nuvemCorpo.getLocalBounds().width / 2,
			nuvemCorpo.getLocalBounds().height / 2);
	nuvemTiroTextura.loadFromFile("assets/sino.png");
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
	tiroVelocidadeY = 500;
	velocidadeX = 100;
}
