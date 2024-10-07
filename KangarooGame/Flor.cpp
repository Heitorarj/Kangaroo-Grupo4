#include "Flor.h"

Flor::Flor() {
	florTextura.loadFromFile("assets/flor.png");
	florCorpo.setTexture(florTextura);
	florCorpo.setScale(3, 3);
	florCorpo.setOrigin(florCorpo.getLocalBounds().width / 2,
			florCorpo.getLocalBounds().height / 2);
}
