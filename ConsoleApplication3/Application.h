#pragma once

#include <vector>
#include "Card.h"
#include "Deck.h"


using namespace std;

class Application
{
public:
	Application();
	~Application();

	void set_game_deck(Deck &deck);
	void play();
private:
	vector<Card> game_deck;
};

