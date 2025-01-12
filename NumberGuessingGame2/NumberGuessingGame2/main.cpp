#include <iostream>
#include "Game.h"



int main() {
	Game game;
	game.NewGame();
	std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
	if (game.checkGameLives()) {
		while (game.checkAlive() && !game.checkAnswer()) {
			game.CheckAnswer();
			game.DisplayInfo(game.checkGameLives());

		}
	}
	else {
		while (game.checkAlive() && !game.checkAnswer()) {
			game.CheckAnswer();
			game.DisplayInfo();

		}
	}

}