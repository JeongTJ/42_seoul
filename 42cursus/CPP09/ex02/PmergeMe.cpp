#include "PmergeMe.hpp"
#include <iostream>

PmergeMe::PmergeMe(std::vector<unsigned int> input): node_max_count(input.size() * 10) {
	node_pool.resize(node_max_count);
	node_idx = 0;
	v_compare = 0;

	for (size_t i = 0; i < input.size(); i++) {
		Node *tmp = get_new_node();
		if (tmp == NULL) {
			return ;
		}
		tmp->set_head(input[i]);
		tmp->set_main(NULL);
		tmp->set_sub(NULL);
		v_origin.push_back(tmp);
	}
	for (size_t i = 0; i < v_origin.size(); i++) {
		Node *tmp = get_new_node();
		if (tmp == NULL) {
			return ;
		}
		*tmp = *v_origin[i];
		v_sort.push_back(tmp);
	}
	for (size_t i = 0; i < input.size(); i++) {
		Node *tmp = get_new_node();
		if (tmp == NULL) {
			return ;
		}
		tmp->set_head(input[i]);
		tmp->set_main(NULL);
		tmp->set_sub(NULL);
		l_origin.push_back(tmp);
	}
	for (std::list<Node*>::iterator it = l_origin.begin(); it != l_origin.end(); it++) {
		Node *tmp = get_new_node();
		if (tmp == NULL) {
			return ;
		}
		*tmp = *(*it);
		l_sort.push_back(tmp);
	}
}

PmergeMe::~PmergeMe() { }

PmergeMe::PmergeMe(const PmergeMe &other): v_origin(other.v_origin), v_sort(other.v_sort), node_pool(other.node_pool), node_max_count(other.node_max_count), node_idx(other.node_idx) {

}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
	if (this == &other) {
		return *this;
	}
	return *this;
}

PmergeMe::Node::Node(): head(-1), main(NULL), sub(NULL) {
	
}

PmergeMe::Node::~Node() {
	
}

PmergeMe::Node::Node(const Node &other): head(other.head), main(other.main), sub(other.sub) {
	
}

PmergeMe::Node &PmergeMe::Node::operator=(const Node &other) {
	if (this == &other) {
		return *this;
	}
	this->head = other.head;
	this->main = other.main;
	this->sub  = other.sub;
	return *this;
}

void PmergeMe::Node::set_head(int head) {
	this->head = head;
}

void PmergeMe::Node::set_main(Node *main) {
	this->main = main;
}

void PmergeMe::Node::set_sub(Node *sub) {
	this->sub = sub;
}

void PmergeMe::Node::set_real_idx(size_t real_idx) {
	this->real_idx = real_idx;
}

int PmergeMe::Node::get_head() const {
	return this->head;
}

PmergeMe::Node *PmergeMe::Node::get_main() const {
	return this->main;
}

PmergeMe::Node *PmergeMe::Node::get_sub() const {
	return this->sub;
}

size_t PmergeMe::Node::get_real_idx() const {
	return this->real_idx;
}

PmergeMe::Node* PmergeMe::get_new_node() {
	if (node_idx >= node_max_count) {
		return NULL;
	}
	return &node_pool[node_idx++];
}

void PmergeMe::v_sorting() {
	print_v_sort();
	v_merge();
	print_v_sort();
}

void PmergeMe::print_v_sort() {
	for (size_t i = 0; i < v_sort.size(); i++) {
		std::cout << v_sort[i]->get_head() << ' ';
	}
	std::cout << '\n';
}

unsigned int PmergeMe::get_v_compare() const {
	return this->v_compare;
}

void PmergeMe::v_merge() {
	if (v_sort.size() < 2) {
		return ;
	}
	Node *remain_node = NULL;
	std::vector<Node*> even_idx;
	std::vector<Node*> odd_idx;

	for (size_t i = 0; i < v_sort.size(); i++) {
		if (i % 2 == 0) {
			even_idx.push_back(v_sort[i]);
		} else {
			odd_idx.push_back(v_sort[i]);
		}
	}
	if (even_idx.size() > odd_idx.size()) {
		remain_node = even_idx[even_idx.size() - 1];
		even_idx.pop_back();
	}

	v_sort.clear();
	for (size_t i = 0; i < even_idx.size(); i++) {
		Node *tmp = get_new_node();
		Node *main_node;
		Node *sub_node;

		if (tmp == NULL) {
			return ;
		}
		v_compare++;
		if (even_idx[i]->get_head() >= odd_idx[i]->get_head()) {
			main_node = even_idx[i];
			sub_node = odd_idx[i];
		} else {
			main_node = odd_idx[i];
			sub_node = even_idx[i];
		}
		tmp->set_head(main_node->get_head());
		tmp->set_main(main_node);
		tmp->set_sub(sub_node);

		v_sort.push_back(tmp);
	}

	v_merge();
	v_insertion();
	if (remain_node == NULL) {
		return ;
	}
	size_t insert_idx;

	insert_idx = v_binary_search(0, v_sort.size(), remain_node, v_sort);
	v_sort.insert(v_sort.begin() + insert_idx, remain_node);
}

void PmergeMe::v_insertion() {
	std::vector<Node*> main_chain;
	std::vector<Node*> sub_chain;

	for (size_t i = 0; i < v_sort.size(); i++) {
		main_chain.push_back(v_sort[i]->get_main());
		sub_chain.push_back(v_sort[i]->get_sub());
		sub_chain[i]->set_real_idx(i);
		main_chain[i]->set_real_idx(i);
	}

	main_chain.insert(main_chain.begin(), sub_chain[0]);
	sub_chain[0] = NULL;
	sub_chain.insert(sub_chain.begin(), NULL);

	size_t two_power = 2;
	int idx = two_power;
	while (1) {
		if (two_power < sub_chain.size()) {
			idx = two_power - 1;
		} else {
			idx = sub_chain.size() - 1;
		}
		if (sub_chain[sub_chain.size() - 1] == NULL) {
			break;
		}
		while (idx >= 0) {
			if (sub_chain[idx] != NULL) {
				size_t insert_idx;

				insert_idx = v_binary_search(0, idx, sub_chain[idx], main_chain);
				main_chain.insert(main_chain.begin() + insert_idx, sub_chain[idx]);
				sub_chain[idx] = NULL;
				sub_chain.insert(sub_chain.begin() + insert_idx, NULL);

				if ((int)insert_idx < idx) {
					idx++;
				}
			}
			idx--;
		}
		two_power *= 2;
	}
	
	v_sort.clear();
	for (size_t i = 0; i < main_chain.size(); i++) {
		v_sort.push_back(main_chain[i]);
	}
}

size_t PmergeMe::v_binary_search(size_t s, size_t e, Node *target, std::vector<Node*> &arr) {
	size_t start, mid, end;

	start = s;
	end = e;
	while (start < end) {
		mid = (start + end) / 2;
		v_compare++;
		if (arr[mid]->get_head() > target->get_head()) {
			end = mid;
		} else {
			start = mid + 1;
		}
	}
	return start;
}

void PmergeMe::l_sorting() {
	// print_l_sort();
	l_merge();
	// print_l_sort();
}

void PmergeMe::print_l_sort() {
	for (std::list<Node*>::iterator it = l_sort.begin(); it != l_sort.end(); it++) {
		std::cout << (*it)->get_head() << ' ';
	}
	std::cout << '\n';
}

unsigned int PmergeMe::get_l_compare() const {
	return this->l_compare;
}

void PmergeMe::l_merge() {
	if (l_sort.size() < 2) {
		return ;
	}
	Node *remain_node = NULL;
	std::list<Node*> even_idx;
	std::list<Node*> odd_idx;
	int idx = 0;

	for (std::list<Node*>::iterator it = l_sort.begin(); it != l_sort.end(); it++, idx++) {
		if (idx % 2 == 0) {
			even_idx.push_back(*it);
		} else {
			odd_idx.push_back(*it);
		}
	}
	if (even_idx.size() > odd_idx.size()) {
		remain_node = even_idx.back();
		even_idx.pop_back();
	}

	l_sort.clear();
	for (std::list<Node*>::iterator eit = even_idx.begin(), oit = odd_idx.begin(); eit != even_idx.end() && oit != odd_idx.end(); eit++, oit++) {
		Node *tmp = get_new_node();
		Node *main_node;
		Node *sub_node;

		if (tmp == NULL) {
			return ;
		}
		l_compare++;
		if ((*eit)->get_head() >= (*oit)->get_head()) {
			main_node = (*eit);
			sub_node = (*oit);
		} else {
			main_node = (*oit);
			sub_node = (*eit);
		}
		tmp->set_head(main_node->get_head());
		tmp->set_main(main_node);
		tmp->set_sub(sub_node);

		l_sort.push_back(tmp);
	}

	l_merge();
	l_insertion();
	if (remain_node == NULL) {
		return ;
	}
	size_t insert_idx;

	insert_idx = l_binary_search(0, l_sort.size(), remain_node, l_sort);
	std::list<Node*>::iterator insert_it = l_sort.begin();
	std::advance(insert_it, insert_idx);
	l_sort.insert(insert_it, remain_node);
}

void PmergeMe::l_insertion() {
	std::list<Node*> main_chain;
	std::list<Node*> sub_chain;
	int idx = 0;

	for (std::list<Node*>::iterator it = l_sort.begin(); it != l_sort.end(); it++, idx++) {
		main_chain.push_back((*it)->get_main());
		sub_chain.push_back((*it)->get_sub());
		main_chain.back()->set_real_idx(idx);
		sub_chain.back()->set_real_idx(idx);
	}

	main_chain.insert(main_chain.begin(), sub_chain.front());
	sub_chain.front() = NULL;
	sub_chain.insert(sub_chain.begin(), NULL);

	size_t two_power = 2;
	idx = two_power;
	std::list<Node*>::reverse_iterator it = sub_chain.rbegin();
	while (1) {
		if (two_power < sub_chain.size()) {
			idx = two_power;
		} else {
			idx = sub_chain.size();
		}
		if (sub_chain.back() == NULL) {
			break;
		}
		it = sub_chain.rbegin();
		std::advance(it, sub_chain.size() - idx);
		while (it != sub_chain.rend()) {
			if ((*it) != NULL) {
				size_t insert_idx;

				insert_idx = l_binary_search(0, idx - 1, (*it), main_chain);
				std::list<Node*>::iterator insert_it = main_chain.begin();
				std::list<Node*>::iterator null_insert_it = sub_chain.begin();
				std::advance(insert_it, insert_idx);
				std::advance(null_insert_it, insert_idx);
				main_chain.insert(insert_it, (*it));
				(*it) = NULL;
				sub_chain.insert(null_insert_it, NULL);
				if ((int)insert_idx < idx) {
					idx++;
				}
			}
			it++;
			idx--;
		}
		two_power *= 2;
	}
	
	l_sort.clear();
	for (std::list<Node*>::iterator it = main_chain.begin(); it != main_chain.end(); it++) {
		l_sort.push_back((*it));
	}
}

size_t PmergeMe::l_binary_search(size_t s, size_t e, Node *target, std::list<Node*> &arr) {
	size_t start, mid, end;
	std::list<Node*>::iterator it;

	start = s;
	end = e;
	while (start < end) {
		mid = (start + end) / 2;
		it = arr.begin();
		std::advance(it, mid);
		l_compare++;
		if ((*it)->get_head() > target->get_head()) {
			end = mid;
		} else {
			start = mid + 1;
		}
	}
	return start;
}
