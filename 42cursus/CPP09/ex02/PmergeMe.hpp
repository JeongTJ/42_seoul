#pragma once
#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <deque>
# include <list>
# include <utility>
/*
    0xF01     0xF02     0xF03     0xF04     0xF05     0xF06     0xF07     0xF08     0xF09
[9, NULL] [8, NULL] [7, NULL] [6, NULL] [5, NULL] [4, NULL] [3, NULL] [2, NULL] [1, NULL]
            0xF0A             0xF0B             0xF0C             0xF0D            0xF0E
[9, 0xF01, 0xF02] [7, 0xF03, 0xF04] [5, 0xF05, 0xF06] [3, 0xF07, 0xF08] [1, 0xF09, NULL]
            0xF0F             0xF10
[9, 0xF0A, 0xF0B] [5, 0xF0C, 0xF0D]
            0xF11
[9, 0xF0F, 0xF10]
이전 데이터들의 주소를 알아야함 어떻게?

[9, 0xF0F, 0xF10]

sub 주소를 별도로 저장
main 에 접근해서 현재 데이터를 대치
[9, 0xF0A, 0xF0B]
sub을 시작위치 ~ 현재위치로 insert
[5, 0xF0C, 0xF0D] [9, 0xF0A, 0xF0B]

0xF0B
[3, 0xF07, 0xF08] [5, 0xF05, 0xF06] [7, 0xF03, 0xF04] [9, 0xF01, 0xF02]





*/

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
		void printVector();
		void printList();
	private:
		std::vector<Node*> vOrigin;
		std::vector<Node*> vSort;
		std::list<Node*> lOrigin;
		std::list<Node*> lSort;
};

#endif