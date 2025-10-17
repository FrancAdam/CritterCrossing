#ifndef PLATFORMER_GAME_H
#define PLATFORMER_GAME_H

#include <SFML/Graphics.hpp>
#include "GameObject.h"

enum class GameState
{
	MENU,
	INGAME,
	PAUSE
};


class Game
{
 public:
  Game(sf::RenderWindow& window);
  ~Game();
  bool init();
  void update(float dt);
  void render();
  void mouseClicked(sf::Event event);
  void keyPressed(sf::Event event, float dt);

  bool textInit();

  GameState current_state;

 private:
  sf::RenderWindow& window;
  GameObject background;
  sf::Texture background_texture;

  sf::Font OSBold;
  sf::Text cc_title;
  sf::Text press_enter;
  sf::Text paused;
};

#endif // PLATFORMER_GAME_H
