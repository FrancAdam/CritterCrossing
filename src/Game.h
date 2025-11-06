#ifndef PLATFORMER_GAME_H
#define PLATFORMER_GAME_H

#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "Animal.h"
#include "Passport.h"
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

  bool textInit();
  //bool arrayInit();

  GameState current_state;

 private:
  sf::RenderWindow& window;

  UI background;

  Animal animal;



  sf::Texture* passports = new sf::Texture[3];

  //std::vector<std::string> passport_textures; // initialize vector here and then just add strings into it in cpp file
  //std::vector<std::string> animal_textures;

  sf::Font OSBold;
  sf::Text cc_title;
  sf::Text press_enter;
  sf::Text paused;
};

#endif // PLATFORMER_GAME_H
