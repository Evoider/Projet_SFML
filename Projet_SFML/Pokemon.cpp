#include "Pokemon.h"

Pokemon::Pokemon(std::string File, std::string type,int pv, int att, int def, int vit)
{
	texture.loadFromFile(File);
	sprite.setTexture(texture);
	m_type = type;
}
