#include "Application.h"
#include "Hand.h"

Application::Application()
{
}

Application::~Application()
{
}

void Application::set_game_deck(Deck& deck)
{
	game_deck.push_back(deck.get_card());
	game_deck.push_back(deck.get_card());
	game_deck.push_back(deck.get_card());
	game_deck.push_back(deck.get_card());
	game_deck.push_back(deck.get_card());
}

void Application::play()
{
	Deck deck;
	deck.shuffle();
	Hand hand1;

	hand1.get_card(deck);
	hand1.get_card(deck);

	set_game_deck(deck);


}
