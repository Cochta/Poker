#pragma once
#include <string>
enum class Suit {
	CLUBS,
	HEARTS,
	SPADES,
	DIAMONDS,
	enumEnd
};
enum class Value {
	TWO = 2,
	THREE = 3,
	FOUR = 4,
	FIVE = 5,
	SIX = 6,
	SEVEN = 7,
	EIGHT = 8,
	NINE = 9,
	TEN = 10,
	JACK = 11,
	QUEEN = 12,
	KING = 13,
	ACE = 14,
	enumEnd
};
class Card
{
public:
	Card(Suit, Value);
private:
	std::string suitToString();
	std::string valueToString();
	Suit suit;
	Value value;
public:
	std::string ToString();
	Suit GetSuit() { return suit; };
	void SetSuit(Suit _suit) { suit = _suit; };
	void SetValue(Value _value) { value = _value; };
	Value GetValue() { return value; };
};

