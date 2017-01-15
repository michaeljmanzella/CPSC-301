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
bool splitList(Node & list1, Node & list2);


int main()
{
	Node list1(0);
	Node list2(0);
	char choice = 'm';

	while (choice != 'z')
	{
		cout << "q Insert at front\n";
		cout << "w Insert at rear\n";
		cout << "e Delete first\n";
		cout << "r Print\n";
		cout << "t Split List\n";
		cout << "y Print Split\n";
		cout << "Please Choose: ";
		cin >> choice;

		switch (choice)
		{
		case 'q':
		{
			int value = getValue();
			list1.insertAtFront(value);
			break;
		}
		case 'w':
		{
			int value = getValue();
			list1.insertAtRear(value);
			break;
		}
		case 'e':
		{
			list1.deleteFirst();
			break;
		}
		case 'r':
		{
			list1.print(list1);
			break;
		}
		case 't':
		{
			if (splitList(list1,list2))
			{
				cout << "NODE SPLIT\n";
			}
			else
			{
				cout << "ERROR\n";
			}
			break;
		}
		case 'y':
		{
			list2.print(list2);
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
bool splitList(Node & list1, Node & list2)
{
	Node * middle;
	Node * current;

	if (list1.first == NULL)//list empty
	{
		cout << "empty\n";
		list2.first = NULL;
		return false;
	}
    else if (list1.next == NULL)//list has one node
	{
		cout << "one node\n";
		list2.first = NULL;
		return false;
	}
	else
	{
		middle = list1.first;//assign the head to the new middle pointer
		current = list1.first;//current to next item in the list

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
		list2.first = middle->next;//place the new head to the middle
		middle->next = NULL;//make the first list end and point to NULL
		return true;
	}
}