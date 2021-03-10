#pragma once
#include <vector>
#include <string>
#include <time.h>
#include "Card.h"
#include <random>

using namespace std;
class Deck
{
public:
	Deck();
	void print();
	Card get_card();
	void shuffle();
	~Deck();
private:
	vector<string> RANKS = { "2", "3", "4", "5", "6", "7",
							"8", "9", "10", "J", "Q", "K", "A" };
	vector<string> SUITS = {
		"D", "H", "V", "P" // обозначить масти карт
	};
	vector<Card> deck;
};

