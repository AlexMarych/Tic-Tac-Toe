#include "Game/Game.h"

int main() {

	Core::GameConfig config;
	config.windowTitle = "Tic tac toe";

	Core::Game game(config);
	game.Run();
}