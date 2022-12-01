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

	float posX;
	float posY;
	int offSetX;
	int offSetY;
	float movementSpeed;

	sf::IntRect devant;
	sf::IntRect derriere;
	sf::IntRect gauche;
	sf::IntRect droite;

	int commtpeurAnimation;
	sf::Clock dtclock;

public:
	Entity();
	~Entity();

	//Functions
	virtual void move(std::string direction, sf::View& view);

	//Affichage
	virtual void update(const float& dt);
	virtual void render(sf::RenderTarget* target);

	int getPositionX();
	int getPositionY();
};