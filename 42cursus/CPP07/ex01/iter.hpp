#pragma once
#ifndef ITER_HPP
# define ITER_HPP

template <typename T>
void iter(T* addr, unsigned int length, void (*f)(T& element)) {
	for (unsigned int i = 0; i < length; i++)
		f(addr[i]);
}

#endif