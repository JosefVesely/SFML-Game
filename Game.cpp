#include "Game.h"
#include <iostream>

Game::Game()
{
	this->init("Game", 800, 600);
}

Game::~Game()
{
	delete this->window;
}

void Game::init(const char* title, int width, int height)
{
	this->window = new sf::RenderWindow(sf::VideoMode(width, height), title, sf::Style::Close);
}

void Game::run()
{
	while (this->isRunning)
	{
		this->handleEvents();
		this->updateDt();
		this->update();
		this->render();
	}
}

void Game::close()
{
	this->isRunning = false;
}

void Game::handleEvents()
{
	while (this->window->pollEvent(this->evnt))
	{
		switch (evnt.type)
		{
		case sf::Event::Closed:
			this->close();
			break;

		case sf::Event::KeyPressed:
			if (evnt.key.code == sf::Keyboard::Escape)
				this->close();
			break;
		}
	}
}

// Update delta time
void Game::updateDt()
{
	this->dt = this->dtClock.restart().asSeconds();
}

void Game::update()
{
	// Update FPS
	int fps = 1.f / this->dt;
	this->window->setTitle(std::to_string(fps));
}

void Game::render()
{
	this->window->clear(sf::Color(0, 0, 255));

	// Render

	this->window->display();
}
