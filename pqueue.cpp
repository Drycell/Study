#include <iostream>

struct Node
{
	int data;
	Node *Next;
	Node *Prev;
};

class Priority_Queue
{
	private:
		Node *front;
		Node *rear;
		Node *cur;
		int index;
		void swap(Node *node1, Node *node2);

	public:
		Priority_Queue();
		~Priority_Queue();
		void enqueue(int data);
		int dequeue();
		void sorting(bool (*comp)(int data1, int data2));
		void list_print();
		int print_index();
};

bool comp(int data1, int data2);

int main(void)
{
	Priority_Queue pqueue;
	int sel;
	int data;
	std::cout << "PQ!" << std::endl;

	while(1)
	{
		std::cout << "\n\n1. Enqueue\n2. Dequeue\n3. Exit\n" << std::endl;
		std::cout << "Select : ";
		std::cin >> sel;

		if(sel == 1)
		{
			std::cout << "Input data : ";
			std::cin >> data;
			pqueue.enqueue(data);
			pqueue.sorting(comp);
		}
		else if(sel == 2)
		{
			std::cout << "Data : " << pqueue.dequeue() << std::endl;
		}
		else if(sel == 3)
			break;
		else
		{
			std::cout << "Reselect" << std::endl;
			continue;
		}

	}
	return 0;
}

Priority_Queue::Priority_Queue()
{
	front = new Node;
	rear = new Node;

	front -> Next = rear;
	front -> Prev = nullptr;
	rear -> Next = nullptr;
	rear -> Prev = front;

	cur = nullptr;
	index = 0;
}

Priority_Queue::~Priority_Queue()
{
	Node *tmp;
	cur = front -> Next;

	for(int i = 0; i < index - 1; i++)
	{
		tmp = cur -> Next;
		delete cur;
		cur = tmp;
	}
	delete front;
	delete rear;
}

void Priority_Queue::enqueue(int data)
{
	cur = new Node;

	cur -> data = data;

	cur -> Next = front -> Next;
	cur -> Prev = front;
	front -> Next -> Prev = cur;
	front -> Next = cur;

	index++;
	std::cout << data << std::endl;
}

int Priority_Queue::dequeue()
{
	if(front -> Next -> Next == nullptr)
	{
		std::cout << "No Node." << std::endl;
		return 0;
	}
	int tmp;

	cur = front -> Next;
	tmp = cur -> data;
	cur -> data = 0;

	front -> Next -> Next -> Prev = front;
	front -> Next = front -> Next -> Next;

	cur -> Next = nullptr;
	cur -> Prev = nullptr;

	delete cur;
	
	index--;

	return tmp;
}

void Priority_Queue::sorting(bool (*comp)(int data1, int data2))
{
	for(int i = 0; i < index - 1; i++)
	{
		cur = front -> Next;
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

void Priority_Queue::swap(Node *node1, Node *node2)
{
	node1 -> Next = node2 -> Next;
	node2 -> Prev = node1 -> Prev;
	node1 -> Prev -> Next = node2;
	node2 -> Next -> Prev = node1;
	node1 -> Prev = node2;
	node2 -> Next = node1;
}

bool comp(int data1, int data2)
{
	return ((data1 - data2) > 0);
}
