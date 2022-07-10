#include "Q1.h"
#include "Constants.h"
#include <iostream>
namespace Q1
{
	const double getHeight(void)
	{
		std::cout << "Enter height of the ball:";
		double height{};
		std::cin >> height;
		return height;

	}
	void calculateAndPrintResult(const double height)
	{
		double remaining{ height };
		int seconds{ 0 };
		while (remaining > 0)
		{
			remaining = remaining - Constants::gravity * seconds / 2;
			if (remaining < 0)	remaining = 0;				
			std::cout << "Remaining height = " << remaining << '\n';
			seconds++;
		} 
		
	}


}