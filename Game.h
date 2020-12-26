#pragma once

#include <SFML/Graphics.hpp>
#include <string>

#include "Player.h"

class Game
{
public:
	~Game();

	void initWindow(const char* title, int width, int height, bool maximize = false);
	void init();
	void run();
	void close();

	void handleEvents();
	void update();
	void updateDt();
	void render();

private:
	bool running;
	std::string title;

	Player player;

	sf::RenderWindow* window;
	sf::VideoMode videoMode;

	sf::Event evnt;
	sf::Clock dtClock;
	float dt; // Delta time
};