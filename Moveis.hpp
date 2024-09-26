
#ifndef MOVEIS_HPP_
#define MOVEIS_HPP_

class Movel {
public:
	float velocidadeX, velocidadeY;
};

class Jogador: public Movel {
public:
	sf::Texture jogadorTextura;
	sf::Texture jogadorTexturaGirado;
	sf::Texture jogadorAgachadoTextura;
	sf::Sprite jogadorCorpo;
	sf::RectangleShape jogadorHitbox;
	sf::Vector2f escalaOriginal;
	sf::Vector2f escalaAgachado;
	int pontos;

	Jogador();
	void moveJogador();
};

class Nuvem: public Movel {
public:
	float velocidadeX;
	sf::Texture nuvemTextura;
	sf::Sprite nuvemCorpo;

	Nuvem();
	void moverNuvem();
};
#endif
