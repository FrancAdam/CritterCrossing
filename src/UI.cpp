#include "UI.h"
#include <iostream>

bool UI::backgroundInit()
{
	return initialiseSprite(background_texture, "../Data/WhackaMole_Worksheet/background.png");
}

bool UI::aStampInit()
{
	initialiseSprite(accept_stamp_tex, "../data/Critter Crossing Customs/accept.png");
	centerOrigin();
	setVisible(false);

	return true;
}

bool UI::rStampInit()
{
	return initialiseSprite(reject_stamp_tex, "../data/Critter Crossing Customs/reject.png");
}

void UI::updateStamps(sf::Vector2f passport_position)
{
	sprite->setPosition(passport_position.x, passport_position.y - 100);
}













//void Passport::initStamps()
//{
//	initialiseSprite(accept_stamp_tex, "../data/Critter Crossing Customs/accept.png");
//	initialiseSprite(reject_stamp_tex, "../data/Critter Crossing Customs/reject.png");
//	accept_stamp.setTexture(accept_stamp_tex);
//	reject_stamp.setTexture(reject_stamp_tex);
//
//}
//
//void Passport::updateStamps()
//{
//	//accept_stamp.setPosition(sprite->getPosition().x, sprite->getPosition().y);
//}