#include "Cards.h"
#ifndef DECK_H
#define DECK_H
#include <vector>
#include <stack>

class Deck
{
	public:
		Deck(); // Constructor
		~Deck(); // Destructor

	public:
		void shuffle(); // Shuffle Deck of Card Pointers
		Cards* draw(); // Draw card from Stack 
		void printDeck(); // Print Deck of Cards - Helper
		bool isEmpty(); // Check if Deck is logically empty - Helper

	protected:
		std::vector<Cards*> deck;   // non-shuffled deck
		std::stack<Cards*> dStack; // shuffled(playing) deck
};

#endif