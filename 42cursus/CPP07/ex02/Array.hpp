#pragma once
#ifndef ARRAY_HPP
# define ARRAY_HPP

template <typename T>
class Array {
	public:
		Array();
		Array(unsigned int n);
		~Array();
		Array(const Array& other);
		Array<T>& operator=(const Array& other);
		T& operator[](unsigned int idx) const;
		unsigned int size() const;
	private:
		T* data;
		unsigned int length;
};

#include "Array.tpp"

#endif