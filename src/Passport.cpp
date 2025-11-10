#include "Passport.h"
#include <iostream>

Passport::~Passport()
{
}

bool Passport::initPassportTextures()
{
	passport_texture_location = {
			"../data/Critter Crossing Customs/elephant passport.png",
			"../data/Critter Crossing Customs/moose passport.png",
			"../data/Critter Crossing Customs/penguin passport.png" };

	passport_textures.resize(passport_texture_location.size());

	initTextures(passport_textures, passport_texture_location);
	sprite->scale(0.5, 0.5);
	sprite->setPosition(600, 300);
	return true;
}
void Passport::changePassport()
{
	int max_passports = passport_texture_location.size();
	int random_index = getRandInt(0, max_passports - 1);
	std::cout << random_index << std::endl;
	sprite->setTexture(*passport_textures[random_index]);

}


