#ifndef BUTTON_H
#define BUTTON_H
#define BUTTON_SCALE 0.9

#include <SFML/Graphics.hpp>
#include "GameObject.h"

class Button : public GameObject
{
public:
	void acceptButton();
	void rejectButton();
	void acceptReset();
	void rejectReset();

private:
	sf::Texture accept_button_texture;
	sf::Texture reject_button_texture;
};


#endif