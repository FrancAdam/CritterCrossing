#include "UI.h"
#include <iostream>

bool UI::backgroundInit()
{
	return initialiseSprite(background_texture, "../Data/WhackaMole_Worksheet/background.png");
}

bool UI::aStampInit()
{
	initialiseSprite(accept_stamp_tex, "../data/Critter Crossing Customs/accept.png");
	centerOrigin();
	setVisible(false);

	return true;
}

bool UI::rStampInit()
{
	initialiseSprite(reject_stamp_tex, "../data/Critter Crossing Customs/reject.png");
	centerOrigin();
	setVisible(true);

	return true;
}

void UI::updateStamps(sf::Vector2f passport_position)
{
	sprite->setPosition(passport_position.x, passport_position.y - 100);
}

bool UI::textInit(sf::RenderWindow& window)
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
	paused.setCharacterSize(65);
	paused.setFillColor(sf::Color::Black);
	paused.setPosition(
		window.getSize().x / 2 - paused.getGlobalBounds().width / 2, 150);

	lives.setFont(OSBold);
	lives.setCharacterSize(30);
	lives.setFillColor(sf::Color::Black);
	lives.setPosition(950, 10);

	cases.setFont(OSBold);
	cases.setCharacterSize(30);
	cases.setFillColor(sf::Color::Black);
	cases.setPosition(790, 40);

	score_text.setFont(OSBold);
	score_text.setCharacterSize(65);
	score_text.setOutlineColor(sf::Color::White);
	

	score_sub_text.setFont(OSBold);
	score_sub_text.setCharacterSize(30);
	score_sub_text.setFillColor(sf::Color::White);
	score_sub_text.setOutlineColor(sf::Color::Black);

	instruction.setFont(OSBold);
	instruction.setCharacterSize(30);
	instruction.setString("Press 'Enter' to play again or 'Escape' to go back to the main menu");
	instruction.setFillColor(sf::Color::White);
	instruction.setOutlineColor(sf::Color::Black);




	overlay.setSize(sf::Vector2f(window.getSize()));
	overlay.setFillColor(sf::Color(100, 100, 100, 150));

	return true;
}

void UI::renderMenu(sf::RenderWindow& window)
{
	window.draw(cc_title);
	window.draw(press_enter);

}
void UI::renderGame(sf::RenderWindow& window)
{
	window.draw(lives);
	window.draw(cases);
}
void UI::renderPause(sf::RenderWindow& window)
{
	window.draw(overlay);
	window.draw(paused);
}
void UI::renderScore(sf::RenderWindow& window)
{
	window.draw(score_text);
	window.draw(score_sub_text);
	window.draw(instruction);

}


void UI::textUpdate(int current_lives, int current_cases, sf::RenderWindow& window)
{
	lives.setString("Lives: " + std::to_string(current_lives));
	cases.setString("Cases solved: " + std::to_string(current_cases) + "/" + std::to_string(GOAL));
	instruction.setPosition(
		window.getSize().x / 2 - instruction.getGlobalBounds().width / 2,
		430);

	if (current_lives > 0)
	{
		score_text.setString("Another successful day \n at the Critter Crossing");
		score_text.setFillColor(sf::Color::Yellow);
		score_text.setPosition(
			window.getSize().x / 2 - score_text.getGlobalBounds().width / 2,
			120);


		score_sub_text.setString("You succesfully completed " + std::to_string(GOAL) + " cases today");
		score_sub_text.setPosition(
			window.getSize().x / 2 - score_sub_text.getGlobalBounds().width / 2,
			300);

	}
	else
	{
		score_text.setString("Game Over");
		score_text.setFillColor(sf::Color::Red);
		score_text.setPosition(
			window.getSize().x / 2 - score_text.getGlobalBounds().width / 2,
			150);


		score_sub_text.setString("You made 3 mistakes and failed to complete " + std::to_string(GOAL) + " cases today");
		score_sub_text.setPosition(
			window.getSize().x / 2 - score_sub_text.getGlobalBounds().width / 2,
			300);
	}

}
