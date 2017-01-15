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
//precondition - new Node must be sent
bool Node::splitList(Node * head1, Node *& head2)
{
	Node * middle;
	Node * current;

	if (head1 == NULL)//list empty
	{
		head2 = NULL;
		return false;
	}
	else if (head1->next == NULL)//list has one node
	{
		head2 = NULL;
		return false;
	}
	else
	{
		middle = head1;//assign the head to the new middle pointer
		current = head1->next;//current to next item in the list

		if (current != NULL)//list has multiple nodes
		{
			current = current->next;//move the current down the list 
		}
		while (current != NULL)//move middle onece and current twice
		{
			middle = middle->next;//move foward middle once
			current = current->next;//move current 
			if (current != NULL)
				current = current->next;//move current again
		}
		head2 = middle->next;//place the new head to the middle
		middle->next = NULL;//make the first list end and point to NULL
		return true;
	}
}