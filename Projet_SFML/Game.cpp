#include "Game.h"


//Static Functions

//Initializer Functions

void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "Pokémon Cynthia", sf::Style::Default);
}

//Constructor/Destructor
Game::Game()
{
	this->initWindow();
}

Game::~Game()
{
	delete this->window;
}


//Functions

void Game::updateDt()
{
	this->dt = this->dtClock.getElapsedTime().asSeconds();	
}

void Game::updateSFMLEvents()
{
	while (this->window->pollEvent(this->sfEvent))
	{
		if (this->sfEvent.type == sf::Event::Closed)
			this->window->close();
	}
}

void Game::update()
{
	/*Update dt variable with the time elapsed to update and render in one frame*/

	this->updateSFMLEvents();
}

void Game::render()
{
	this->window->clear();
	this->window->display();
}

void Game::run()
{
	while (this->window->isOpen())
	{
		this->updateDt();
		this->update();
		this->render();
	}
}

