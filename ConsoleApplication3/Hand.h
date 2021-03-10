#pragma once
#include <vector>
#include "Card.h"
#include "Deck.h"

class Hand
{
public:
	Hand();
	~Hand();

	void get_card(Deck &deck);
	void print_hand_deck();

	int size_hand = 2;
private:
	vector<Card> hand_deck;
};

