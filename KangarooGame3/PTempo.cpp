#include "PTempo.h"

Tempo::Tempo() {
	deltaTime = deltaTimeObject.restart().asSeconds();
}

void Tempo::updateDeltaTime() {
	deltaTime = deltaTimeObject.restart().asSeconds();
}
