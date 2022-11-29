#include "LoadingState.h"


void LoadingState::initBackground()
{
	this->textureBg.loadFromFile("Ressources/Sprites/Bg3.png");
	std::cout << this->textureBg.getSize().x << "\n";

	float scalebg = this->window->getSize().x / (float)(this->textureBg.getSize().x);
	this->background.setTexture(textureBg);
	this->background.setScale(scalebg, scalebg);
}

void LoadingState::initKeyBinds()
{
}

LoadingState::LoadingState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states, sf::Font font, float scale, std::string nextState)
	:State(window, supportedKeys, states), scale(scale), font(font), nextState(nextState)
{
	this->initBackground();
	load = 0.f;
}

LoadingState::~LoadingState()
{
}

//Functions

void LoadingState::endState()
{
	std::cout << "Ending loading state" << "\n";
}







void LoadingState::updateInput(const float& dt)
{
}

void LoadingState::update(const float& dt)
{

	this->quit = false;
	this->updateMousePosition();
	this->load += 10 * dt;



	if (this->nextState == "new_game")
	{
		
		if (this->load >= 15.f)
		{
			this->states->push(new GameState(this->window, this->supportedKeys, this->states, this->font, this->scale));
			this->nextState = "stop";
			this->load = 0.f;
		}
	}
	if (this->nextState == "settings")
	{
		
		if (this->load >= 0.5f)
		{
			this->states->push(new SettingsState(this->window, this->supportedKeys, this->states, this->font, this->scale));
			this->nextState = "stop";
			this->load = 0.f;

		}
	}
	if (this->nextState == "stop")
	{
		
		if (this->load >= 20.f)
		{
			this->quit = true;
		}
	}
	

}


void LoadingState::render(sf::RenderTarget* target)
{
	if (!target)
	{
		target = this->window;
	}
	target->draw(this->background);
}
