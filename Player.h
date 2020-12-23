#pragma once

#include "Entity.h"

class Player : public Entity
{
public:
	void render(sf::RenderWindow& window);
	void handleEvents(float dt);
};