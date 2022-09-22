#include <iostream>
#include <limits>
#include "Card.h"
#include "DeckOfCards.h"
#include "Player.h"
#include <cstdlib>

struct GreaterRank
{
	bool operator()(Player& lx, Player& rx) const {
		return lx.pattern.patternRank > rx.pattern.patternRank;
	}
};
bool isGreaterPattern(Player _p1, Player _p2)
{
	if (_p1.pattern.patternRank != _p2.pattern.patternRank)
	{
		return _p1.pattern.patternRank > _p2.pattern.patternRank;
	}
	else if (_p1.pattern.patternRank == HandRank::HIGHCARD && _p1.pattern.patternRank == _p2.pattern.patternRank)
	{
		for (int i = 4; i > 0; i--)
		{
			std::cout << (int)_p1.hand[i].GetValue() << " - " << (int)_p2.hand[i].GetValue() << std::endl;
			if ((int)_p1.hand[i].GetValue() == (int)_p2.hand[i].GetValue())
			{
				continue;
			}
			else
			{
				return (int)_p1.hand[i].GetValue() > (int)_p2.hand[i].GetValue();
			}
		}
	}
	return false;
	// reste à incrémenter les autres possibilités je n'ai pas le temps de faire maintenant
}

bool isPatternEqual(Player _p1, Player _p2)
{
	if (_p1.pattern.patternRank == HandRank::HIGHCARD && _p1.pattern.patternRank == _p2.pattern.patternRank)
	{
		for (int i = 4; i > 0; i--)
		{
			std::cout << (int)_p1.hand[i].GetValue() << " - " << (int)_p2.hand[i].GetValue() << std::endl;
			if ((int)_p1.hand[i].GetValue() == (int)_p2.hand[i].GetValue())
			{
				continue;
			}
			else
			{
				return false;
			}
		}
		return true;
	}
	// reste à incrémenter les autres possibilités je n'ai pas le temps de faire maintenant
	return false;
}

std::string GetWinner(std::vector<Player> _players) {
	std::vector<Player> winners;
	Player bestPlayer = Player("Default", 14);
	bestPlayer.pattern = Pattern(HandRank::HIGHCARD);
	bestPlayer.hand.push_back(Card(Suit::enumEnd, Value::TWO));
	bestPlayer.hand.push_back(Card(Suit::DIAMONDS, Value::FOUR));
	bestPlayer.hand.push_back(Card(Suit::SPADES, Value::FIVE));
	bestPlayer.hand.push_back(Card(Suit::CLUBS, Value::SIX));
	bestPlayer.hand.push_back(Card(Suit::HEARTS, Value::SEVEN));
	for (Player player : _players)
	{
		if (isPatternEqual(player, bestPlayer))
		{
			winners.emplace_back(player);
		}
		else if (isGreaterPattern(player, bestPlayer))
		{
			bestPlayer = player;
			bestPlayer.hand = player.hand;
			bestPlayer.pattern = player.pattern;
			winners = { bestPlayer };
		}

	}

	std::string winnerStr = "And the winner is: ";
	if (winners.size() > 1)
	{
		winnerStr = "Their is a draw betwin: ";
	}
	for (auto& i : winners)
	{
		winnerStr += i.GetName() + ", ";
	}
	return winnerStr;
}
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
	Card card1 = Card(Suit::DIAMONDS, Value::TWO);
	Card card2 = Card(Suit::CLUBS, Value::NINE);
	Card card3 = Card(Suit::CLUBS, Value::TWO);
	Card card4 = Card(Suit::CLUBS, Value::FIVE);
	Card card5 = Card(Suit::CLUBS, Value::THREE);
	bernard.hand.emplace_back(card1);
	bernard.hand.emplace_back(card2);
	bernard.hand.emplace_back(card3);
	bernard.hand.emplace_back(card4);
	bernard.hand.emplace_back(card5);
	players.emplace_back(bernard);
	bernard.EvaluateHand();
	std::cout << bernard.pattern.HandRankToString();*/

	std::string newgame = "y";
	while (newgame != "n")
	{
		system("cls");//clears console
		DeckOfCards myDeck;
		myDeck.Shuffle();

		for (Player& player : players)//each player picks 5 cards 
		{
			player.FillHand(NB_CARDS, myDeck);

			std::cout << player.ToString();
		}
		std::cout << GetWinner(players) << std::endl;

		for (Player& player : players)// each player puts his cards back into the deck
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
