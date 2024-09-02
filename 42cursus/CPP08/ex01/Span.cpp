#include "Span.hpp"

Span::Span(int N): data(std::vector<unsigned int>(0)), N(N) {
	
}

Span::~Span() {
	
}

Span::Span(const Span& other): data(other.data), N(other.N) {

}

Span& Span::operator=(const Span& other) {
	if (this == &other)
		return *this;
	this->data = other.data;
	this->N = other.N;
	return *this;
}

void Span::addNumber(unsigned int n) {
	if (this->data.size() == N)
		throw std::logic_error("container is full");
	this->data.push_back(n);
}

unsigned int Span::shortestSpan() {
	std::sort(this->data.begin(), this->data.end());
	unsigned int res = ~0;
	if (this->data.size() < 1)
		throw std::logic_error("cannot found shortestSpan");
	for (std::vector<unsigned int>::const_iterator it = this->data.begin(); it + 1 != this->data.end(); it++)
		res = std::min(res, *(it + 1) - *it);
	return res;
}

unsigned int Span::longestSpan() {
	std::sort(this->data.begin(), this->data.end());
	if (this->data.size() < 1)
		throw std::logic_error("cannot found longestSpan");
	return *(this->data.end() - 1) - *this->data.begin();
}
