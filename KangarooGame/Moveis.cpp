#include "Jogo.hpp"
#include "Moveis.hpp"

Tempo::Tempo() {
	deltaTime = deltaTimeObject.restart().asSeconds();
}

void Tempo::updateDeltaTime() {
	deltaTime = deltaTimeObject.restart().asSeconds();
}

Jogador::Jogador() {
	jogadorTextura.loadFromFile("assets/kangaroo.png");
	jogadorTexturaGirado.loadFromFile("assets/kangarooGirado.png");
	jogadorAgachadoTextura.loadFromFile("assets/kangarooAgachado.png");
	jogadorCorpo.setTexture(jogadorTextura);
	jogadorCorpo.setScale(escalaOriginal);
	jogadorCorpo.setPosition(sf::Vector2f(225, 700));
	jogadorCorpo.setOrigin(jogadorCorpo.getLocalBounds().width / 2,
			jogadorCorpo.getLocalBounds().height / 2);
	escalaOriginal = sf::Vector2f(0.1, 0.1); //tamanho kangaroo normal
	escalaAgachado = sf::Vector2f(0.1, 0.1); //tamanho kangaroo agachado
	jogadorHitbox.setFillColor(sf::Color::Transparent);
	jogadorHitbox.setOutlineColor(sf::Color::Green);
	jogadorHitbox.setOutlineThickness(5);
	jogadorHitbox.setSize(sf::Vector2f(60, 100));
	pontos = 0;
}

void Jogador::moveJogador(float deltaTime) {
	velocidadeX = 0;
	velocidadeY = 0;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		jogadorCorpo.setTexture(jogadorAgachadoTextura); // Troca a textura ao agachar
		jogadorCorpo.setScale(escalaAgachado); // Aplica a escala para a imagem agachada
		velocidadeY = 200;
	} else {
		jogadorCorpo.setTexture(jogadorTextura);
		jogadorCorpo.setScale(escalaOriginal);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		velocidadeX = -200;
		jogadorCorpo.setTexture(jogadorTexturaGirado); //Altera a imagem para o kanguru invertido
		jogadorCorpo.setScale(escalaOriginal); // Aplica a escala para a imagem normal
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		velocidadeX = 200;
		jogadorCorpo.setTexture(jogadorTextura);
		jogadorCorpo.setScale(escalaOriginal);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		velocidadeY = -200;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F1)) {
		jogadorCorpo.rotate(500000000000000000 * deltaTime); // Transforma o kanguru em um sharingan, apenas um easter egg engraçadinho
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F2)) {
		for (int i = 0; i < 1000; i++) {
			std::cout << i << std::endl; // Fps debug
		}
	}
	jogadorHitbox.setOrigin(
			sf::Vector2f((jogadorHitbox.getLocalBounds().width / 2),
					jogadorHitbox.getLocalBounds().height / 2));
	jogadorHitbox.setPosition(
			sf::Vector2f(jogadorCorpo.getPosition().x,
					jogadorCorpo.getPosition().y));

	jogadorCorpo.setPosition(
			jogadorCorpo.getPosition().x + velocidadeX * deltaTime,
			jogadorCorpo.getPosition().y + velocidadeY * deltaTime); //Velocidade aplicada só após de determinar a direção
}

Nuvem::Nuvem() {

	nuvemTextura.loadFromFile("assets/nuvem.png");
	nuvemCorpo.setTexture(nuvemTextura);
	nuvemCorpo.setScale(5, 5);
	nuvemCorpo.setOrigin(nuvemCorpo.getLocalBounds().width / 2,
			nuvemCorpo.getLocalBounds().height / 2);
	velocidadeX = 50;
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
	hitboxNuvemInimiga.setSize(sf::Vector2f(0, 800));
	tiroVelocidadeY = 50;
	velocidadeX = 100;
}

void NuvemInimiga::moverTiro() {
	while (nuvemTiro.getPosition().y < 900) {
		nuvemTiro.setPosition(nuvemTiro.getPosition().x,
				nuvemTiro.getPosition().y + tiroVelocidadeY);
	}
}

void NuvemInimiga::nuvemAtacar(Jogador &inputJogador) {

	if (inputJogador.jogadorHitbox.getGlobalBounds().intersects(
			hitboxNuvemInimiga.getGlobalBounds())) {

		moverTiro();

	}
}

Filhote::Filhote() {
	filhoteTextura.loadFromFile("assets/kangaroo.png");
	filhoteCorpo.setTexture(filhoteTextura);
	filhoteCorpo.setOrigin(filhoteCorpo.getLocalBounds().width / 2,
			filhoteCorpo.getLocalBounds().height / 2);
	filhoteCorpo.setScale(0.05, 0.05);
	filhoteHitbox.setSize(
			sf::Vector2f(filhoteCorpo.getLocalBounds().width / 20,
					filhoteCorpo.getLocalBounds().height / 20));
	filhoteHitbox.setOrigin(filhoteHitbox.getLocalBounds().width / 2,
			filhoteHitbox.getLocalBounds().height / 2);
	filhoteHitbox.setFillColor(sf::Color::Transparent);
	filhoteHitbox.setOutlineColor(sf::Color::Green);
	filhoteHitbox.setOutlineThickness(5);
	velocidadeX = 70;
}
