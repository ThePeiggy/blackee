#ifndef DECK_H
#define DECK_H

#include <vector>
#include <string>
#include <random>
#include "card.h"
using namespace std;

class Deck 
{
public:

	static const int NUM_DECKS = 6;
	static const int CARDS_PER_DECK = 52;
	static const int CARDS_PER_SUIT = 13;
	static const int NUM_CARDS = NUM_DECKS * CARDS_PER_DECK;

	Deck();

	~Deck();

	Card* draw();

	int getCardsRemaining();

/*
	int getCount();

	double getTrueCount();

	double getEstimatedTrueCount();
*/

	string toString();

private:
	vector<Card*> cards;
	int cardsRemaining;
    mt19937 generator{random_device{}()};
};

#endif