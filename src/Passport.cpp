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

	initTextures(passport_textures, passport_texture_location);

	sprite->scale(PASSPORT_SCALE, PASSPORT_SCALE);
	centerOrigin();
	//initStamps();

	return true;
}


void Passport::changePassport(int random_index)
{
	int max_passports = passport_texture_location.size();
	//int random_index = getRandInt(0, max_passports - 1);
	std::cout << random_index << std::endl;
	sprite->setTexture(*passport_textures[random_index]);

	centerOrigin();
	sprite->setPosition(200, 200);
}


int Passport::getPassportSize()
{
	return passport_texture_location.size();
}

sf::Vector2f Passport::getPosition()
{
	return sprite->getPosition();
}