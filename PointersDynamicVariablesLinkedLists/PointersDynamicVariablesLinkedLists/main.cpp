#include "Node.h"
using namespace std;

int getValue();
void addPtr(NodeType *& head);
void printAll(NodeType *& head);
bool find(NodeType *& head);
bool deleteNode(NodeType *& head);
bool deleteList(NodeType *& head);
//recursive
void insertAtend(NodeType *& head,NodeType *& current, NodeType *& previous,int num );


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
			NodeType * previous = head;
			int num = getValue();
			insertAtend(head, current, previous,num);

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
	while (temp != NULL)
	{
		cout << temp->info << endl;
		temp = temp->nextPtr;
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
void insertAtend(NodeType *& head, NodeType *& current, NodeType *& previous,int num)
{
	//find last node


}

