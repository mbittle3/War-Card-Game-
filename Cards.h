#include <string>
#ifndef CARDS_H
#define CARDS_H
using namespace std;


class Cards
{
	public:
		// Card suits
		enum Suit { CLUB, DIAMOND, HEART, SPADE };
		// Card value
		enum Value { TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE };

	public:
		// Card Constructor
		Cards(Suit, Value);

	public:
		// Check if two card values are equal
		int valueEquality(Cards);
		// Check if two card suits are equal
		bool suitEquality(Cards);
		// Print card suit and value
		void printCard();

	private:
		/* Helper Methods */

		// Get string representation of suit enum values
		string suitToString(Suit);
		// For string representation of Jack, Queen, and King values
		string valueToString(Value);

	protected:
		// Card objects card suit
		Suit suit;
		// Card objects numeric card value representation
		Value value;
};

#endif