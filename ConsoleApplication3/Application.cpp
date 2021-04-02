#include "Application.h"

Application::Application()
{
}

Application::~Application()
{
}

void Application::set_game_deck(Deck& deck) {
	game_deck.push_back(deck.get_card());
	game_deck.push_back(deck.get_card());
	game_deck.push_back(deck.get_card());
	game_deck.push_back(deck.get_card());
	game_deck.push_back(deck.get_card());
}

void Application::set_hand_deck(Deck& deck, Hand& hand) {
	hand.get_card(deck);
	hand.get_card(deck);
}

void Application::play()
{
	// по умолчанию перемешивается при создании
	Deck deck;
	Hand hand;
	
	string answer;

	do
	{
		set_game_deck(deck);
		set_hand_deck(deck, hand);

	} while (true);



}
