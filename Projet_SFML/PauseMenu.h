#pragma once
#include "Button.h"


#include <map>

class PauseMenu
{
private:
	bool pause;
	bool quit;
	float scale;
	sf::Font font;
	sf::Text menuText;

	sf::RectangleShape background;
	sf::RectangleShape container;
	sf::RenderWindow* window;
	sf::Vector2f mousePosView;

	std::map<std::string, Button*> buttons;


	void initButtons(sf::RenderWindow& window);
public:
	PauseMenu(sf::RenderWindow& window, const sf::Font& font, float scale, sf::Vector2f mousePosView);
	~PauseMenu();

	//Functions

	void pauseState();
	void unpauseState();
	bool getPauseState();
	bool getQuit();

	void updateButtons();
	void renderButtons(sf::RenderTarget* target = nullptr);

	void update();
	void render(sf::RenderTarget* target);
};