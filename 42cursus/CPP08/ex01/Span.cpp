#include "Span.hpp"

Span::Span(int capacity): data(std::vector<unsigned int>(0)), capacity(capacity) {

}

Span::~Span() {

}

Span::Span(const Span& other): data(other.data), capacity(other.capacity) {

}

Span& Span::operator=(const Span& other) {
	if (this == &other)
		return *this;
	this->data = other.data;
	this->capacity = other.capacity;
	return *this;
}

void Span::addNumber(unsigned int n) {
	if (this->data.size() == capacity)
		throw std::logic_error("container is full");
	this->data.push_back(n);
}

unsigned int Span::shortestSpan() {
	if (this->data.size() < 2)
		throw std::logic_error("cannot found shortestSpan");
	std::vector<unsigned int> tmp = this->data;
	std::sort(tmp.begin(), tmp.end());
	unsigned int res = ~0;
	for (std::vector<unsigned int>::const_iterator it = tmp.begin(); it + 1 != tmp.end(); it++)
		res = std::min(res, *(it + 1) - *it);
	return res;
}

unsigned int Span::longestSpan() {
	if (this->data.size() < 2)
		throw std::logic_error("cannot found longestSpan");
	std::vector<unsigned int> tmp = this->data;
	std::sort(tmp.begin(), tmp.end());
	return *(tmp.end() - 1) - *tmp.begin();
}
