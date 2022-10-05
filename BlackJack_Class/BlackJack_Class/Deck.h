#pragma once
#include "Card.h"
#include <array>

constexpr int DECK_SIZE{ 52 };	
class Deck
{
public:
	using deck_type = std::array<Card, DECK_SIZE>;
	using index_type = deck_type::size_type;

	Deck();
	
	void print() const;
	void shuffle();

	const Card& dealCard();
private:
	deck_type m_deck{};
	index_type m_cardIndex{ 0 };


};

