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
	int tabmap[40][40] =
	{
        {11, 12, 13, 14, 15, 16, 11, 12, 13, 14, 15, 16, 11, 12, 13, 14, 15, 16, 11, 12, 13, 14, 15, 16, 11, 12, 13, 14, 15, 16, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {32, 33, 34, 35, 36, 37, 32, 33, 34, 35, 36, 37, 32, 33, 34, 35, 36, 37, 32, 33, 34, 35, 36, 37, 32, 33, 34, 35, 36, 37, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {53, 54, 55, 56, 57, 58, 53, 54, 55, 56, 57, 58, 53, 54, 55, 56, 57, 58, 53, 54, 55, 56, 57, 58, 53, 54, 55, 56, 57, 58, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {74, 75, 76, 77, 78, 79, 74, 75, 76, 77, 78, 79, 74, 75, 76, 77, 78, 79, 74, 75, 76, 77, 78, 79, 74, 75, 76, 77, 78, 79, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {95, 96, 97, 98, 99, 100, 95, 96, 97, 98, 99, 100, 95, 96, 97, 98, 99, 100, 95, 96, 97, 98, 99, 100, 95, 96, 97, 98, 99, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {116, 117, 118, 119, 120, 121, 116, 117, 118, 119, 120, 121, 116, 117, 118, 119, 120, 121, 116, 117, 118, 119, 120, 121, 116, 117, 118, 119, 120, 121, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 18, 19, 19, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 39, 40, 40, 41, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 39, 40, 40, 41, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 39, 40, 40, 102, 19, 19, 19, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 39, 40, 40, 40, 40, 40, 40, 41, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 39, 40, 40, 40, 40, 40, 40, 41, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 60, 61, 61, 61, 82, 40, 40, 41, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 39, 40, 40, 41, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 39, 40, 40, 41, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 60, 61, 61, 62, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},

	};

	

	for (int y = 0; y < 40 ; y++)
	{
		for (int x = 0; x < 40; x++)
		{
            for (int m = 0; m < 1000; m++)
            {
                if (tabmap[y][x] - 1 == m)
                {
                    if (m <= 20)
                    {
                        sf::Sprite box;
                        box.setTexture(forest);
                        box.setTextureRect(sf::IntRect((m % 21) * 16, 0, 16, 16));
                        box.scale(4.6875, 4.6875);
                        box.setPosition(sf::Vector2f(x * offSetX, y * offSetY));
                        vecbox.push_back(box);
                    }
                    else if (m <= 41)
                    {
                        sf::Sprite box;
                        box.setTexture(forest);
                        box.setTextureRect(sf::IntRect((m % 21) * 16, 16, 16, 16));
                        box.scale(4.6875, 4.6875);
                        box.setPosition(sf::Vector2f(x * offSetX, y * offSetY));
                        vecbox.push_back(box);
                    }
                    else if (m <= 62)
                    {
                        sf::Sprite box;
                        box.setTexture(forest);
                        box.setTextureRect(sf::IntRect((m % 21) * 16, 2*16, 16, 16));
                        box.scale(4.6875, 4.6875);
                        box.setPosition(sf::Vector2f(x * offSetX, y * offSetY));
                        vecbox.push_back(box);
                    }
                    else if (m <= 83)
                    {
                        sf::Sprite box;
                        box.setTexture(forest);
                        box.setTextureRect(sf::IntRect((m % 21) * 16, 3*16, 16, 16));
                        box.scale(4.6875, 4.6875);
                        box.setPosition(sf::Vector2f(x * offSetX, y * offSetY));
                        vecbox.push_back(box);
                    }
                    else if (m <= 104)
                    {
                        sf::Sprite box;
                        box.setTexture(forest);
                        box.setTextureRect(sf::IntRect((m % 21) * 16, 4*16, 16, 16));
                        box.scale(4.6875, 4.6875);
                        box.setPosition(sf::Vector2f(x * offSetX, y * offSetY));
                        vecbox.push_back(box);
                    }
                    else if (m <= 125)
                    {
                        sf::Sprite box;
                        box.setTexture(forest);
                        box.setTextureRect(sf::IntRect((m % 21) * 16, 5*16, 16, 16));
                        box.scale(4.6875, 4.6875);
                        box.setPosition(sf::Vector2f(x * offSetX, y * offSetY));
                        vecbox.push_back(box);
                    }
                }
            }
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


//if (tabmap[y][x] == 1)
//{
//	sf::Sprite pass;
//	pass.setTexture(forest);
//	pass.setTextureRect(sf::IntRect(272 + 16, 0 + 16, 16, 16));
//	pass.scale(4.6875, 4.6875);
//	pass.setPosition(sf::Vector2f(x * offSetX, y * offSetY));
//	vecbox.push_back(pass);
//}
////1-Chemin millieu
//if (tabmap[y][x] == 2)
//{
//	sf::Sprite pass;
//	pass.setTexture(forest);
//	pass.setTextureRect(sf::IntRect(272 + 16, 0, 16, 16));
//	pass.scale(4.6875, 4.6875);
//	pass.setPosition(sf::Vector2f(x * offSetX, y * offSetY));
//	vecbox.push_back(pass);
//}
////2-Chemin haut
//if (tabmap[y][x] == 3)
//{
//	sf::Sprite pass;
//	pass.setTexture(forest);
//	pass.setTextureRect(sf::IntRect(272 + 16, 0 + 16 + 16, 16, 16));
//	pass.scale(4.6875, 4.6875);
//	pass.setPosition(sf::Vector2f(x * offSetX, y * offSetY));
//	vecbox.push_back(pass);
//}
////3-Chemin bas
//if (tabmap[y][x] == 4)
//{
//	sf::Sprite pass;
//	pass.setTexture(forest);
//	pass.setTextureRect(sf::IntRect(272, 0 + 16, 16, 16));
//	pass.scale(4.6875, 4.6875);
//	pass.setPosition(sf::Vector2f(x * offSetX, y * offSetY));
//	vecbox.push_back(pass);
//}
////4-Chemin gauche
//if (tabmap[y][x] == 5)
//{
//	sf::Sprite pass;
//	pass.setTexture(forest);
//	pass.setTextureRect(sf::IntRect(272 + 16 + 16, 0 + 16, 16, 16));
//	pass.scale(4.6875, 4.6875);
//	pass.setPosition(sf::Vector2f(x * offSetX, y * offSetY));
//	vecbox.push_back(pass);
//}
////5-Chemin droite
//if (tabmap[y][x] == 13)
//{
//	sf::Sprite pass;
//	pass.setTexture(forest);
//	pass.setTextureRect(sf::IntRect(160, 0, 96, 96));
//	pass.scale(4.6875, 4.6875);
//	pass.setPosition(sf::Vector2f(x * offSetX, y * offSetY));
//	vecbox.push_back(pass);
//}
////13- Forêt
//if (tabmap[y][x] == 14)
//{
//	sf::Sprite pass;
//	pass.setTexture(forest);
//	pass.setTextureRect(sf::IntRect(160 + 16, 0, 82, 96));  //2 arbres forêt et demi + 2 pixels
//	pass.scale(4.6875, 4.6875);
//	pass.setPosition(sf::Vector2f(x * offSetX, y * offSetY));
//	vecbox.push_back(pass);
//}
////14- Forêt fin droite