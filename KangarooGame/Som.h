#ifndef SOM_H_
#define SOM_H_

#include "Bibliotecas.h"

class Som {
public:
	sf::SoundBuffer gotaSomBuffer, raioSomBuffer, socoSomBuffer, danoSomBuffer,
			sinoSomBuffer, sinoSomDificilBuffer, frutaSomBuffer, pularSomBuffer, agacharSomBuffer;
	sf::Sound gotaSom, raioSom, socoSom, danoSom, sinoSom, frutaSom, pularSom,
			agacharSom;
	sf::Music musicaMenu, musicaPrincipal, musicaVitoria, musicaDerrota, andarSom;

	bool musicaMenuOn, musicaPrincipalOn, musicaPrincipalDificilOn, musicaPrincipalDificilOnCerteza, musicaVitoriaOn, musicaDerrotaOn;

	Som();
	void somMusica(int inputTelaCodigo);
};

#endif
