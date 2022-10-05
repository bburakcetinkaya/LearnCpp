#include <iostream>
#include <array>
#include <cassert>
constexpr int arrSize{ 10 };
class Stack
{
	using arr_type = std::array<int, arrSize>;
public:
	void reset()
	{
		m_size = 0;		
	}
	bool push(int num)
	{
		if (m_size == arrSize) return false;
		m_arr[m_size] = num;
		m_size++;
	}
	int pop()
	{
		if (m_size == 0) assert(false && "No values on stack!");
		m_size--;
		return m_arr[m_size];

	}
	void print()
	{
		std::cout << "( ";
		for (int i = 0; i<m_size ;i++)
			std::cout << m_arr[i] << ' ';
		std::cout << ")";
		std::cout << '\n';
	}
private: 
	arr_type m_arr{};
	int m_size{};





};
int main(int argc, char* argv[])
{
	Stack stack;
	stack.reset();

	stack.print();

	stack.push(5);
	stack.push(3);
	stack.push(8);
	stack.print();

	stack.pop();
	stack.print();

	stack.pop();
	stack.pop();

	stack.print();
}