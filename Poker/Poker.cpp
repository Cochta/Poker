#include <iostream>
#include <limits>
#include "Card.h"
#include "DeckOfCards.h"
#include "Player.h"
#include <cstdlib>
#include <regex>


int main()
{
	const int NB_CARDS = 5;
	std::vector<Player> players;
	int nbPlayers;
	std::cout << "How many players is there ?" << std::endl;
	while (!(std::cin >> nbPlayers)) {// allows the user to only input numerical values
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid input.  Try again: ";
	}

	for (int i = 1; i < nbPlayers + 1; i++) // init players
	{
		std::string name;
		std::cout << "Enter the name of player " << i << std::endl;
		std::cin >> name;
		players.emplace_back(Player(name, i));
	}

	/*Player bernard = Player("bernard", 0);
	Card card1 = Card(Suit::CLUBS, Value::ACE);
	Card card2 = Card(Suit::CLUBS, Value::KING);
	Card card3 = Card(Suit::CLUBS, Value::JACK);
	Card card4 = Card(Suit::CLUBS, Value::TEN);
	Card card5 = Card(Suit::CLUBS, Value::QUEEN);
	bernard.hand.emplace_back(card1);
	bernard.hand.emplace_back(card2);
	bernard.hand.emplace_back(card3);
	bernard.hand.emplace_back(card4);
	bernard.hand.emplace_back(card5);
	players.emplace_back(bernard);*/

	std::string newgame = "y";
	while (newgame != "n")
	{
		system("cls");//clears console
		DeckOfCards myDeck;
		myDeck.Shuffle();

		for (Player player : players)//each player picks 5 cards 
		{
			player.FillHand(NB_CARDS, myDeck);
			player.Sort();
			std::cout << player.ToString();
		}

		for (Player player : players)// each player puts his cards back into the deck
		{
			player.ClearHand(myDeck);
		}

		std::cout << "Would you like to play another round ?" << std::endl;
		std::cout << "Type y for yes or n for no" << std::endl;
		while (std::cin >> newgame) {// allows the user to only input y or n
			if (newgame == "y" || newgame == "n")
				break;
			else
				std::cout << "Your input is not correct, only characters y and n are allowed:" << std::endl;
		}
	}
}
