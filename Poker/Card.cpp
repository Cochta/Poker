#include "Card.h"

Card::Card(Suit _suit, Value _value) { // default and only constructor 
	this->suit = _suit;
	this->value = _value;
}

std::string Card::suitToString() // return the suit as a string
{
	switch (GetSuit())
	{
	case Suit::CLUBS:
		return "clubs";
	case Suit::HEARTS:
		return "hearts";
	case Suit::SPADES:
		return "spades";
	case Suit::DIAMONDS:
		return "diamonds";
	default:
		return "unknown";
	}
}


std::string Card::valueToString()// return the value as a string
{
	switch (GetValue())
	{
	case Value::TWO:
		return "2";
	case Value::THREE:
		return "3";
	case Value::FOUR:
		return "4";
	case Value::FIVE:
		return "5";
	case Value::SIX:
		return "6";
	case Value::SEVEN:
		return "7";
	case Value::EIGHT:
		return "8";
	case Value::NINE:
		return "9";
	case Value::TEN:
		return "10";
	case Value::JACK:
		return "Jack";
	case Value::QUEEN:
		return "Queen";
	case Value::KING:
		return "King";
	case Value::ACE:
		return "Ace";
	default:
		return "Unknown";
	}
}

std::string Card::ToString() {// return the value and the suit as a string
	return valueToString() + " of " + suitToString();
}
