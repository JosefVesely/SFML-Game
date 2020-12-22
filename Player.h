#pragma once

#include "Entity.h"

class Player : public Entity
{
public:
	void render(sf::RenderWindow& window);
};