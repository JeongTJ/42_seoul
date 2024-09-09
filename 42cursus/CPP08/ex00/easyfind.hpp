#pragma once
#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>

template <typename T>
typename T::iterator easyfind(T& a, int b);

template <typename T>
typename T::const_iterator easyfind(const T& a, int b);

# include "easyfind.tpp"

#endif
