#pragma once

#include <SFML/Graphics.hpp>

class Entity
{
public:
	virtual ~Entity();

	void update();
	virtual void render(sf::RenderWindow& window) = 0;
	virtual void handleEvents(float dt) = 0;

	void move(int distX, int distY);
	void moveX(int distX);
	void moveY(int distY);
	
	void setPosition(int x, int y);

//private:
	int x, y;
	float speed;
	int angle;
	int health;
	bool crouching;
	// sf::Texture sprite;
};