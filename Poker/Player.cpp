#include "Player.h"
Player::Player(std::string _name, int _id) {
	this->name = _name;
	this->id = _id;
};
void Player::DrawCard(DeckOfCards& _deck) {
	this->hand.emplace_back(_deck.cards[0]);
	_deck.cards.erase(_deck.cards.begin());
}
void Player::FillHand(int _nbCard, DeckOfCards& _deck) {
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
std::string Player::ToString() {
	std::string string = "Player " + this->name + " cards are:\n";
	for (Card card : this->hand)
	{
		string += card.ToString() + "\n";
	}
	string += "\n";
	return string;
};

int compareCards(Card _card1, Card _card2) {// test qui ne fais pas parti du code, pas besoin de regarder
	return (int)_card1.GetValue() - (int)_card2.GetValue();
}
int Player::evaluateHand() { // test qui ne fais pas parti du code, pas besoin de regarder
	/*std::sort(hand.begin(), hand.end());
	//std::sort(hand.begin(), 5, hand.size(), compareCards);
	int straight, flush, three, four, full, pairs;
	int k;

	straight = flush = three = four = full = pairs = 0;
	k = 0;

	//checks for flush
	while (k < 4 && hand[k].GetSuit() == hand[k + 1].GetSuit())
		k++;
	if (k == 4)
		flush = 1;

	// checks for straight
	k = 0;
	while (k < 4 && (int)hand[k].GetValue() == (int)hand[k + 1].GetValue() - 1)
		k++;
	if (k == 4)
		straight = 1;

	// checks for fours 
	for (int i = 0; i < 2; i++) {
		k = i;
		while (k < i + 3 && hand[k].GetValue() == hand[k + 1].GetValue())
			k++;
		if (k == i + 3)
			four = 1;
	}

	//checks for threes and fullhouse
	if (!four) {
		for (int i = 0; i < 3; i++) {
			k = i;
			while (k < i + 2 && hand[k].GetValue() == hand[k + 1].GetValue())
				k++;
			if (k == i + 2) {
				three = 1;
				if (i == 0) {
					if (hand[3].GetValue() == hand[4].GetValue())
						full = 1;
				}
				else if (i == 1) {
					if (hand[0].GetValue() == hand[4].GetValue())
						full = 1;
				}
				else {
					if (hand[0].GetValue() == hand[1].GetValue())
						full = 1;
				}
			}
		}
	}*/
	return 0;
}