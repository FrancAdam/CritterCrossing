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
	PAUSE,
	SCORE
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
  sf::Vector2f getMousePos();
  void gameReset();

  //bool arrayInit();

  GameState current_state;

 private:
  sf::RenderWindow& window;

  bool passport_accepted = false;
  bool passport_rejected = false;
  bool should_accept = false;
  bool passport_dragged = false;
  bool accept_dragged = false;
  bool reject_dragged = false;
  int lives = MAX_LIVES;
  int cases_solved = 0;

  sf::Vector2f drag_offset;

  UI background;
  UI accept_stamp;
  UI reject_stamp;
  UI ui;



  Animal animal;
  Passport passport;
  Button reject_button;
  Button accept_button;

};

#endif // PLATFORMER_GAME_H
