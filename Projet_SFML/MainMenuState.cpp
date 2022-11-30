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
	this->buttons["GAME_STATE"] = new gui::Button((this->window->getSize().x / 2) - 150 * this->scale, (this->window->getSize().y / 2) - 100 * this->scale, 300 * this->scale, 50 * this->scale,
		this->font, "New Game", 20 * this->scale,
		sf::Color(70, 70, 70, 200),
		sf::Color(150, 150, 150, 255),
		sf::Color(20, 20, 20, 200)
	);
	this->buttons["SETTINGS"] = new gui::Button((this->window->getSize().x / 2) - 150 * this->scale, (this->window->getSize().y / 2), 300 * this->scale, 50 * this->scale,
		this->font, "Settings", 20 * this->scale,
		sf::Color(70, 70, 70, 200),
		sf::Color(150, 150, 150, 255),
		sf::Color(20, 20, 20, 200)
	);
	this->buttons["EXIT_STATE"] = new gui::Button((this->window->getSize().x / 2) - 150 * this->scale, (this->window->getSize().y / 2) + 100 * this->scale, 300 * this->scale, 50 * this->scale,
		this->font, "Quit", 20 * this->scale,
		sf::Color(70, 70, 70, 200),
		sf::Color(150, 150, 150, 255),
		sf::Color(20, 20, 20, 200)
	);
	
}

void MainMenuState::initBackground()
{
	this->textureBg.loadFromFile("Ressources/Sprites/Bg2.png");
	std::cout << this->textureBg.getSize().x << "\n";

	this->scale = this->window->getSize().x / 1920.f;
	float scalebg = this->window->getSize().x / (float)(this->textureBg.getSize().x);
	this->background.setTexture(textureBg);
	this->background.setScale(scalebg,scalebg);
}


MainMenuState::MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states)
	:State(window, supportedKeys, states)
{
	this->initFonts();
	this->initKeyBinds();
	this->initBackground();
	this->initButtons();

	std::ifstream ifs("Config/window.ini");
	std::string title = "None";
	if (ifs.is_open())
	{
		std::getline(ifs, title);
	}
	ifs.close();
	this->titleBox.setPosition(sf::Vector2f(((this->window->getSize().x / 2) - 400) * this->scale, 100 * this->scale));
	this->titleBox.setSize(sf::Vector2f(800, 100));
	this->titleBox.setFillColor(sf::Color(0, 0, 0, 50));
	this->title.setFont(this->font);
	this->title.setString(title);
	this->title.setFillColor(sf::Color::Black);
	this->title.setCharacterSize(50 * this->scale);
	this->title.setPosition(
		this->titleBox.getPosition().x + (this->titleBox.getGlobalBounds().width / 2.f) - this->title.getGlobalBounds().width / 2.f,
		this->titleBox.getPosition().y + (this->titleBox.getGlobalBounds().height) / 2.f - this->title.getGlobalBounds().height / 2.f
	);
	
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
		this->states->push(new GameState(this->window, this->supportedKeys, this->states, this->font, this->scale));
	}
	
	//Settings
	if (this->buttons["SETTINGS"]->isPressed())
	{
		this->states->push(new SettingsState(this->window, this->supportedKeys, this->states, this->font, this->scale));
	}

	//Quit the Game
	if (this->buttons["EXIT_STATE"]->isPressed())
	{
		this->quit = true;
		std::cout << this->quit << " Main menu update button  " << states->size() << "\n";
	}
}

void MainMenuState::update(const float& dt)
{
	
	this->quit = false;
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
	target->draw(this->titleBox);
	target->draw(this->title);
	this->renderButtons(target);
}


