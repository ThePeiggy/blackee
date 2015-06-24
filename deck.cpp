#include <string>
#include <vector>
#include <random>
#include "card.h"
#include "deck.h"
using namespace std;

Deck::Deck() 
{
	cards.reserve(NUM_CARDS);
	for (int deck = 0; deck < NUM_DECKS; deck++) {
		for (int suit = Card::DIAMOND; suit <= Card::SPADE; suit++) { 
			for (int value = 1; value <= CARDS_PER_SUIT; value++) {
				cards.push_back(new Card(value, (Card::Suit)suit));
			}
		}
	}

	cardsRemaining = NUM_CARDS;
}

Deck::~Deck() 
{
	for (int i = 0; i < cards.size(); i++) {
		delete cards[i];
	}
}

Card* Deck::draw() 
{
	uniform_int_distribution<int> distribution(0, cardsRemaining - 1);
	int randomIndex = distribution(generator);
	Card *swap = cards.at(randomIndex);
	cards.at(randomIndex) = cards.at(cardsRemaining - 1);
	cards.at(cardsRemaining - 1) = swap;
	cardsRemaining--;
	return swap;
}

int Deck::getCardsRemaining() 
{
	return cardsRemaining;
}

string Deck::toString() 
{
	string deck;
	for (int i = 0; i < cards.size(); i++) {
		deck += (to_string(cards[i]->getValue()) + cards[i]->getSuitString() + " ");
	}
	return deck;
}