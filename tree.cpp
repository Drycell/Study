#include <iostream>

struct Node
{
	int data;
	Node *left;
	Node *right;
};

class Bitree
{
	private:			
	public:
		Bitree();
		~Bitree();
		void Create_node();
		void Connect_left();
		void Connect_right();
		void Input_data();		
};

int main(void)
{
	return 0;
}

Bitree::Bitree()
{
	
}

void Bitree::Create_node()
{
	Node *Newnode = new Node;
	NewNode -> left = nullptr;
	NewNode -> right = nullptr;
}

void Bitree::
