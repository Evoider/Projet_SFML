#include "Player.h"

Player::Player()
	: Entity()
{
	this->texture.loadFromFile("Ressources/Sprites/cynthia_sprites.png");
	this->sprite.setTexture(texture);

    this->clock;
}

void Player::animationMove(std::string direction)
{

}
