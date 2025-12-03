#include "Animal.h"
#include <iostream>

Animal::~Animal()
{
}

bool Animal::initAnimalTextures()
{
	animal_texture_location = {
				"../data/Critter Crossing Customs/animals/elephant.png",
				"../data/Critter Crossing Customs/animals/moose.png",
				"../data/Critter Crossing Customs/animals/penguin.png",
				"../data/Critter Crossing Customs/animals/chicken.png",
				"../data/Critter Crossing Customs/animals/buffalo.png",
				"../data/Critter Crossing Customs/animals/gorilla.png",
				"../data/Critter Crossing Customs/animals/narwhal.png",
				"../data/Critter Crossing Customs/animals/walrus.png",
				"../data/Critter Crossing Customs/animals/giraffe.png"};

	initTextures(animal_textures, animal_texture_location);
	

	return true;
}
void Animal::changeAnimal(int random_index)
{
	int max_animals = animal_texture_location.size();
	//int random_index = getRandInt(0, max_animals - 1);
	std::cout << random_index << std::endl;
	sprite->setTexture(*animal_textures[random_index], true);
	sprite->setScale(ANIMAL_SCALE, ANIMAL_SCALE);
	centerOrigin();
	sprite->setPosition(200, 540);
}

int Animal::getAnimalSize()
{
	return animal_texture_location.size();
}

