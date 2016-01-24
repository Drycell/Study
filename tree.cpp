#include <iostream>

struct Node
{
	int data;
	Node *Left;
	Node *Right;
};

class Bitree
{
	private:			
	public:
		Node *Create_node();
		void Connect_left(Node *pa, Node *ch);
		void Connect_right(Node *pa, Node *ch);
		void Pre(Node *node);
		void In(Node *node);
		void Post(Node *node);
};

int main(void)
{
	Bitree bitree;
	Node **node = new Node*[8];

	for(int i = 1; i < 8; i++)
	{
		node[i] = bitree.Create_node();
		node[i] -> data = i;
	}

	for(int i = 1; i < 4; i++)
	{
		bitree.Connect_left(node[i], node[2*i]);
		bitree.Connect_right(node[i], node[2*i + 1]);
	}

	std::cout << "Pre : ";
	bitree.Pre(node[1]);
	std::cout << std::endl;

	std::cout << "Post : ";
	bitree.Post(node[1]);
	std::cout << std::endl;
	
	std::cout << "In : ";
	bitree.In(node[1]);
	std::cout << std::endl;
	
	delete []node;

	return 0;
}

Node *Bitree::Create_node()
{
	Node *NewNode = new Node;
	NewNode -> Left = nullptr;
	NewNode -> Right = nullptr;
	return NewNode;
}

void Bitree::Connect_left(Node *pa, Node *ch)
{
	pa -> Left = ch;
}

void Bitree::Connect_right(Node *pa, Node *ch)
{
	pa -> Right = ch;
}

void Bitree::Pre(Node *node)
{
	if(node == nullptr)
		return;

	std::cout << node -> data << " ";
	Pre(node -> Left);
	Pre(node -> Right);
}

void Bitree::Post(Node *node)
{
	if(node == nullptr)
		return;

	Post(node -> Left);
	Post(node -> Right);
	std::cout << node -> data << " ";
}

void Bitree::In(Node *node)
{
	if(node == nullptr)
		return;

	In(node -> Left);
	std::cout << node -> data << " ";
	In(node -> Right);
}
