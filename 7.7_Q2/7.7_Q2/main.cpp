#include <iostream>

int main(void)
{
	for (int i = 0; i < 255; i++)
	{
		std::cout << i << "\t\t" << static_cast<char>(i) << '\n';
	}


}