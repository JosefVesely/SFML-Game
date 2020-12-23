#include "Entity.h"
#include <SFML/Graphics.hpp>

Entity::~Entity()
{

}

void Entity::update() {}

void Entity::render(sf::RenderWindow& window)
{
	sf::RectangleShape rect;
	rect.setSize(sf::Vector2f(32, 32));
	rect.setFillColor(sf::Color::Red);
	rect.setPosition(this->x, this->y);

	window.draw(rect);
}

void Entity::handleEvents(float dt) {}

void Entity::setPosition(int x, int y)
{
	this->x = x; this->y = y;
}

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