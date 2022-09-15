#include <iostream>
#include "Card.h"
#include "DeckOfCards.h"
#include "Player.h"
#include <cstdlib>

int main()
{
	const int NB_CARDS = 5;
	std::vector<Player> players;
	int nbPlayers;
	std::cout << "How many players is there ?" << std::endl;
	std::cin >> nbPlayers;
	for (int i = 1; i < nbPlayers + 1; i++) // init players
	{
		std::string name;
		std::cout << "Enter the name of player " << i << std::endl;
		std::cin >> name;
		players.emplace_back(Player(name, i));
	}
	char newgame = 'y';
	while (newgame != 'n')
	{
		system("cls");//clears console
		DeckOfCards myDeck;
		myDeck.Shuffle();

		for (Player player : players)//each player picks 5 cards 
		{
			player.FillHand(NB_CARDS, myDeck);
			std::cout << player.ToString();
		}
		for (Player player : players)// each player puts his cards back into the deck
		{
			player.ClearHand(myDeck);
		}
		std::cout << "Would you like to play another round ?" << std::endl;
		std::cout << "Type y for yes or n for no" << std::endl;
		std::cin >> newgame;
	}
}
