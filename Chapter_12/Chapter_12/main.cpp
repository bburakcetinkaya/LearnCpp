#include <iostream>
#include <functional>

using ArithmeticFunction = std::function<int(int, int)>;
char getOperator();
void ignoreLine();
int getNumber();

int add(int num1, int num2);
int subtract(int num1, int num2);
int multiply(int num1, int num2);
int division(int num1, int num2);

ArithmeticFunction getArithmeticFunction(const char operatr);

int main()
{
	std::cout << "Enter first integer: ";
	int num1{getNumber()};

	std::cout << "Enter second integer: ";
	int num2{ getNumber() };

	char operatr{getOperator()};

    int result = getArithmeticFunction(operatr)(num1, num2);

    std::cout << num1 << operatr << num2 << "=" << result;
	




}
ArithmeticFunction getArithmeticFunction(const char operatr)
{
    switch (operatr)
    {
    case '+':
        return add;
    case '-':
        return subtract;
    case '*':
        return multiply;
    case '/':
        return division; // return it to the caller
    default: // otherwise tell the user what went wrong
        std::cerr << "FUCK\n";
    }
}
int add(int num1, int num2)
{
    return num1 + num2;
}
int subtract(int num1, int num2)
{
    return num1 - num2;
}
int multiply(int num1, int num2)
{
    return num1 * num2;
}
int division(int num1, int num2)
{
    return num1 / num2;
}
int getNumber()
{
    while (true) // Loop until user enters a valid input
    {
        int num{};
        std::cin >> num;

        // Check whether the user entered meaningful input

        if (!std::cin) // has a previous extraction failed?
        {
            // yep, so let's handle the failure
            std::cin.clear(); // put us back in 'normal' operation mode
            ignoreLine(); // and remove the bad input
            std::cout << "Wrong input!\n";
        }
        else // else our extraction succeeded
        {
            ignoreLine();
            return num;
            
        }
        
    }

}
char getOperator()
{

    while (true) // Loop until user enters a valid input
    {
        std::cout << "Enter one of the following: +, -, *, /: ";
        char operation{};
        std::cin >> operation;

        // Check whether the user entered meaningful input

        if (!std::cin) // has a previous extraction failed?
        {
            // yep, so let's handle the failure
            std::cin.clear(); // put us back in 'normal' operation mode
            ignoreLine(); // and remove the bad input
        }
        else // else our extraction succeeded
        {
            ignoreLine();
            switch (operation)
            {
            case '+':
            case '-':
            case '*':
            case '/':
                return operation; // return it to the caller
            default: // otherwise tell the user what went wrong
                std::cerr << "Oops, that input is invalid.  Please try again.\n";
            }
        }
    }
}
void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}