#ifndef ANIMAL_H
#define ANIMAL_H

#include <SFML/Graphics.hpp>
#include "GameObject.h"

class Animal : public GameObject
{
public:
	~Animal();
	bool initAnimalTextures();
	void changeAnimal();
private:
	//sf::Texture* animal_textures = new sf::Texture[3];
	std::vector<sf::Texture> animal_textures;
	std::vector<std::string> animal_texture_location;
};

#endif