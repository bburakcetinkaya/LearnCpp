#include "Q3.h"
#include <iostream>
#include <random>
namespace Q3
{
	int generateRandomNumber(void)
	{
		std::random_device rd;
		std::seed_seq seq{ rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd() };
		std::mt19937 mt{seq};
		std::uniform_int_distribution randNumSeq{ 1, 100 };
		int num = randNumSeq(mt);
		return num;
	}
	int getGuessFromUser(void)
	{
		int guess{};
		std::cin >> guess;
		return guess;
		return 0;
	}
	bool evaluateGuess(const int guess, const int randomNum)
	{
		if (randomNum == guess)
		{
			std::cout << "You have correctly guessed the number " << randomNum << '\n';
			return true;
		}
		else if (randomNum < guess)
		{
			std::cout << "HIGH try again" << '\n';
			return false;
		}
		else 
		{
			std::cout << "LOW try again" << '\n';
			return false;
		}		
	}


}