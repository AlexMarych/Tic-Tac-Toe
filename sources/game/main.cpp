#include "core/game/Game.hpp"


int main() {
	
	Core::GameConfig config;
	config.windowTitle = "Angry Pirates";

	Core::Game game(config);
	game.Run();
}
