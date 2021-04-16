#include "Card.h"
#include <iostream>
#include <string>

using namespace std;

Card::Card()
{
}

Card::Card(size_t _rank, string _suit)
{
	rank = _rank;
	suit = _suit;
}

Card::~Card()
{
}

void Card::print_card() const
{
	cout << rank << " " << suit << endl;
}

bool operator<(const Card& c1, const Card& c2)
{
	return c1.rank < c2.rank;
}
