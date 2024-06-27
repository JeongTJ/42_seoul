#include "Zombie.hpp"

/**
 * 이 함수는 12 그리고, 각각의 좀비들에게 인자로 전달된 이름을 부여하면서 초기화해야 합니다. 
 * 이 함수는 첫 번째 좀비의 포인터를 반환해야 합니다.
 * */
Zombie* zombieHorde( int N, std::string name ) {
	Zombie* zombies = new Zombie[N];
	for (int i = 0; i < N; i++) {
		zombies[i].setName(name);
	}
	return zombies;
}