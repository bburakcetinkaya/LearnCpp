#include <iostream>
#include "Deck.h"	
#include "Print.h"
#include "BlackJack.h"

int main()
{
	deck_t deck = Deck::createDeck();
	//std::cout << "Deck: \n";
	//Print::deck(deck);
	Deck::shuffleDeck(deck);
	//std::cout << "\n\n";
	//std::cout << "Deck after shuffle: \n";
	//Print::deck(deck);
	BlackJack::play(deck);

	return 0;
}