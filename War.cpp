#include "War.h"
#include "Cards.h"
#include "Deck.h"
#include <iostream>

War::War()
{
	// Get players human players name
	std::cout << "Welcome to the card game War. Please enter your name: ";
	std::cin >> this->playerName;
	std::cout << "Hello, " << this->playerName << ". Lets play!" << std::endl;
	std::cout << std::endl;
}

War::~War()
{
}

void War::deal()
{
	// Deal
	for (int index = 0; index < War::FIFTY_TWO; index++)
	{
		// Simulates dealing the cards one at a time
		if (index % 2 == 0)
		{
			this->player_hand.push(this->war_deck.draw());
		}
		else
		{
			this->computer_hand.push(this->war_deck.draw());
		}
	}

	std::cout << "Each player begins the game with 26 cards each! (Deck of 52 dived into two)" << std::endl; 
}

void War::play()
{
	std::string nextRound; // For if player wants to continue play

	// Shuffle deck then deal cards
	this->war_deck.shuffle();
	this->deal();

	// Play the game until a winner has been determined (i.e, one player has all 52 cards)
	while (!this->computer_hand.empty() && !this->player_hand.empty())
	{
		std::cout << " -----> New Round - Both players deal a card" << std::endl;
		std::cout << std::endl;

		// Display value of human player's top card
		std::cout << this->playerName << "'s card: ";
		this->player_hand.front()->printCard();
		std::cout << std::endl;

		// Push top card to player_pile then pop the top card from player_hand
		this->player_pile.push(this->player_hand.front());
		this->player_hand.pop();

		// Display value of computer player's top card
		std::cout << "Computer's card: ";
		this->computer_hand.front()->printCard();
		std::cout << std::endl;

		// Push top card to computer_pile then pop the top card from computer_hand
		this->computer_pile.push(this->computer_hand.front());
		this->computer_hand.pop();

		this->compare();

		// Print current score (i.e, the amount of cards eahc player has remaining
		std::cout << "Current Score: " << std::endl;
		std::cout << this->playerName << ", you have " << this->player_hand.size() << " cards remaining" << std::endl;
		std::cout << "Computer has " << this->computer_hand.size() << " cards remaining" << std::endl;
		std::cout << std::endl;

		// Give user option to keep playing
		std::cout << "Proceed to next round?(Y/N):";
		std::cin >> nextRound;
		std::cout << std::endl;

		// End game if user declines to keep playing by terminating the program - (winner is person with most cards upon termination)
		if (toupper(nextRound.at(0)) != 'Y')
		{
			std::cout << "Game ended." << std::endl;
			this->term();
			exit(0);
		}
	}// End of game loop container

	this->winner(); // Decide winner (i.e, if the game looped terminated, the person with all 52 cards wins)
}

void War::compare()
{
	// Computer player's card value is greater than human player's card value
	if (this->player_pile.top()->valueEquality(*this->computer_pile.top()) == -1)
	{
		std::cout << "Computer's card has a greater value. They win this round." << std::endl;
		std::cout << std::endl;

		// Add all winnings to winners hand
		while (!this->player_pile.empty() && !this->computer_pile.empty())
		{
			this->computer_hand.push(this->player_pile.top());
			this->computer_hand.push(this->computer_pile.top());

			// Empty the player piles
			this->player_pile.pop();
			this->computer_pile.pop();
		}
	}
	else if (this->player_pile.top()->valueEquality(*this->computer_pile.top()) == 1)
	{// Human player's card value is greater than computer player's card value
		std::cout << this->playerName << ", your card has a greater value. You win this round." << std::endl;
		std::cout << std::endl;

		// Add all winnings to winners hand
		while (!this->player_pile.empty() && !this->computer_pile.empty())
		{
			this->player_hand.push(this->player_pile.top());
			this->player_hand.push(this->computer_pile.top());

			// Empty the player piles
			this->player_pile.pop();
			this->computer_pile.pop();
		}
	}
	else
	{
		this->war(); // Handles event where both players draw cards of equal value
	}
}

void War::validWar()
{// Check if both players have enough cards to handle war
	if (this->player_hand.size() < War::WAR_MIN)
	{
		// If human player doesn't have enough cards to execute war - (i.e they had two cards at the start, war occured, and now they don't have enough to play war
		std::cout << this->playerName << ", you do not have enough cards to play war. Therefore, the Computer wins! GAME OVER" << std::endl;
		std::cout << std::endl;
		exit(0); // Terminate program
	}

	if (this->computer_hand.size() < War::WAR_MIN)
	{
		// If computer player doesn't have enough cards to execute war - (i.e they had two cards at the start, occured, and now they don't have enough to play war
		std::cout << "The computer does not have enough cards to play war. Therefore, " << this->playerName << " wins! GAME OVER" << std::endl;
		std::cout << std::endl;
		exit(0); // Terminate program
	}
}

void War::war()
{
	// Player's cards have equal value
	std::cout << "Both cards have the same value. " << "THIS MEANS WAR!" << std::endl;
	std::cout << std::endl;

	do
	{ // War loop (at least two cards are needed for war)

		// Check if each user has at least 2 cards when war occurs (minimum of two cards needed when war occurs)
		this->validWar();

		for (int index = 0; index < War::WAR_MIN; index++)
		{ // For war, two cards are drawn from each players hand onto their play pile
			this->player_pile.push(this->player_hand.front());
			this->computer_pile.push(this->computer_hand.front());

			// Remove cards from players hand
			this->player_hand.pop();
			this->computer_hand.pop();
		}

		// Print human-players card
		std::cout << this->playerName << "'s card: ";
		this->player_pile.top()->printCard();
		std::cout << std::endl;

		// Print computer players card
		std::cout << "Computer's card: ";
		this->computer_pile.top()->printCard();
		std::cout << std::endl;

		this->compare(); 

		// Return control if play piles (computer_pile & player_pile stack) are empty - indicates that winner of round has been decided
		if (this->player_pile.empty() && this->computer_pile.empty())
			return; 

	// Execute war loop again if there is no winner (i.e, the next set of cards have equal values too)
	} while (this->player_pile.top()->valueEquality(*this->computer_pile.top()) == 1);
}

void War::winner()
{
	// After game loop terminates, decide winner - 52 cards needed to win
	if (this->player_hand.size() == War::FIFTY_TWO)
	{
		std::cout << this->playerName << ", you win the game! GAME OVER." << std::endl;
	}

	if (this->computer_hand.size() == War::FIFTY_TWO)
	{
		std::cout << "The Computer player wins the game! GAME OVER." << std::endl;
	}
}

void War::term()
{
	if (this->player_hand.size() > this->computer_hand.size())
		std::cout << this->playerName << ", you win because you had the most cards before the game terminated." << std::endl;
	else if (this->player_hand.size() < this->computer_hand.size())
		std::cout << "Computer wins because they had the most cards before the game terminated." << std::endl;
	else
		std::cout << "The game ends in a draw because both players had an equal amount of cards before the game terminated." << std::endl;
}