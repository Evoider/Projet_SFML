#pragma once

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include <ctime>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stack>
#include <map>

class State
{
private:
	sf::RenderWindow* window;
	std::vector<sf::Texture> textures;
public:
	State(sf::RenderWindow* window);
	virtual ~State();

	//Functions
	virtual void endState();

	virtual void update(const float& dt) = 0;
	virtual void render(sf::RenderTarget* target = nullptr) = 0;
};

