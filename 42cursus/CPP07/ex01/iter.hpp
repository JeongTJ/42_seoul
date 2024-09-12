#pragma once
#ifndef ITER_HPP
# define ITER_HPP

template <typename T, typename F>
void iter(T* addr, unsigned int length, F f) {
	for (unsigned int i = 0; i < length; i++)
		f(addr[i]);
}

#endif
