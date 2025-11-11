#ifndef UI_H
#define UI_H

#include <SFML/Graphics.hpp>
#include "GameObject.h"

class UI : public GameObject
{
public:

	bool backgroundInit();
	bool aStampInit();
	bool rStampInit();
	void updateStamps(sf::Vector2f passport_position);

private:
	sf::Texture background_texture;
	sf::Texture accept_stamp_tex;
	sf::Texture reject_stamp_tex;
};

#endif
