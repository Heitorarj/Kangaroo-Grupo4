#ifndef MOVEIS_HPP_
#define MOVEIS_HPP_

class Tempo {
public:
	sf::Clock deltaTimeObject;
	float deltaTime;

	Tempo();
	void updateDeltaTime();
};

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
	void moveJogador(float deltaTime);
};

class Nuvem {
public:
	float velocidadeX;
	sf::Texture nuvemTextura;
	sf::Sprite nuvemCorpo;

	Nuvem();
};

class NuvemInimiga: public Nuvem {
public:
	float velocidadeX, tiroVelocidadeY;
	sf::Texture nuvemTiroTextura;
	sf::Sprite nuvemTiro;
	sf::RectangleShape hitboxNuvemInimiga;

	NuvemInimiga();
	void moverTiro();
	void nuvemAtacar(Jogador &inputJogador);
};

class Filhote {
public:
	sf::Texture filhoteTextura;
	sf::Sprite filhoteCorpo;
	sf::RectangleShape filhoteHitbox;
	float velocidadeX;

	Filhote();
};
#endif
