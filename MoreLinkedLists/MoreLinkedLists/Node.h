#include <iostream>
using namespace std;

class Node {
public:
	Node(int = 0);
	int info;
	int length;
	Node * next;
	Node * first;
	Node * last;

	void insertAtFront(int value);
	void insertAtRear(int value);
	void deleteFirst();
	void print(Node const& first);
};
