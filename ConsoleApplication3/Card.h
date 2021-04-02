#pragma once
#include <string>
class Card
{
public:
	Card();
	Card(std::string _rank, std::string _suit);
	~Card();
	void print_card();

	std::string get_rank() {
		return rank;
	}
private:
	std::string rank, suit;
};

