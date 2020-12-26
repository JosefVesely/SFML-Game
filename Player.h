#pragma once

#include "Entity.h"

class Player : public Entity
{
public:
	Player();

	void update(sf::Vector2i mousePos);
	void render(sf::RenderWindow& window);
	void handleEvents(float dt);
	int getAngle(sf::Vector2i mousePos);

private:
	int angle;
};