//Michael Manzella
//Text VS Binary
//25 Sep 17
#include <iostream>
#include <fstream>
#include "Header.h"
using namespace std;

void progranOne();
void programTwo();
void programThree();
void programFour();

void programFive();
void programSix();
void programSeven();

int main()
{
	progranOne();
	programTwo();
	programThree();
	programFour();
	programFive();
	programSix();
	programSeven();

	return 0;
}
void progranOne()//one that opens a text file, write 2 integers to it, and closes it
{
	cout << "Program 1 -- one that opens a text file, write 2 integers to it, and closes it\n";
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
void programTwo()//one that opens the text file you wrote to, reads the 2 integers from it and prints them out to the screen
{
	cout << "Program 2 -- one that opens the text file you wrote to, reads the 2 integers from it and prints them out to the screen\n";
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
void programThree()//binary: one that opens a text file, write 2 integers to it, and closes it
{
	cout << "Program 3 -- binary: one that opens a text file, write 2 integers to it, and closes it\n";
	char data[] = { '3','4' };
	fstream file;

	file.open("testBinary.bin", ios::out | ios::binary);
	file.write(data, sizeof(data));
	file.close();
}
void programFour()//binary: one that opens the text file you wrote to, reads the 2 numbers from it and prints them out to the screen
{
	cout << "Program 4 -- binary: one that opens the text file you wrote to, reads the 2 numbers from it and prints them out to the screen\n";
	char data[2] = {};
	fstream file;
	
	file.open("testBinary.bin", ios::in | ios::binary);
	file.read(data, sizeof(data));
	cout << "OUTPUTING BINARY\n";
	for (int i = 0; i < 2; i++)
	{
		cout << data[i] << endl;
	}
	file.close();

}
void programFive()//binary,classes: one that opens a text file, write 2 objects to it, and closes it
{
	cout << "Program 5 -- binary,classes: one that opens a text file, write 2 objects to it, and closes it\n";
	Numbers testObjects[2];
	//assign numbers to object
	testObjects[0].integer = 1;
	testObjects[0].dbl = 1.5;
	testObjects[1].integer = 2;
	testObjects[1].dbl = 2.5;

	//create binary file
	fstream outFile;
	//open binary
	outFile.open("testBinaryClasses.bin", ios::out | ios::binary);
	//error check
	if (outFile.fail())
	{
		cout << "FAIL out\n";
	}
	//output objects to binary file
	outFile.write(reinterpret_cast<char *>(&testObjects), sizeof(testObjects));
	outFile.close();
}
void programSix()//binary classes: one that opens the text file you wrote to, reads the 2 classes from it and prints them out to the screen
{
	cout << "Program 6 -- binary classes: one that opens the text file you wrote to, reads the 2 classes from it and prints them out to the screen\n";
	//create object
	Numbers testObject[2];
	fstream inFile;
	//open binary inFile
	inFile.open("testBinaryClasses.bin", ios::binary | ios::in);
	//read binary file into array
	inFile.read(reinterpret_cast<char *>(&testObject), sizeof(testObject));
	//close binary
	inFile.close();
	//output object
	cout << "OUTPUTING TEST OBJECT\n";
	cout << testObject[0].integer << endl;
	cout << testObject[0].dbl << endl;
	cout << testObject[1].integer << endl;
	cout << testObject[1].dbl << endl;
}
void programSeven()//Create an fstream to a binary file that you can both write to and read from.  
//Write 5 objects of your class to your binary file.  Then see if you can read them all back in order 
//and print them to the screen.  Next, see if you can retrieve the third object directly from the 
//file by using seekg() and an offset from the file beginning of 2 object size. 
{
	cout << "Program 7 -- seek 2nd object in array\n";
	Numbers testObjectsOut[5];
	Numbers testObjectsIn;
	int num1 = 1;
	double num2 = 1.5;
	//assign numbers to object
	for (int i = 0; i < 5; i++)
	{

		testObjectsOut[i].integer = num1;
		testObjectsOut[i].dbl = num2;
		num1 = num1 + 1;
		num2 = num2 + 1;
	}
	//create binary file
	fstream file;
	//open binary
	file.open("testBinarySeek.bin", ios::binary | ios::out);
	//error check
	if (file.fail())
	{
		cout << "FAIL out\n";
	}
	//output objects to binary file
	file.write(reinterpret_cast<char *>(&testObjectsOut), sizeof(testObjectsOut));
	file.close();

	//input objects
	file.open("testBinarySeek.bin", ios::binary | ios::in);

	//seek 2nd object
	//cout << sizeof(testObjectsOut) << endl;
	//each object in the array is 16
	file.seekg(16L, ios::beg);
	//read in object
	file.read(reinterpret_cast<char *>(&testObjectsIn), sizeof(testObjectsIn));
	//output single object
	cout << "integer = " << testObjectsIn.integer << endl;
	cout << "double = " << testObjectsIn.dbl << endl;

	file.close();
}
