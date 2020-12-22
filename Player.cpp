#include "Entity.h"
#include "Player.h"

void Player::render(sf::RenderWindow& window)
{
	sf::RectangleShape rect;
	rect.setSize(sf::Vector2f(64, 64));
	rect.setFillColor(sf::Color::Red);
	rect.setPosition(16, 16);

	window.draw(rect);
}