#include <SFML/Graphics.hpp>
#include "Entity.h"

Entity::~Entity()
{

}

void Entity::update() {}

void Entity::render(sf::RenderWindow& window)
{
	sf::RectangleShape rect;
	rect.setSize(sf::Vector2f(this->width, this->height));
	rect.setFillColor(sf::Color::Red);
	rect.setPosition(this->x, this->y);

	window.draw(rect);
}

void Entity::handleEvents(float dt) {}

void Entity::move(int distX, int distY)
{
	this->x += distX; this->y += distY;
}

void Entity::moveX(int dist)
{
	this->x += dist;
}

void Entity::moveY(int dist)
{
	this->y += dist;
}

// Getters
int Entity::getX()
{
	return this->x;
}

int Entity::getY()
{
	return this->y;
}

// Setters
void Entity::setPosition(int x, int y)
{
	this->x = x; this->y = y;
}

void Entity::setSpeed(float speed)
{
	this->speed = speed;
}