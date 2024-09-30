#ifndef PTEMPO_H_
#define PTEMPO_H_

#include "PJogador.h"

class Tempo {
public:
	sf::Clock deltaTimeObject;
	float deltaTime;

	Tempo();
	void updateDeltaTime();
};

#endif
