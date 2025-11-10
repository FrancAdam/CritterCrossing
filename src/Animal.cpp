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
				"../data/Critter Crossing Customs/penguin.png"};

	animal_textures.resize(animal_texture_location.size());

	initTextures(animal_textures, animal_texture_location);
	sprite->scale(1, 1);
	sprite->setPosition(100, 500);
	//sprite->setOrigin(getSprite()->getGlobalBounds().width / 2, getSprite()->getGlobalBounds().height / 2); 
	return true;
}
void Animal::changeAnimal()
{
	int max_animals = animal_texture_location.size();
	int random_index = getRandInt(0, max_animals - 1);
	std::cout << random_index << std::endl;
	sprite->setTexture(*animal_textures[random_index]);
}

//void Animal::changeAnimal()
//{
//    int max_animals = animal_texture_location.size();
//    int random_index = getRandInt(0, max_animals - 1);
//    std::cout << "Selected animal index: " << random_index << std::endl;
//
//
//    // Set the texture and reset the texture rectangle
//    sprite->setTexture(*animal_textures[random_index], true);
//
//    // Reset previous scale
//    sprite->setScale(1.f, 1.f);
//
//    // Optional: scale uniformly to fit within a max size
//    const float maxSize = 100.f; // max width or height you want on screen
//    sf::Vector2u texSize = animal_textures[random_index]->getSize();
//    float scaleFactor = std::min(maxSize / static_cast<float>(texSize.x),
//        maxSize / static_cast<float>(texSize.y));
//    sprite->setScale(scaleFactor, scaleFactor);
//}
