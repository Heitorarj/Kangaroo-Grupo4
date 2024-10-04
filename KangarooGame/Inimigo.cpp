#include "Inimigo.h"

//Funcoes privadas
void Inimigo::inicializaVariaveisInimigo() {
	this->velocidadeMovimento = 5.f;
	this->escalaInimigo = sf::Vector2f(0.1, 0.1);
	this->persegueJogadorX = 200.f;
	this->persegueJogadorY = 200.f;
}
void Inimigo::inicializaHitboxInimigo() {
	this->hitboxInimigo.setFillColor(sf::Color::Transparent);
	this->hitboxInimigo.setSize(sf::Vector2f(60.f, 100.f));
	this->hitboxInimigo.setPosition(sf::Vector2f(900.f, 20.f));
}
void Inimigo::inicializaTexturaInimigo() {
	this->corpoInimigo.setTexture(texturaInimigo);
	this->corpoInimigo.setScale(escalaInimigo);
	this->corpoInimigo.setPosition(hitboxInimigo.getPosition());
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
	hitboxNuvemInimiga.setOutlineColor(sf::Color::Transparent);
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
			}
		}
	}
}
