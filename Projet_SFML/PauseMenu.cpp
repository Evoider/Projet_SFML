#include "PauseMenu.h"
void PauseMenu::initButtons()
{
	this->buttons["POKEDEX"] = new gui::Button((this->window->getSize().x / 2) - 150 * this->scale, (this->window->getSize().y / 2) - 400 * this->scale, 300 * this->scale, 50 * this->scale,
		this->font, "Pokedex", 20 * this->scale,
		sf::Color(70, 70, 70, 200),
		sf::Color(150, 150, 150, 255),
		sf::Color(20, 20, 20, 200),
		sf::Color(0, 0, 235, 255), 10 * this->scale
	);
	this->buttons["SETTINGS"] = new gui::Button((this->window->getSize().x / 2) - 150 * this->scale, (this->window->getSize().y / 2) + 300 * this->scale, 300 * this->scale, 50 * this->scale,
		this->font, "Settings", 20 * this->scale,
		sf::Color(70, 70, 70, 200),
		sf::Color(150, 150, 150, 255),
		sf::Color(20, 20, 20, 200),
		sf::Color(0, 0, 235, 255), 10 * this->scale
	);
	this->buttons["EXIT_PAUSE"] = new gui::Button((this->window->getSize().x / 2) - 150 * this->scale, (this->window->getSize().y / 2) + 200 * this->scale, 300 * this->scale, 50 * this->scale,
		this->font, "Continue", 20 * this->scale,
		sf::Color(70, 70, 70, 200),
		sf::Color(150, 150, 150, 255),
		sf::Color(20, 20, 20, 200),
		sf::Color(0, 0, 235, 255), 10 * this->scale
	);
	this->buttons["QUIT_STATE"] = new gui::Button((this->window->getSize().x / 2) - 150 * this->scale, (this->window->getSize().y / 2) + 400 * this->scale, 300 * this->scale, 50 * this->scale,
		this->font, "Quit", 20 * this->scale,
		sf::Color(70, 70, 70, 200),
		sf::Color(150, 150, 150, 255),
		sf::Color(20, 20, 20, 200),
		sf::Color(0, 0, 235, 255), 10 * this->scale
	);
}

PauseMenu::PauseMenu(sf::RenderWindow* window, GraphicsSettings& graphSettings, const sf::Font& font, float scale, std::stack<State*>* states, std::map<std::string, int>* supportedKeys)
	:font(font), scale(scale), states(states), supportedKeys(supportedKeys),graphSettings(graphSettings)
{
	this->background.setSize(sf::Vector2f(
		static_cast<float>(window->getSize().x),
		static_cast<float>(window->getSize().y)
	));
	this->background.setFillColor(sf::Color(20, 20, 20, 100));

	this->container.setSize(sf::Vector2f(
		static_cast<float>(window->getSize().x) / 4.f,
		static_cast<float>(window->getSize().y) - 100.f * this->scale
	));
	this->container.setFillColor(sf::Color(20, 20, 20, 200));
	this->container.setPosition((static_cast<float>(window->getSize().x) / 2.f - this->container.getSize().x / 2.f)  , 30.f * this->scale);
	
	this->font = font;
	this->menuText.setFont(this->font);
	this->menuText.setFillColor(sf::Color(255, 255, 255, 200));
	this->menuText.setCharacterSize(30 * this->scale);
	this->menuText.setString(" *-*-*-*-*-*-* PAUSE *-*-*-*-*-*-*");
	this->menuText.setPosition(this->container.getPosition());

	this->window = window;
	this->initButtons();
	this->pause = false;
	this->quit = false;
	this->settings = false;
}

PauseMenu::~PauseMenu()
{
	auto it = this->buttons.begin();
	for (it = this->buttons.begin(); it != this->buttons.end(); ++it)
	{
		delete it->second;
	}
}

//Functions

void PauseMenu::pauseState()
{
	this->pause = true;
}

void PauseMenu::unpauseState()
{
	this->pause = false;
}

bool PauseMenu::getPauseState()
{
	return this->pause;
}

bool PauseMenu::getQuit()
{
	return this->quit;
}

void PauseMenu::updateWindow(sf::RenderWindow* window, float scale)
{
	this->scale = scale;
	this->background.setSize(sf::Vector2f(
		static_cast<float>(window->getSize().x),
		static_cast<float>(window->getSize().y)
	));
	this->background.setFillColor(sf::Color(20, 20, 20, 100));

	this->container.setSize(sf::Vector2f(
		static_cast<float>(window->getSize().x) / 4.f,
		static_cast<float>(window->getSize().y) - 100.f * this->scale
	));
	this->container.setFillColor(sf::Color(20, 20, 20, 200));
	this->container.setPosition((static_cast<float>(window->getSize().x) / 2.f - this->container.getSize().x / 2.f), 30.f * this->scale);
	this->menuText.setCharacterSize(30 * this->scale);
	this->menuText.setPosition(this->container.getPosition());

	this->window = window;
	this->initButtons();
}

void PauseMenu::updateButtons()
{
	for (auto& it : this->buttons)
	{
		it.second->update(this->mousePosView);
	}

	/*Action of the Button*/

	
	if (this->buttons["POKEDEX"]->isPressed())
	{
		
	}
	if (this->buttons["SETTINGS"]->isPressed())
	{
		this->settings = true;
		this->wait = 0.f;
		this->states->push(new SettingsState(this->window,this->graphSettings, this->supportedKeys, this->states, this->font, this->scale));
		
	}
	if (this->buttons["EXIT_PAUSE"]->isPressed())
	{
		this->unpauseState();
	}
	if (this->buttons["QUIT_STATE"]->isPressed() && !this->settings)
	{
		this->quit = true;
		std::cout << this->quit << " pause menu update button  " <<  "\n";
	}
}

void PauseMenu::renderButtons(sf::RenderTarget* target)
{
	for (auto& it : this->buttons)
	{
		it.second->render(target);
	}
}

void PauseMenu::update( sf::Vector2f mousePosView, const float& dt)
{
	this->mousePosView = mousePosView;
	this->updateButtons();
	this->wait += 10 * dt;
	if (this->wait>=10.f)
	{
		this->settings = false; 
		this->wait = 0.f;
	}
	std::cout << "wait" << this->wait << "\n";
}

void PauseMenu::render(sf::RenderTarget* target)
{
	target->draw(background);
	target->draw(container);
	target->draw(this->menuText);
	this->renderButtons(target);

}