#pragma once
#include <string>
#include <SFML/Graphics.hpp>
class Pokemon
{
private:
	sf::Texture texture;
	sf::Sprite sprite;
	int m_pv;
	int m_att;
	int m_def;
	int m_vit;
	std::string m_type;

public:
	Pokemon(std::string File, std::string type,int pv,int att,int def,int vit);
};

