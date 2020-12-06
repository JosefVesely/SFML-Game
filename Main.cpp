#define NOMINMAX
#include <Windows.h>
#include "Game.h"

int main()
{
	// ShowWindow(GetConsoleWindow(), SW_HIDE);
	Game game;
	game.run();
}
