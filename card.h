#ifndef CARD_H
#define CARD_H

#include <string>
using namespace std;

class Card 
{
	public:
	enum Suit //DO NOT EVER CHANGE THIS
	{
		DIAMOND,
		CLUB,
		HEART,
		SPADE
	};

	Card(int value, Suit suit);
	
	//returns the value of the card in the context of face value
	int getValue();

	//returns the suit of the card as an enum
	Suit getSuit();

	//returns the suit of the card as a string
	string getSuitString();

	//returns true if two cards are equal in value and suit and false otherwise
	bool equals(Card *card);

	//returns the value of the card in the context of Blackjack counting
	int getCountValue();

	//returns the value of the card in the context of Blackjack gameplay
	int getGameValue();

private:
	int value;
	Suit suit;
};

#endif