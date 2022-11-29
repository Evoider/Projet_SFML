#pragma once
#include "Gui.h"

#include "SettingsState.h"

#include <map>

class PauseMenu
{
private:
	bool pause;
	bool quit,settings;
	float scale,wait;
	sf::Font font;
	sf::Text menuText;

	sf::RectangleShape background;
	sf::RectangleShape container;
	sf::RenderWindow* window;
	sf::Vector2f mousePosView;

	std::map<std::string, gui::Button*> buttons;
	std::map<std::string, int>* supportedKeys;
	std::stack<State*>* states;

	void initButtons(sf::RenderWindow& window);
public:
	PauseMenu(sf::RenderWindow& window, const sf::Font& font, float scale, std::stack<State*>* states, std::map<std::string, int>* supportedKeys);
	~PauseMenu();

	//Functions

	void pauseState();
	void unpauseState();
	bool getPauseState();
	bool getQuit();

	void updateButtons();
	void renderButtons(sf::RenderTarget* target = nullptr);

	void update( sf::Vector2f mousePosView, const float& dt);
	void render(sf::RenderTarget* target);
};