#include "Checker.h"
#include "Card.h"

Checker::Checker() {
	//combinations

}


bool operator<(Card& card1, Card& card2) {
	return card1.get_rank() < card2.get_rank();
}

Checker::~Checker()
{

}

bool Checker::OlderCard() {

}
