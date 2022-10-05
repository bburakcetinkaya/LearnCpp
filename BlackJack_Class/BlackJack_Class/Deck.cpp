#include "Deck.h"
#include <iostream>
#include <algorithm>
#include <random>
#include <cassert>

Deck::Deck()
{
    index_type index{ 0 };

    for (int suit{ 0 }; suit < static_cast<int>(Card::Suit::max_suits); ++suit)
    {
        for (int rank{ 0 }; rank < static_cast<int>(Card::Rank::max_ranks); ++rank)
        {
            m_deck[index] = Card{ static_cast<Card::Rank>(rank),  static_cast<Card::Suit>(suit) };
            ++index;
        }
    }
}

void Deck::print() const
{
    for (const auto& card : m_deck)
    {
        card.print();
        std::cout << ' ';
    }

    std::cout << '\n';
}

void Deck::shuffle()
{
    static std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };

    std::shuffle(m_deck.begin(), m_deck.end(), mt);
    m_cardIndex = 0;
}

const Card& Deck::dealCard()
{
    assert(m_cardIndex < static_cast<Deck::index_type>(m_deck.size()));
    return m_deck[m_cardIndex++];
}
