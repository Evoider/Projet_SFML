#pragma once

#include "MainMenuState.h"

class Game
{
private:
	
	
	//Variables
	GraphicsSettings graphSettings;
	sf::RenderWindow *window;
	sf::Event sfEvent;
	

	sf::Clock dtClock, clock;
	float dt;
	

	std::stack<State*> states;

	std::map<std::string, int> supportedKeys;

	//Initialization
	void initVariables();
	void initGraphicsSettings();
	void initWindow();
	void initKeys();
	void initStates();

public:
	Game();

	virtual ~Game();

	//Functions

	void endApplaction();

	//Update
	void updateDt();

	void updateSFMLEvents();

	void update();

	//Render
	void render();
	
	//Core
	void run();
};

