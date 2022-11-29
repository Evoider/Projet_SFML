#include "SettingsState.h"


void SettingsState::initKeyBinds()
{

	std::ifstream ifs("Config/SettingsState_keybinds.ini");
	if (ifs.is_open())
	{
		std::string key = "";
		std::string key_name = "";

		while (ifs >> key >> key_name)
		{
			this->keyBinds[key] = this->supportedKeys->at(key_name);
		}
	}

	ifs.close();

	this->keyBinds["CLOSE"] = this->supportedKeys->at("Escape");
}

void SettingsState::initButtons()
{
	
	this->buttons["EXIT_STATE"] = new gui::Button((this->window->getSize().x / 2) - 150 * this->scale, (this->window->getSize().y / 2) + 400 * this->scale, 300 * this->scale, 50 * this->scale,
		this->font, "Quit", 20 * this->scale,
		sf::Color(70, 70, 70, 200),
		sf::Color(150, 150, 150, 255),
		sf::Color(20, 20, 20, 200)
	);

}

void SettingsState::initBackground()
{
	this->textureBg.loadFromFile("Ressources/Sprites/Bg4.png");
	std::cout << this->textureBg.getSize().x << "\n";

	float scalebg = this->window->getSize().x / (float)(this->textureBg.getSize().x);
	this->background.setTexture(textureBg);
	this->background.setScale(scalebg, scalebg);
}

SettingsState::SettingsState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states, sf::Font font, float scale)
	:State(window, supportedKeys, states),scale(scale),font(font)
{
	this->initKeyBinds();
	this->initBackground();
	this->initButtons();

}

SettingsState::~SettingsState()
{
}

//Functions

void SettingsState::endState()
{
	std::cout << "Ending settings state" << "\n";
}

void SettingsState::updateInput(const float& dt)
{


	//Check for key pressed

}

void SettingsState::updateButtons()
{

	for (auto& it : this->buttons)
	{
		it.second->update(this->mousePosView);
	}

	/*Action of the Button*/

	//Exit the settings
	if (this->buttons["EXIT_STATE"]->isPressed())
	{
		this->quit = true;
		std::cout << this->quit << " settings menu update button  " << states->size() << "\n";
	}
}

void SettingsState::update(const float& dt)
{

	this->quit = false;
	this->updateMousePosition();
	this->updateInput(dt);
	this->updateButtons();


}

void SettingsState::renderButtons(sf::RenderTarget* target)
{

	for (auto& it : this->buttons)
	{
		it.second->render(target);
	}
}

void SettingsState::render(sf::RenderTarget* target)
{
	if (!target)
	{
		target = this->window;
	}
	target->draw(this->background);
	this->renderButtons(target);
}

