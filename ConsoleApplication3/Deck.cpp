#include <string>
#include <time.h>
#include <algorithm>
#include "Deck.h"

Deck::Deck()
{
	for (int i = 0; i < SUITS.size(); i++) {
		for (int j = 0; j < RANKS.size(); j++)
		{
			Card card(RANKS[j], SUITS[i]);
			deck.push_back(card);
		}
	}
	shuffle();
}

void Deck::print()
{
	for (int i = 0; i < deck.size(); i++)
	{
		deck[i].print_card();
	}
}

// сделать нормальную выборку карты из колоды
Card Deck::get_card()
{
	Card result = deck.back();
	deck.pop_back();
	return result;
}

void Deck::shuffle()
{
	srand(unsigned(time(NULL)));
	std::random_shuffle(deck.begin(), deck.end());
}

Deck::~Deck()
{
}

std::ostream& operator<<(std::ostream& out, const Deck& deck)
{
	std::string space = " ";
	for (const auto& card : deck.deck) {
		out << card << '\n';
	}
	return out;
}
