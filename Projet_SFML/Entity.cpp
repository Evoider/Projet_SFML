#include "Entity.h"

Entity::Entity()
{
	this->texture.loadFromFile("Ressources/Sprites/cynthia_final.png");
	this->sprite.setTexture(texture);

	this->devant = sf::IntRect(64, 32, 32, 32);
	this->derriere = sf::IntRect(0, 0, 32, 32);
	this->gauche = sf::IntRect(0, 64, 32, 32);
	this->droite = sf::IntRect(32, 0, 32, 32);


	this->sprite.setTextureRect(devant);
	this->sprite.scale(3, 3);
	this->movementSpeed = 100.f;

	this->posX = 12.75;
	this->posY = 9.5;

	this->offSetX = 64;
	this->offSetY = 64;

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
			this->sprite.setTextureRect(derriere);
			view.setCenter(view.getCenter().x, view.getCenter().y - offSetY);
		}
		else if (direction == "Down")
		{
			posY++;
			sprite.setPosition(posX * offSetX, posY * offSetY);
			this->sprite.setTextureRect(devant);
			view.setCenter(view.getCenter().x, view.getCenter().y + offSetY);
		}
		else if (direction == "Left")
		{
			posX--;
			sprite.setPosition(posX * offSetX, posY * offSetY);
			this->sprite.setTextureRect(gauche);
			view.setCenter(view.getCenter().x - offSetX, view.getCenter().y);
		}
		else if (direction == "Right")
		{
			posX++;
			sprite.setPosition(posX * offSetX, posY * offSetY);
			this->sprite.setTextureRect(droite);
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

int Entity::getPositionX()
{
	return posX;
}
int Entity::getPositionY()
{
	return posY;
}