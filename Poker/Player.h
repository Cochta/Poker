#pragma once
#include "vector"
#include "Card.h"
#include "DeckOfCards.h"
#include <string>
#include <iostream>
#include <algorithm> 
class Player
{
public:
	Player(std::string _name, int _id);
private:
	std::string name;
	int id;

public:
	std::vector<Card> hand;

	void SetId(int _id) { id = _id; };
	int GetId() { return id; };
	void SetName(std::string _name) { name = _name; };
	std::string GetName() { return name; };
	void FillHand(int _nbCard, DeckOfCards& _deck);
	void DrawCard(DeckOfCards& _deck);
	void ClearHand(DeckOfCards& _deck);
	std::string ToString();
	int evaluateHand();
};

