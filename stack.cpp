#include <iostream>

struct Node
{
	int data;
	Node *Next;
};

class Stack
{
	private:
		Node *top;
		Node *cur;
		int index;

	public:
		Stack();
		~Stack();
		void push(int data); // input data
		int pop(); // return data & delete node
		int peek(); // only return
		int size(); // return size
		bool isEmpty(); // check index
		bool checkStack(); // except
};

int main(void)
{
	Stack stack_t = Stack();
	int sel;
	int data;
	std::cout << "STACK!" << std::endl;
	
	while(1)
	{
		std::cout << "1.Push\n2.Pop\n3.Peek\n4.Index\n5.Exit\n" ;
		std::cout << "Select : ";
		std::cin >> sel;

		if(sel == 1)
		{
			std::cout << "Input data : ";
			std::cin >> data;
			stack_t.push(data);
		}
		else if(sel == 2)
			std::cout << "Pop data : " << stack_t.pop() << std::endl;
		else if(sel == 3)
			std::cout << "Peek data : " << stack_t.peek() << std::endl;
		else if(sel == 4)
			std::cout << "Size : " << stack_t.size() << std::endl;
		else if(sel == 5)
			break;
		else
			continue;
	}
	
	return 0;
}

Stack::Stack()
{
	top = new Node;
	top -> Next = NULL;
	index = 0;
}

Stack::~Stack()
{
	Node *tmp = top -> Next;
	for(int i = 0; i < index; i++)
	{
		cur = tmp -> Next;
		delete tmp;
		tmp = cur;
	}
	delete top;
	std::cout << "Elimination success" << std::endl;
}

void Stack::push(int data)
{
	cur = new Node;
	cur -> data = data;
	cur -> Next = top -> Next;
	top -> Next = cur;
	index++;
}

int Stack::pop(void)
{
	int p_data;
	
	if(checkStack())
	{
		std::cout << "No data" << std::endl;
		return 0;
	}

	p_data = top -> Next -> data;
	
	cur = top -> Next;
	
	top -> Next = top -> Next -> Next;

	delete cur;
	index--;
	return p_data;
}

int Stack::peek(void)
{
	if(checkStack())
	{
		std::cout << "No data" << std::endl;
		return 0;
	}

	return top -> Next -> data;
}

int Stack::size(void)
{
	return index;
}

bool Stack::isEmpty(void)
{
	return (index == 0);
}

bool Stack::checkStack(void)
{
	if(isEmpty())
	{
		return 1;
	}
	else
		return 0;
}
