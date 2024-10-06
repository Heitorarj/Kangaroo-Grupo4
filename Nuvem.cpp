#include "Nuvem.h"

Nuvem::Nuvem() {

	nuvemTextura.loadFromFile("assets/nuvem.png");
	nuvemCorpo.setTexture(nuvemTextura);
	nuvemCorpo.setScale(5, 5);
	nuvemCorpo.setOrigin(nuvemCorpo.getLocalBounds().width / 2,
			nuvemCorpo.getLocalBounds().height / 2);
	velocidadeX = 3;
}
