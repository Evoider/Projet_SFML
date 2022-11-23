#pragma once

#include "Entity.h"

class State
{
private:
	sf::RenderWindow* window;
	std::vector<sf::Texture> textures;
	bool quit;

public:
	State(sf::RenderWindow* window);
	virtual ~State();

	//Functions

	const bool& getQuit() const;

	virtual void checkForQuit();

	virtual void endState() = 0;

	virtual void updateKeyBinds(const float& dt) = 0;
	virtual void update(const float& dt) = 0;
	virtual void render(sf::RenderTarget* target = nullptr) = 0;
};

