#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include <time.h>
#include "Card.h"
#include "Deck.h"
#include "Hand.h"


using namespace std;

int main() 
{	
	Deck deck;
	Hand hand;

	hand.get_card(deck);
	hand.get_card(deck);

	hand.print_hand_deck();

    return 0;
}