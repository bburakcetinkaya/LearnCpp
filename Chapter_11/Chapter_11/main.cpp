#include <iostream>
#include <array>
#include <vector>
#include <string>
#include <algorithm>
#include "cstdio"
enum class ItemType
{
    Health_potion,
    Torch,
    Arrow,
    size
};
struct Student
{
    std::string name{};
    int grade{};

};
template <std::size_t size>
auto countTotalItems(const std::array<int, size>& items);
int question_one();
int question_two();
int question_four();

int main()
{
    question_four();
}
template <std::size_t size>
auto countTotalItems(const std::array<int, size>& items)
{
    int total{0};
    for (auto element : items)
        total += element;
    
    return total;
}
int question_one()
{
    std::array<int, static_cast<int>(ItemType::size)> playerItems{ 2,5,10 };
    std::cout << "Total count of items : " << countTotalItems(playerItems) << '\n'
        << "Number of torches: " << playerItems[static_cast<int>(ItemType::Torch)] << '\n';
    return 0;

}
int question_two()
{
    std::cout << "How many students to enter";
    int numOfStudents{};
    std::cin >> numOfStudents;

    std::vector<Student> students{};
    for (int i = 0; i < numOfStudents; i++)
    {
        Student student{};
        std::cout << "Enter name of the " << i << "th student: ";
        std::getline(std::cin >> std::ws, student.name);

        std::cout << "Enter grade of " << student.name <<": ";
        std::cin >> student.grade;
        students.push_back(student);  
        std::cout << '\n';
    }
    std::sort(students.begin(), students.end(), [](Student a, Student b) {
        return a.grade > b.grade; });
    std::cout << '\n';
    for (Student element : students)
        std::cout << element.name << " got a grade of " << element.grade << '\n';
    return 0;
}
int question_four()
{
    const char str[]{"Hello, World!"};
    const char* itr = str;
    while (*itr != '\0')
    {
        printf("%c", *itr);
        itr++;
    }
    return 0;

}



