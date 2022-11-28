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

	sf::Texture texture;
	sf::Sprite sprite;

	int posX;
	int posY;
	int offSetX;
	int offSetY;
	float movementSpeed;

	sf::Clock dtclock;

public:
	Entity();
	~Entity();

	//Functions
	virtual void move(std::string direction);

	//Affichage
	virtual void update(const float& dt);
	virtual void render(sf::RenderTarget* target);
};

