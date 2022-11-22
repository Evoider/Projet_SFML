#pragma once

#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <iostream>

class App
{
public:
	static sf::RenderWindow window;
public:
	static void init(int x, int y, std::string title);
	static void quit();
	static void event();

};

