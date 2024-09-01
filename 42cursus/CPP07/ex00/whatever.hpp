#pragma once
#ifndef WHATEVER_HPP
# define WHATEVER_HPP
# include <iostream>

template <typename T>
void swap(T& a, T& b) {
	std::cout << "template swap called" << std::endl;
	T tmp;
	
	tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
T& min(T& a, T& b) {
	std::cout << "template min called" << std::endl;
	if (a <= b)
		return a;
	return b;
}

template <typename T>
T& max(T& a, T& b) {
	std::cout << "template max called" << std::endl;
	if (a >= b)
		return a;
	return b;
}

#endif