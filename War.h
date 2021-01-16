#include "Deck.h"
#ifndef WAR_H
#define WAR_H
#include <queue>

class War
{
	public:
		War();
		~War();

	public:
		void deal(); // Deal cards to each player (two players - 26 cards each)
		void play(); // War Game Play
		void compare(); // Compare card values to determine winner of each round
		void winner(); // Determine winner if full game is playes (i.e, someone has all 52 cards
		void term(); // If user decides to quit mid game, winner is determined by who has the most cards upon termination 
		void validWar(); // If war occurs, check if each player has enough cards to execute war (Minimum 2 cards needed)   
		void war(); // Handles case of war (both players deal card with equal values) 

	protected:
		Deck war_deck;
		std::string playerName; 
		std::queue<Cards*> computer_hand;
		std::queue<Cards*> player_hand; 
		std::stack<Cards*> computer_pile;
		std::stack<Cards*> player_pile;
		
		// Minumum cards needed in case of war (2)
		static const int WAR_MIN = 2;

		// Cards needed to win (52)
		static const int FIFTY_TWO = 52; 
		
};
#endif