#include "Q4.h"
#include <iostream>
#include <limits>

int Q4::getValidNum()
{
	while (true) // loop until user enters valid input
	{
		int guess{};
		std::cin >> guess;

		if (std::cin.fail()) // did the extraction fail?
		{
			// yep, so let's handle the failure
			std::cin.clear(); // put us back in 'normal' operation mode
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // remove the bad input
			std::cout << "INVALID INPUT TRY AGAIN\n";
			continue; // and try again
		}

		// We may have gotten a partial extraction (e.g. user entered '43x')
		// We'll remove any extraneous input before we proceed
		// so the next extraction doesn't fail
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return guess;
	}
}
