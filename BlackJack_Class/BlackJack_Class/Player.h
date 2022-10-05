#pragma once
#include "Card.h"
#include "Deck.h"
constexpr int g_maximumScore{ 21 };
class Player
{
private:
	int m_score{0};

public:
	bool isBust();
	int drawCard(Deck& deck);
	int score();

};

