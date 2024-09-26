
#include "Jogo.hpp"
#include "Moveis.hpp"
#include "Cenario.hpp"

int main() {

	sf::RenderWindow janela(sf::VideoMode(1100, 800), "Kangaroo Game");
	std::vector<Parede> minhasParedes;
	std::vector<Escada> minhasEscadas;
	std::vector<Fruta> minhasFrutas;
	std::vector<Arvore> minhasArvores;
	std::vector<Flor> minhasFlores;
	std::vector<Nuvem> minhasNuvens;
	Jogador meuJogador;
	Texto meuTexto;
	srand(time(NULL));

	criarMapa(1, &minhasParedes, &minhasEscadas, &minhasFrutas, &minhasArvores,
			&minhasFlores, &minhasNuvens, &janela);

	while (janela.isOpen()) {

		sf::Event evento;

		while (janela.pollEvent(evento)) {
			if (evento.type == sf::Event::Closed) {
				janela.close();
			}
		}

		meuJogador.moveJogador();
		moverNuvem(1, minhasNuvens);
		janela.clear(sf::Color(168, 231, 240));
		checarColisaoFruta(&meuJogador, minhasFrutas, &meuTexto);
		desenharMapa(1, minhasParedes, minhasEscadas, minhasFrutas,
				minhasArvores, minhasFlores, minhasNuvens, &janela);
		janela.draw(meuJogador.jogadorCorpo);
		janela.draw(meuJogador.jogadorHitbox);
		janela.draw(meuTexto.retanguloCenario);
		janela.draw(meuTexto.texto);
		janela.display();
	}
}
