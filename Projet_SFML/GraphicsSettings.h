#pragma once
#include "Entity.h"
class GraphicsSettings
{
public:
	GraphicsSettings();
	
	//Variables
	std::string title;
	sf::VideoMode resolution;
	bool fullscreen;
	bool verticaleSync;
	unsigned frameRateLimit;
	sf::ContextSettings contextSettings;
	std::vector<sf::VideoMode> videoModes;

	bool changed;

	//Functions
	void saveToFile(const std::string path);
	
	void loadFromFile(const std::string path);
	
private:

};


