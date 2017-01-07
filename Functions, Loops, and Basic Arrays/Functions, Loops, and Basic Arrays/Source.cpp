#include <iostream>
using namespace std;

void askNumbers();
int getNumbers();
void printArray(int Table[],int & count);
void printNum(int num);
int Getaverage(int Table[], int & count);
int averageFind(int Table[], int & count, int average, int num);
int findValue(int value, int Table[], int count);
void swapSmallFirst(int Table[], int & count, int average);
void sortTable(int count, int Table[]);
bool insert(int value, int Table[], int & count, int size);
bool remove(int value, int Table[], int & count);

//get numbers from user


int main()
{
	int Table[10];
	int temp = 0;
	int i = 0;

	int count = 0;

	int average = 0;

	int lessAverage = 0;

	int sameAsAverage = 0;
	int moreThanAverage = 0;
	
	int valueToSearchFor = 0;
	int location = -1;
	char choice;
	int menuChoice = 0;
	
	int smallest = 0;

	int removeValue = 0;
	int removeAt = 0;

	while (menuChoice != 420)
	{
		cout << "1. Insert Numbers in Table\n";
		cout << "2. Print Array\n";
		cout << "3. Get Count\n";
		cout << "4. Find Average\n";
		cout << "5. Find less than Average\n";
		cout << "6. Same as Average\n";
		cout << "7. More than Average\n";
		cout << "8. Enter Number to Search for\n";
		cout << "9. Sort for\n";
		cout << "10. Insert\n";
		cout << "11. Remove\n";
		cout << "Enter Selection:";
		cin >> menuChoice;

		switch (menuChoice)
		{
			//get numbers from user
		case 1:
		{
			cout << "-----------------------------------------------\n";
			i = 0;
			count = 0;
			temp = -2;
			askNumbers();
			while (temp != -1)
			{
				temp = getNumbers();
				if (temp != -1)
				{
					Table[i] = temp;
					count++;
				}
				i++;
			}
			break;
		}
		case 2:
		{
			cout << "-----------------------------------------------\n";
			printArray(Table, count);
			break;
		}
		case 3:
		{
			cout << "-----------------------------------------------\n";
			cout << "Count = ";
			printNum(count);
			break;
		}
		case 4:
		{
			cout << "-----------------------------------------------\n";
			//find average
			average = 0;
			average = Getaverage(Table, count);
			cout << "Average = ";
			printNum(average);
			break;
		}
		case 5:
		{
			cout << "-----------------------------------------------\n";
			//find less than average
			lessAverage = 0;
			lessAverage = averageFind(Table, count, average, 1);
			cout << "Less than Average: ";
			printNum(lessAverage);
			break;
		}
		case 6:
		{
			cout << "-----------------------------------------------\n";
			//find equel to average
			sameAsAverage = 0;
			sameAsAverage = averageFind(Table, count, average, 2);
			cout << "Same as Average: ";
			printNum(sameAsAverage);
			break;
		}
		case 7:
		{
			cout << "-----------------------------------------------\n";
			//find more than average
			moreThanAverage = averageFind(Table, count, average, 3);
			cout << "More than Average: ";
			printNum(moreThanAverage);
			break;
		}
		case 8:
		{
			cout << "-----------------------------------------------\n";
			//get number to search for
			cout << "Enter Value to search: ";
			cin >> valueToSearchFor;
			location = findValue(valueToSearchFor, Table, count);
			if (location == -1)
			{
				cout << "Value not Found\n";
			}
			else
			{
				cout << "Found at " << location << endl;
			}
			break;
		}
		case 9:
		{
			cout << "-----------------------------------------------\n";
			//sort
			cout << "sorting\n";
			sortTable(count, Table);
			break;
		}
		case 10:
		{
			cout << "-----------------------------------------------\n";
			//insert
			int insertNum = 0;
			cout << "Insert: ";
			cin >> insertNum;
			insert(insertNum, Table, count, 10);
			break;
		}
		case 11:
		{
			cout << "-----------------------------------------------\n";
			//remove value
			removeValue = 0;
			removeAt = 0;
			cout << "Remove: ";
			cin >> removeValue;
			removeAt = findValue(removeValue, Table, count);
			remove(removeAt, Table, count);
			break;
		}
		}
	}



return 0;
}
void askNumbers()
{
	cout << "Enter Number (-1 to STOP): ";
	cout << endl;
}
int getNumbers()
{
	int temp;
	cin >> temp;
	return temp;
}
void printArray(int Table[],int & count)
{
	for (int i = 0; i < count; i++)
	{
		cout << "Table" << i << " = " << Table[i] << endl;
	}
}
void printNum(int num)
{
	cout << num << endl;
}
int Getaverage(int Table[], int & count)
{
	int average = 0;
	for (int i = 0; i < count; i++)
	{
		average = (average + Table[i]);
	}
	return average/count;
}
int averageFind(int Table[], int & count, int average, int num)
{
	int temp = 0;
	if (num == 1)
	{
		for (int i = 0; i < count; i++)
		{
			if (Table[i] < average)
			{
				temp++;
			}
		}
	}
	if (num == 2)
	{
		for (int i = 0; i < count; i++)
		{
			if (Table[i] == average)
			{
				temp++;
			}
		}
	}
	if (num == 3)
	{
		for (int i = 0; i < count; i++)
		{
			if (Table[i] > average)
			{
				temp++;
			}
		}
	}
	if (num == 4)
	{
		temp = Table[0];
		for (int i = 0; i < count; i++)
			{
				if (Table[i] < temp)
				{
					temp = Table[i];
				}
			}
		}
	
	return temp;
}
int findValue(int value, int Table[], int count)
{
	for (int i = 0; i < count; i++)
	{
		if (Table[i] == value)
		{
			return i;
		}
	}
	return -1;
}
void swapSmallFirst(int Table[], int & count, int average)
{
	int location = 0;
	int smallest = 0;
	int temp = 0;
	smallest = averageFind(Table, count, average, 4);
	cout << smallest << endl;
	location = findValue(smallest, Table, count);
	cout << location << endl;
	temp = Table[0];
	Table[0] = smallest;
	Table[location] = temp;
}
void sortTable(int count,int Table[])
{
	for (int i = 1; i < count; i++)
	{
		for (int j = 0; j < count - i; j++)
		{
			if (Table[j] > Table[j + 1])
			{
				int temp = Table[j];
				Table[j] = Table[j + 1];
				Table[j + 1] = temp;
			}
		}
	}
}
bool insert(int value, int Table[], int & count,int size)
{
	if (count < size)
	{
		Table[count] = value;
		count++;
		sortTable(count, Table);
		
		return 0;
	}
	else
	{
		return 1;
	}
}
bool remove(int value, int Table[], int & count)
{
	if (value < count && value != -1)
	{
		for (int i = value; i < count; i++)
		{
			Table[i] = Table[i + 1];
		}
		count--;
		return 0;
	}
	else
	{
		cout << "Value not in the list.\n";
		return 1;
	}
		
}