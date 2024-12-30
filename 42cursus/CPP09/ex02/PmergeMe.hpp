#pragma once
#include <vector>
#include <list>
#include <iostream>

class PmergeMe {
	public:
		PmergeMe(std::vector<unsigned int> input);
		~PmergeMe();

		void v_sorting();
		void l_sorting();
		void print_v_sort();
		void print_l_sort();
		unsigned int get_v_compare() const ;
		unsigned int get_l_compare() const ;
	private:
		class Node {
			public:
				Node();
				~Node();
				Node(const Node &other);
				Node &operator=(const Node &other);

				void set_head(int head);
				void set_main(Node *main);
				void set_sub(Node *sub);
				void set_real_idx(size_t real_idx);
				int get_head() const ;
				Node *get_main() const ;
				Node *get_sub() const ;
				size_t get_real_idx() const ;
			private:
				unsigned int head;
				size_t real_idx;
				Node *main;
				Node *sub;
		};
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		Node* get_new_node();

		void v_merge();
		void v_insertion();
		size_t v_binary_search(size_t s, size_t e, Node *target, std::vector<Node*> &arr);

		void l_merge();
		void l_insertion();
		size_t l_binary_search(size_t s, size_t e, Node *target, std::list<Node*> &arr);

		std::vector<Node*> v_origin;
		std::vector<Node*> v_sort;
		std::list<Node*> l_origin;
		std::list<Node*> l_sort;
		unsigned int v_compare;
		unsigned int l_compare;

		std::vector<Node> node_pool;
		const unsigned int node_max_count;
		unsigned int node_idx;

};
