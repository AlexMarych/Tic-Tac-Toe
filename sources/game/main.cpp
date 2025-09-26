#include "core/game/Game.hpp"


int main() {
	
	Core::GameConfig config;
	config.WINDOW_TITLE = "Angry Pirates";

	Core::Game game(config);
	game.Run();
}
