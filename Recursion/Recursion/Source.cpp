#include <iostream>
#include <cstring>
using namespace std;

void mysteryRecurse(char[], int);
int count1 = 0;
int count2 = 0;
int call = 0;

int main()
{
	char testString[50] = "";
	mysteryRecurse(testString, 4);
	return 0;
}
void mysteryRecurse(char myString[], int digit)
{
	//cout << "call = " << call << endl;
	//call++;
	char copyString0[50];
	char copyString1[50];

	if (digit == 0)
	{
		cout << "print= " << myString << endl;
		cout << "*******************************\n";
		cout << endl;
		//cout << endl;
	}
	else
	{
		cout << myString << endl;
		strcpy_s(copyString0, myString);
		cout << "add 0\n";
		strcat_s(copyString0, "0");
		cout << "calling copyString0\n";
		cout << "____________________________\n";
		mysteryRecurse(copyString0, digit - 1);

		cout << myString << endl;
		strcpy_s(copyString1, myString);
		cout << "add 1\n";
		strcat_s(copyString1, "1"); 
		cout << "calling copyString1\n";
		cout << "____________________________\n";
		mysteryRecurse(copyString1, digit - 1);
	}
}
