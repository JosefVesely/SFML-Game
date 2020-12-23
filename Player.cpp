#include "Entity.h"
#include "Player.h"

void Player::render(sf::RenderWindow& window)
{
	sf::RectangleShape rect;
	rect.setSize(sf::Vector2f(48, 48));
	rect.setFillColor(sf::Color::Red);
	rect.setPosition(this->x, this->y);

	window.draw(rect);
}

void Player::handleEvents(float dt)
{
	// Movement
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		this->moveY(dt * -this->speed);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		this->moveY(dt * this->speed);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		this->moveX(dt * -this->speed);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		this->moveX(dt * this->speed);
	}
}