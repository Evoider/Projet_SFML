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

class State
{
private:
	std::vector<sf::Texture> textures;
public:
	State();
	virtual ~State();

	virtual void update() = 0;
	virtual void render() = 0;
};

