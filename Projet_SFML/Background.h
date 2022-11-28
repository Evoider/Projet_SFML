#pragma once
#include "State.h"
#include <vector>

class Background
{
private:
	int offSetX = 32;
	int offSetY = 32;
	std::vector<sf::RectangleShape>vecbox;

public:
	Background();
	void initTab();
	void render(sf::RenderTarget* target);
};

