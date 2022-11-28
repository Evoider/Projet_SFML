#pragma once
#include "Button.h"


#include <map>

class PauseMenu
{
private:
	float scale;
	sf::Font font;
	sf::Text menuText;

	sf::RectangleShape background;
	sf::RectangleShape container;

	std::map<std::string, Button*> buttons;

public:
	PauseMenu(sf::RenderWindow& window, const sf::Font& font, float scale);
	~PauseMenu();

	//Functions
	void update();
	void render(sf::RenderTarget* target);
};