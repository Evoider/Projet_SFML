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

	int compteurAnimUp;
	int compteurAnimDown;
	int compteurAnimLeft;
	int compteurAnimRight;

	sf::IntRect Up;
	sf::IntRect Up1;
	sf::IntRect Up2;
	sf::IntRect Down;
	sf::IntRect Down1;
	sf::IntRect Down2;
	sf::IntRect Left;
	sf::IntRect Left1;
	sf::IntRect Left2;
	sf::IntRect Right;
	sf::IntRect Right1;
	sf::IntRect Right2;

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