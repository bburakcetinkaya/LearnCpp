#ifndef DECK_H
#define DECK_H
#include <array>
enum class Rank
{
	two,
	three,
	four,
	five,
	six,
	seven,
	eight,
	nine,
	ten,
	jack,
	queen,
	king,
	ace,
	max_rank
};
enum class Suits
{
	clubs,
	diamonds,
	hearts,
	spades,
	max_suits
};
struct Card
{
	Rank rank{};
	Suits suit{};
};

inline constexpr int DECK_SIZE{ 52 };
using deck_t = std::array<Card, DECK_SIZE>;

namespace Deck
{
	deck_t createDeck();
	void shuffleDeck(deck_t& deck);
	int getCardValue(const Card card);
}


#endif