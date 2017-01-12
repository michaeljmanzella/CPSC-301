#include <iostream>
#include "Node.h"
using namespace std;

int count(Node * ptr);
void createList(Node *& head);
void printList(Node *& head);
int sumList(Node *& head);
Node * copyList(Node * head);
void reverse(Node *& head);
int getValue();


int main()
{
	Node list;
	char choice = 'm';

	while (choice != 'z')
	{
		cout << "q Insert at front\n";
		cout << "w Insert at rear\n";
		cout << "e Delete first\n";
		cout << "r Print\n";
		cout << "Please Choose: ";
		cin >> choice;

		switch (choice)
		{
		case 'q':
		{
			int value = getValue();
			list.insertAtFront(value);
			break;
		}
		case 'w':
		{
			int value = getValue();
			list.insertAtRear(value);
			break;
		}
		case 'e':
		{
			list.deleteFirst();
			break;
		}
		case 'r':
		{
			list.print();
			break;
		}
		}
	}
	
	
	

	return 0;
}
void createList(Node *& head)
{
	int arrayList[10] = { 1,2,3,4,5,6,7,8,9,10 };
	for (int i = 0; i < 10; i++)
	{
		Node * temp = new Node;
		temp->info = arrayList[i];
		temp->next = head;
		head = temp;
	}
}
void printList(Node *& head)
{
	Node * temp = new Node;
	temp = head;
	while( temp != NULL)
	{
		cout << temp->info << endl;
		temp = temp->next;
	} 
}

int count(Node * ptr)
{
	Node * temp = new Node;
	temp = ptr;
	int count = 0;
	while (temp != nullptr)
	{
		temp = temp->next;
		count++;
	}
	return count;
}
int sumList(Node *& head)
{
	Node * temp = new Node;
	temp = head;
	int sum = 0;
	while (temp != NULL)
	{
		sum += temp->info;
		temp = temp->next;
	}
	return sum;
}
Node * copyList(Node * head)
{
	Node * newHead = NULL;
	Node * source = head;

	while (source != NULL)
	{
		Node * copy = new Node;
		copy->info = source->info;
		copy->next = newHead;
		newHead = copy;

		source = source->next;
	}
	return newHead;
}
void reverse(Node *& head)
{
	Node * newHead = NULL;
	Node * source = head;

	while (source != NULL)
	{
		Node * copy = new Node;
		copy->info = source->info;
		copy->next = newHead;
		newHead = copy;
		source = source->next;
	}
	head = newHead;
}
int getValue()
{
	int temp;
	cout << "Enter value: ";
	cin >> temp;
	return temp;
}
void insertAtFront(int value)
{

}