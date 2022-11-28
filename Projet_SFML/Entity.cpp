#include "Entity.h"

Entity::Entity(int height, int width)
{
	this->shape.setSize(sf::Vector2f(height, width));
	this->movementSpeed = 100.f;
}

Entity::~Entity()
{
}

void Entity::initMainCharacter()
{
	sf::Texture texture;
	texture.loadFromFile("Ressources/Sprites/cynthia_sprites.png");
	sf::Sprite sprite(texture);
}

void Entity::move(const float& dt,const float dir_x, const float dir_y)
{
	this->shape.move(dir_x * movementSpeed * dt, dir_y * movementSpeed * dt);
}

void Entity::update(const float& dt)
{
	
}

void Entity::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}
