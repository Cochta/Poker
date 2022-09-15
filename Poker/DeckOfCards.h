#pragma once
#include <string>
#include <algorithm>
#include <random>
#include "Card.h"
#include "vector"

class DeckOfCards
{
public:
	DeckOfCards();
private:

public:
	std::vector<Card> cards;
	void Shuffle();
	std::string ToString();
};

