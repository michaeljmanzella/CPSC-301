#include "Node.h"

Node::Node(int data)
{
	info = data;
	length = 0;
	next = nullptr;
	first = nullptr;
	last = nullptr;
}
void Node::insertAtFront(int value)
{
	if (first == NULL && last == NULL)
	{
		Node * temp = new Node;
		temp->info = value;
		temp->next = first;
		first = temp;
		last = temp;
	}
	else
	{
		Node * temp = new Node;
		temp->info = value;
		temp->next = first;
		first = temp;
	}
	
}
void Node::insertAtRear(int value)
{
	if (first == NULL && last == NULL)
	{
		Node * temp = new Node;
		temp->info = value;
		temp->next = first;
		first = temp;
		last = temp;
	}
	else
	{
		Node * temp = new Node;
		temp->info = value;
		temp->next = NULL;
		last->next = temp;
		last = temp;
	}
	
}
void Node::deleteFirst()
{
	Node * temp = new Node;
	temp = first;
	first = first->next;
	delete temp;
}
void Node::print()
{
	Node * temp = new Node;
	temp = first;
	while (temp != NULL)
	{
		cout << temp->info << endl;
		temp = temp->next;
	}
}