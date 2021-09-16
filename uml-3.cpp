#include <iostream>

using std::cout;
using std::cin;
using std::endl;

struct Node {
	Node* next = nullptr;
	int value;
	Node(int value = 0) :
		value{ value } 
	{};
};


class List {
public:
	List() :
		_head{ nullptr },
		_tail{ nullptr } 
	{};

	~List() {
		while (_head != nullptr) 
		{
			Node* tmp = _head;
			_head = _head->next;
			delete tmp;
		}
	}
	void add(int value) 
	{
		Node* tmp = new Node(value);
		if (_head == nullptr) 
		{
			_head = _tail = tmp;
		}
		else 
		{
			_tail->next = tmp;
			_tail = tmp;
		}
	}

	int remove(int index) 
	{
		int value;
		if (this->count_index() < index)
		{
			return-1;
		}

		if (index == 0) 
		{
			Node* tmp = _head;
			value = _head->value;
			_head = _head->next;
			delete tmp;
			return value;
		}
		else 
		{
			Node* tmp = _head;
			for (auto i = 0; i < index - 1; i++) {
				tmp = tmp->next;
			}
			Node* tmp_remove = tmp->next;
			tmp->next = tmp_remove->next;
			value = tmp_remove->value;
			delete tmp_remove;
			return value;
		}
	}

	void insert(int value, int index) {
		if (this->count_index()<index)
		{
			return;
		}
		
		Node* new_node = new Node(value);
		if (index == 0) {
			new_node->next = _head;
			_head = new_node;
		}
		else {
			Node* tmp = _head;
			for (auto i = 0; i < index - 1; i++) 
			{
				tmp = tmp->next;
			}
			new_node->next = tmp->next;
			tmp->next = new_node;
		}
	}

	

	int find_index(int value) 
	{
		Node* tmp = _head;
		int i= 0;
		while (tmp != nullptr) 
		{
			if (tmp->value == value) 
			{
				return i;
			}
			tmp = tmp->next;
			i++;
		}
		return -1;
	}

	void out_list()
	{
		Node* tmp = _head;
		int i=0;
		while (tmp!=nullptr)
		{
			cout << "Node#" << i++ << endl;
			cout << tmp->value;
			cout << endl;
			tmp = tmp->next;

		}
	}

	int count_index()
	{
		Node* tmp = _head;
		int i = -1;
		
		while (tmp!=nullptr)
		{
			
			i++;
			tmp = tmp->next;
		}
		return i;
	}

	

private:
	Node* _head;
	Node* _tail;
};






