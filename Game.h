#pragma once
#include <SFML/Graphics.hpp>

class Game
{
public:
	Game();
	~Game();

	void init(const char* title, int width, int height, bool fullscreen);

	void handleEvents();
	void update();
	void render();
	void clean();

	bool running();

private:
	bool isRunning = true;
	sf::RenderWindow* window;
	sf::Event evnt;
};
