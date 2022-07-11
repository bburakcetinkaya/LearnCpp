#ifndef BLACKJACK_H
#define BLACKJACK_H
#include "Deck.h"
#include "Print.h"
#include <vector>

using user_t = std::vector<Card>;
namespace BlackJack
{
	enum user
	{
		player,
		dealer
	};
	void play(const deck_t& deck);
	void drawCards(const deck_t& deck, user_t& cards);
	void printCurrentState(const BlackJack::user selection, user_t& cards);
	int calculatePoints(const user_t& cards);
	void printPoints(const int dealerPoints, const int playerPoints);
	int evaluateWinCondition(const int dealerPoints, const int playerPoints);
	void stepUp(const int choice, const deck_t& deck, user_t& dealerCards, user_t& playerCards, int& dealerPoints, int& playerPoints);
}



#endif