#include "DeckOfCards.h"
#include <iostream>
DeckOfCards::DeckOfCards() { // default and only constructor
	for (int suit = (int)Suit::CLUBS; suit < (int)Suit::enumEnd; suit++)
	{
		for (int value = (int)Value::TWO; value < (int)Value::enumEnd; value++)
		{
			cards.emplace_back(Card(static_cast<Suit>(suit), static_cast<Value>(value)));
		}
	}
}

void DeckOfCards::Shuffle() { // shuffles the deck (the vector) randomly
	std::shuffle(this->cards.begin(), this->cards.end(), std::random_device());
}

std::string DeckOfCards::ToString() { // returns all cards in the deck as a string
	std::string string = "The deck contains the following cards: \n";
	for (Card card : this->cards)
	{
		string += card.ToString() + "\n";
	}
	return string;
};