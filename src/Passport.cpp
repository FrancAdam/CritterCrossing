#include "Passport.h"
#include <iostream>

Passport::~Passport()
{
}

bool Passport::initPassportTextures()
{
	passport_texture_location = {
				"../data/Critter Crossing Customs/passports/elephant_passport.png",
				"../data/Critter Crossing Customs/passports/moose_passport.png",
				"../data/Critter Crossing Customs/passports/penguin_passport.png",
				"../data/Critter Crossing Customs/passports/chicken_passport.png",
				"../data/Critter Crossing Customs/passports/buffalo_passport.png",
				"../data/Critter Crossing Customs/passports/gorilla_passport.png",
				"../data/Critter Crossing Customs/passports/narwhal_passport.png",
				"../data/Critter Crossing Customs/passports/walrus_passport.png",
				"../data/Critter Crossing Customs/passports/giraffe_passport.png" };

	initTextures(passport_textures, passport_texture_location);

	sprite->scale(PASSPORT_SCALE, PASSPORT_SCALE);
	centerOrigin();


	return true;
}


void Passport::changePassport(int random_index)
{
	int max_passports = passport_texture_location.size();

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