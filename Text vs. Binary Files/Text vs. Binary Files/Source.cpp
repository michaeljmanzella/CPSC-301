#include <iostream>
#include <fstream>
#include "Header.h"
//this is a test
using namespace std;

void progranOne();
void programTwo();
void programThree();
void programFour();

int main()
{
	progranOne();
	programTwo();
	programThree();
	programFour();

	return 0;
}
void progranOne()
{
	int num1 = 1;
	double num2 = 2;
	ofstream outFile;
	outFile.open("test.txt");
	if (outFile.fail())
	{
		cout << "FAIL out\n";
	}
	outFile << num1 << endl;
	outFile << num2 << endl;
	outFile.close();
}
void programTwo()
{
	int num1;
	int num2;
	ifstream inFile;
	inFile.open("test.txt");
	if (inFile.fail())
	{
		cout << "FAIL in\n";
	}
	inFile >> num1;
	inFile >> num2;
	cout << "OUTPUTTING TEXT DOC\n";
	cout << num1 << endl;
	cout << num2 << endl;
}
void programThree()
{
	char data[] = { '3','4' };
	fstream file;

	file.open("test.bin", ios::out | ios::binary);
	file.write(data, sizeof(data));
	file.close();
}
void programFour()
{
	char data[2] = {};
	fstream file;
	
	file.open("test.bin", ios::in | ios::binary);
	file.read(data, sizeof(data));
	cout << "OUTPUTING BINARY\n";
	for (int i = 0; i < 2; i++)
	{
		cout << data[i] << endl;
	}
	file.close();

}
/*
Numbers testObjects[5];
Numbers testObject2[5];
Numbers testObject3;



//assign numbers to object
for (int i = 0; i < 5; i++)
{

testObjects[i].interger = num1;
testObjects[i].dbl = num2;
num1 = num1 + 2;
num2 = num2 + 2;
}
//output objects to confirm
for (int i = 0; i < 5; i++)
{
cout << testObjects[i].interger << endl;
cout << testObjects[i].dbl << endl;
}
//open bianry outfile
outFile.open("test.bin", ios::binary | ios::out);

//output objects to binary file
outFile.write(reinterpret_cast<char *>(&testObjects),sizeof(testObjects));

//close binary file
outFile.close();

//open binary inFile
inFile.open("test.bin", ios::binary | ios::in);


//read binary file into array[5]
inFile.read(reinterpret_cast<char *>(&testObject2), sizeof(testObject2));

//seek 3rd object
inFile.seekg(32L, ios::beg);
//read in object
inFile.read(reinterpret_cast<char *>(&testObject3), sizeof(testObject3));
//output single object
cout << testObject3.interger << endl;
cout << testObject3.dbl << endl;

/*
//output entire binary File
for (int i = 0; i < 5; i++)
{
cout << testObject2[i].interger << endl;
cout << testObject2[i].dbl << endl;


//close binary infile
inFile.close();
*/