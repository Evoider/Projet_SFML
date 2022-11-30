#pragma once
#include "State.h"
#include <vector>

class Background
{
private:
	int offSetX;
	int offSetY;
	std::vector<sf::Sprite>vecbox;

	sf::Texture forest;
	sf::Texture haute_herbe;
	sf::Texture batiment;

public:
	Background();
	void initTab();
	void render(sf::RenderTarget* target);
};

