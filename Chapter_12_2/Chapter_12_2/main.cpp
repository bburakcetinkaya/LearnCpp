#include <iostream>

int factorial(int num)
{
	if (num <= 0)
		return 1;
	if (num > 1);
		return factorial(num - 1) * num;

}
int sumDigits(int num)
{
	if (num == 0)
		return 0;
	if(num > 0)
		return sumDigits(num / 10) + num % 10;
}
int dec2bin(int num)
{
	if (num > 1)
		return 10*dec2bin(num / 2) +  num % 2;

}

int main()
{	
	std::cout << "Enter a number to find its binary representation: ";
	int num{};
	std::cin >> num;
	int result = dec2bin(num);
	std::cout << "The result is : " << result;
	/*int result = factorial(num);
	std::cout << "The factorial is : " << result;*/


}