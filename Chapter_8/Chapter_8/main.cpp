#include <iostream>
#include <string>

enum class MonsterType
{
	ogre,
	dragon,
	orc,
	giantSpider,
	slime,
	typelen
};
struct Monster
{
	MonsterType type{};
	std::string name{};
	int health{};
};
template <typename T>
struct Triad
{
	T num1{};
	T num2{};
	T num3{};
};
template <typename T>
Triad(T, T, T) -> Triad< T >;

void printMonster(Monster monster);
constexpr std::string_view getMonsterTypeAsString(const MonsterType& type);
int question_one();
int question_two();
template <typename T>
void print(const Triad<T>& triad);

int main()
{
	question_two();
}

void printMonster(Monster monster)
{
	std::cout << "This " << getMonsterTypeAsString(monster.type);
	std::cout << " is named " << monster.name;
	std::cout << " and has " << monster.health << " health.\n";
}
constexpr std::string_view getMonsterTypeAsString(const MonsterType &type)
{
	switch (type)
	{
	case MonsterType::ogre:			return "Ogre";
	case MonsterType::dragon:		return "Dragon";
	case MonsterType::orc:			return "Orc";
	case MonsterType::giantSpider:	return "Giant Spider";
	case MonsterType::slime:		return "Slime";
	default:						return "ERROR";
	}
}
int question_one()
{
	Monster Ogre{ MonsterType::ogre,"Torg",145 };
	Monster Slime{ MonsterType::slime,"Blurp",23 };
	printMonster(Ogre);
	printMonster(Slime);
	return 0;
}
template <typename T>
void print(const Triad<T> &triad)
{s
	std::cout << "num1 = " << triad.num1 << '\n';
	std::cout << "num2 = " << triad.num2 << '\n';
	std::cout << "num3 = " << triad.num3 << '\n';
}
int question_two()
{
	Triad t1{ 1, 2, 3 }; // note: uses CTAD to deduce template arguments
	print(t1);

	Triad t2{ 1.2, 3.4, 5.6 }; // note: uses CTAD to deduce template arguments
	print(t2);

	return 0;
}