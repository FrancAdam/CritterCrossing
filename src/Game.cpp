
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

}

bool Game::init() // all init functions
{
	background.backgroundInit();
	textInit();
	animal.initAnimalTextures();
	passport.initPassportTextures();
	accept_button.acceptButton();
	reject_button.rejectButton();

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

			break;
		}
		case GameState::PAUSE:
		{
			window.draw(paused);
			break;
		}
	}
}

void Game::mouseClicked(sf::Event event)
{
  //get the click position
  sf::Vector2i click = sf::Mouse::getPosition(window);


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
	else
	{
		cout << "FALSE remaining live: " << lives<<  endl;
		lives -= 1;
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



