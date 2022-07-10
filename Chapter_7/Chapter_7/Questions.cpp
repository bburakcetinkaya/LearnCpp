#include "Operations.h"
#include "Constants.h"
#include "Q1.h"
#include "Q2.h"
#include "Q3.h"
#include "Q4.h"
#include <iostream>

namespace Questions
{
	void question_1()
	{
		std::cout << "Question 1:\n";
		double height{ Q1::getHeight() };
		Q1::calculateAndPrintResult(height);	
	}
	void question_2()
	{
		std::cout << "Question 2:\n";
		Q2::assertResult();
	}
	void question_3()
	{
		int guesses{ 7 };
		int num{};
		int guess{};
		bool result{false};
		
		std::cout << "Question 3:\n";
		std::cout << "You have 7 guesses to guess the number.\n";
		num = Q3::generateRandomNumber();
		while (true)
		{			
			guess	= Q3::getGuessFromUser() ;
			result	= Q3::evaluateGuess(guess,num) ;
			guesses--;
			
			std::cout << "Remaining guesses = " << guesses << '\n';
			if (!guesses || result) break;
		}
		std::cout << result ? "You won" : "You lost" ;
		std::cout << "\n The number was " << num;
	}
	void question_4()
	{
		int guesses{ 7 };
		int num{};
		int guess{};
		bool result{ false };

		std::cout << "Question 4:\n";
		std::cout << "You have 7 guesses to guess the number.\n";
		num = Q3::generateRandomNumber();
		while (true)
		{
			guess = Q4::getValidNum();
			result = Q3::evaluateGuess(guess, num);
			guesses--;

			std::cout << "Remaining guesses = " << guesses << '\n';
			if (!guesses || result) break;
		}
		std::cout << result ? "You won" : "You lost";
		std::cout << "\n The number was " << num;
	}
}