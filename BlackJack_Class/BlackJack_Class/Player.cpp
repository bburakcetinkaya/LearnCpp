#include "Player.h"
#include "Deck.h"

bool Player::isBust()
{
	
	return (m_score > g_maximumScore);
}

int Player::drawCard(Deck& deck)
{
	int value = deck.dealCard().getCardValue();
	m_score += value;
	return m_score;
}

int Player::score()
{
	return m_score;
}
