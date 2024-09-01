#include <exception>

template <typename T>
Array<T>::Array(): data(new T[0]), length(0) {
	
}

template <typename T>
Array<T>::Array(unsigned int n): data(new T[n]), length(n) {

}

template <typename T>
Array<T>::~Array() {
	delete[] this->data;
}

template <typename T>
Array<T>::Array(const Array& other): data(new T[other.length]), length(other.n) {
	for (unsigned int i = 0; i < length; i++)
		this->data[i] = other.data[i];
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other) {
	if (this == &other)
		return *this;
	delete[] this->data;
	this->length = other.length;
	this->data = new T[this->length];
	for (unsigned int i = 0; i < this->length; i++)
		this->data[i] = other.data[i];
	return *this;
}

template <typename T>
T& Array<T>::operator[](unsigned int idx) const {
	if (idx >= length)
		throw std::exception();
	return data[idx];
}

template <typename T>
unsigned int Array<T>::size() const {
	return length;
}