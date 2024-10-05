#include "Som.h"

Som::Som() {
	gotaSomBuffer.loadFromFile("assets/gota.wav");
	gotaSom.setBuffer(gotaSomBuffer);

	raioSomBuffer.loadFromFile("assets/legal.wav");
	raioSom.setBuffer(raioSomBuffer);

	socoSomBuffer.loadFromFile("assets/legal.wav");
	socoSom.setBuffer(socoSomBuffer);

	danoSomBuffer.loadFromFile("assets/legal.wav");
	danoSom.setBuffer(danoSomBuffer);

	frutaSomBuffer.loadFromFile("assets/legal.wav");
	frutaSom.setBuffer(frutaSomBuffer);

	sinoSom.openFromFile("assets/legal.wav");
	sinoSom.setLoop(true);

	musicaPrincipal.openFromFile("assets/rain.wav");
	musicaPrincipal.setLoop(true);

	musicaVitoria.openFromFile("assets/rain.wav");
	musicaVitoria.setLoop(true);

	musicaDerrota.openFromFile("assets/derrota.wav");
	musicaDerrota.setLoop(true);

	musicaPrincipalOn = false;
	musicaVitoriaOn = false;
	musicaDerrotaOn = false;
	sinoSomOn = false;

}

void Som::somUpdate(int inputTelaCodigo) {
	switch (inputTelaCodigo) {
	case -1:

		break;

	case 0:

		if (musicaPrincipalOn == false) {
			musicaPrincipal.play();
			musicaPrincipalOn = true;
		}

		break;
	case 1:

		if (musicaVitoriaOn == false) {
			musicaPrincipal.pause();
			musicaVitoria.play();
			musicaVitoriaOn = true;
		}

		break;

	case 2:

		if (musicaDerrotaOn == false) {
			musicaPrincipal.pause();
			musicaDerrota.play();
			musicaDerrotaOn = true;
		}

		break;

	}

	if (sinoSomOn == true) {
		sinoSom.play();
		sinoSomOn = false;
	}
}

