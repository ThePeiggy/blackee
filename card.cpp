#include "card.h"

Card::Card(int value, Suit suit) {
	this->value = value;
	this->suit = suit;
}

int Card::getValue()
{
	return value;
}

Card::Suit Card::getSuit()
{
	return suit;
}

string Card::getSuitString()
{
	switch (suit) {
		case DIAMOND:
			return "D";
		case CLUB:
			return "C";
		case HEART:
			return "H";
		case SPADE:
			return "S";
	}
}

bool Card::equals(Card *card)
{
	if (value == card->getValue() && suit == card->getSuit())
	{
		return true;
	}
	return false;
}

int Card::getCountValue() {
	switch (value) {
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
			return 1;
		case 7:
		case 8:
		case 9:
			return 0;
		default:
			return -1;
	}
}

int Card::getGameValue() {
	switch (value) {
		case 11:
		case 12:
		case 13:
			return 10;
		default:
			return value;
	}
}