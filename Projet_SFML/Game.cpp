#include "Game.h"


//Static Functions

//Initializer Functions

void Game::initWindow()
{
	/*Create a window using option from a window.ini file*/

	std::ifstream ifs("Config/window.ini");

	std::string title = "None";
	sf::VideoMode window_bounds(800,600);
	unsigned framerate_limit = 60;
	bool vertical_sync_enabled = false;

	if (ifs.is_open())
	{
		std::getline(ifs, title);
		ifs >> window_bounds.width >> window_bounds.height;
		ifs >> framerate_limit;
		ifs >> vertical_sync_enabled; 
	}

	ifs.close();

	this->window = new sf::RenderWindow(window_bounds, title, sf::Style::Default);
	this->window->setFramerateLimit(framerate_limit);
	this->window->setVerticalSyncEnabled(vertical_sync_enabled);
}

void Game::initStates()
{
	this->states.push(new GameState(this->window));
}

//Constructor/Destructor
Game::Game()
{
	this->initWindow();
	this->initStates();
	
}

Game::~Game()
{
	delete this->window;

	while (!this->states.empty())
	{
		delete this->states.top();
		this->states.pop();
	}
}


//Functions

void Game::endApplaction()
{
	std::cout << "Ending application !" << "\n";
}

void Game::updateDt()
{
	this->dt = this->dtClock.restart().asSeconds();	

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

	if (!this->states.empty())
	{
		this->states.top()->update(this->dt);

		if (this->states.top()->getQuit())
		{
			this->states.top()->endState();
			delete this->states.top();
			this->states.pop();
		}
	}
	//Application end
	else
	{
		this->endApplaction();
		this->window->close();
	}
}

void Game::render()
{
	this->window->clear();

	//render items
	if (!this->states.empty())
	{
		this->states.top()->render(this->window);
	}

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

