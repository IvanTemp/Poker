#pragma once
#include <string>
#include <fstream>
class Card
{
public:
	Card();
	Card(size_t _rank, std::string _suit);
	~Card();
	void print_card() const;

	const size_t get_rank() {
		return rank;
	}
	const std::string get_suit() {
		return suit;
	}
	friend bool operator< (const Card& c1, const Card& c2);

	friend std::ostream& operator<< (std::ostream& out, const Card& card);

private:
	size_t rank;
	std::string suit;
};