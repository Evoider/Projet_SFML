#include "Entity.h"

Entity::Entity(int height, int width)
{
	this->movementSpeed = 100.f;
}

Entity::~Entity()
{
}


void Entity::move(const float& dt,const float dir_x, const float dir_y)
{
	this->sprite.move(dir_x * movementSpeed * dt, dir_y * movementSpeed * dt);
}

void Entity::update(const float& dt)
{
	
}

void Entity::render(sf::RenderTarget* target)
{
	target->draw(this->sprite);
}
