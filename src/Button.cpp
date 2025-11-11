#include "Button.h"
#include <iostream>

void Button::acceptButton()
{
	initialiseSprite(accept_button_texture, "../data/Critter Crossing Customs/accept button.png");
	sprite->scale(BUTTON_SCALE, BUTTON_SCALE);
	centerOrigin();
	sprite->setPosition(850, 500);
}

void Button::rejectButton()
{
	initialiseSprite(accept_button_texture, "../data/Critter Crossing Customs/reject button.png");
	sprite->scale(BUTTON_SCALE, BUTTON_SCALE);
	centerOrigin();
	sprite->setPosition(850, 625);
}

