#pragma once

#include "GraphicsSettings.h"

class State
{
private:

protected:
	std::stack<State*>* states;
	sf::RenderWindow* window;
	std::map<std::string, int>* supportedKeys;
	std::map<std::string, int> keyBinds;
	bool quit;
	sf::Vector2i mousePosScreen;
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;

	//block key spamming
	float keytime, keytimeMax;

	//Ressources
	std::vector<sf::Texture> textures;

	//Functions
	virtual void initKeyBinds() = 0;

public:
	State(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
	virtual ~State();

	//Functions

	const bool& getQuit() const;
	const bool getKeytime() ;


	virtual void endState() = 0;

	virtual void updateWindow(sf::RenderWindow* window) = 0;
	virtual void updateKeytime(const float& dt);
	virtual void updateMousePosition();
	virtual void updateInput(const float& dt) = 0;
	virtual void update(const float& dt) = 0;
	virtual void render(sf::RenderTarget* target = nullptr) = 0;

};