#include "Jogo.hpp"
#include "Moveis.hpp"

Jogador::Jogador() {
	jogadorTextura.loadFromFile("assets/kangaroo.png");
	jogadorTexturaGirado.loadFromFile("assets/kangarooGirado.png");
	jogadorAgachadoTextura.loadFromFile("assets/kangarooAgachado.png");
	jogadorCorpo.setTexture(jogadorTextura);
	jogadorCorpo.setScale(escalaOriginal);
	jogadorCorpo.setPosition(sf::Vector2f(225, 650));
	jogadorCorpo.setOrigin(jogadorCorpo.getLocalBounds().width / 2,
			jogadorCorpo.getLocalBounds().height / 2);
	escalaOriginal = sf::Vector2f(0.05, 0.05); //tamanho kangaroo normal
	escalaAgachado = sf::Vector2f(0.04, 0.04); //tamanho kangaroo agachado
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
}
Nuvem::Nuvem(int inputNumeroFase) {
	if (inputNumeroFase == 1) {
		for (int i = 0; i < 5; i++) {
			nuvemTextura.loadFromFile("assets/nuvem.png");
			nuvemCorpo[i].setTexture(nuvemTextura);
			nuvemCorpo[i].setScale(5, 5);
			nuvemCorpo[i].setOrigin(nuvemCorpo[i].getLocalBounds().width / 2,
					nuvemCorpo[i].getLocalBounds().height / 2);
			velocidadeX[i] = 1;
		}
		srand(time(NULL));
		nuvemCorpo[0].setPosition((rand() % 100) + (rand() % 100),
				rand() % 100);
		nuvemCorpo[1].setPosition((rand() % 100) + (rand() % 100),
				rand() % 200 + 50);
		nuvemCorpo[2].setPosition((rand() % 100) + (rand() % 100),
				rand() % 200 + 50);
		nuvemCorpo[3].setPosition((rand() % 100) + (rand() % 100),
				rand() % 230 + 50);
		nuvemCorpo[4].setPosition((rand() % 100) + (rand() % 100),
				rand() % 400 + 50);
	}
}
void Nuvem::moverNuvem() {
	for (int i = 0; i < 5; i++) {
		if ((nuvemCorpo[i].getPosition().x <= 0)
				or (nuvemCorpo[i].getPosition().x >= 1000)) {
			nuvemCorpo[i].setPosition(
							nuvemCorpo[i].getPosition().x,
							rand () % 500);
			velocidadeX[i] *= -1;
		}
		nuvemCorpo[i].setPosition(
				nuvemCorpo[i].getPosition().x + velocidadeX[i],
				nuvemCorpo[i].getPosition().y);
	}
}
void Nuvem::girar() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F1)) {
		for (int i = 0; i < 5; i++) {
			nuvemCorpo[i].rotate(5);
		}
	}
}
