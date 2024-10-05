#ifndef SOM_H_
#define SOM_H_

#include "Bibliotecas.h"

class Som {
public:
	sf::SoundBuffer gotaSomBuffer, raioSomBuffer, socoSomBuffer, danoSomBuffer, sinoSomBuffer, frutaSomBuffer;
	sf::Sound gotaSom, raioSom, socoSom, danoSom, frutaSom;
	sf::Music musicaPrincipal, musicaVitoria, musicaDerrota, sinoSom;

	bool musicaPrincipalOn, musicaVitoriaOn, musicaDerrotaOn, sinoSomOn;

	Som();
	void somUpdate(int inputTelaCodigo);
};

#endif
