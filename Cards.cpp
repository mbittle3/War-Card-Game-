#include "Cards.h"
#include <iostream>

// Constructor
Cards::Cards(Suit s,Value v) 
{
	// Assign card suit
	this->suit = s;

	// Assign card  numeric value
	this->value = v;
}

// Test two cards for value equality 
int Cards::valueEquality(Cards newCard)
{
	if (this->value < newCard.value)
		return -1;
	else if (this->value > newCard.value)
		return 1;
	else
		return 0; 
}

// Test two cards for suit equality 
bool Cards::suitEquality(Cards newCard)
{
	if (this->suit == newCard.suit)
		return true;
	else
		return false; 
}

// Print card value and card suit
void Cards::printCard()
{
	// Print card suit and value of card
	std::cout << this->suitToString(this->suit) << " of " << this->valueToString(this->value) << std::endl;
}

// Helper function to convert Suit type to string representation 
string Cards::suitToString(Suit s)
{
	switch (s)
	{
	case Suit::CLUB:
			return "Club";
			break;
	case Suit::DIAMOND:
			return "Diamond";
			break;
	case Suit::HEART:
			return "Heart";
			break;
	case Suit::SPADE:
			return "Spade";
			break;
		default:
			return "Invalid Suit!";
			break;

	}
}

// Helper function to convert Value to String representation 
string Cards::valueToString(Value v)
{
	switch (v)
	{
	case Value::TWO:
			return "2";
			break;
	case Value::THREE:
			return "3";
			break;
	case Value::FOUR:
			return "4";
			break;
	case Value::FIVE:
			return "5";
			break;
	case Value::SIX:
			return "6";
			break;
	case Value::SEVEN:
			return "7";
			break;
	case Value::EIGHT:
			return "8";
			break;
	case Value::NINE:
			return "9";
			break;
	case Value::TEN:
			return "10" ;
			break;
	case Value::JACK:
			return "Jack";
			break;
	case Value::QUEEN: 
			return "Queen";
			break;
	case Value::KING:
			return "King";
			break;
	case Value::ACE:
			return "Ace";
			break;
	default:
			return "Invalid Value";
			break;
	}
}