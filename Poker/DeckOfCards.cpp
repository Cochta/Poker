#include "DeckOfCards.h"
#include <iostream>
DeckOfCards::DeckOfCards() {
	//char valueArray[13] = { 2,3,4,5,6,7,8,9,10,'J','Q','K','A' };
	//std::string symbolArray[4] = { "Pike", "Trèfle", "Carreau","Coeur" };
	for (int suit = (int)Suit::CLUBS; suit < (int)Suit::enumEnd; suit++)
	{
		for (int value = (int)Value::TWO; value < (int)Value::enumEnd; value++)
		{
			cards.emplace_back(Card(static_cast<Suit>(suit), static_cast<Value>(value)));
		}
	}
}
void DeckOfCards::Shuffle() {
	std::shuffle(this->cards.begin(), this->cards.end(), std::random_device());
}
std::string DeckOfCards::ToString() {
	std::string string = "The deck contains the following cards: \n";
	for (Card card : this->cards)
	{
		string += card.ToString() + "\n";
	}
	return string;
};