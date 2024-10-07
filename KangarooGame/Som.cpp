#include "Som.h"

Som::Som() {
	gotaSomBuffer.loadFromFile("assets/gota.wav");
	gotaSom.setBuffer(gotaSomBuffer);

	raioSomBuffer.loadFromFile("assets/raio.wav");
	raioSom.setBuffer(raioSomBuffer);

	socoSomBuffer.loadFromFile("assets/agachar.wav");
	socoSom.setBuffer(socoSomBuffer);

	danoSomBuffer.loadFromFile("assets/dano.wav");
	danoSom.setBuffer(danoSomBuffer);

	frutaSomBuffer.loadFromFile("assets/frutaColetar.wav");
	frutaSom.setBuffer(frutaSomBuffer);

	pularSomBuffer.loadFromFile("assets/agachar.wav");
	pularSom.setBuffer(pularSomBuffer);

	pularSomBuffer.loadFromFile("assets/pulo.wav");
	pularSom.setBuffer(pularSomBuffer);

	sinoSomBuffer.loadFromFile("assets/sinoNormal.wav");
	sinoSomDificilBuffer.loadFromFile("assets/sinoDificil.wav");
	sinoSom.setBuffer(sinoSomBuffer);

	musicaMenu.openFromFile("assets/menu.wav");
	musicaMenu.setLoop(true);

	musicaPrincipal.openFromFile("assets/jogo.wav");
	musicaPrincipal.setLoop(true);

	musicaVitoria.openFromFile("assets/vitoria.wav");

	musicaDerrota.openFromFile("assets/derrota.wav");

	musicaMenuOn = false;
	musicaPrincipalOn = false;
	musicaPrincipalDificilOn = false;
	musicaPrincipalDificilOnCerteza = false;
	musicaVitoriaOn = false;
	musicaDerrotaOn = false;

}

void Som::somMusica(int inputTelaCodigo) {
	switch (inputTelaCodigo) {
	case -1:

		if (musicaMenuOn == false) {
			musicaMenu.play();
			musicaMenuOn = true;
		}

		break;

	case 0:

		if (musicaPrincipalOn == false) {
			musicaMenu.pause();
			musicaPrincipal.play();
			musicaPrincipalOn = true;
		}

		if ((musicaPrincipalDificilOn == true) and (musicaPrincipalOn == true) and ((musicaPrincipalDificilOnCerteza == false))) {
			musicaPrincipal.openFromFile("assets/musicaDificil.wav");
			musicaPrincipal.setVolume(50);
			musicaPrincipal.pause();
			musicaPrincipal.play();
			musicaPrincipalDificilOnCerteza = true;
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
}

