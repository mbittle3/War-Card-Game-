#include "Deck.h"
#include "Cards.h"
#include <iostream> 
#include <random>

static std::random_device rd; 
static std::mt19937 rng(rd());

Deck::Deck()
{
	// Loop counter variables
	Cards::Suit i;
	Cards::Value j; 
	
	// Build each suit with playing Card values Two through Ace
	for (i = Cards::Suit::CLUB; i <= Cards::Suit::SPADE; i = static_cast<Cards::Suit>(i + 1))
	{
		for (j = Cards::Value::TWO; j <= Cards::Value::ACE; j = static_cast<Cards::Value>(j + 1))
		{
			// Create pointers to Card instances
			Cards *card = new Cards(i, j);

			// Add pointers to Deck (vector)
			this->deck.push_back(card);
		}
	}
}

Deck::~Deck()
{
	// Free memory associated with each Card instance 
	for (int index = 0; index < this->deck.size(); index++)
	{
		delete this->deck[index];
	}
}

void Deck::shuffle()
{
	// Shuffle Deck (vector)
	std::shuffle(deck.begin(), deck.end(), rng);
	
	if (dStack.empty())
	{ //Shuffle "new" Deck - new Deck has not yet been shuffled
		
		// Populate Stack with shuffled Deck
		for (int index = 0; index < deck.size(); index++)
		{
			dStack.push(deck[index]);
		}
	}
	else
	{ // Re-shuffle Deck

		// Make Stack logically empty by popping all elements
		while (!dStack.empty())
		{
			dStack.pop();
		}

		// Populate Stack with Re-shuffled Deck
		for (int index = 0; index < deck.size(); index++)
		{
			dStack.push(deck[index]);
		}

	}
}

Cards* Deck::draw()
{
	// Check for empty Stack - cannot draw from empty Stack 
	if (dStack.empty()) 
	{
		std::cout << "CANNOT DRAW FROM EMPTY STACK!" << std::endl;
		return nullptr; 
	}

	// Save card that was drawn from top of Stack
	Cards* topCard = dStack.top();

	// Pop the card that was drawn - pop the card at the top of Stack
	dStack.pop(); 

	// Return pointer to Card drawn 
	return topCard;
}

void Deck::printDeck()
{
	// Print Cards in the deck
	for (const auto& crd : deck)
	{
		crd->printCard(); 
	}
}

bool Deck::isEmpty()
{
	// Check if vector is logically empty 
	if (deck.size() == 0)
	{
		return true;
	}

	return false; 
}