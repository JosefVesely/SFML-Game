#include "Game.h"
#include "Entity.h"
#include <iostream>

Game::~Game()
{
	delete this->window;
}

void Game::init(const char* title, int width, int height, bool maximize = false)
{
	this->title = title;
	this->videoMode.width = width;
	this->videoMode.height = height;

	this->running = true;

	char style = maximize ? sf::Style::Default : sf::Style::Close;
	this->window = new sf::RenderWindow(this->videoMode, this->title, style);

	this->window->setFramerateLimit(60);
}

void Game::run()
{
	this->init("Game", 960, 540);

	player.setPosition(512, 256);
	player.speed = 256.f;

	while (this->running)
	{
		this->handleEvents();
		this->update();
		this->render();
	}
}

void Game::close()
{
	this->window->close();
	this->running = false;
}

void Game::handleEvents()
{
	while (this->window->pollEvent(this->evnt))
	{
		switch (this->evnt.type)
		{
		case sf::Event::Closed:
			this->close();
			break;
		}
	}

	player.handleEvents(this->dt);
}

void Game::updateDt()
{
	this->dt = this->dtClock.restart().asSeconds();
	std::cout << this->dt << std::endl;
}

void Game::update()
{
	this->updateDt();

	// Update FPS
	int fps = 1 / this->dt;
	std::string title = this->title + " FPS: " + std::to_string(fps);
	this->window->setTitle(title);

	// Update
}

void Game::render()
{
	this->window->clear(sf::Color(0, 0, 255));

	// Render
	player.render(*this->window);

	this->window->display();
}