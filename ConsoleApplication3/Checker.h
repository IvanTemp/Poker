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

	bool OlderCard(vector<Card>& game_deck) {
		return false;
	}
	bool Pair(vector<Card>& game_deck) {
		for (size_t i = 0; i < game_deck.size(); i++)
		{
			Card card1 = game_deck[i];
			for (size_t j = 0; j < game_deck.size(); j++)
			{
				Card card2 = game_deck[j];
				if (i != j && card1.get_rank() == card2.get_rank())
					return true;
			}
		}
		return false;
	}
	
	bool TwoPairs(vector<Card>& game_deck) {
		return false;
	}
	
	bool Triple(vector<Card>& game_deck) {
		return false;
	}
	
	bool Straight(vector<Card>& game_deck) {
		bool flag = true;
		for (size_t i = 0; i < game_deck.size() - 1; i++)
			flag = game_deck[i + 1].get_rank() == (game_deck[i].get_rank() + 1);
		return flag;
	}

	bool Flush(vector<Card>& game_deck) {
		bool flag = true;
		for (size_t i = 0; i < game_deck.size() - 1; i++)
			flag = game_deck[i].get_suit() == game_deck[i + 1].get_suit();
		return flag;
	}
	
	// TODO: определить, как проверить колоду по частям
	bool FullHouse(vector<Card>& game_deck) {
		if (Triple(game_deck) && Pair(game_deck))
			return true;
		return false;
	}
	
	bool Kare(vector<Card>& game_deck) {
		vector<size_t> ranks;

		for (auto card : game_deck) {
			ranks.push_back(card.get_rank());
		}

		// j,k,k,k,k
		bool flag1 = true, flag2 = true;
		for (size_t i = 1; i < ranks.size() - 1; i++)
		{
			flag1 = ranks[i] == ranks[i + 1];
		}

		for (size_t i = 0; i < 2; i++)
		{
			flag2 = ranks[i] == ranks[i + 1];
		}
		return flag1 || flag2;
	}
	
	bool StraightFlush(vector<Card>& game_deck) {
		if (Straight(game_deck) && Flush(game_deck)) {
			return true;
		}
		return false;
	}

	bool RoyalFlush(vector<Card>& game_deck) {
		// 5 карт от 10 до туза одной масти
		if (Straight(game_deck) && game_deck[0].get_rank() == 10 && Flush(game_deck)) {
			return true;
		}
		return false;
	}
	
	/*
	* @return scores
	*/
	size_t WinnerCombination(vector<Card> game_deck) {
		// TODO: сделать оператор сравнения для сортировки
		//sort(game_deck.begin(), game_deck.end());

		if (RoyalFlush(game_deck))
			return 100;

		else if (StraightFlush(game_deck))
			return 90;

		else if (Kare(game_deck))
			return 80;
		
		else if (FullHouse(game_deck))
			return 70;
		
		else if (Flush(game_deck))
		{
			return 60;
		}
		else if (Straight(game_deck)) {
			return 50;
		}
		else if (Triple(game_deck)) {
			return 40;
		}
		else if (TwoPairs(game_deck)) {
			return 30;
		}
		if (Pair(game_deck)) {
			return 20;
		}
		else {
			return 10;
		}
	}

private:
};

