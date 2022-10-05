#pragma once
class Card
{
public:
    enum Rank
    {
        rank_2, rank_3, rank_4, rank_5, rank_6, rank_7, rank_8, rank_9, rank_10,
        rank_jack, rank_queen, rank_king, rank_ace, max_ranks
    };
    enum Suit
    {
        club, diamond,  heart,  spade,  max_suits
    }; 
    Card() = default;
    Card(Rank rank, Suit suit);
    void print() const;
    int getCardValue() const;
private:
    Rank m_rank{};
    Suit m_suit{};

};

