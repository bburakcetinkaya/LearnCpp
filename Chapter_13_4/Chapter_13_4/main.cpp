#include <iostream>
#include <string>
#include <string_view>
#include <cassert>
#include <array>
#include <ctime> // for time()
#include <cstdlib> // for rand() and srand()
class Monster
{
public:
	using monster_type = std::string_view;
	enum Type
	{
		Dragon, Goblin, Ogre, Orc, Skeleton, Troll, Vampire, Zombie, max_monster_types
	};
	Monster(Type type, const std::string_view name, const std::string_view roar, int hp)
		:m_type{type},m_name{name},m_roar{roar},m_hp{hp}{}
	monster_type getTypeString(Type t)
	{
		switch (t)
		{
		case Dragon:	return "Dragon";
		case Goblin:	return "Goblin";
		case Ogre:		return "Ogre";
		case Orc:		return "Orc";
		case Skeleton:	return "Skeleton";
		case Troll:		return "Troll";
		case Vampire:	return "Vampire";
		case Zombie:	return "Zombie";
		default: assert(false && "FUCK");
		}
	}
	void print()
	{
		std::cout << m_name << " the " << getTypeString(m_type) << " has " << m_hp << " and says " << m_roar << '\n';
	}
private:
	Type m_type{};
	const std::string_view m_name{};
	const std::string_view m_roar{};
	int m_hp{};

};
class MonsterGenerator
{
public:
	using strarr_type = std::array<std::string_view, 6>;
	static Monster generateMonster()
	{		
		static constexpr strarr_type s_names{ "Ahmet", "Mehmet", "Cemal", "Deniz", "Fatma", "Ece" };
		static constexpr strarr_type s_roars{ "*ROAR*", "*peep*", "*squeal*", "*whine*", "*hum*", "*burp*" };
		return Monster(static_cast<Monster::Type>(getRandomNumber(0,Monster::Type::max_monster_types-1))
						, s_names[getRandomNumber(0,5)]
						, s_roars[getRandomNumber(0, 5)]
						, getRandomNumber(1,100));
	}

	// Generate a random number between min and max (inclusive)
	// Assumes srand() has already been called
	static int getRandomNumber(int min, int max)
	{
		static constexpr double fraction{ 1.0 / (static_cast<double>(RAND_MAX) + 1.0) };  
		// static used for efficiency, so we only calculate this value once
		// evenly distribute the random number across our range
		return static_cast<int>(std::rand() * fraction * (max - min + 1) + min);
	}
private:
	
};
int main(int argc, char* argv[])
{
	std::srand(static_cast<unsigned int>(std::time(nullptr))); // set initial seed value to system clock
	int num = std::rand(); // If using Visual Studio, discard first random value
	for(int i = 0 ; i<100; i++)
	Monster { MonsterGenerator::generateMonster() }.print();


}