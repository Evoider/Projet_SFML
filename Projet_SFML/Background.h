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
	sf::IntRect green;

public:
	Background();
	void initTab();
	void render(sf::RenderTarget* target);
};

