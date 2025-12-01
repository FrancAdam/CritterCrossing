#ifndef UI_H
#define UI_H
#define GOAL 10

#include <SFML/Graphics.hpp>
#include "GameObject.h"

class UI : public GameObject
{
public:

	bool backgroundInit();
	bool aStampInit();
	bool rStampInit();
	void updateStamps(sf::Vector2f passport_position);
	bool textInit(sf::RenderWindow& window);

	void renderMenu(sf::RenderWindow& window);
	void renderGame(sf::RenderWindow& window);
	void renderPause(sf::RenderWindow& window);
	void renderScore(sf::RenderWindow& window);
	void textUpdate(int lives, int current_cases, sf::RenderWindow& window);

private:
	sf::Texture background_texture;
	sf::Texture accept_stamp_tex;
	sf::Texture reject_stamp_tex;

	sf::Font OSBold;
	sf::Text cc_title;
	sf::Text press_enter;
	sf::Text paused;
	sf::Text lives;
	sf::Text cases;
	sf::Text score_text;
	sf::Text score_sub_text;
	sf::Text instruction;

	sf::RectangleShape overlay;
};

#endif
