// PointersandLinkedLists.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int getValue();
void insert(NodeType *& head);
void printList(NodeType *& head);
void deleteFirst(NodeType *& head);
bool find(NodeType *& head);
bool findAndDelete(NodeType *& head);
bool deleteList(NodeType *& head);

int main()
{
	NodeType * head = NULL;
	int value = 0;
	char choice = 'm';

	while (choice != 'z')
	{
		cout << "*****************************\n";
		cout << "a. Add:\n";
		cout << "b. Print All:\n";
		cout << "c. Find\n";
		cout << "d. Delete First\n";
		cout << "e. Delete\n";
		cout << "f. Delete All\n";
		cout << "q. Quit\n";
		cout << "Enter Selection:";
		cin >> choice;
		switch (choice)
		{
		case 'a':
		{
			insert(head);
			break;
		}
		case 'b':
		{
			cout << "Printing List\n";
			printList(head);
			break;
		}
		case 'c':
		{
			if (find(head))
			{
				cout << "FOUND\n";
			}
			else
				cout << "NOT FOUND!\n";
			break;
		}
		case 'd':
		{
			cout << "Deleting First\n";
			deleteFirst(head);
			break;
		}
		case 'e':
		{
			if (findAndDelete(head))
			{
				cout << "NODE REMOVED\n";
			}
			else
			{
				cout << "NODE NOT FOUND\n";
			}
			break;
		}
		case 'f':
		{
			if (deleteList(head))
			{
				cout << "LIST DELETED\n";
			}
			break;
		}
		
		}
	}

	deleteList(head);

	return 0;
}
int getValue()
{
	int value;
	cout << "Enter a Value: ";
	cin >> value;
	return value;
}
void insert(NodeType *& head)
{
	NodeType * temp = new NodeType;
	temp->info = getValue();
	temp->nextPtr = head;
	head = temp;
}
void printList(NodeType *& head)
{
	NodeType * temp = new NodeType;
	temp = head;
	if (head != NULL)
	{
		while (temp != NULL)
		{
			cout << temp->info << endl;
			temp = temp->nextPtr;
		}
	}
	else
	{
		cout << "LIST EMPTY\n";
	}

}
void deleteFirst(NodeType *& head)
{	//create temp to point at head
	NodeType * temp = new NodeType;
	//point temp to head
	temp = head;
	//point head to next in list
	head = head->nextPtr;
	//delete temp
	delete temp;
}
bool find(NodeType *& head)
{
	int value = getValue();
	NodeType * temp = new NodeType;
	temp = head;
	while (temp->info != value && temp->nextPtr != NULL)
		temp = temp->nextPtr;
	if (temp->info == value)
		return true;
	else
		return false;
}
bool findAndDelete(NodeType *& head)
{
	NodeType * currentPtr = head;
	NodeType * previousPtr = NULL;

	//list is empty
	if (head == NULL)
	{
		cout << "LIST EMPTY\n";
		return false;
	}

	//get number to find
	int nodeToRemove = getValue();

	while ((currentPtr->nextPtr != NULL) && (currentPtr->info != nodeToRemove))
	{
		previousPtr = currentPtr;
		currentPtr = currentPtr->nextPtr;
	}
	//not in the list
	if (currentPtr->info != nodeToRemove)
	{
		return false;
	}
	//the info is in the first node
	else if (currentPtr == head)
	{
		cout << "delete first\n\n";
		head = head->nextPtr;
		delete currentPtr;
		return true;
	}
	//if node is last
	else if ((currentPtr->info == nodeToRemove) && (currentPtr->nextPtr == NULL) && (previousPtr->nextPtr == currentPtr))
	{
		cout << "delete last\n\n";
		previousPtr->nextPtr = NULL;
		delete currentPtr;
		return true;
	}
	else
	{
		cout << "delete somewhere\n";
		previousPtr->nextPtr = currentPtr->nextPtr;
		delete currentPtr;
		return true;
	}
}
bool deleteList(NodeType *& head)
{
	NodeType * currentPtr;

	while (head != NULL)
	{
		currentPtr = head;
		head = head->nextPtr;
		delete currentPtr;
	}
	head = NULL;
	return true;
}





