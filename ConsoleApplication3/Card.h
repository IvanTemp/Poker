#pragma once
#include <string>
class Card
{
public:
	Card();
	Card(std::string _rank, std::string _suit);
	~Card();
	void print_card();

	void set_rank(std::string _rank);
	void set_suit(std::string _suit);
private:
	std::string rank, suit;
};

