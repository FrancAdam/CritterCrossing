#ifndef PLATFORMER_GAME_H
#define PLATFORMER_GAME_H
#define MAX_LIVES 3

#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "Animal.h"
#include "Passport.h"
#include "Button.h"
#include "UI.h"

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
  void newAnimal();
  void checkCorrect();

  bool textInit();
  //bool arrayInit();

  GameState current_state;

 private:
  sf::RenderWindow& window;

  bool passport_accepted;
  bool passport_rejected;
  bool should_accept;
  int lives = MAX_LIVES;

  UI background;

  Animal animal;
  Passport passport;
  Button reject_button;
  Button accept_button;

  sf::Texture* passports = new sf::Texture[3];

  sf::Font OSBold;
  sf::Text cc_title;
  sf::Text press_enter;
  sf::Text paused;
};

#endif // PLATFORMER_GAME_H
