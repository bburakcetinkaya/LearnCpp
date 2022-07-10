#include "Deck.h"


#include <algorithm>
#include <ctime>
#include <random>
#include <cassert>
deck_t Deck::createDeck()
{
	int counter{ 0 };
	std::array<Card, DECK_SIZE> deckArr{};
	for (int j = 0; j < static_cast<int>(Suits::max_suits); j++)
		for (int i = 0; i < static_cast<int>(Rank::max_rank); i++)		
		{
			Card card;
			card.rank = static_cast<Rank>(i);
			card.suit = static_cast<Suits>(j);
			deckArr[counter] = card;
			counter++;
		}
	return deckArr;
}
void Deck::shuffleDeck(deck_t& deck)
{
	static std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
	std::shuffle(deck.begin(), deck.end(), mt);
	

}
int Deck::getCardValue(const Card card)
{
	switch(card.rank)
	{
		case Rank::two:
		case Rank::three:
		case Rank::four:
		case Rank::five:
		case Rank::six:
		case Rank::seven:
		case Rank::eight:
		case Rank::nine:
			return (2 + static_cast<int>(card.rank));

		case Rank::ten:
		case Rank::jack:
		case Rank::queen:
		case Rank::king:
			return 10;

		case Rank::ace:
			return 11;


		default:
			assert(false && "FUCK");
			break;
		}

}