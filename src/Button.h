#ifndef BUTTON_H
#define BUTTON_H
#define BUTTON_SCALE 1

#include <SFML/Graphics.hpp>
#include "GameObject.h"

class Button : public GameObject
{
public:
	void acceptButton();
	void rejectButton();

private:
	sf::Texture accept_button_texture;
	sf::Texture reject_button_texture;
};


#endif