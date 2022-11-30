#include "Entity.h"

Entity::Entity()
{
	this->texture.loadFromFile("Ressources/Sprites/cynthia_sprites.png");
	this->sprite.setTexture(texture);
	this->sprite.setTextureRect(sf::IntRect(0, 0, 75, 75));
	this->sprite.scale(1.3,1.3);
	this->movementSpeed = 100.f;

	this->posX = 10;
	this->posY = 6;

	this->offSetX = 75;
	this->offSetY = 75;

	this->sprite.setPosition(posX * offSetX, posY * offSetY);
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
			sprite.setPosition(posX * offSetX, posY * offSetY);
			view.setCenter(view.getCenter().x, view.getCenter().y - offSetY);
		}
		else if (direction == "Down")
		{
			posY++;
			sprite.setPosition(posX * offSetX, posY * offSetY);
			view.setCenter(view.getCenter().x, view.getCenter().y + offSetY);
		}
		else if (direction == "Left")
		{
			posX--;
			sprite.setPosition(posX * offSetX, posY * offSetY);
			view.setCenter(view.getCenter().x - offSetX, view.getCenter().y);
		}
		else if (direction == "Right")
		{
			posX++;
			sprite.setPosition(posX * offSetX, posY * offSetY);
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
	target->draw(this->sprite);
}
