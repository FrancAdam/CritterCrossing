#ifndef ANIMAL_H
#define ANIMAL_H

#include <SFML/Graphics.hpp>
#include "GameObject.h"

class Animal : public GameObject
{
public:
	bool initAnimalTextures();
	void changeAnimal(int number);
private:
	sf::Texture* animal_textures = new sf::Texture[3];
};

#endif