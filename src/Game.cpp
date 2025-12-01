
#include "Game.h"
#include <iostream>
using std::cout;
using std::endl;

Game::Game(sf::RenderWindow& game_window)
  : window(game_window)
{
  srand(time(NULL));
}

Game::~Game()
{
	//delete passport_dragged;
}

bool Game::init() // all init functions
{
	background.backgroundInit();
	animal.initAnimalTextures();
	passport.initPassportTextures();
	accept_button.acceptButton();
	reject_button.rejectButton();
	accept_stamp.aStampInit();
	reject_stamp.rStampInit();

	ui.textInit(window);

	current_state = GameState::MENU;
	return true;
}

void Game::update(float dt)
{
	switch (current_state)
	{
		case GameState::MENU:
			{
				
				break;
			}
		case GameState::INGAME:
		{
			if (passport_dragged)
			{
				dragSprite(passport.getSprite());
			}
			else if (accept_dragged)
			{
				dragSprite(accept_button.getSprite());
			}
			else if (reject_dragged)
			{
				dragSprite(reject_button.getSprite());
			}

			accept_stamp.updateStamps(passport.getPosition());
			reject_stamp.updateStamps(passport.getPosition());
			ui.textUpdate(lives, cases_solved, window);

			// win/lose condition
			if (lives <= 0 || (cases_solved >= GOAL))
			{
				current_state = GameState::SCORE;
			}

			break;
		}
		case GameState::PAUSE:
		{
			break;
		}
	}
}

void Game::render()
{
	switch (current_state) //state machine
	{
		case GameState::MENU:
		{
			ui.renderMenu(window);
			break;
		}
		case GameState::INGAME:
		{

			background.render(window);
			animal.render(window);
			passport.render(window);
			accept_stamp.render(window);
			reject_stamp.render(window);
			reject_button.render(window);
			accept_button.render(window);

			ui.renderGame(window);
			break;
		}
		case GameState::PAUSE:
		{
			background.render(window);
			animal.render(window);
			passport.render(window);
			accept_button.render(window);
			reject_button.render(window);
			accept_stamp.render(window);
			reject_stamp.render(window);

			ui.renderPause(window);

			break;
		}
		case GameState::SCORE:
		{
			ui.renderScore(window);
			break;
		}
	}
}

void Game::mouseButtonPressed(sf::Event event)
{
	if (event.mouseButton.button == sf::Mouse::Left)
	{
		//get the click position
		sf::Vector2f clickf = getMousePos();

		// assigning a sprite to the dragging logic based on what gets clicked
		if (accept_button.getBounds().contains(clickf))
		{
			drag_offset = accept_button.getPos() - clickf;
			accept_dragged = true;
		}
		else if (reject_button.getBounds().contains(clickf))
		{
			drag_offset = reject_button.getPos() - clickf;
			reject_dragged = true;
		}
		else if (passport.getBounds().contains(clickf))
		{
			drag_offset = passport.getPos() - clickf;
			passport_dragged = true;
		}
		// accounting for clicking on overlapping objects
		else if (accept_button.getBounds().contains(clickf) &&
			passport.getBounds().contains(clickf))
		{
			passport_dragged = false;
			accept_dragged = true;
		}
		else if (reject_button.getBounds().contains(clickf) &&
			passport.getBounds().contains(clickf))
		{
			passport_dragged = false;
			reject_dragged = true;
		}


	}


}
void Game::mouseButtonReleased(sf::Event event)
{
	// gets mouse position in relation to screen size
	sf::Vector2f mouse_positionf = getMousePos();

	if (event.mouseButton.button == sf::Mouse::Left)
	{
		// checks to see if player was holding a passport with an answer above an animal when the 
		// left mouse button was released
		if (animal.getBounds().contains(mouse_positionf) 
			&& (passport_accepted || passport_rejected))
		{
			checkCorrect();
		}
		if (passport.getBounds().contains(mouse_positionf) && accept_dragged)
		{
			if (passport_rejected)
			{
				reject_stamp.setVisible(false);
				passport_rejected = false;
			}
			passport_accepted = true;
			accept_stamp.setVisible(true);
		}
		else if (passport.getBounds().contains(mouse_positionf) && reject_dragged)
		{
			if (passport_accepted)
			{
				accept_stamp.setVisible(false);
				passport_accepted = false;
			}
			passport_rejected = true;
			reject_stamp.setVisible(true);
		}
			
		// resets stamps if they were moved
		if (accept_dragged || reject_dragged)
		{
			accept_dragged = false;
			reject_dragged = false;
			accept_button.acceptReset();
			reject_button.rejectReset();
		}
		passport_dragged = false;
	}
	
}

void Game::keyPressed(sf::Event event, float dt)
{
	if (event.key.code == sf::Keyboard::M)
	{
		current_state = GameState::MENU;
	}
	
	// escape key functionality
	if (event.key.code == sf::Keyboard::Escape)
	{
		//cout << "ran" << endl;
		switch (current_state)
		{
			case GameState::MENU:
			{
				window.close();
				break;
			}
			case GameState::INGAME:
			{
				current_state = GameState::PAUSE;
				break;
			}
			case GameState::PAUSE:
			{
				current_state = GameState::INGAME;
				break;
			}
			case GameState::SCORE:
				current_state = GameState::MENU;
				break;
			}
	}

	switch (current_state)
	{
	case GameState::MENU:
	{
		if (event.key.code == sf::Keyboard::Enter)
		{
			current_state = GameState::INGAME;
			gameReset();
		}
		break;
	}
	case GameState::INGAME:
	{
		if (event.key.code == sf::Keyboard::C)
		{
			newAnimal();
		}
		if (event.key.code == sf::Keyboard::P)
		{
			checkCorrect();
		}

		break;
	}
	case GameState::PAUSE:
	{
		
		break;
	}
	case GameState::SCORE:
	{
		if (event.key.code == sf::Keyboard::Enter)
		{
			current_state = GameState::INGAME;
			gameReset();
		}
		break;
	}
	}
}

void Game::newAnimal()
{
	accept_stamp.setVisible(false);
	reject_stamp.setVisible(false);
	passport_accepted = false;
	passport_rejected = false;

	int animal_index = animal.getRandInt(0, animal.getAnimalSize() - 1);
	int passport_index = passport.getRandInt(0, passport.getPassportSize() - 1);

	if (animal_index == passport_index)
	{
		should_accept = true;
	}
	else
	{
		should_accept = false;
	}

	animal.changeAnimal(animal_index);

	passport.changePassport(passport_index);
}

void Game::checkCorrect()
{
	if (should_accept == true && passport_accepted == true)
	{
		cout << "CORRECT" << endl;
		cases_solved += 1;
	}
	else if (should_accept == false && passport_rejected == true)
	{
		cout << "CORRECT" << endl;
		cases_solved += 1;
	}
	else
	{
		cout << "FALSE remaining live: " << lives<<  endl;
		lives -= 1;
	}

	newAnimal();
}

void Game::dragSprite(sf::Sprite* sprite)
{
	if (sprite != nullptr)
	{
		//sf::Vector2i mouse_position = sf::Mouse::getPosition(window);
		//sf::Vector2f mouse_positionf = static_cast<sf::Vector2f>(mouse_position);

		//mouse_positionf = window.mapPixelToCoords(sf::Mouse::getPosition(window));
		sf::Vector2f mouse_positionf = getMousePos();

		sf::Vector2f drag_position = mouse_positionf + drag_offset; // dragoffset? / or center all origins
		sprite->setPosition(drag_position.x, drag_position.y);
	}
}

sf::Vector2f Game::getMousePos()
{
	sf::Vector2i mouse_position = sf::Mouse::getPosition(window);
	sf::Vector2f mouse_positionf = static_cast<sf::Vector2f>(mouse_position);

	return window.mapPixelToCoords(sf::Mouse::getPosition(window));
}

void Game::gameReset()
{
	lives = MAX_LIVES;
	cases_solved = 0;
	newAnimal();
}




