#include "Hand.h"
#include <iostream>

Hand::Hand()
{

}

Hand::~Hand()
{

}

void Hand::get_card(Deck& deck)
{
	Card card = deck.get_card();
	hand_deck.push_back(card);
}

void Hand::print_hand_deck()
{
	for (int i = 0; i < hand_deck.size(); i++)
	{
		hand_deck[i].print_card();
	}
}
