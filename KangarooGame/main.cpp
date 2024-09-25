#include "Jogo.hpp"
#include "Moveis.hpp"
#include "Cenario.hpp"

int main() {

	sf::RenderWindow janela(sf::VideoMode(1100, 800), "Kangaroo Game");
	Parede minhasParedes;
	Escada minhasEscadas;
	Fruta minhasFrutas;
	Arvore minhasArvores;
	Flor minhasFlores;
	Nuvem minhasNuvens;
	Jogador meuJogador;
	Texto meuTexto;

	criaFase(1, &minhasParedes, &minhasEscadas, &minhasFrutas, &minhasArvores, &minhasFlores, &minhasNuvens);

	while (janela.isOpen()) {

		sf::Event evento;

		while (janela.pollEvent(evento)) {
			if (evento.type == sf::Event::Closed) {
				janela.close();
			}
		}

		meuJogador.moveJogador();
		minhasNuvens.moverNuvem();
		janela.clear(sf::Color(168, 231, 240));
		girar(&minhasParedes, &minhasEscadas, &minhasFrutas, &minhasArvores, &minhasFlores, &minhasNuvens);
		checarColisaoFruta(&meuJogador, &minhasFrutas, &meuTexto);
		desenhaFase(minhasParedes, minhasEscadas, &minhasFrutas, &minhasArvores, &minhasFlores, &minhasNuvens, &janela, 1);
		janela.draw(meuJogador.jogadorCorpo);
		janela.draw(meuJogador.jogadorHitbox);
		janela.draw(meuTexto.retanguloCenario);
		janela.draw(meuTexto.texto);
		janela.display();
	}
}
