#include "Animal.h"
#include <iostream>

Animal::~Animal()
{
}

bool Animal::initAnimalTextures()
{
	animal_texture_location = {
				"../data/Critter Crossing Customs/elephant.png",
				"../data/Critter Crossing Customs/moose.png",
				"../data/Critter Crossing Customs/penguin.png"
			};
	animal_textures.resize(animal_texture_location.size());

	initTextures(animal_textures, animal_texture_location);
	return true;
}
void Animal::changeAnimal()
{
	int max_animals = animal_texture_location.size();
	int random_index = getRandInt(0, max_animals - 1);
	std::cout << random_index << std::endl;
	sprite->setTexture(animal_textures[random_index]);
}