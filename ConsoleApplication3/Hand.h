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

private:
	vector<Card> hand_deck;
};

