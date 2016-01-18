#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
	int data;
	struct _node *Next;
}Node;

typedef struct _list
{
	Node *head;
	Node *tail;
	int index;
}List;

void init_node(List *list);
void menu(List *list);
void insert_node(List *list);
void delete_node(List *list);
void print_all(List *list);
void reverse_list(List *list);
void reset_node(List *list);

int main(void)
{
	List *list;
	init_node(list);
	menu(list);
	reset_node(list);;
	return 0;
}

void init_node(List *list)
{
	list -> head = (Node *)malloc(sizeof(Node));
	list -> tail = (Node *)malloc(sizeof(Node));
	list -> head -> Next = list -> tail;
	list -> head -> Next = NULL;
	list -> tail -> Next = NULL;
	list -> index = 0;
}

void menu(List *list)
{
	int sel = 0;

	printf("Linked list!\n");
	while(1)
	{
		printf("\n1.Insert\n2.Delete\n3.Print\n4.Re\n5.Exit\n");
		printf("Select : ");
		scanf("%d", &sel);

		switch(sel)
		{
			case 1:
				insert_node(list);
				break;
			case 2:
				delete_node(list);
				break;
			case 3:
				print_all(list);
				break;
			case 4:
				reverse_list(list);
				break;
			case 5:
				return ;
			default :
				printf("Re select\n");
				continue;
		}
	}
}

void insert_node(List *list)
{
	int data;
	Node *NewNode = (Node *)malloc(sizeof(Node));

	printf("Input : ");
	scanf("%d", &data);
	
	NewNode -> data = data;
	NewNode -> Next = list -> head -> Next;
	list -> head -> Next = NewNode;

	(list -> index)++;
}

void delete_node(List *list)
{
	if(list -> index == 0)
	{
		printf("No Node!\n");
		return ;
	}
	Node *DelNode;
	
	DelNode = list -> head -> Next;
	list -> head -> Next = list -> head -> Next -> Next;
	DelNode -> Next = NULL;

	free(DelNode);
	DelNode = NULL;

	(list -> index)--;
}

void print_all(List *list)
{
	Node *cur = list -> head -> Next;
	printf("Head -> ");
	if(list -> index != 0)
	{
		while(cur != NULL)
		{
			printf("%d -> ", cur -> data);
			cur = cur -> Next;
		}
	}
	printf("Tail\n");
}

void reverse_list(List *list)
{
	Node **stack = (Node **)malloc((list -> index) * sizeof(Node*));
	int i;
	Node *cur = list -> head -> Next;
	Node *tmp;

	for(i = 0; i < (list -> index); i++)
	{
		stack[i] = cur;
		tmp = cur;
		cur = cur -> Next;
		list -> head -> Next = cur;
		tmp -> Next = NULL;
	}

	for(i = 0; i < (list -> index); i++)
	{
		cur = stack[i];
		cur -> Next = list -> head -> Next;
		list -> head -> Next = cur;
	}
	free(stack);
}

void reset_node(List *list)
{
	Node *cur = list -> head -> Next;
	Node *ncur;
	if(list -> index != 0)
	{
		while(cur -> Next != NULL)
		{
			ncur = cur -> Next;
			free(cur);
			cur = ncur;
			ncur = ncur -> Next;
		}
	}

	free(list -> head);
	free(list -> tail);
}
