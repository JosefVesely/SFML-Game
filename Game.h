#pragma once
#include <SFML/Graphics.hpp>

class Game
{
public:
	Game();
	~Game();

	void init(const char* title, int width, int height);
	void run();
	void close();

	void handleEvents();
	void updateDt();
	void update();
	void render();

private:
	bool isRunning = true;

	sf::RenderWindow* window;
	sf::Event evnt;

	sf::Clock dtClock;
	float dt;
};
