#pragma once

#include <SFML/Graphics.hpp>

class Entity
{
public:
	virtual ~Entity();

	void update();
	virtual void render(sf::RenderWindow& window) = 0;

	void setPosition(int x, int y);
	void moveX(int distance);
	void moveY(int distance);
	void setHealth(int health);

private:
	int x, y;
	int speed;
	int angle;
	int health;
	bool crouching;
	// sf::Texture sprite;
};