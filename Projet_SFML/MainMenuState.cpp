#include "MainMenuState.h"


void MainMenuState::initFonts()
{
	if (!this->font.loadFromFile("Fonts/Pokemon-Solid.ttf"))
	{
		std::cout << "ERROR::MAINMENUSTATE::COULD NOT LOAD FONT" << "\n";
	}
}

void MainMenuState::initKeyBinds()
{

	std::ifstream ifs("Config/mainmenustate_keybinds.ini");
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

void MainMenuState::initButtons()
{
	this->buttons["GAME_STATE"] = new Button((this->window->getSize().x / 2) - 150 * this->scale, (this->window->getSize().y / 2) - 100 * this->scale, 300 * this->scale, 50 * this->scale,
		this->font, "New Game", 20 * this->scale,
		sf::Color(70, 70, 70, 200),
		sf::Color(150, 150, 150, 255),
		sf::Color(20, 20, 20, 200)
	);
	this->buttons["SETTINGS"] = new Button((this->window->getSize().x / 2) - 150 * this->scale, (this->window->getSize().y / 2) , 300 * this->scale, 50 * this->scale,
		this->font, "Settings", 20 * this->scale,
		sf::Color(70, 70, 70, 200),
		sf::Color(150, 150, 150, 255),
		sf::Color(20, 20, 20, 200)
	);
	this->buttons["EXIT_STATE"] = new Button((this->window->getSize().x / 2)-150 * this->scale, (this->window->getSize().y / 2) + 100 * this->scale, 300 * this->scale, 50 * this->scale,
		this->font, "Quit", 20 * this->scale,
		sf::Color(70, 70, 70, 200),
		sf::Color(150, 150, 150, 255),
		sf::Color(20, 20, 20, 200)
	);
	
}

void MainMenuState::initSprite()
{
	this->textureBg.loadFromFile("Ressources/Sprites/Bg2.png");
	std::cout << this->textureBg.getSize().x << "\n";

	this->scale = this->window->getSize().x / (float)(this->textureBg.getSize().x);

	this->background.setTexture(textureBg);
	this->background.setScale(this->scale, this->scale);
}


MainMenuState::MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states)
	:State(window, supportedKeys, states)
{
	
	this->initFonts();
	this->initKeyBinds();
	this->initSprite();
	this->initButtons();

	std::cout << this->scale << "\n";

	
}

MainMenuState::~MainMenuState()
{
	auto it = this->buttons.begin();
	for (it = this->buttons.begin(); it != this->buttons.end(); ++it)
	{
		delete it->second;
	}
}




//Functions

void MainMenuState::endState()
{
	std::cout << "Ending menu state" << "\n";
}

void MainMenuState::updateInput(const float& dt)
{

	//Check for key pressed
	
}

void MainMenuState::updateButtons()
{
	
	for (auto &it : this->buttons)
	{
		it.second->update(this->mousePosView);
	}

	/*Action of the Button*/

	//New Game
	if (this->buttons["GAME_STATE"]->isPressed())
	{
		this->states->push(new GameState(this->window, this->supportedKeys,this->states, this->font, this->scale));
	}

	//Quit the Game
	if (this->buttons["EXIT_STATE"]->isPressed())
	{
		this->quit = true;
	}
}

void MainMenuState::update(const float& dt)
{
	this->updateMousePosition();
	this->updateInput(dt);

	this->updateButtons();

	
}

void MainMenuState::renderButtons(sf::RenderTarget* target)
{
	
	for (auto& it : this->buttons)
	{
		it.second->render(target);
	}
}

void MainMenuState::render(sf::RenderTarget* target)
{
	if (!target)
	{
		target = this->window;
	}
	target->draw(this->background);
	this->renderButtons(target);
}


