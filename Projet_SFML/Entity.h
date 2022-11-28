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
	sf::Texture texture;
	sf::Sprite sprite;
	float movementSpeed;

public:
	Entity(int height, int width);
	~Entity();

	//Functions
	virtual void move(const float& dt,const float x, const float y);

	//Affichage
	virtual void update(const float& dt);
	virtual void render(sf::RenderTarget* target);
};

