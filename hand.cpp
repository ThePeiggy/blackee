#include <string>
#include <vector>
#include "card.h"
#include "hand.h"
using namespace std;

Hand::Hand()
{
	
}

Hand::Hand(Card *card1, Card *card2)
{
	cards.push_back(card1);
	cards.push_back(card2);
}

Hand::~Hand()
{
	for (int i = 0; i < cards.size(); i++) {
		delete cards[i];
	}
}

//this should be cached so we don't need to calculate multiple times
int Hand::getHardValue()
{
	int hardValue = 0;
	for (int i = 0; i < cards.size(); i++) {
		hardValue += cards[i]->getGameValue();
	}
	return hardValue;
}

int Hand::getSoftValue()
{
	int hardValue = getHardValue();
	if (isSoft()) {
		return (hardValue + 10);
	}
	return hardValue;
}

bool Hand::isSoft()
{
	return (contains(1) && getHardValue() <= MAX_VALUE - 10);
}

bool Hand::isBust()
{
	return (getHardValue() > MAX_VALUE ? true : false);	
}

bool Hand::contains(int value)
{
	for (int i = 0; i < cards.size(); i++) {
		if (cards[i]->getValue() == value) return true;
	}
	return false;
}

bool Hand::contains(Card *card)
{
	int value = card->getValue();
	Card::Suit suit = card->getSuit();
	for (int i = 0; i < cards.size(); i++) {
		if (cards[i]->getValue() == value && cards[i]->getSuit() == suit) return true;
	}
	return false;
}

//cache hard value and use for getHardValue()
void Hand::hit(Card *card)
{
	cards.push_back(card);	
}

string Hand::toString()
{
	string hand;
	for (int i = 0; i < cards.size(); i++) {
		hand += (to_string(cards[i]->getValue()) + cards[i]->getSuitString() + " ");
	}
	return hand;
}