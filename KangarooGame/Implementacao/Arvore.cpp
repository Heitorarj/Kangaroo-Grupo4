#include "../Declaracao/Arvore.h"

Arvore::Arvore() {
	arvoreTextura.loadFromFile("assets/arvore.png");
	arvoreCorpo.setTexture(arvoreTextura);
	arvoreCorpo.setScale(4, 4);
	arvoreCorpo.setOrigin(arvoreCorpo.getLocalBounds().width / 2,
			arvoreCorpo.getLocalBounds().height / 2);
}
