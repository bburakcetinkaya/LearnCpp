#include <iostream>
#include "Operations.h"

int main(void)
{	
	while (true)
	{
		Operations::printMenu();
		Operations::executeSelection(Operations::getSelection());
	}	
}

