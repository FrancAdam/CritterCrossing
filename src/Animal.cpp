#include "Animal.h"
#include <iostream>

bool Animal::initAnimalTextures()
{
	animal_texture_location = {
				"../data/Critter Crossing Customs/elephant.png",
				"../data/Critter Crossing Customs/moose.png",
				"../data/Critter Crossing Customs/penguin.png"
			};
		
	for (int i = 0; i < 3; i++)
	{
		if (!animal_textures[i].loadFromFile(animal_texture_location[i]))
		{
			std::cerr << "Failed to load " << animal_texture_location[i] << std::endl;
			return false;
		}
	}
}
void Animal::changeAnimal()
{
	int max_animals = animal_texture_location.size();
	int random_index = getRandInt(0, max_animals - 1);
	std::cout << random_index << std::endl;
	sprite->setTexture(animal_textures[random_index]);
}