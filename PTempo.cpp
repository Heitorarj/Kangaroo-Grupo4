#include "PTempo.h"

Tempo::Tempo() {
	deltaTime = 0;
}

void Tempo::updateDeltaTime() {
	deltaTime = deltaTimeObject.restart().asSeconds();
}
