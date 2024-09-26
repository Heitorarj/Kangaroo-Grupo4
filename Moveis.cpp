
#include "Jogo.hpp"
#include "Moveis.hpp"

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

void Jogador::moveJogador() {
	velocidadeX = 0;
	velocidadeY = 0;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		jogadorCorpo.setTexture(jogadorAgachadoTextura); // Troca a textura ao agachar
		jogadorCorpo.setScale(escalaAgachado); // Aplica a escala para a imagem agachada
		velocidadeY = 0.12;
	} else {
		jogadorCorpo.setTexture(jogadorTextura);
		jogadorCorpo.setScale(escalaOriginal);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		velocidadeX = -0.12;
		jogadorCorpo.setTexture(jogadorTexturaGirado); //Altera a imagem para o kanguru invertido
		jogadorCorpo.setScale(escalaOriginal); // Aplica a escala para a imagem normal
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		velocidadeX = 0.12;
		jogadorCorpo.setTexture(jogadorTextura);
		jogadorCorpo.setScale(escalaOriginal);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		velocidadeY = -0.12;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F1)) {
		jogadorCorpo.rotate(5); // Transforma o kanguru em um sharingan, apenas um easter egg engraçadinho
	}

	jogadorHitbox.setOrigin(
			sf::Vector2f((jogadorHitbox.getLocalBounds().width / 2),
					jogadorHitbox.getLocalBounds().height / 2));
	jogadorHitbox.setPosition(
			sf::Vector2f(jogadorCorpo.getPosition().x,
					jogadorCorpo.getPosition().y));

	jogadorCorpo.move(velocidadeX, velocidadeY); //Velocidade aplicada só após de determinar a direção
}

Nuvem::Nuvem() {

	nuvemTextura.loadFromFile("assets/nuvem.png");
	nuvemCorpo.setTexture(nuvemTextura);
	nuvemCorpo.setScale(5, 5);
	nuvemCorpo.setOrigin(nuvemCorpo.getLocalBounds().width / 2,
			nuvemCorpo.getLocalBounds().height / 2);
	velocidadeX = 0.03;
}

void Nuvem::moverNuvem() {

	if ((nuvemCorpo.getPosition().x <= 0)
			or (nuvemCorpo.getPosition().x >= 1000)) {
		nuvemCorpo.setPosition(nuvemCorpo.getPosition().x, rand() % 500);
		velocidadeX *= -1;
	}
	nuvemCorpo.setPosition(nuvemCorpo.getPosition().x + velocidadeX,
			nuvemCorpo.getPosition().y);
}

