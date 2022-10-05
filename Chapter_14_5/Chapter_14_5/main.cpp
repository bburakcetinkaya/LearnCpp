#include <iostream>
#include <cstdint> // for fixed width integers
#include <cmath> // for std::round()
class FixedPoint2
{
public:
	FixedPoint2(std::int16_t nonfrac, std::int8_t frac): 
		m_nonFractional{(nonfrac) }, m_fractional{ (frac) }
	{
		setSign();
	}
	FixedPoint2(double num):
		m_nonFractional{ static_cast<std::int_least16_t>(std::floor(num)) },
		m_fractional{ static_cast<std::int_least8_t>(std::ceil(num * 100) - m_nonFractional * 100) }
	{
		
	}
	friend std::ostream& operator<<(std::ostream& out, const FixedPoint2& fixP)
	{
		out << static_cast<double>(fixP);
		return out;
	}
	friend std::istream& operator>>(std::istream& in, FixedPoint2& fixP)
	{
		double temp{};
		in >> temp;
		fixP =  FixedPoint2{ temp };
		return in;
	}
	friend FixedPoint2& operator+(const FixedPoint2& p1, const FixedPoint2& p2)
	{
		FixedPoint2 temp{ static_cast<double>(p1) + static_cast<double>(p2) };
		return temp;
	}
	friend bool operator==(const FixedPoint2& p1, const FixedPoint2& p2)
	{

		return (p1.m_nonFractional == p2.m_nonFractional && p1.m_fractional == p2.m_fractional);
	}
	operator double() const
	{
		return m_nonFractional + static_cast<double>(m_fractional) / 100;;
	}
	void setSign()
	{
		if (m_fractional < 0 || m_nonFractional < 0)
		{
			// Make sure base is negative
			if (m_fractional > 0)
				m_fractional = -m_fractional;
			// Make sure decimal is negative
			if (m_nonFractional > 0)
				m_nonFractional = -m_nonFractional;
		}

	}
private:
	std::int16_t m_nonFractional{};
	std::int8_t m_fractional{};
};
void testAddition()
{
	// h/t to reader Sharjeel Safdar for this function
	std::cout << std::boolalpha;
	std::cout << (FixedPoint2{ 0.75 } + FixedPoint2{ 1.23 } == FixedPoint2{ 1.98 }) << '\n'; // both positive, no decimal overflow
	std::cout << (FixedPoint2{ 0.75 } + FixedPoint2{ 1.50 } == FixedPoint2{ 2.25 }) << '\n'; // both positive, with decimal overflow
	std::cout << (FixedPoint2{ -0.75 } + FixedPoint2{ -1.23 } == FixedPoint2{ -1.98 }) << '\n'; // both negative, no decimal overflow
	std::cout << (FixedPoint2{ -0.75 } + FixedPoint2{ -1.50 } == FixedPoint2{ -2.25 }) << '\n'; // both negative, with decimal overflow
	std::cout << (FixedPoint2{ 0.75 } + FixedPoint2{ -1.23 } == FixedPoint2{ -0.48 }) << '\n'; // second negative, no decimal overflow
	std::cout << (FixedPoint2{ 0.75 } + FixedPoint2{ -1.50 } == FixedPoint2{ -0.75 }) << '\n'; // second negative, possible decimal overflow
	std::cout << (FixedPoint2{ -0.75 } + FixedPoint2{ 1.23 } == FixedPoint2{ 0.48 }) << '\n'; // first negative, no decimal overflow
	std::cout << (FixedPoint2{ -0.75 } + FixedPoint2{ 1.50 } == FixedPoint2{ 0.75 }) << '\n'; // first negative, possible decimal overflow
}
int main()
{
	testAddition();

	FixedPoint2 a{ -0.48 };
	std::cout << a << '\n';

	std::cout << -a << '\n';

	std::cout << "Enter a number: "; // enter 5.678
	std::cin >> a;

	std::cout << "You entered: " << a << '\n';

	return 0;
}