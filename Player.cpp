#include <SFML/Graphics.hpp>
#include <iostream>
#include "math.h"

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

	this->angle = this->getAngle(mousePos);
}

int Player::getAngle(sf::Vector2i mousePos)
{
	int deltaX = (this->x + this->width / 2) - mousePos.x;  // x2 - x1
	int deltaY = (this->y + this->height / 2) - mousePos.y; // y2 - y1

	return math::toDegrees(math::atan2(deltaY, deltaX));
}

void Player::render(sf::RenderWindow& window)
{
	// Rectangle
	sf::RectangleShape rect;
	rect.setSize(sf::Vector2f(this->width, this->height));
	rect.setFillColor(sf::Color(255, 50, 150));
	rect.setPosition(this->x, this->y);
	
	// Rotate rectangle
	sf::Transform transform;
	transform.rotate(this->angle, { static_cast<float>(xCenter), static_cast<float>(yCenter) });

	window.draw(rect, transform);

	// Line from player to mouse
	sf::Vertex line[] =
	{
		sf::Vertex(sf::Vector2f(xCenter, yCenter)),
		sf::Vertex(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)))
	};
	window.draw(line, 2, sf::Lines);

	// TODO: Create health bar object
	// Render health bar
	int hb_x = 16;
	int hb_y = 16;
	int hb_tilt = 24;
	int hb_width = 256;
	int hb_height = 24;

	sf::ConvexShape hb;
	hb.setPosition(0, 0);
	hb.setFillColor(sf::Color(255, 0, 0));
	hb.setPointCount(4);
	hb.setPoint(0, sf::Vector2f(hb_x + hb_tilt,			   hb_y            ));
	hb.setPoint(1, sf::Vector2f(hb_y + hb_width + hb_tilt, hb_x            ));
	hb.setPoint(2, sf::Vector2f(hb_y + hb_width,		   hb_x + hb_height));
	hb.setPoint(3, sf::Vector2f(hb_x,					   hb_y + hb_height));
	window.draw(hb);

	if (this->health > 0)
	{
		hb.setFillColor(sf::Color(0, 255, 0));
		hb.setPoint(1, sf::Vector2f(this->health * (hb_width / 100.f) + hb_y + hb_tilt, hb_x			));
		hb.setPoint(2, sf::Vector2f(this->health * (hb_width / 100.f) + hb_y,           hb_x + hb_height));
		window.draw(hb);
	}
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
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		this->health--;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
	{
		this->setHealth(100);
	}
}