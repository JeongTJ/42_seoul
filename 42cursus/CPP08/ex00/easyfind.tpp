#include "easyfind.hpp"

template <typename T>
typename T::const_iterator easyfind(T& container, int value) {
	typename T::const_iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw std::logic_error("not found value");
	return it;
}