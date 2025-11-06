#ifndef UI_H
#define UI_H

#include <SFML/Graphics.hpp>
#include "GameObject.h"

class UI : public GameObject
{
public:

	bool backgroundInit();

private:
	sf::Texture background_texture;

};

#endif
