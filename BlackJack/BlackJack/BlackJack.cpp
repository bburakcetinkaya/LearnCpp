#include "BlackJack.h"

#include <vector>
#include <iostream>
#include <cassert>

void BlackJack::play(const deck_t& deck)
{
	int dealerPoints{};
	int playerPoints{};
	std::vector<Card> dealerCards{};
	std::vector<Card> playerCards{};



	int choice{ 2 };
	int winCondition{ 0 };
	
	do
	{		
		stepUp(choice, deck, dealerCards, playerCards, dealerPoints, playerPoints);
		std::cout << "Hit or Stand ? (1/0): ";			
		std::cin >> choice;		
		
	} while (!(winCondition = BlackJack::evaluateWinCondition(dealerPoints, playerPoints)));
	switch (winCondition)
	{	
	case 1:
		std::cout << "Player won! Congratulations!\n";
		return;
	case 2:
		std::cout << "Delaer won! :( \n";
		return;

	default:
		assert(false && "Something gone terribly wrong!!!");
		return;
	}
	if(dealerPoints > playerPoints)
		std::cout << "Delaer won! :( \n";
	if(playerPoints > dealerPoints)
		std::cout << "Player won! Congratulations!\n";

}
int BlackJack::calculatePoints(const user_t& cards)
{
	int points{};
	for (auto element : cards)
	{
		points += Deck::getCardValue(element);
	}
	return points;
}
void BlackJack::printPoints(const int dealerPoints, const int playerPoints)
{
	std::cout << "Player has " << playerPoints <<" points" << '\n';
	std::cout << "Dealer has " << dealerPoints <<" points" << '\n';
}
int BlackJack::evaluateWinCondition(const int dealerPoints, const int playerPoints)
{
	if (dealerPoints == 21 || playerPoints > 21)
		return 2;
	else if (dealerPoints > 21 || playerPoints == 21)
		return 1;

	return 0;
	
}
void BlackJack::stepUp(const int choice, const deck_t& deck,user_t& dealerCards, user_t&playerCards, int& dealerPoints,int&playerPoints)
{
	switch (choice)
	{
	case 0:
		while (dealerPoints < 17)
		{
			BlackJack::drawCards(deck, dealerCards);
			BlackJack::printCurrentState(BlackJack::user::dealer, dealerCards);
			dealerPoints = BlackJack::calculatePoints(dealerCards);
			BlackJack::printPoints(dealerPoints, playerPoints);
		}
		break;

	case 1:
		BlackJack::drawCards(deck, playerCards);
		BlackJack::printCurrentState(BlackJack::user::player, playerCards);
		playerPoints = BlackJack::calculatePoints(playerCards);
		BlackJack::printPoints(dealerPoints, playerPoints);
		break;

	case 2:
		BlackJack::drawCards(deck, playerCards);
		BlackJack::drawCards(deck, dealerCards);
		BlackJack::drawCards(deck, playerCards);

		BlackJack::printCurrentState(BlackJack::user::player, playerCards);
		BlackJack::printCurrentState(BlackJack::user::dealer, dealerCards);

		dealerPoints = BlackJack::calculatePoints(dealerCards);
		playerPoints = BlackJack::calculatePoints(playerCards);
		BlackJack::printPoints(dealerPoints, playerPoints);
		break;

	default: 
		assert(false && "FUCK!");
		break;
	}
}
void BlackJack::drawCards(const deck_t& deck, user_t& cards)
{
	static int cardNumber{ 0 };
	cards.push_back(deck[cardNumber]);
	cardNumber++;
}

void BlackJack::printCurrentState(const BlackJack::user selection, user_t& cards)
{
	
	if (selection) std::cout << "Dealer has : ";
	else std::cout << "Player has : ";
	for (auto element : cards)
	{
		Print::card(element);
		std::cout << ' ';
	}
	std::cout << '\n';
}

