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
	friend std::ostream& operator<< (std::ostream& out, const Deck& point);
private:
	vector<size_t> RANKS = { 2, 3, 4, 5, 6, 7,
							8, 9, 10, 11, 12, 13, 14 };
	vector<string> SUITS = {
		"D", "H", "V", "P"
	};
	vector<Card> deck;
};

