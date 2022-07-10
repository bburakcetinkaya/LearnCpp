#include "Print.h"
#include "Deck.h"

#include <iostream>

void Print::card(const Card& card)
{
	switch (card.rank)
	{
	case Rank::two:
		std::cout << "2";
		break;
	case Rank::three:
		std::cout << "3";
		break;
	case Rank::four:
		std::cout << "4";
		break;
	case Rank::five:
		std::cout << "5";
		break;
	case Rank::six:
		std::cout << "6";
		break;
	case Rank::seven:
		std::cout << "7";
		break;
	case Rank::eight:
		std::cout << "8";
		break;
	case Rank::nine:
		std::cout << "9";
		break;
	case Rank::ten:
		std::cout << "T";
		break;
	case Rank::jack:
		std::cout << "J";
		break;
	case Rank::queen:
		std::cout << "Q";
		break;
	case Rank::king:
		std::cout << "K";
		break;
	case Rank::ace:
		std::cout << "A";
		break;
	default:
		std::cout << '?';
		break;
	}
	switch (card.suit)
	{
	case Suits::clubs:
		std::cout << "C";
		break;
	case Suits::diamonds:
		std::cout << "D";
		break;
	case Suits::hearts:
		std::cout << "H";
		break;
	case Suits::spades:
		std::cout << "S";
		break;
	default:
		std::cout << '?';
		break;
	}
}

void Print::deck(const deck_t& deck)
{
	for (auto element : deck)
	{
		Print::card(element);
		std::cout << ' ';
	}
}
