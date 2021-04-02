#pragma once

#include <vector>
#include "Card.h"
#include "Deck.h"
#include "Hand.h"


using namespace std;

class Application
{
public:
	Application();
	~Application();

	void set_game_deck(Deck& deck);
	void set_hand_deck(Deck& deck, Hand& hand);

	void play();
private:
	vector<Card> game_deck;
};

