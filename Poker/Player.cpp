#include "Player.h"
#include <iostream>
#include <stdio.h>
#include <map>
#include <algorithm>

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
	EvaluateHand();
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
		string += card.ToString() + " \n";
	}
	string += "He got a " + this->pattern.HandRankToString() + "\n" + "\n";

	return string;
};

struct Xgreater
{
	bool operator()(Card& lx, Card& rx) const {
		return lx.GetValue() < rx.GetValue();
	}
};

void Player::Sort() {

	std::sort(this->hand.begin(), this->hand.end(), Xgreater());
};

bool ValueIsEqual(Card _card1, Card _card2) {
	return _card1.GetValue() == _card2.GetValue();
}

void Player::EvaluateHand() {
	Sort();
	int straight = 0;
	int flush = 0;
	bool four = false, full = false, three = false, twoPairs = false, pair = false;

	for (int i = 0; i < hand.size(); i++)// detect if flush and suit
	{
		if (hand[0].GetSuit() == hand[i].GetSuit())
			flush++;
		if ((int)hand[0].GetValue() == (int)hand[i].GetValue() - i)
			straight++;
	}
	if (straight == 5 && flush == 5 && hand[4].GetValue() == Value::ACE) // straight flush
	{
		pattern = Pattern(HandRank::ROYALFLUSH);
		return;
	}
	else if (straight == 5 && flush == 5)
	{
		pattern = Pattern(HandRank::STRAIGHTFLUSH, hand[4].GetValue());
		return;
	}
	else if (flush == 5)
	{
		pattern = Pattern(HandRank::FLUSH);
	}
	else if (straight == 5)
	{
		pattern = Pattern(HandRank::STRAIGHT, hand[4].GetValue());
	}

	std::map<Value, int> countValue;
	std::map<Suit, int> countSuit;

	for (auto& card1 : hand)
	{
		int cntV = 0;
		int cntS = 0;
		for (auto& card2 : hand)
		{
			if (card1.GetValue() == card2.GetValue())
			{
				cntV++;
			}
		}
		countValue[card1.GetValue()] = cntV;
		countSuit[card1.GetSuit()] = cntS;
	}
	for (auto val : countValue)
	{
#pragma region Four of a kind

		if (val.second == 4)
		{
			for (auto& val2 : countValue)
			{
				if (val != val2)
				{
					pattern = Pattern(HandRank::FOUROFAKIND, val.first, val2.first);
					return;
				}
			}

		}
#pragma endregion 

#pragma region Full house and three of a kind
		if (val.second == 3)
		{
			for (auto& val2 : countValue)
			{
				if (val2.second == 2)
				{
					pattern = Pattern(HandRank::FULLHOUSE, val.first, val2.first);
					return;
				}
				if (val2.second == 1)
				{
					for (auto& val3 : countValue)
					{
						if (val2 != val3)
						{
							pattern = Pattern(HandRank::THREEOFAKIND, val.first, val2.first, val3.first);
							return;
						}
					}
				}
			}
		}
#pragma endregion

#pragma region pairs and two pairs
		if (val.second == 2)
		{
			for (auto& val2 : countValue)
			{
				if (val != val2 && val2.second == 2)
				{
					for (auto& val3 : countValue)
					{
						if (val3.second == 1)
						{
							std::vector<Value> bestpair;
							bestpair.emplace_back(val.first);
							bestpair.emplace_back(val2.first);
							std::sort(bestpair.begin(), bestpair.end());
							pattern = Pattern(HandRank::TWOPAIR, bestpair[0], bestpair[1], val3.first);
							return;
						}
					}

				}
			}
			pattern = Pattern(HandRank::PAIR, val.first);
			return;
		}
#pragma endregion
	}

	pattern = Pattern(HandRank::HIGHCARD);
	return;


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
}