
#ifndef MOVEIS_HPP_
#define MOVEIS_HPP_

class Movel {
public:
	float velocidadeX, velocidadeY;
};

class Jogador: public Movel {
public:
	sf::Texture jogadorTextura;
	sf::Texture jogadorAgachadoTextura;
	sf::Sprite jogadorCorpo;
	sf::Vector2f escalaOriginal = sf::Vector2f(0.05, 0.05);
	sf::Vector2f escalaAgachado = sf::Vector2f(0.045, 0.045); // Ajuste o fator de escala para a imagem agachada

	Jogador() {
		jogadorTextura.loadFromFile("assets/kangaroo.png");
		jogadorAgachadoTextura.loadFromFile("assets/kangarooAgachado.png");
		jogadorCorpo.setTexture(jogadorTextura);
		jogadorCorpo.setScale(escalaOriginal);
		jogadorCorpo.setPosition(sf::Vector2f(200, 600));
		jogadorCorpo.setOrigin(jogadorCorpo.getLocalBounds().width / 2,
				jogadorCorpo.getLocalBounds().height / 2);
	}

	void moveJogador() {

		velocidadeX = 0;
		velocidadeY = 0;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			velocidadeX = 0.12;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			velocidadeX = -0.12;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			velocidadeY = -0.12;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			jogadorCorpo.setTexture(jogadorAgachadoTextura); // Troca a textura ao agachar
			jogadorCorpo.setScale(escalaAgachado); // Aplica a escala para a imagem agachada
			velocidadeY = 0.12;
		} else {
			jogadorCorpo.setTexture(jogadorTextura); // Retorna à textura original
			jogadorCorpo.setScale(escalaOriginal); // Retorna à escala original
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::F1)) {
			jogadorCorpo.rotate(5); // Transforma o kanguru em um sharingan, apenas um easter egg engraçadinho
		}

		jogadorCorpo.move(velocidadeX, velocidadeY); //Velocidade aplicada só após de determinar a direção

	}

};

#endif
