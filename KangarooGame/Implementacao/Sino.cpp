#include "../Declaracao/Sino.h"

Sino::Sino() {
	sinoTextura.loadFromFile("assets/sino.png");
	sinoCorpo.setTexture(sinoTextura);
	sinoCorpo.setOrigin(sinoCorpo.getLocalBounds().width / 2,
			sinoCorpo.getLocalBounds().height / 2);
	sinoCorpo.setScale(0.06, 0.06);
}
