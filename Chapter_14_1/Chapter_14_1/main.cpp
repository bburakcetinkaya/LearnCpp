#include <iostream>
#include <numeric>
class Fraction
{
public:
	Fraction(int numarator=0,int denumarator=1): m_numerator{ numarator }, m_denumarator{ denumarator }
	{
		reduce();
	}
	void print()
	{
		std::cout << m_numerator << '/' << m_denumarator << std::endl;
	}
	
	friend Fraction operator*(const Fraction& frac, int integer);
	friend Fraction operator*(int integer, const Fraction& frac);
	friend Fraction operator*(const Fraction& frac1, const Fraction& frac2);
	friend std::ostream& operator<<(std::ostream& out, const Fraction& frac);
	friend std::istream& operator>>(std::istream& in, Fraction& frac);
	void reduce()
	{
		int gcd = std::gcd(m_numerator, m_denumarator);
		this->m_numerator /= gcd;
		this->m_denumarator /= gcd;
	}
private:
	int m_numerator{};
	int m_denumarator{};
	
};

Fraction operator*(const Fraction& frac, int integer)
{
	return{(integer*frac.m_numerator),frac.m_denumarator};
}
Fraction operator*(int integer, const Fraction& frac)
{
	return{frac*integer};
}
Fraction operator*(const Fraction& frac1, const Fraction& frac2)
{
	return { (frac1.m_numerator * frac2.m_numerator),(frac1.m_denumarator * frac2.m_denumarator) };
}
std::ostream& operator<<(std::ostream& out, const Fraction& frac)
{
	out << frac.m_numerator << '/' << frac.m_denumarator;
	return out;

}
std::istream& operator>>(std::istream& in, Fraction& frac)
{
	in >> frac.m_numerator;
	in >> frac.m_denumarator;
	return in;
}
int main(int argc, char* argv[])
{
	Fraction f1;
	std::cout << "Enter fraction 1: ";
	std::cin >> f1;

	Fraction f2;
	std::cout << "Enter fraction 2: ";
	std::cin >> f2;

	std::cout << f1 << " * " << f2 << " is " << f1 * f2 << '\n';
	// note: The result of f1 * f2 is an r-value

}