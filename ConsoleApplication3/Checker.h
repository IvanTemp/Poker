#pragma once
#include <vector>
#include <iostream>
#include <map>
#include "Card.h"
#include "Hand.h"

using namespace std;

class Checker
{
public:
	Checker();
	~Checker();

	bool OlderCard(const vector<Card>& game_deck);

	bool Pair(const vector<Card>& game_deck);
	
	bool TwoPairs(const vector<Card>& game_deck);
	
	bool Triple(const vector<Card>& game_deck);
	
	bool Straight(const vector<Card>& game_deck);

	bool Flush(const vector<Card>& game_deck);
	
	// TODO: определить, как проверить колоду по частям
	bool FullHouse(const vector<Card>& game_deck);
	
	bool Kare(const vector<Card>& game_deck);
	
	bool StraightFlush(const vector<Card>& game_deck);

	bool RoyalFlush(const vector<Card>& game_deck);
	
	/*
	* @return scores
	*/
	size_t WinnerCombination(const vector<Card> game_deck);

private:
};

