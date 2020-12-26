#include <SFML/Graphics.hpp>
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h> // atan2, M_PI

#include "Entity.h"
#include "Player.h"

Player::Player()
{
	this->angle = 0;
	this->width = this->height = 32;
}

void Player::update(sf::Vector2i mousePos)
{
	xCenter = this->x + this->width / 2;
	yCenter = this->y + this->height / 2;

	std::cout << "Angle: " << getAngle(mousePos) << '\n';
}

int Player::getAngle(sf::Vector2i mousePos)
{
	// angle - int in range from -179 to 179
	int deltaX = (this->x + this->width / 2) - mousePos.x;  // x2 - x1
	int deltaY = (this->y + this->height / 2) - mousePos.y; // y2 - y1

	return atan2(deltaY, deltaX) * 180 / M_PI; // convert angle from radians to degrees
}

void Player::render(sf::RenderWindow& window)
{
	// Rectangle
	sf::RectangleShape rect;
	rect.setSize(sf::Vector2f(this->width, this->height));
	rect.setFillColor(sf::Color::Red);
	rect.setPosition(this->x, this->y);

	window.draw(rect);

	// Line from player to mouse
	sf::Vertex line[] =
	{
		sf::Vertex(sf::Vector2f(xCenter, yCenter)),
		sf::Vertex(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)))
	};
	window.draw(line, 2, sf::Lines);
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