#include <iostream>
#include <string>
#include <string_view>
#include <algorithm>
#include <vector>

class Car
{
private:
    std::string m_make;
    std::string m_model;

public:
    Car(std::string_view make, std::string_view model)
        : m_make{ make }, m_model{ model }
    {
    }

    friend bool operator== (const Car& c1, const Car& c2);
    friend bool operator!= (const Car& c1, const Car& c2);
    friend bool operator<(const Car& c1, const Car& c2);
    friend std::ostream& operator<< (std::ostream& out, const Car& car);

};

bool operator== (const Car& c1, const Car& c2)
{
    return (c1.m_make == c2.m_make &&
        c1.m_model == c2.m_model);
}

bool operator!= (const Car& c1, const Car& c2)
{
    return (c1.m_make != c2.m_make ||
        c1.m_model != c2.m_model);
}
bool operator<(const Car& c1, const Car& c2)
{
    if (c1 == c2) return false;
    
    if (c1.m_make == c2.m_make)
    {
        return c1.m_model < c2.m_model;
    }
    else
    {
        return c1.m_make < c2.m_make;
    }
}
 std::ostream& operator<< (std::ostream& out, const Car& car)
{
     out << "( " << car.m_make << "," << car.m_model << " )";
     return out;
}



int main()
{
    std::vector<Car> cars{
      { "Toyota", "Corolla" },
      { "Honda", "Accord" },
      { "Toyota", "Camry" },
      { "Honda", "Civic" }
    };

    std::sort(cars.begin(), cars.end()); // requires an overloaded operator<

    for (const auto& car : cars)
        std::cout << car << '\n'; // requires an overloaded operator<<

    return 0;
}