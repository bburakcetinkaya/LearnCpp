#include "Operations.h"
#include "Questions.h"

#include <iostream>

namespace Operations
{
	void printMenu(void)
	{
		std::cout << "0 --> for exit." << '\n';
		std::cout << "1 --> Result of question 1" << '\n';
		std::cout << "2 --> Result of question 2" << '\n';
		std::cout << "3 --> Result of question 3" << '\n';
		std::cout << "4 --> Result of question 4" << '\n';
	}
	int getSelection(void)
	{
		int selection{};
		std::cout << "Enter your selection: ";
		std::cin >> selection;
		return selection;
	}
	void executeSelection(const int selection)
	{
		switch (selection)
		{
		case 0:
			std::exit(0);
			break;
		case 1:
			Questions::question_1();
			break;
		case 2:
			Questions::question_2();
			break;
		case 3:
			Questions::question_3();
			break;
		case 4:
			Questions::question_4();
			break;
		}


	}
}