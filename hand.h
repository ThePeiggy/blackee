#ifndef HAND_H
#define HAND_H

#include <vector>
#include <string>
#include "card.h"

using namespace std;

class Hand
{
public:

	static const int MAX_VALUE = 21;

	Hand();

	Hand(Card *card1, Card *card2);

	~Hand();

	//returns the lowest possible value of the cards in the hand
	int getHardValue();

	//returns the value of the cards in the hand if one of the aces is treated as 11.
	//returns the hard value if no aces are present, or the soft value busts the hand
	int getSoftValue();

	//returns true if the hand does not bust if an ace is present and is treated as 11.
	bool isSoft();

	//returns true if the hand's value exceeds MAX_VALUE
	bool isBust();

	//returns true if the hand contains a card matching a given face value
	bool contains(int value);

	//returns true if the hand contains a card matching a given face value and suit
	bool contains(Card *card);

	//adds a card to the hand
	void hit(Card *card);

	//prints the contents of the hand;
	string toString();

private:
	vector<Card*> cards;

};

#endif