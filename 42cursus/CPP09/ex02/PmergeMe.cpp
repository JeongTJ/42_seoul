#include "PmergeMe.hpp"
#include <sstream>
#include <iostream>
#include <iomanip>

PmergeMe::PmergeMe(int argc, char *argv[]) {
	for (int i = 0; i < argc; i++) {
		std::istringstream iss(argv[i]);
		int data;
		if (!(iss >> data) || !iss.eof() || data <= 0) {
			for (std::vector<Node*>::iterator it = vOrigin.begin(); it != vOrigin.end(); it++)
				delete *it;
			for (std::list<Node*>::iterator it = lOrigin.begin(); it != lOrigin.end(); it++)
				delete *it;
			for (std::vector<Node*>::iterator it = vSort.begin(); it != vSort.end(); it++)
				delete *it;
			for (std::list<Node*>::iterator it = lSort.begin(); it != lSort.end(); it++)
				delete *it;
			throw std::logic_error("Error");
		}
		vOrigin.push_back(new Node(data, 0, NULL, NULL));
		vSort.push_back(new Node(data, 0, NULL, NULL));
		lOrigin.push_back(new Node(data, 0, NULL, NULL));
		lSort.push_back(new Node(data, 0, NULL, NULL));
	}
}

PmergeMe::~PmergeMe() {
	for (std::vector<Node*>::iterator it = vOrigin.begin(); it != vOrigin.end(); it++)
		delete *it;
	for (std::list<Node*>::iterator it = lOrigin.begin(); it != lOrigin.end(); it++)
		delete *it;
	for (std::vector<Node*>::iterator it = vSort.begin(); it != vSort.end(); it++)
		delete *it;
	for (std::list<Node*>::iterator it = lSort.begin(); it != lSort.end(); it++)
		delete *it;
}

PmergeMe::PmergeMe(const PmergeMe& other): vOrigin(other.vOrigin), vSort(other.vSort), lOrigin(other.lOrigin), lSort(other.lSort) {
	
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	if (this == &other)
		return *this;
	this->vOrigin = other.vOrigin;
	this->vSort = other.vSort;
	this->lOrigin = other.lOrigin;
	this->lSort = other.lSort;
	return *this;
}

void PmergeMe::merge(std::vector<Node*>& before) {
	std::vector<Node*> curr;
	std::vector<Node*>::iterator currIt;
	std::vector<Node*>::iterator nextIt;
	Node* remain = NULL;

	if (before.size() == 1)
		return ;

	for (currIt = before.begin(), nextIt = currIt + 1; currIt != before.end() && nextIt != before.end(); currIt = nextIt + 1, nextIt = currIt + 1) {
		if ((*currIt)->getHead() >= (*nextIt)->getHead()) {
			curr.push_back(new Node((*currIt)->getHead(), (*currIt)->getLevel() + 1, *currIt, *nextIt));
		} else {
			curr.push_back(new Node((*nextIt)->getHead(), (*nextIt)->getLevel() + 1, *nextIt, *currIt));
		}
	}
	if (currIt != before.end())
		remain = *currIt;
	merge(curr);
	std::vector<Node*>::iterator it;
	std::vector<Node*> mainChain;
	std::vector<Node*> subChain;

	for (std::vector<Node*>::iterator it = curr.begin(); it != curr.end(); it++) {
		mainChain.push_back((*it)->getMain());
		subChain.push_back((*it)->getSub());
		delete *it;
	}

	mainChain.insert(mainChain.begin(), *subChain.begin());
	*subChain.begin() = NULL;
	int totalInsertCnt = 1;
	int power = 2;
	while (1) {
		if (subChain.size() > std::pow(2, power) - totalInsertCnt)
			it = subChain.begin() + std::pow(2, power) - totalInsertCnt;
		else
			it = subChain.end() - 1;
		if (*it == NULL) {
			break ;
		}
		while (1) {
			if (*it == NULL)
				break ;
			std::vector<Node*>::iterator insertIt = std::lower_bound(mainChain.begin(), mainChain.begin() + totalInsertCnt + (it - subChain.begin()), *it, Node::nodeCompare);
			mainChain.insert(insertIt, *it);
			*it = NULL;
			totalInsertCnt++;
			it--;
		}
		power++;
	}
	if (remain != NULL) {
		std::vector<Node*>::iterator insertIt = std::lower_bound(mainChain.begin(), mainChain.end(), remain, Node::nodeCompare);
		mainChain.insert(insertIt, remain);
		remain = NULL;
	}
	before = mainChain;
}

void PmergeMe::merge(std::list<Node*>& before) {
	std::list<Node*> curr;
	std::list<Node*>::iterator currIt;
	std::list<Node*>::iterator nextIt;
	Node* remain = NULL;

	if (before.size() == 1)
		return ;

	currIt = before.begin();
	nextIt = before.begin();
	nextIt++;
	while (currIt != before.end() && nextIt != before.end()) {
		if ((*currIt)->getHead() >= (*nextIt)->getHead()) {
			curr.push_back(new Node((*currIt)->getHead(), (*currIt)->getLevel() + 1, *currIt, *nextIt));
		} else {
			curr.push_back(new Node((*nextIt)->getHead(), (*nextIt)->getLevel() + 1, *nextIt, *currIt));
		}
		std::advance(currIt, 2);
		std::advance(nextIt, 2);
	}
	if (currIt != before.end())
		remain = *currIt;
	merge(curr);
	std::list<Node*>::iterator it;
	std::list<Node*> mainChain;
	std::list<Node*> subChain;

	for (std::list<Node*>::iterator it = curr.begin(); it != curr.end(); it++) {
		mainChain.push_back((*it)->getMain());
		subChain.push_back((*it)->getSub());
		delete *it;
	}

	mainChain.insert(mainChain.begin(), *subChain.begin());
	*subChain.begin() = NULL;
	int totalInsertCnt = 1;
	int power = 2;
	while (1) {
		if (subChain.size() > std::pow(2, power) - totalInsertCnt) {
			it = subChain.begin();
			std::advance(it, std::pow(2, power) - totalInsertCnt);
		} else {
			it = subChain.end();
			std::advance(it, -1);
		}
		if (*it == NULL) {
			break ;
		}
		while (1) {
			if (*it == NULL)
				break ;
			std::list<Node*>::iterator mainChainSearchBegin = mainChain.begin();
			std::list<Node*>::iterator mainChainSearchEnd = mainChain.begin();
			std::advance(mainChainSearchEnd, totalInsertCnt + std::distance(subChain.begin(), it));
			std::list<Node*>::iterator insertIt = std::lower_bound(mainChainSearchBegin, mainChainSearchEnd, *it, Node::nodeCompare);
			mainChain.insert(insertIt, *it);
			// for (std::list<Node*>::iterator searchIt = mainChainSearchBegin; searchIt != mainChainSearchEnd; searchIt++) {
			// 	if ((*it)->getHead() <= (*searchIt)->getHead()) {
			// 		mainChain.insert(searchIt, *it);
			// 		break ;
			// 	}
			// }
			*it = NULL;
			totalInsertCnt++;
			it--;
		}
		power++;
	}
	if (remain != NULL) {
		// for (std::list<Node*>::iterator searchIt = mainChain.begin(); searchIt != mainChain.end(); searchIt++) {
		// 	if ((remain)->getHead() <= (*searchIt)->getHead()) {
		// 		mainChain.insert(searchIt, remain);
		// 		break ;
		// 	}
		// }
		std::list<Node*>::iterator insertIt = std::lower_bound(mainChain.begin(), mainChain.end(), remain, Node::nodeCompare);
		mainChain.insert(insertIt, remain);
		remain = NULL;
	}
	before = mainChain;
}

std::vector<PmergeMe::Node*>& PmergeMe::getVector() {
	return this->vSort;
}

std::list<PmergeMe::Node*>& PmergeMe::getList() {
	return this->lSort;
}


void PmergeMe::printVector() {
	std::cout << std::setw(10) << std::left << "Before: ";
	for (std::vector<Node*>::iterator it = vOrigin.begin(); it != vOrigin.end(); it++)
		std::cout << (*it)->getHead() << " ";
	std::cout << std::endl;

	std::cout << std::setw(10) << std::left << "After: ";
	for (std::vector<Node*>::iterator it = vSort.begin(); it != vSort.end(); it++)
		std::cout << (*it)->getHead() << " ";
	std::cout << std::endl;
}

void PmergeMe::printList() {
	std::cout << std::setw(10) << "Before: ";
	for (std::list<Node*>::iterator it = lOrigin.begin(); it != lOrigin.end(); it++)
		std::cout << (*it)->getHead() << " ";
	std::cout << std::endl;

	std::cout << std::setw(10) << "After: ";
	for (std::list<Node*>::iterator it = lSort.begin(); it != lSort.end(); it++)
		std::cout << (*it)->getHead() << " ";
	std::cout << std::endl;
}

/* **** */
/* Node */
/* **** */

PmergeMe::Node::Node(int data, int level, Node* main, Node* sub): head(data), level(level), main(main), sub(sub) {

}

PmergeMe::Node::~Node() {

}

PmergeMe::Node::Node(const Node& other): head(other.head), level(other.level), main(other.main), sub(other.sub) {

}

PmergeMe::Node& PmergeMe::Node::operator=(const Node& other) {
	if (this == &other)
		return *this;
	this->head = other.head;
	this->level = other.level;
	this->main = other.main;
	this->sub = other.sub;
	return *this;
}

int PmergeMe::Node::getHead() const {
	return this->head;
}

int PmergeMe::Node::getLevel() const {
	return this->level;
}

PmergeMe::Node* PmergeMe::Node::getMain() const {
	return this->main;
}

PmergeMe::Node* PmergeMe::Node::getSub() const {
	return this->sub;
}

bool PmergeMe::Node::nodeCompare(const Node* a, const Node* b) {
	return a->getHead() <= b->getHead();
}
