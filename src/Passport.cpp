#include "Passport.h"
#include <iostream>

bool Passport::initPassportTextures()
{
	passport_texture_location = {
			"../data/Critter Crossing Customs/elephant passport.png",
			"../data/Critter Crossing Customs/moose passport.png",
			"../data/Critter Crossing Customs/penguin passport.png" };


	for (int i = 0; i < 3; i++)
	{
		if (!passport_textures[i].loadFromFile(passport_texture_location[i]))
		{
			std::cerr << "Failed to load " << passport_texture_location[i] << std::endl;
			return false;
		}
	}
}
void Passport::changePassport()
{
	int max_passports = passport_texture_location.size();
	int random_index = getRandInt(0, max_passports - 1);
	std::cout << random_index << std::endl;
	sprite->setTexture(passport_textures[random_index]);
}