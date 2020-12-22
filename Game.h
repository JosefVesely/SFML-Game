#pragma once

#include <SFML/Graphics.hpp>
#include "Player.h"
#include <string>

class Game
{
public:
	~Game();

	void init(const char* title, int width, int height, bool maximize);
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