#include "Card.h"
#include <iostream>
#include <string>

using namespace std;

Card::Card()
{
}

Card::Card(string _rank, string _suit)
{
	rank = _rank;
	suit = _suit;
}

Card::~Card()
{
}

void Card::print_card()
{
	cout << rank << " " << suit << endl;
}

void Card::set_rank(string _rank)
{
	rank = _rank;
}

void Card::set_suit(string _suit)
{
	suit = _suit;
}

