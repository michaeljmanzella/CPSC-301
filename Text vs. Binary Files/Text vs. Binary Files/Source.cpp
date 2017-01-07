#include <iostream>
#include <fstream>
#include "Header.h"

using namespace std;

int main()
{
	Numbers testObjects[5];
	Numbers testObject2[5];
	Numbers testObject3;

	int num1 = 1;
	double num2 = 2;
	ofstream outFile;
	ifstream inFile;
	
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
	
	/*
	//read binary file into array[5]
	inFile.read(reinterpret_cast<char *>(&testObject2), sizeof(testObject2));
	*/
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
	}
	*/
	
	//close binary infile
	inFile.close();

	return 0;
}