#include "Entity.h"

Entity::Entity(int height, int width)
{
	this->shape.setSize(sf::Vector2f(50.f, 50.f));
	this->movementSpeed = 100.f;
	this->shape.setFillColor(sf::Color::White);
}

Entity::~Entity()
{
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
