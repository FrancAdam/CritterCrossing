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
  void mouseButtonPressed(sf::Event event);
  void mouseButtonReleased(sf::Event event);
  void keyPressed(sf::Event event, float dt);
  void newAnimal();
  void checkCorrect();
  void dragSprite(sf::Sprite* sprite);

  bool textInit();
  //bool arrayInit();

  GameState current_state;

 private:
  sf::RenderWindow& window;

  bool passport_accepted;
  bool passport_rejected;
  bool should_accept;
  int lives = MAX_LIVES;
  bool passport_dragged = false;
  bool accept_dragged = false;
  bool reject_dragged = false;

  sf::Vector2f drag_offset;

  UI background;

  Animal animal;
  Passport passport;
  Button reject_button;
  Button accept_button;

  //sf::Sprite* dragged = nullptr;



  sf::Font OSBold;
  sf::Text cc_title;
  sf::Text press_enter;
  sf::Text paused;
};

#endif // PLATFORMER_GAME_H
