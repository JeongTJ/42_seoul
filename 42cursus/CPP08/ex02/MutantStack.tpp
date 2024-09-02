#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack() {

}
template <typename T>
MutantStack<T>::~MutantStack() {

}
template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T>& other): std::stack<T>(other) {

}
template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack<T>& other) {
	if (this == &other)
		return *this;
	return *this;
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {
	return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() {
	return this->c.end();
}
