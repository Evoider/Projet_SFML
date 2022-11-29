#include "Background.h"

Background::Background()
{
	this->offSetX = 75;
	this->offSetY = 75;
	this->vecbox;

	this->forest.loadFromFile("Ressources/Sprites/background_forest.png");
	
}

void Background::initTab()
{
	int tabmap[20][30] =
	{
		{13,0,0,0,0,0,13,0,0,0,0,0,13,0,0,0,0,0,13,0,0,0,0,0,13,0,0,0,0,0},	//Forêt
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{13,0,0,0,0,14,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,99,99,99,99,99,99,99,99,99,99,99,99,99,0,0,0,0,0,0,0}, //Fin forêt haut
		{0,0,0,0,0,0,0,0,0,0,99,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		  {0,0,0,0,0,0,0,0,0,99,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{13,0,0,0,0,14,0,0,0,99,0,0,0,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		   {0,0,0,0,0,0,0,0,0,0,0,0,4,1,1,1,0,0,0,1,0,0,0,0,0,0,0,0,0,1},
		   {0,0,0,0,0,0,0,0,0,0,0,0,4,1,1,1,0,0,0,1,0,0,0,0,0,0,0,0,0,1},
		   {0,0,0,0,0,0,0,0,0,0,0,0,4,1,1,1,0,0,0,1,0,0,0,0,0,0,0,0,0,1},
		   {0,0,0,0,0,0,0,0,0,0,0,0,4,1,1,1,0,0,0,1,0,0,0,0,0,0,0,0,0,1},
		{0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1},
		{0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1},

	};

	

	for (int y = 0; y < 20 ; y++)
	{
		for (int x = 0; x < 30; x++)
		{
			if (tabmap[y][x] == 1)	
			{
				sf::Sprite pass;
				pass.setTexture(forest);
				pass.setTextureRect(sf::IntRect (272 + 16, 0 + 16, 16, 16));
				pass.scale(4.6875, 4.6875);
				pass.setPosition(sf::Vector2f(x * offSetX, y * offSetY));
				vecbox.push_back(pass);
			}
			//1-Chemin millieu
			if (tabmap[y][x] == 2)	
			{
				sf::Sprite pass;
				pass.setTexture(forest);
				pass.setTextureRect(sf::IntRect(272 + 16, 0, 16, 16));
				pass.scale(4.6875, 4.6875);
				pass.setPosition(sf::Vector2f(x * offSetX, y * offSetY));
				vecbox.push_back(pass);
			}
			//2-Chemin haut
			if (tabmap[y][x] == 3)	
			{
				sf::Sprite pass;
				pass.setTexture(forest);
				pass.setTextureRect(sf::IntRect(272 + 16, 0 + 16 + 16, 16, 16));
				pass.scale(4.6875, 4.6875);
				pass.setPosition(sf::Vector2f(x * offSetX, y * offSetY));
				vecbox.push_back(pass);
			}
			//3-Chemin bas
			if (tabmap[y][x] == 4)
			{
				sf::Sprite pass;
				pass.setTexture(forest);
				pass.setTextureRect(sf::IntRect(272, 0 + 16, 16, 16));
				pass.scale(4.6875, 4.6875);
				pass.setPosition(sf::Vector2f(x * offSetX, y * offSetY));
				vecbox.push_back(pass);
			}
			//4-Chemin gauche
			if (tabmap[y][x] == 5)
			{
				sf::Sprite pass;
				pass.setTexture(forest);
				pass.setTextureRect(sf::IntRect(272 + 16 + 16, 0 + 16, 16, 16));
				pass.scale(4.6875, 4.6875);
				pass.setPosition(sf::Vector2f(x * offSetX, y * offSetY));
				vecbox.push_back(pass);
			}
			//5-Chemin droite
			if (tabmap[y][x] == 13)
			{
				sf::Sprite pass;
				pass.setTexture(forest);
				pass.setTextureRect(sf::IntRect(160, 0, 96, 96));
				pass.scale(4.6875, 4.6875);
				pass.setPosition(sf::Vector2f(x * offSetX, y * offSetY));
				vecbox.push_back(pass);
			}
			//13- Forêt
			if (tabmap[y][x] == 14)
			{
				sf::Sprite pass;
				pass.setTexture(forest);
				pass.setTextureRect(sf::IntRect(160 + 16, 0, 82, 96));  //2 arbres forêt et demi + 2 pixels
				pass.scale(4.6875, 4.6875);
				pass.setPosition(sf::Vector2f(x * offSetX, y * offSetY));
				vecbox.push_back(pass);
			}
			//14- Forêt fin droite
		}
	}
}

void Background::render(sf::RenderTarget* target)
{
	for (int i = 0; i < vecbox.size(); i++)
	{
		target->draw(this->vecbox[i]);
	}
}