#include <cstdlib>
#include<iostream>
using namespace std;

#define NOT_CREATE_NODE 0x0001
#define EMPTY_LIST 0x0002
#define NOT_ENOUGH_ELEMENTS 0x0004

typedef struct Node{
	int value;
	Node *prev;
	Node *next;
}Node;
typedef struct List{
	Node *head;
	Node *tail;
	unsigned int error;
}List;

List *creatlist(); // Создать новый список
bool isEmpty(List *d); // Проверка на пустоту
void addfront(List *d, int a); // Добавить елемент в начало
void addback(List *d, int a); // Добавить елемент в конец
Node *front(List *d); // Возвращает адрес первого елемента 
Node *back(List *d); // Возвращает адрес последнего елемента
int getfront(List *d); // Возвращает первый елемент
int getback(List *d); // Возвращает последний елемент
void print(List *d); // Печать всех елеметов
void printRevers(List *d); // Печать всеч елеметов с конца
int countNodes(List *d); // Счетчик количества елементов
void printFiveNodesFirst(List *d); // Печать первых пяти елеметов
void printFiveNodesLast(List *d); // Печать последних пяти елементов
void deleteList(List *d); // Удаление занимаемой памяти

int main()
{
	List *List1 = creatlist();
	List *List2 = creatlist();

	if(List1 == NULL)
		cout << "Could not create list";
	for(int i = 11; i < 102; i+=10)
		addfront(List1, i);
	if(List2 == NULL)
		cout << "Could not create list";
	for(int i = 11; i < 102; i+=10)
		addback(List2, i);

	print(List1);
	cout << endl;
	printRevers(List1);
	cout << endl;
	printFiveNodesFirst(List1);
	cout << endl;
	printFiveNodesLast(List1);
	cout << endl;

	deleteList(List1);

	print(List2);
	cout << endl;
	printRevers(List2);
	cout << endl;
	printFiveNodesFirst(List2);
	cout << endl;
	printFiveNodesLast(List2);
	cout << endl;

	deleteList(List2);

	system("pause");
	return 0;
}

List *creatlist()
{
	List*d = new List;
	d->head = NULL;
	d->tail = NULL;
	return d;
}

bool isEmpty(List *d)
{
	return (d->head==NULL&&d->tail==NULL);
}

void addfront(List *d, int a)
{
	Node *t = new Node;

	if(t == NULL)
		d -> error | NOT_CREATE_NODE;
	else
	{
		t->value = a;
		t->prev = NULL;
		t->next = d->head;
		if(isEmpty(d))
		{
			d->head = t;
			d->tail = t;
		}
		else
		{

			d->head->prev = t;
			d->head = t;
		}
	}
}

void addback(List *d, int a)
{
	if(isEmpty(d))
		addfront(d,a);
	else
	{
		Node *t = new Node;
		if(t == NULL)
			d -> error | NOT_CREATE_NODE;
		else
		{
			t->value = a;
			t->prev = d->tail;
			t->next = NULL;
			d->tail->next = t;
			d->tail = t;
		}
	}
}

Node *front(List*d) 
{
	if(isEmpty(d))
	{
		d-> error | EMPTY_LIST;
		return NULL;
	}
	else
		return d->head;
}

Node *back(List*d) 
{
	if(isEmpty(d))
	{
		d-> error | EMPTY_LIST;
		return NULL;
	}
	else
		return d ->tail;
}

int getfront(List *d) 
{
	if(isEmpty(d))
	{
		d-> error | EMPTY_LIST;
		return NULL;
	}
	else
		return d -> head -> value;
}

int getback(List*d)
{
	if(isEmpty(d))
	{
		d-> error | EMPTY_LIST;
		return NULL;
	}
	else
	return d -> tail -> value;
}

void print(List *d)
{
	Node *i = d -> head;

	if(isEmpty(d))
	{
		d-> error | EMPTY_LIST;
	}
	else
	{
		for(; i != NULL; i = i->next)
		cout << i ->value;
	}
}

void printRevers(List *d)
{
	Node *i = d -> tail;

	if(isEmpty(d))
	{
		d-> error | EMPTY_LIST;
	}
	else
	{
		for(; i != NULL; i = i->prev)
			cout << i -> value;
	}
}

void printFiveNodesFirst(List *d)
{
	Node *i = d -> head;
    int counter = 1;

	if(isEmpty(d))
	{
		d->error | EMPTY_LIST;
	}
	else if(countNodes(d) < 5)
	{
		d -> error | NOT_ENOUGH_ELEMENTS;
	}
	else
	{
		for(; counter <= 5; i = i->next, counter ++)
			cout << i->value;
	}
}

void printFiveNodesLast(List *d)
{
	Node *i = d -> tail;
	int counter = 1;

	if(isEmpty(d))
	{
		d->error | EMPTY_LIST;
	}
	else if(countNodes(d) < 5)
	{
		d -> error | NOT_ENOUGH_ELEMENTS;
	}
	else
	{
		for(; counter <= 5; i = i->prev, counter ++)
			cout << i->value;
	}
}

int countNodes(List *d)
{
	Node *i = d -> head;
	int counter = 0;
	if(isEmpty(d))
	{
		d->error | EMPTY_LIST;
		return NULL;
	}
	else
	{
		for(; i != NULL; i = i->next)
			counter ++;
		return counter;
	}
	
}

void deleteList(List *d)
{
	if(isEmpty(d))
	{
		cout << "I am empty";
		delete d;
	}
	else
	{
		Node *i = d -> head;
		Node *next = NULL;
		for(; i != NULL; i = next)
		{	
			next = i->next;
			delete i;
		}

		delete d;
	}
	
}