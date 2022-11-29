#include "Entity.h"

Entity::Entity()
{
	this->shape.setSize(sf::Vector2f(75.f, 75.f));
	this->shape.setFillColor(sf::Color::White);
	this->movementSpeed = 100.f;

	this->posX = 10;
	this->posY = 6;

	this->offSetX = 75;
	this->offSetY = 75;

	this->shape.setPosition(posX * offSetX, posY * offSetY);
}

Entity::~Entity()
{
}


void Entity::move(std::string direction, sf::View& view)
{
	if (dtclock.getElapsedTime().asSeconds() > 0.5f) {
		if (direction == "Up")
		{
			posY--;
			shape.setPosition(posX * offSetX, posY * offSetY);
			view.setCenter(view.getCenter().x, view.getCenter().y - offSetY);
		}
		else if (direction == "Down")
		{
			posY++;
			shape.setPosition(posX * offSetX, posY * offSetY);
			view.setCenter(view.getCenter().x, view.getCenter().y + offSetY);
		}
		else if (direction == "Left")
		{
			posX--;
			shape.setPosition(posX * offSetX, posY * offSetY);
			view.setCenter(view.getCenter().x - offSetX, view.getCenter().y);
		}
		else if (direction == "Right")
		{
			posX++;
			shape.setPosition(posX * offSetX, posY * offSetY);
			view.setCenter(view.getCenter().x + offSetX, view.getCenter().y);
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
