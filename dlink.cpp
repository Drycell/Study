#include <iostream>

struct Node
{
	int data;
	Node *Next;
	Node *Prev;
};

class List
{
	private:
		Node *head;
		Node *tail;
		Node *cur;
		int index;
		void swap(Node *node1, Node *node2);

	public:
		List();
		~List();
		void insert_head_node(int data);
		void insert_tail_node(int data);
		void del_head_node();
		void del_tail_node();
		void sorting(bool (*comp)(int data1, int data2));
		void list_print();
		int print_index();
};

bool comp(int data1, int data2);

int main(void)
{
	List list;
	int sel;
	int data;
	std::cout << "List List!" << std::endl;

	while(1)
	{
		std::cout << "\n\n1.Insert head\n2.Insert tail\n3.Delete head\n4.Delete tail\n5.Sorting\n6.List print\n7.Get size\n8.Exit\n" ;
		std::cout << "Select : ";
		std::cin >> sel;

		if(sel == 1)
		{
			std::cout << "Input data : ";
			std::cin >> data;
			list.insert_head_node(data);
		}
		else if(sel == 2)
		{
			std::cout << "Input data : ";
			std::cin >> data;
			list.insert_tail_node(data);
		}
		else if(sel == 3)
			list.del_head_node();
		else if(sel == 4)
			list.del_tail_node();
		else if(sel == 5)
			list.sorting(comp);
		else if(sel == 6)
			list.list_print();
		else if(sel == 7)
			std::cout << list.print_index() << std::endl;
		else if(sel == 8)
			break;
		else
			continue;
	}
	return 0;
}

List::List()
{
	head = new Node;
	tail = new Node;

	head -> Next = tail;
	head -> Prev = nullptr;
	tail -> Next = nullptr;
	tail -> Prev = head;

	cur = nullptr;
	index = 0;
}

List::~List()
{
	Node *tmp;
	cur = head -> Next;

	for(int i = 0; i < index - 1; i++)
	{
		tmp = cur -> Next;
		delete cur;
		cur = tmp;
	}
	delete head;
	delete tail;
}

void List::insert_head_node(int data)
{
	cur = new Node;

	cur -> data = data;

	cur -> Next = head -> Next;
	cur -> Prev = head;
	head -> Next -> Prev = cur;
	head -> Next = cur;

	index++;
}

void List::insert_tail_node(int data)
{
	cur = new Node;

	cur -> data = data;

	cur -> Next = tail;
	cur -> Prev = tail -> Prev;
	tail -> Prev -> Next = cur;
	tail -> Prev = cur;

	index++;
}

void List::del_head_node()
{
	if(head -> Next -> Next == nullptr)
	{
		std::cout << "No Node." << std::endl;
		return ;
	}

	head -> Next -> data = 0;
	cur = head -> Next;

	head -> Next -> Next -> Prev = head;
	head -> Next = head -> Next -> Next;

	cur -> Next = nullptr;
	cur -> Prev = nullptr;

	delete cur;

	index--;
}

void List::del_tail_node()
{
	if(tail -> Prev -> Prev == nullptr)
	{
		std::cout << "No Node." << std::endl;
		return ;
	}

	tail -> Prev -> data = 0;
	cur = tail -> Prev;

	tail -> Prev -> Prev -> Next = tail;
	tail -> Prev = tail -> Prev -> Prev;

	cur -> Next = nullptr;
	cur -> Prev = nullptr;

	delete cur;
	index--;

}

void List::sorting(bool (*comp)(int data1, int data2))
{
	for(int i = 0; i < index - 1; i++)
	{
		cur = head -> Next;
		for(int j = index - 1; j > i; j--)
		{
			if(comp(cur -> data, cur -> Next -> data) > 0)
			{
				swap(cur, cur -> Next);
			}
			else
				cur = cur -> Next;
		}
	}

}

void List::swap(Node *node1, Node *node2)
{
	node1 -> Next = node2 -> Next;
	node2 -> Prev = node1 -> Prev;
	node1 -> Prev -> Next = node2;
	node2 -> Next -> Prev = node1;
	node1 -> Prev = node2;
	node2 -> Next = node1;
}

void List::list_print()
{
	cur = head -> Next;
	for(int i = 0; i < index ; i++)
	{
		std::cout << i + 1 << "data : " << cur -> data << std::endl;
		cur = cur -> Next;
	}
}

int List::print_index()
{
	return index;
}


bool comp(int data1, int data2)
{
	return ((data1 - data2) > 0);
}
