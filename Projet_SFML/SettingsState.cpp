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

void SettingsState::initGui()
{
	
	this->buttons["EXIT_STATE"] = new gui::Button((this->window->getSize().x / 2) - 150 * this->scale, (this->window->getSize().y / 2) + 400 * this->scale, 300 * this->scale, 50 * this->scale,
		this->font, "Quit", 20 * this->scale,
		sf::Color(70, 70, 70, 200),
		sf::Color(150, 150, 150, 255),
		sf::Color(20, 20, 20, 200)
	);
	//Init resolution settings
	std::string resolutions[] = {"1366  x 768","1600 x 900","1920 x 1080","1920 x 1200","2560 x 1440","2560 x 1600","3840 x 2160" };

	this->ddl["RESOLUTIONS"] = new gui::DropDownList("Résolution : ",(this->window->getSize().x / 2) + 150 * this->scale, (this->window->getSize().y / 2) - 200 * this->scale, 300 * this->scale, 50 * this->scale,
		&this->font, resolutions, 20 * this->scale,
		7,3);
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
	this->initGui();

}

SettingsState::~SettingsState()
{
	auto it = this->buttons.begin();
	for (it = this->buttons.begin(); it != this->buttons.end(); ++it)
	{
		delete it->second;
	}
	auto it2 = this->ddl.begin();
	for (it2 = this->ddl.begin(); it2 != this->ddl.end(); ++it2)
	{
		delete it2->second;
	}
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

void SettingsState::updateGui(const float& dt)
{
	//Update buttons==============
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
	//update Drop down lists================
	for (auto& it : this->ddl)
	{
		it.second->update(this->mousePosView,dt);
	}
}

void SettingsState::update(const float& dt)
{

	this->quit = false;
	this->updateMousePosition();
	this->updateInput(dt);
	this->updateGui(dt);


}

void SettingsState::renderGui(sf::RenderTarget* target)
{
	//Render Buttons============
	for (auto& it : this->buttons)
	{
		it.second->render(target);
	}
	//Render Drop down lists=========
	for (auto& it : this->ddl)
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
	this->renderGui(target);
}

