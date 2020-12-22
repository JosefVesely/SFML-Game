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

void Entity::setPosition(int x, int y)
{
	this->x = x; this->y = y;
}

void Entity::moveX(int distance)
{
	this->x += distance;
}

void Entity::moveY(int distance)
{
	this->y += distance;
}

void Entity::setHealth(int health)
{
	this->health = health;
}
