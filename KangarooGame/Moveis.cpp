#include "Jogo.hpp"
#include "Moveis.hpp"

Jogador::Jogador() {
	jogadorTextura.loadFromFile("assets/kangaroo.png");
	jogadorTexturaGirado.loadFromFile("assets/kangarooGirado.png");
	jogadorAgachadoTextura.loadFromFile("assets/kangarooAgachado.png");
	jogadorCorpo.setTexture(jogadorTextura);
	jogadorCorpo.setScale(escalaOriginal);
	jogadorCorpo.setPosition(sf::Vector2f(200, 600));
	jogadorCorpo.setOrigin(jogadorCorpo.getLocalBounds().width / 2,
			jogadorCorpo.getLocalBounds().height / 2);
	escalaOriginal = sf::Vector2f(0.05, 0.05); //tamanho kangaroo normal
	escalaAgachado = sf::Vector2f(0.04, 0.04); //tamanho kangaroo agachado
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

	jogadorCorpo.move(velocidadeX, velocidadeY); //Velocidade aplicada só após de determinar a direção
}

