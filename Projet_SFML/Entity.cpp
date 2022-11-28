#include "Entity.h"

Entity::Entity()
{
	this->shape.setSize(sf::Vector2f(75.f, 75.f));
	this->movementSpeed = 100.f;
	this->shape.setFillColor(sf::Color::White);

	this->posX = 0;
	this->posY = 0;

	this->offSetX = 75;
	this->offSetY = 75;
}

Entity::~Entity()
{
}


void Entity::move(std::string direction)
{
	if (dtclock.getElapsedTime().asSeconds() > 0.6f) {
		if (direction == "Up")
		{
			posY--;
			shape.setPosition(posX * offSetX, posY * offSetY);
		}
		else if (direction == "Down")
		{
			posY++;
			shape.setPosition(posX * offSetX, posY * offSetY);
		}
		else if (direction == "Left")
		{
			posX--;
			shape.setPosition(posX * offSetX, posY * offSetY);
		}
		else if (direction == "Right")
		{
			posX++;
			shape.setPosition(posX * offSetX, posY * offSetY);
		}
		dtclock.restart();
	}
}

void Entity::update(const float& dt)
{
	
}

void Entity::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}
