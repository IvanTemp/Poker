#pragma once
#include <vector>
#include <map>
#include "Card.h"
#include "Hand.h"

using namespace std;

class Checker
{
	Checker();
	~Checker();

	bool OlderCard(vector<Card>& hand_deck, vector<Card>& game_deck) {

	}
	bool Pair(vector<Card>& game_deck);
	bool TwoPairs(vector<Card>& game_deck);
	bool Triple(vector<Card>& game_deck);
	bool Straight(vector<Card>& game_deck);
	bool Flush(vector<Card>& game_deck);
	bool FullHouse(vector<Card>& game_deck);
	bool Kare(vector<Card>& game_deck);
	bool StraightFlush(vector<Card>& game_deck);
	bool RoyalFlush(vector<Card>& game_deck);

	vector<Card> WinnerCombination(vector<Card> hand_deck, vector<Card> game_deck) {
		game_deck.push_back(hand_deck[0]);
		game_deck.push_back(hand_deck[1]);

		sort(game_deck.begin(), game_deck.end());

		bool result = RoyalFlush(game_deck);
	}

private:
	map<vector<Card>, int> combinations;
};

