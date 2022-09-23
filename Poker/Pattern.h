#pragma once
#include <string>
#include "Card.h"
enum class HandRank {
	HIGHCARD,
	PAIR,
	TWOPAIR,
	THREEOFAKIND,
	STRAIGHT,
	FLUSH,
	FULLHOUSE,
	FOUROFAKIND,
	STRAIGHTFLUSH,
	ROYALFLUSH
};
class Pattern
{
public:
	Pattern(HandRank _rank, Value _value1 = Value::TWO, Value _value2 = Value::TWO, Value _value3 = Value::TWO);

	Value firstCard = Value::TWO;
	Value secondCard = Value::TWO;
	Value thirdCard = Value::TWO;
private:


public:

	HandRank patternRank = HandRank::HIGHCARD;
	std::string HandRankToString();
};

