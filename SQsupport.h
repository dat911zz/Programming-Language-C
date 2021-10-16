#ifndef _STACK_QUEUE_
#define _STACK_QUEUE_
//==================================================
#include<iostream>
#include<stdarg.h>
//==================================================
template <class data>
class node {
	public:
		data info;
		node* next;

	//Khoi tao
		node();
		node(data element);
};

template <class data>
node<data>::node(data element)
{
	info = element;
	next = NULL;
}

template <class data>
node<data>::node()
{
	next = NULL;
}
//==================================================
template <class data>
class stack {
	public:
		node<data>* top;
		unsigned int size;
	//Khoi tao
		stack();
		~stack();
	//Ham
		bool isEmpty();
		void show();
		void push(data element);
		void pop(data& get);
		void free();
		void get(data& read_only);
};

template <class data>
void stack<data>::get(data& read_only)
{
	if (top == NULL)
		return;
	read_only = top->info;
}

template <class data>
void stack<data>::free()
{
	node<data>* p = top;
	for (; top; p = top)
	{
		top = top->next;
		delete p;
	}
	size = 0;
}

template <class data>
void stack<data>::pop(data& get)
{
	if (top == NULL)
		return;

	get = top->info;
	node<data>* p = top;
	top = top->next;
	delete p;
	size--;
}

template <class data>
bool stack<data>::isEmpty()
{
	return top == NULL;
}

template <class data>
void stack<data>::push(data element)
{
	node<data>* p = new node<data>(element);
	p->next = top;
	top = p;
	size++;
}

template <class data>
void stack<data>::show()
{
	for (node<data>* i = top; i; i = i->next)
		std::cout << i->info << " ";
	std::cout << "NULL\n";
}

template <class data>
stack<data>::~stack()
{
	free();
}

template <class data>
stack<data>::stack()
{
	top = NULL;
	size = 0;
}
//==================================================
template <class data>
class queue {
	public:
		node<data>* head, * tail;
		unsigned size;

	//Khoi tao
		queue();
		~queue();
	//Ham
		bool isEmpty();
		void show();
		void push(data element);
		void pop(data& get);
		void free();
};

template <class data>
void queue<data>::free()
{
	node<data>* p = head;
	for (; head; p = head)
	{
		head = head->next;
		delete p;
	}
	tail = NULL;
	size = 0;
}

template <class data>
void queue<data>::pop(data& get)
{
	if (head == NULL)
		return;

	get = head->info;
	node<data>* p = head;
	head = head->next;

	if (tail == p)
		tail = NULL;
	delete p;
	size--;
}

template <class data>
void queue<data>::push(data element)
{
	node<data>* p = new node<data>(element);
	
	if (head == NULL)
	{
		head = tail = p;
		size = 1;
		return;
	}

	tail->next = p;
	tail = p;
	size++;
}

template <class data>
void queue<data>::show()
{
	for (node<data>* i = head; i; i = i->next)
		std::cout << i->info << " ";
	std::cout << "NULL\n";
}

template <class data>
bool queue<data>::isEmpty()
{
	return head == NULL;
}

template <class data>
queue<data>::~queue()
{
	free();
}

template <class data>
queue<data>::queue()
{
	head = tail = NULL;
	size = 0;
}
//==================================================
#endif
