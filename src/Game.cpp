
#include "Game.h"
#include <iostream>

Game::Game(sf::RenderWindow& game_window)
  : window(game_window)
{
  srand(time(NULL));
}

Game::~Game()
{
	delete character;
	delete passport;
	delete[] animals;
	delete[] passports;

}

bool Game::init()
{
	background.initialiseSprite(background_texture, "../Data/WhackaMole_Worksheet/background.png");
	textInit();

	character = new sf::Sprite;
	passport = new sf::Sprite;
	arrayInit();
	passport->setTexture(passport_textures[1]);

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
	switch (current_state)
	{
		case GameState::MENU:
		{
			window.draw(cc_title);
			window.draw(press_enter);
			break;
		}
		case GameState::INGAME:
		{
			window.draw(*background.getSprite());
			window.draw(*character);
			window.draw(*passport);
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
		std::cout << "ran" << std::endl;
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
		}
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

bool Game::arrayInit()
{
	std::vector<std::string>passport_texture = {
		"../data/Critter_Crossing_Customs/elephant_passport.png",
		"../data/Critter_Crossing_Customs/moose_passport.png",
		"../data/Critter_Crossing_Customs/penguin_passport.png" };
	std::vector<std::string> animal_texture = {
		"../data/Critter_Crossing_Customs/elephant.png",
		"../data/Critter_Crossing_Customs/moose.png",
		"../data/Critter_Crossing_Customs/penguin.png"
	};

	for (int i = 0; i < 3; i++)
	{
		if (!animals[i].loadFromFile(animal_texture[i]))
		{
			std::cerr << "Failed to load " << animal_texture[i] << std::endl;
			return false;
		}
		if (!passports[i].loadFromFile(passport_texture[i]))
		{
			std::cerr << "Failed to load " << passport_texture[i] << std::endl;
		}

	}

}