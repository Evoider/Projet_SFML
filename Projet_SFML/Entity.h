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

class Entity
{
private:

protected:
	sf::RectangleShape shape;

public:
	Entity();
	~Entity();

	//Functions
	virtual void update(const float& dt) = 0;
	virtual void render(sf::RenderTarget& target) = 0;
};

