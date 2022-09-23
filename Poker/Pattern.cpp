#include "Pattern.h"
Pattern::Pattern(HandRank _rank, Value _value1, Value _value2, Value _value3) {
	patternRank = _rank;
	firstCard = _value1;
	secondCard = _value2;
	thirdCard = _value3;
}

std::string Pattern::HandRankToString()// return the hand ranking as a string
{
	switch (patternRank)
	{
	case HandRank::HIGHCARD:
		return "high card";
	case HandRank::PAIR:
		return "pair";
	case HandRank::TWOPAIR:
		return "two pairs";
	case HandRank::THREEOFAKIND:
		return "three of a kind";
	case HandRank::STRAIGHT:
		return "straight";
	case HandRank::FLUSH:
		return "flush";
	case HandRank::FULLHOUSE:
		return "full house";
	case HandRank::FOUROFAKIND:
		return "four of a kind";
	case HandRank::STRAIGHTFLUSH:
		return "straight flush";
	case HandRank::ROYALFLUSH:
		return "royal flush";
	default:
		return "Unknown";
	}
}