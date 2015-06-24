#include <iostream>
#include "card.h"
#include "hand.h"
#include "deck.h"
using namespace std;

bool testCompareCards();
bool testHandValue();
bool testDeck();

int main(void) {
	if (testCompareCards()) cout << "Card comparison wrong." << endl;
	if (testHandValue()) cout << "Hand value wrong." << endl;
	if (testDeck()) cout << "Deck wrong." << endl;

	cout << "Testing complete." << endl;

	return 0;
}

bool testCompareCards() {
	bool error = false;

	Card *card1 = new Card(5, Card::SPADE);
	Card *card2 = new Card(5, Card::DIAMOND);
	Card *card3 = new Card(4, Card::SPADE);
	Card *card4 = new Card(5, Card::SPADE);

	if (card1->equals(card2)) error = true;
	if (card1->equals(card3)) error = true;
	if (!card1->equals(card4)) error = true;
	if (card2->equals(card3)) error = true;

	delete card1;
	delete card2;
	delete card3;
	delete card4;
	
	return error;
}

bool testHandValue() {
	bool error = false;

	Hand *hand = new Hand(new Card(4, Card::SPADE), new Card(3, Card::SPADE));
	if (hand->getHardValue() != 7) error = true;

	hand->hit(new Card(1, Card::SPADE));
	if (hand->getHardValue() != 8) error = true;
	if (hand->getSoftValue() != 18) error = true;

	hand->hit(new Card(6, Card::SPADE));
	if (hand->getHardValue() != 14) error = true;
	if (hand->getSoftValue() != 14) error = true;

	hand->hit(new Card(11, Card::SPADE));
	if (hand->getHardValue() != 24) error = true;

	delete hand;

	return error;
}

bool testDeck() {
	Deck *deck = new Deck();
	deck->draw();
	cout << deck->toString() << endl;
	return false;
}