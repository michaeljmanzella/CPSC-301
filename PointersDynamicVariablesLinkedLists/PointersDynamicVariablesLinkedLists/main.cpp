#include "Node.h"
using namespace std;

int getValue();
void addPtr(NodeType *& head);
void printAll(NodeType *& head);
bool find(NodeType *& head);
bool deleteNode(NodeType *& head);
bool deleteList(NodeType *& head);
//recursive
void insertAtend(NodeType *& current,int num );
void deleteAtEnd(NodeType *& current, NodeType *& previous,NodeType *& head);
void recursivePrintBackwards(NodeType *& current);
//void recursiveDelete();
bool hitEnd = false;


int main()
{
	NodeType * head = NULL;
	int value = 0;
	char choice = 'x';

	while (choice != 'z')
	{
		cout << "a. Enter Value:\n";
		cout << "b. Print All:\n";
		cout << "c. Find\n";
		cout << "d. Delete Node\n";
		cout << "e. Delete All\n";
		cout << "f. Insert at End\n";
		cout << "g. Delete at End\n";
		cout << "h. Print Recursivly Backwards\n";
		cout << "q. Quit\n";
		cout << "Enter Selection:";
		cin >> choice;
		switch (choice)
		{
		case 'a':
		{
			addPtr(head);
			break;
		}
		case 'b':
		{
			printAll(head);
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
			if (deleteNode(head))
			{
				cout << "NODE REMOVED\n";
			}
			else
			{
				cout << "NODE NOT FOUND\n";
			}
			break;
		}
		case 'e':
		{
			if (deleteList(head))
			{
				cout << "LIST DELETED\n";
			}
			break;
		}
		case 'f':
		{
			NodeType * current = head;
			int num = getValue();
			insertAtend(current,num);

			break;
		}
		case 'g':
		{
			NodeType * current = head;
			NodeType * previous = head;
			deleteAtEnd(current, previous,head);
			break;
		}
		case'h':
		{
			NodeType * current = new NodeType;
			int temp;
			bool hitEnd = false;
			current = head;
			recursivePrintBackwards(current);

			break;
		}
		case 'q':
		{
			if (deleteList(head))
			{
				cout << "LIST DELETED\n";
			}
			choice = 'z';
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
void addPtr(NodeType *& head)
{
	NodeType * temp = new NodeType;
	temp->info = getValue();
	temp->nextPtr = head;
	head = temp;
}
void printAll(NodeType *& head)
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
bool deleteNode(NodeType *& head)
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
void insertAtend(NodeType *& current,int num)
{
	if (current->nextPtr == NULL)
	{
		NodeType * node = new NodeType;
		current->nextPtr = node;
		node->info = num;
		node->nextPtr = NULL;
	}
	else
	{
		current = current->nextPtr;
		insertAtend(current, num);
	}
}
void deleteAtEnd(NodeType *& current, NodeType *& previous, NodeType *& head)
{
	//if empty
	if (current == NULL)
	{
		cout << "LIST EMPTY\n";
	}
	else if (current->nextPtr == NULL)
	{
		//only one item 
		if (head->nextPtr == NULL)
		{
			head = NULL;
			delete current;
		}
		else
		{
			previous->nextPtr = NULL;
			delete current;
		}
	}
	else
	{
		previous = current;
		current = current->nextPtr;
		deleteAtEnd(current, previous,head);
	}
}
void recursivePrintBackwards(NodeType *& current)
{
	int temp = current->info;
	if (current->nextPtr != NULL)
	{
		current = current->nextPtr;
		recursivePrintBackwards(current);
	}
	cout << temp << endl;
}