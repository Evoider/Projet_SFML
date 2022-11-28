#pragma once
#include "Button.h"


#include <map>

class PauseMenu
{
private:
	sf::RectangleShape background;
	sf::RectangleShape container;

	std::map<std::string, Button*> buttons;

public:
	PauseMenu(sf::RenderWindow& window);
	~PauseMenu();

	//Functions
	void update();
	void render(sf::RenderTarget* target);
};

