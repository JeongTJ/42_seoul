#pragma once
#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <deque>
# include <list>
# include <utility>

class PmergeMe {
	public:
		class Node {
			public:
				Node();
				Node(int data);
				Node(int data, int level, Node* main, Node* sub);
				~Node();
				Node(const Node& other);
				Node& operator=(const Node& other);
				int getHead() const;
				int getLevel() const;
				Node* getMain() const;
				Node* getSub() const;
				static bool nodeCompare(const Node* a, const Node* b);
			private:
				int head;
				int level;
				Node* main;
				Node* sub;
		};
		PmergeMe();
		PmergeMe(int argc, char *argv[]);
		~PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		void merge(std::vector<Node*>& before);
		void merge(std::list<Node*>& before);
		std::vector<Node*>& getVector();
		std::list<Node*>& getList();
		unsigned int getVCnt();
		unsigned int getLCnt();
		void printVector();
		void printList();
		std::vector<Node*>::iterator binarySearch(std::vector<Node*>::iterator start, std::vector<Node*>::iterator end, Node* find);
		std::list<Node*>::iterator binarySearch(std::list<Node*>::iterator start, std::list<Node*>::iterator end, Node* find);
	private:
		std::vector<Node*> vOrigin;
		std::vector<Node*> vSort;
		std::list<Node*> lOrigin;
		std::list<Node*> lSort;
		unsigned int vCnt;
		unsigned int lCnt;
};

#endif