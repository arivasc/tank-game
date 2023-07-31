#include "Game.h"

int main()
{
	//inicializar la raiz de ramdom
	srand(static_cast<unsigned>(time(0)));

	//inicializar la Clase Game
	Game game;

	//Funcion para correr el juego
	game.run();
}