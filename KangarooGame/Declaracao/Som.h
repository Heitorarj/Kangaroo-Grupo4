#ifndef SOM_H_
#define SOM_H_

#include "Bibliotecas.h"

class Som {
public:
	sf::SoundBuffer gotaSomBuffer, raioSomBuffer, socoSomBuffer, danoSomBuffer,
			sinoSomBuffer, frutaSomBuffer, pularSomBuffer,
			agacharSomBuffer, QOTASomBuffer;
	sf::Sound gotaSom, socoSom, danoSom, sinoSom, frutaSom, pularSom,
			agacharSom, QOTASom;
	sf::Music musicaMenu, musicaPrincipal, musicaVitoria, musicaDerrota;

	bool musicaMenuOn, musicaPrincipalOn, musicaPrincipalDificilOn,
			musicaPrincipalDificilOnCerteza, musicaVitoriaOn, musicaDerrotaOn, cenarioRaio;

	Som();
	void somMusica(int inputTelaCodigo);
};

#endif
