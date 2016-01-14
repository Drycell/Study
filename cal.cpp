#include <iostream>
#include <cstring>

class Stack
{
	private:
		char data[30];
		int top;
	   	bool isNum(char tmp);// check number or operator
		int getpre(char op);
		int precedence(char op1, char op2);
		bool isEmpty();
	public:
		Stack();
		void convert_postfix(char *input);
		void push(char tmp);
		char pop();
		char peek();
};

/*
class Queue
{
	private:
	public:
		bool isEmpty();
		void enqueue();
		void dequeue();
		void print_prefix();
};
*/

int main(void)
{
	Stack stack;
	char compute[30];

	std::cout << "Input : ";
	//ste::cin >> tmp; blank erroe
	std::cin.getline(compute, 30); //sol : copy this code

	stack.convert_postfix(compute);
	std::cout << "Postfix : " << compute << std::endl;

	//std::cout << "Prefix : " << compute << std::endl;
	return 0;
}

Stack::Stack()
{
	top = -1;
}

bool Stack::isEmpty(void)
{
	if(top == -1)
		return 1;
	else
		return 0;
}
int Stack::getpre(char op)
{
	if(op == '+' || op == '-')
		return 1;
	else if(op == '*' || op == '/')
		return 2;
	else
		return -1;
	return 0;
}
bool Stack::isNum(char tmp)
{
	if('0' <= tmp && tmp <= '9')
		return 1;
	else
		return 0;
}

int Stack::precedence(char op1, char op2)
{
	int pre_op1 = getpre(op1);
	int pre_op2 = getpre(op2);

	if(pre_op1 > pre_op2)
		return 1;
	else if(pre_op1 < pre_op2)
		return -1;
	else
		return 0;
}

void Stack::convert_postfix(char *input)
{
	char tmp, oper;
	int j = 0;
	int len = strlen(input);
	char *output = new char[len + 1];

	for(int i = 0; i < len + 1; i++)
	{
		tmp = input[i];
		if(isNum(tmp))
		{
			output[j++] = tmp;
		}
		else if(input[i] == ' ')
		{
			output[j++] = ' ';
			continue;
		}
		else
		{
			switch(tmp)
			{
				case '(' :
					push(tmp);
					break;
				case ')' :
					while(1)
					{
						oper = pop();
						if(oper == '(')
							break;
						output[j++] = oper;
					}
					break;
				case '+' : case '-' :
				case '*' : case '/' :
					while(!isEmpty() && precedence(peek(), tmp) >= 0)
						output[j++] = pop();
					push(tmp);
					break;
			}
		}
	}

	while(!isEmpty())
		output[j++] = pop();

	strcpy(input, output);
	delete[] output;
}


void Stack::push(char oper)
{
	top += 1;
	data[top] = oper;
}

char Stack::pop()
{
	top -= 1;
	return data[top + 1];
}

char Stack::peek()
{
	return data[top];
}
