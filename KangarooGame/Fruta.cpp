#include "Fruta.h"

Fruta::Fruta() {
	frutaTextura.loadFromFile("assets/fruta.png");
	frutaCorpo.setTexture(frutaTextura);
	frutaCorpo.setScale(0.04, 0.04);
	frutaCorpo.setOrigin(frutaCorpo.getLocalBounds().width / 2,
			frutaCorpo.getLocalBounds().height / 2);
	valorPontos[0] = 100;
	valorPontos[1] = 200;
	valorPontos[2] = 500;
	valorPontos[3] = 1000;
	numeroTextura = 0;
}

