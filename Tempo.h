#ifndef TEMPO_H_
#define TEMPO_H_

#include "Jogador.h"

class Tempo {
public:
	sf::Clock deltaTimeObject;
	float deltaTime;

	Tempo();
	void updateDeltaTime();
};

#endif
