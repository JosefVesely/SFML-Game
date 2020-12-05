#define NOMINMAX
#include <Windows.h>
#include "Game.h"

int main()
{
	// ShowWindow(GetConsoleWindow(), SW_HIDE);
	Game game;

	while (game.running())
	{
		game.handleEvents();
		//game.update();
		game.render();
		//game.clean();
	}
}
