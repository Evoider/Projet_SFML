#include "PauseMenu.h"
void PauseMenu::initButtons(sf::RenderWindow& window)
{
	this->buttons["POKEDEX"] = new Button((window.getSize().x / 2) - 150 * this->scale, (window.getSize().y / 2) - 100 * this->scale, 300 * this->scale, 50 * this->scale,
		this->font, "Pokedex", 20 * this->scale,
		sf::Color(70, 70, 70, 200),
		sf::Color(150, 150, 150, 255),
		sf::Color(20, 20, 20, 200)
	);
	this->buttons["EXIT_PAUSE"] = new Button((window.getSize().x / 2) - 150 * this->scale, (window.getSize().y / 2) , 300 * this->scale, 50 * this->scale,
		this->font, "Exit", 20 * this->scale,
		sf::Color(70, 70, 70, 200),
		sf::Color(150, 150, 150, 255),
		sf::Color(20, 20, 20, 200)
	);
	this->buttons["QUIT_STATE"] = new Button((window.getSize().x / 2) - 150 * this->scale, (window.getSize().y / 2) + 100 * this->scale, 300 * this->scale, 50 * this->scale,
		this->font, "Quit", 20 * this->scale,
		sf::Color(70, 70, 70, 200),
		sf::Color(150, 150, 150, 255),
		sf::Color(20, 20, 20, 200)
	);
}

PauseMenu::PauseMenu(sf::RenderWindow& window, const sf::Font& font, float scale, sf::Vector2f mousePosView)
	:font(font), scale(scale), mousePosView(mousePosView)
{
	this->background.setSize(sf::Vector2f(
		static_cast<float>(window.getSize().x),
		static_cast<float>(window.getSize().y)
	));
	this->background.setFillColor(sf::Color(20, 20, 20, 100));

	this->container.setSize(sf::Vector2f(
		static_cast<float>(window.getSize().x) / 4.f,
		static_cast<float>(window.getSize().y) - 100.f * this->scale
	));
	this->container.setFillColor(sf::Color(20, 20, 20, 200));
	this->container.setPosition((static_cast<float>(window.getSize().x) / 2.f - this->container.getSize().x / 4.f)  , 30.f * this->scale);
	
	this->font = font;
	this->menuText.setFont(this->font);
	this->menuText.setFillColor(sf::Color(255, 255, 255, 200));
	this->menuText.setCharacterSize(30 * this->scale);
	this->menuText.setString(" *-*-*-*-*-*-* PAUSE *-*-*-*-*-*-*");
	this->menuText.setPosition(this->container.getPosition());

	this->window = &window;
	this->initButtons(window);
	this->pause = false;
	this->quit = false;
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
	if (this->buttons["EXIT_PAUSE"]->isPressed())
	{

	}
	if (this->buttons["QUIT_STATE"]->isPressed())
	{

	}
}

void PauseMenu::renderButtons(sf::RenderTarget* target)
{
	for (auto& it : this->buttons)
	{
		it.second->render(target);
	}
}

void PauseMenu::update()
{
	this->updateButtons();
}

void PauseMenu::render(sf::RenderTarget* target)
{
	target->draw(background);
	target->draw(container);
	target->draw(this->menuText);
	this->renderButtons(target);

}