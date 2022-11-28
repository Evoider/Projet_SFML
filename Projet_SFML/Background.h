#pragma once
#include "State.h"
#include <vector>

class Background
{
private:
	int offSetX;
	int offSetY;
	std::vector<sf::RectangleShape>vecbox;

public:
	Background();
	void initTab();
	void render(sf::RenderTarget* target);
};

