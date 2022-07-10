#include <iostream>
#include "constants.h"
int main(void)
{
	std::cout << "How many students are in your class? ";
	int students{};
	std::cin >> students;

	if (students > constants::max_class_size)
		std::cout << "There are too many students in this class";
	else
		std::cout << "This class is not too large. ";


	return 0;
}