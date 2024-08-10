#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int main() {
	{
		Data tmp;
		Data *res;
		uintptr_t ptr;

		tmp.y = tmp.x = 0;
		ptr = Serializer::serialize(&tmp);
		std::cout << "ptr    : " << ptr << std::endl;
		std::cout << "&tmp   : " << &tmp << std::endl;
		((Data *)ptr)->y = 1;
		((Data *)ptr)->x = 2;
		std::cout << "((int *)(&tmp) + 1)  : " << ((int *)(&tmp) + 1) << std::endl;
		std::cout << "(int *)(ptr + 4)     : " << (int *)(ptr + 4) << std::endl;
		std::cout << "*((int *)(&tmp) + 1) : " << *((int *)(&tmp) + 1) << std::endl;
		std::cout << "*(int *)(ptr + 4)    : " << *(int *)(ptr + 4) << std::endl;
		res = Serializer::deserialize(ptr);
		std::cout << "res->y : " << res->y << std::endl;
		std::cout << "res->x : " << res->x << std::endl;
		std::cout << "tmp.y  : " << tmp.y << std::endl;
		std::cout << "tmp.x  : " << tmp.x << std::endl;
	}
	std::cout << "==========================" << std::endl;
	{
		Data tmp[2];
		uintptr_t tmp0, tmp1, harfTmp;
		Data *res;

		tmp[0].y = 111;
		tmp[0].x = 222;
		tmp[1].y = 333;
		tmp[1].x = 444;

		std::cout << "&tmp[0]  : " << &tmp[0] << std::endl;
		std::cout << "&tmp[1]  : " << &tmp[1] << std::endl;
		tmp0 = Serializer::serialize(&tmp[0]);
		tmp1 = Serializer::serialize(&tmp[1]);
		harfTmp = (tmp0 + tmp1) / 2;
		std::cout << "tmp0     : " << tmp0 << std::endl;
		std::cout << "tmp1     : " << tmp1 << std::endl;
		std::cout << "hardTmp  : " << harfTmp << std::endl;
		res = Serializer::deserialize(harfTmp);
		std::cout << "res->y   : " << res->y << std::endl;
		std::cout << "res->x   : " << res->x << std::endl;
	}
	return 0;
}
