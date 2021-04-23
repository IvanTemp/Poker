#include "Checker.h"
#include "Card.h"

Checker::Checker() {
	
	
}
Checker::~Checker()
{
	
}

bool Checker::OlderCard(vector<Card>& game_deck)
{
	return false;
}

bool Checker::Pair(vector<Card>& game_deck)
{
	for (size_t i = 0; i < game_deck.size() - 1; i++)
	{
		Card card1 = game_deck[i],
			card2 = game_deck[i + 1];
	}
	return false;
}

bool Checker::TwoPairs(vector<Card>& game_deck)
{
	bool first_pair = false, second_pair = false;

	size_t index = 0;
	for (size_t i = 0; i < game_deck.size() - 1; i++) {
		Card card1 = game_deck[i],
			card2 = game_deck[i + 1];

		if (card1.get_rank() == card2.get_rank()) {
			first_pair = true;
			index = i;
			break;
		}
	}

	for (size_t i = index; i < game_deck.size() - 1; i++) {
		Card card1 = game_deck[i],
			card2 = game_deck[i + 1];

		if (card1.get_rank() == card2.get_rank()) {
			second_pair = true;
			break;
		}
	}

	return first_pair && second_pair;
}

bool Checker::Triple(vector<Card>& game_deck)
{
	for (size_t i = 0; i < game_deck.size() - 2; i++) {
		Card card1 = game_deck[i],
			card2 = game_deck[i + 1],
			card3 = game_deck[i + 2];

		if (card1.get_rank() == 
			card2.get_rank() == 
			card3.get_rank())
			return true;
	}

	return false;
}

bool Checker::Straight(vector<Card>& game_deck)
{
	bool flag = true;
	for (size_t i = 0; i < game_deck.size() - 1; i++)
		flag = game_deck[i + 1].get_rank() == game_deck[i].get_rank() + 1;
	return flag;
}

bool Checker::Flush(vector<Card>& game_deck)
{
	bool flag = true;
	for (size_t i = 0; i < game_deck.size() - 1; i++)
		flag = game_deck[i].get_suit() == game_deck[i + 1].get_suit();
	return flag;
}

bool Checker::FullHouse(const vector<Card>& game_deck)
{	
	vector<Card> left = { game_deck.cbegin(), game_deck.cbegin() + 3 };
	vector<Card> right = { game_deck.cbegin() + 3, game_deck.cend() };

	bool flag = false;
	if (Triple(left) && Pair(right))
		flag = true;

	left = { game_deck.cbegin(), game_deck.cbegin() + 2 };
	right = { game_deck.cbegin() + 2, game_deck.cend() };

	return flag || Pair(left) && Triple(right);
}

bool Checker::Kare(const vector<Card>& game_deck)
{
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

bool Checker::StraightFlush(vector<Card>& game_deck)
{
	if (Straight(game_deck) && Flush(game_deck)) {
		return true;
	}
	return false;
}

bool Checker::RoyalFlush(vector<Card>& game_deck)
{
	// 5 карт от 10 до туза одной масти
	if (Straight(game_deck) && game_deck[0].get_rank() == 10 && Flush(game_deck)) {
		return true;
	}
	return false;
}

size_t Checker::WinnerCombination(vector<Card> game_deck)
{
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

