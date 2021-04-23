#include "Application.h"
#include "Checker.h"

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
	size_t total_score = 0;
	size_t score = 0;
	
	string answer;

	do
	{
		game_deck = {};
		set_game_deck(deck);

		sort(game_deck.begin(), game_deck.end());

		for (auto card : game_deck) {
			card.print_card();
		}

		// проверить комбинации и записать счет
		Checker checker;
		score = checker.WinnerCombination(game_deck);
		cout << "Your score from this combination: " << score << endl;

		cout << "Your total score: " << total_score << endl;
		cout << "Would you like to play again? (y/n)" << endl;
		cin >> answer;
		if (answer == "y")
		{
			total_score += score;
			score = 0;
			continue;
		}
		else
			break;
	} while (true);

	cout << "Your total score: " << total_score << endl;
}
