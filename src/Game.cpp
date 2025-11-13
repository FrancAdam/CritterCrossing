
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
	textInit();
	animal.initAnimalTextures();
	passport.initPassportTextures();
	accept_button.acceptButton();
	reject_button.rejectButton();
	accept_stamp.aStampInit();
	reject_stamp.rStampInit();

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
			window.draw(cc_title);
			window.draw(press_enter);
			break;
		}
		case GameState::INGAME:
		{

			background.render(window);
			animal.render(window);
			passport.render(window);
			accept_button.render(window);
			reject_button.render(window);
			accept_stamp.render(window);
			reject_stamp.render(window);

			break;
		}
		case GameState::PAUSE:
		{
			window.draw(paused);
			break;
		}
	}
}

void Game::mouseButtonPressed(sf::Event event)
{
	if (event.mouseButton.button == sf::Mouse::Left)
	{
		//get the click position
		sf::Vector2i click = sf::Mouse::getPosition(window);
		sf::Vector2f clickf = static_cast<sf::Vector2f>(click);

		if (passport.getSprite()->getGlobalBounds().contains(clickf))
		{
			drag_offset = passport.getSprite()->getPosition() - clickf;
			passport_dragged = true;
		}
		if (accept_button.getSprite()->getGlobalBounds().contains(clickf))
		{
			drag_offset = accept_button.getSprite()->getPosition() - clickf;
			accept_dragged = true;
		}
		if (reject_button.getSprite()->getGlobalBounds().contains(clickf))
		{
			drag_offset = reject_button.getSprite()->getPosition() - clickf;
			reject_dragged = true;
		}


	}


}
void Game::mouseButtonReleased(sf::Event event)
{
	sf::Vector2i mouse_position = sf::Mouse::getPosition(window);
	sf::Vector2f mouse_positionf = static_cast<sf::Vector2f>(mouse_position);

	if (event.mouseButton.button == sf::Mouse::Left)
	{
		// checks to see if player was holding a passport with an answer above an animal when the 
		// left mouse button was released
		if (animal.getSprite()->getGlobalBounds().contains(mouse_positionf) 
			&& (passport_accepted || passport_rejected))
		{
			checkCorrect();
		}
		if (passport.getSprite()->getGlobalBounds().contains(mouse_positionf) && accept_dragged)
		{
			passport_accepted = true;
			accept_stamp.setVisible(true);
		}
		else if (passport.getSprite()->getGlobalBounds().contains(mouse_positionf) && reject_dragged)
		{
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
		cout << "ran" << endl;
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
			}
	}

	switch (current_state)
	{
	case GameState::MENU:
	{
		if (event.key.code == sf::Keyboard::Enter)
		{
			current_state = GameState::INGAME;
			newAnimal();
			lives = MAX_LIVES; //consider adding gameReset() function


		}
		break;
	}
	case GameState::INGAME:
	{
		if (event.key.code == sf::Keyboard::C)
		{
			newAnimal();
			cout << "ran newAnimal()" << endl;
		}
		if (event.key.code == sf::Keyboard::P)
		{
			checkCorrect();
		}
		if (event.key.code == sf::Keyboard::O)
		{
			accept_stamp.setVisible(true);
		}
		break;
	}
	case GameState::PAUSE:
	{
		
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
	}
	else if (should_accept == false && passport_rejected == true)
	{
		cout << "CORRECT" << endl;
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
		sf::Vector2i mouse_position = sf::Mouse::getPosition(window);
		sf::Vector2f mouse_positionf = static_cast<sf::Vector2f>(mouse_position);

		sf::Vector2f drag_position = mouse_positionf + drag_offset; // dragoffset? / or center all origins
		sprite->setPosition(drag_position.x, drag_position.y);
	}
}



bool Game::textInit()
{
	if (!OSBold.loadFromFile("../Data/Fonts/OpenSans-Bold.ttf"))
	{
		std::cerr << "Failed to load font file\n";
		return false;
	}

	cc_title.setFont(OSBold);
	cc_title.setString("Critters Crossing");
	cc_title.setCharacterSize(65);
	cc_title.setFillColor(sf::Color::Blue);
	cc_title.setOutlineColor(sf::Color::White);
	cc_title.setPosition(
		window.getSize().x / 2 - cc_title.getGlobalBounds().width / 2,
		150);

	press_enter.setFont(OSBold);
	press_enter.setString("Press 'Enter' to start the game:");
	press_enter.setCharacterSize(40);
	press_enter.setFillColor(sf::Color::White);
	press_enter.setPosition(
		window.getSize().x / 2 - press_enter.getGlobalBounds().width / 2, 275);


	paused.setFont(OSBold);
	paused.setString("The Game is Paused");
	paused.setCharacterSize(50);
	paused.setFillColor(sf::Color::Cyan);
	paused.setPosition(
		window.getSize().x / 2 - paused.getGlobalBounds().width / 2, 150);

	return true;
}



