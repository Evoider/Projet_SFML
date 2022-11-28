#include "Player.h"

Player::Player(int height, int width)
	: Entity(height, width)
{
	this->texture.loadFromFile("Ressources/Sprites/cynthia_sprites.png");
	this->sprite.setTexture(texture);
}

void Player::animationMove(std::string direction)
{

}
