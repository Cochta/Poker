#pragma once
#include "vector"
#include "Card.h"
#include "DeckOfCards.h"
#include <string>
#include <iostream>
#include <algorithm> 
#include "Pattern.h"
class Player
{
public:
	Player(std::string _name, int _id);// default and only constructor
	Pattern pattern = Pattern(HandRank::HIGHCARD);
private:
	std::string name;
	int id;

	
public:
	std::vector<Card> hand;

	void SetId(int _id) { id = _id; };
	int GetId() { return id; };

	void SetName(std::string _name) { name = _name; };
	std::string GetName() { return name; };

	/*void SetRank(HandRank _rank) { rank = _rank; };
	HandRank GetRank() { return rank; };*/

	void DrawCard(DeckOfCards& _deck);// takes 1 card from the deck
	void FillHand(int _nbCard, DeckOfCards& _deck);// gives x number of cards to the player
	void ClearHand(DeckOfCards& _deck);

	std::string ToString();// returns all cards in the hand as a string
	void Sort();
	void EvaluateHand();
};

