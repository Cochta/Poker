#pragma once
#include <string>
#include <algorithm>
#include <random>
#include "Card.h"
#include <vector>

class DeckOfCards
{

public:
	DeckOfCards();// default and only constructor

private:

public:
	std::vector<Card> cards;
	void Shuffle();// shuffles the deck (the vector) randomly
	std::string ToString();// returns all cards in the deck as a string

};

