#ifndef JOGO_HPP_
#define JOGO_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "Cenario.hpp"

void criaFase(int numeroFase, Parede *inputParede, Escada *inputEscada);
void desenhaFase(Parede inputParede, Escada inputEscada, sf::RenderWindow *inputJanela);

#endif
