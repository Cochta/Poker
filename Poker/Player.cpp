#include "Player.h"
#include <iostream>
#include<stdio.h>

Player::Player(std::string _name, int _id) {// default and only constructor
	this->name = _name;
	this->id = _id;
};

void Player::DrawCard(DeckOfCards& _deck) {// takes 1 card from the deck
	this->hand.emplace_back(_deck.cards[0]);
	_deck.cards.erase(_deck.cards.begin());
}

void Player::FillHand(int _nbCard, DeckOfCards& _deck) { // gives x number of cards to the player
	for (int i = 0; i < _nbCard; i++)
	{
		DrawCard(_deck);
	}
};

void Player::ClearHand(DeckOfCards& _deck) {
	for (Card card : this->hand)
	{
		_deck.cards.emplace_back(card);
	}
	this->hand.clear();
};

std::string Player::ToString() {// returns all cards in the hand as a string
	std::string string = "Player " + this->name + " cards are:\n";
	for (Card card : this->hand)
	{
		string += card.ToString() + "\n";
	}
	string += "He got a " + HandRankToString() + "\n" + "\n";

	return string;
};

int compareCards(Card _card1, Card _card2) {// test qui ne fais pas parti du code, pas besoin de regarder
	return (int)_card1.GetValue() - (int)_card2.GetValue();
}

void Player::Sort() {
	struct Xgreater
	{
		bool operator()(Card& lx, Card& rx) const {
			return lx.GetValue() < rx.GetValue();
		}
	};
	std::sort(hand.begin(), hand.end(), Xgreater());
};

HandRank Player::EvaluateHand() {  // C'EST DEGEULASSE PUTIN JE SAIS PAS CODER
	Sort();
	int straight = 0;
	int flush = 0;

	for (int i = 0; i < hand.size(); i++)// detect if flush
	{
		if (hand[0].GetSuit() == hand[i].GetSuit())
			flush++;
	}

	for (int i = 0; i < hand.size(); i++)// detect if straight
	{
		if ((int)hand[0].GetValue() == (int)hand[i].GetValue() - i)
			straight++;
	}

	std::vector<int> pairs; // très laid
	for (int i = 0; i < hand.size(); i++)// detects number of pairs three of a kind and four of a kind
	{
		pairs.emplace_back(0);
		for (int j = 0; j < hand.size(); j++)
		{
			if (hand[i].GetValue() == hand[j].GetValue())
			{
				pairs[i] += 1;
			}
		}
	}
	std::sort(pairs.rbegin(), pairs.rend());
	if (straight == 5 && flush == 5 && hand[4].GetValue() == Value::ACE)
		return HandRank::ROYALFLUSH;
	else if (straight == 5 && flush == 5)
		return HandRank::STRAIGHTFLUSH;
	else if (pairs[0] == 4)
		return HandRank::FOUROFAKIND;
	else if (pairs[0] == 3 && pairs[3] == 2)
		return HandRank::FULLHOUSE;
	else if (flush == 5)
		return HandRank::FLUSH;
	else if (straight == 5)
		return HandRank::STRAIGHT;
	else if (pairs[0] == 3)
		return HandRank::THREEOFAKIND;
	else if (pairs[0] == 2 && pairs[3] == 2)
		return HandRank::TWOPAIR;
	else if (pairs[0] == 2)
		return HandRank::PAIR;
	else
		return HandRank::HIGHCARD;

}
std::string Player::HandRankToString()// return the hand ranking as a string
{
	switch (EvaluateHand())
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

