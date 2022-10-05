#include <iostream>
#include <string>
#include <random>
#include <algorithm>
#include <vector>
using numHolder_t = std::vector<int>;
int getNumberFromUser(std::string message)
{
    std::cout << message;
    int num{};
    std::cin >> num;
    return num;
}
int getRandomInteger()
{
    std::random_device rd;
    std::seed_seq ss{ rd()}; 
    std::mt19937 mt{ ss }; 
    std::uniform_int_distribution num{ 2, 4 };
    return num(mt);

}
void generateNumPool(int beginNum, std::size_t size,int randNum, numHolder_t& numHolder)
{
    
    for (int i = 0; i < size; i++)
        numHolder.push_back((beginNum+i) * (beginNum+i) * randNum);
}


int main()
{
    int beginNum{ getNumberFromUser("Enter start number: ")};
    std::size_t size{ static_cast<std::size_t>(getNumberFromUser("Enter how many numbers :"))};
    int randNum{ getRandomInteger() };
    numHolder_t numHolderVector{};    
    generateNumPool(beginNum, size, randNum, numHolderVector);

    std::cout << "Starting from " << beginNum << ", " << size << " number are generated.";
    std::cout << " Guess the numbers multiplied by " << randNum << '\n';

    while(!(numHolderVector.empty()))
    {
        std::cout << "Guess: ";
        int guess{}; std::cin >> guess;
        auto found{ std::find(numHolderVector.begin(),numHolderVector.end(),guess) };
        //for (auto i : numHolderVector)
        //{
        //    std::cout << i << ' ';
        //}
        std::cout << '\n';
        if (found == numHolderVector.end())
        {
            std::cout << "Wrong guess sorry you lose....";
            auto nearest = *std::min_element(numHolderVector.begin(), numHolderVector.end(), [=](int a,int b) {
                return (std::abs(a - guess) < std::abs(b - guess));
                });
            if(std::abs(guess - nearest)<=4)
            std::cout << "You guessed " << guess << " but it should be " << nearest;
            break;
        }
        else
        {
            numHolderVector.erase(found);
        }
    }
    if(numHolderVector.empty())
    std::cout << "You won! Congratulations!!!";
    




    return 0;
}