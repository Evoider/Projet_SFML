#include "Game.h"


//Static Functions

//Initializer Functions

void Game::initVariables()
{
	this->window = NULL;
	this->dt = 0.f;
}

void Game::initGraphicsSettings()
{
	this->graphSettings.loadFromFile("Config/graphics.ini");
}

void Game::initWindow()
{

	if (this->graphSettings.fullscreen)
	{
		this->window = new sf::RenderWindow(this->graphSettings.resolution,
			this->graphSettings.title,
			sf::Style::Fullscreen,
			this->graphSettings.contextSettings);
	}
	else
	{
		this->window = new sf::RenderWindow(
			this->graphSettings.resolution,
			this->graphSettings.title, 
			sf::Style::Titlebar|sf::Style::Close,
			this->graphSettings.contextSettings);
	}
	
	this->window->setFramerateLimit(this->graphSettings.frameRateLimit);
	this->window->setVerticalSyncEnabled(this->graphSettings.verticaleSync);
}

void Game::initKeys()
{
	std::ifstream ifs("Config/supported_keys.ini");
	if (ifs.is_open())
	{
		std::string key = "";
		int key_value = 0;

		while (ifs >> key >> key_value)
		{
			this->supportedKeys[key] = key_value;
		}
	}
	
}

void Game::initStates()
{
	this->states.push(new MainMenuState(this->window,this->graphSettings,&this->supportedKeys, &this->states));
}


//Constructor/Destructor
Game::Game()
{
	this->initVariables();
	this->initGraphicsSettings();
	this->initWindow();
	this->initKeys();
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
	/*Update dt variable with the time elapsed to update and render in one frame*/
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
	
	
	this->updateSFMLEvents();
	if (!this->states.empty())
	{
		if (this->graphSettings.changed)
		{
			if (this->graphSettings.fullscreen)
			{
				this->window->create(this->graphSettings.resolution,
					this->graphSettings.title,
					sf::Style::Fullscreen,
					this->graphSettings.contextSettings);
			}
			else
			{
				this->window->create(
					this->graphSettings.resolution,
					this->graphSettings.title,
					sf::Style::Titlebar | sf::Style::Close,
					this->graphSettings.contextSettings);
			}

			this->window->setFramerateLimit(this->graphSettings.frameRateLimit);
			this->window->setVerticalSyncEnabled(this->graphSettings.verticaleSync);

			this->states.top()->updateWindow(this->window);
			this->graphSettings.changed = false;
		}
		this->states.top()->update(this->dt);

		if (this->states.top()->getQuit())
		{
			
			auto *to_delete = this->states.top();
			this->states.pop();
			delete to_delete;
			if (!this->states.empty())
				this->states.top()->updateWindow(this->window);
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

