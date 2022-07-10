#include "Q2.h"
#include <iostream>
#include <cassert>

namespace Q2
{
	const int getNumber()
	{
		std::cout << "Enter an integer: ";
		int num{};
		std::cin >> num;
		return num;

	}
	bool isPrime(const int num)
	{
		if (num < 2) return false;
		for (int i = 2; i < num; i++)
		{
			if (!(num % i))
				return false;
		}
		return true;

	}
	void assertResult()
	{
		assert(!isPrime(0));
		assert(!isPrime(1));
		assert(isPrime(2));
		assert(isPrime(3));
		assert(!isPrime(4));
		assert(isPrime(5));
		assert(isPrime(7));
		assert(!isPrime(9));
		assert(isPrime(11));
		assert(isPrime(13));
		assert(!isPrime(15));
		assert(!isPrime(16));
		assert(isPrime(17));
		assert(isPrime(19));
		assert(isPrime(97));
		assert(!isPrime(99));
		assert(isPrime(13417));

		std::cout << "Success!\n";
	}
}