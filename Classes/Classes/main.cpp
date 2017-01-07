#include <iostream>
#include <fstream>
#include "Date.h"
#include "Patient.h"
using namespace std;
int searchID(char ID[], Patient allPatients[], int totalPatients);

int main()
{
	int month, day, year = 0;
	char choice = 'm';
	Patient checkIN[100];
	Patient allPatient[100];

	int totalPatients = 0;
	int checkIn = 0;
	ofstream outFile;
	ifstream inFile;

	//open inFile
	inFile.open("patients.bin", ios::binary | ios::in);
	inFile.read(reinterpret_cast<char *>(&allPatient), sizeof(allPatient));
	inFile.read(reinterpret_cast<char *>(&totalPatients), sizeof(totalPatients));
	inFile.close();	

	//get todays date
	cout << "Enter MM/DD/YYYY:\n";
	cin >> month;
	cin >> day;
	cin >> year;
	Date current(month,day,year);

	while (choice != 'a')
	{
		cout << "N: Check in new patient:\n";
		cout << "R: Check in returning patient\n";
		cout << "O: Check out a patient\n";
		cout << "I: Print out information from all patients\n";
		cout << "P: Print out information from checked in\n";
		cout << "Q: Exit program\n";
		cout << "Enter Selection:";
		cin >> choice;

		switch (choice)
		{
		case 'n'://"N: Check in new patient:\n":
		{
			char firstName[15];
			char lastName[15];
			int month;
			int day;
			int year;
			int primaryDoctorID;

			cout << "Enter first name: ";
			cin.ignore();
			cin.getline(firstName, 15);

			cout << "Enter last name: ";
			cin.getline(lastName, 15);

			cout << "Enter birthday MM/DD/YYYY:\n";
			cin >> month;
			cin >> day;
			cin >> year;

			cout << "Enter Primary Doctor ID: ";
			cin >> primaryDoctorID;

			checkIN[checkIn].setFirstName(firstName);
			checkIN[checkIn].setLastName(lastName);
			Date birthDate;
			birthDate.setDate(month, day, year);
			checkIN[checkIn].setBirthDate(birthDate);
			checkIN[checkIn].setPrimaryDoctorId(primaryDoctorID);
			checkIn++;
			break;
		}
		case 'r'://"R: Check in returning patient\n";
		{
			char ID[15];
			int location;
			cout << "Enter last name: ";
			cin.ignore();
			cin.getline(ID, 15);
			location = searchID(ID, allPatient, totalPatients);
			if (location == -1)
			{
				cout << "NOT FOUND!\n";
			}
			else
			{
				checkIN[checkIn].setBirthDate(allPatient[location].getBirthDate());
				checkIN[checkIn].setFirstName(allPatient[location].getFirstName());
				checkIN[checkIn].setID(allPatient[location].getID());
				checkIN[checkIn].setLastName(allPatient[location].getLastName());
				checkIN[checkIn].setPrimaryDoctorId(allPatient[location].primaryDoctorID);
				checkIN[checkIn].copyProcedure(allPatient[location]);
				checkIn++;
			}
			


			break;
		}
		case 'o'://check out patient
		{
			char ID[15];
			int location;
			int procedureID;
			int procedureProviderID;
			cout << "Enter last name: ";
			cin.ignore();
			cin.getline(ID, 15);
			location = searchID(ID, checkIN, checkIn);
			if (location == -1)
			{
				cout << "NOT FOUND!\n";
			}
			else
			{
				cout << "Enter procedure ID: ";
				cin >> procedureID;
				cout << "Enter procedure provider ID:";
				cin >> procedureProviderID;
				checkIN[location].enterProcedure(current, procedureID, procedureProviderID);
			}
			location = searchID(ID, allPatient, totalPatients);
			allPatient[location].enterProcedure(current, procedureID, procedureProviderID);
			location = searchID(ID, checkIN, totalPatients);
			checkIN[location].setBirthDate(checkIN[checkIn - 1].getBirthDate());
			checkIN[location].setFirstName(checkIN[checkIn - 1].getFirstName());
			checkIN[location].setID(checkIN[checkIn - 1].getID());
			checkIN[location].setLastName(checkIN[checkIn - 1].getLastName());
			checkIN[location].setPrimaryDoctorId(checkIN[checkIn - 1].primaryDoctorID);
			checkIN[location].copyProcedure(checkIN[location - 1]);
			checkIn--;
			break;
		}
		case 'i'://"I: Print out information from all patients\n";
		{
			char lastName[15];
			int location = -1;
			cout << "Enter last name: ";
			cin.ignore();
			cin.getline(lastName, 15);
			location = searchID(lastName, allPatient, totalPatients);
			cout << "Last Name: " << allPatient[location].getLastName() << endl;
			cout << "Birthdate: "<<allPatient[location].getBirthDate() << endl;;
			cout << "First Name: "<< allPatient[location].getFirstName() << endl;;
			cout  << "ID: "<< allPatient[location].getID() << endl;
			allPatient[location].printAllProcededures();
			break;
		}
		case 'p':
		{
			char lastName[15];
			int location = -1;
			cout << "Enter last name: ";
			cin.ignore();
			cin.getline(lastName, 15);
			location = searchID(lastName, checkIN, checkIn);
			if (location != -1)
			{
				cout << "Last Name: " << checkIN[location].getLastName() << endl;
				cout << "First Name: " << checkIN[location].getFirstName() << endl;
				cout << "Birthdate: " << checkIN[location].getBirthDate() << endl;
				cout << "ID: " << checkIN[location].getID() << endl;
				checkIN[location].printAllProcededures();
			}
			else
				cout << "NOT FOUND\n\n";
			break;
		}
		case 'q':
		{
			cout << "checked In: " << checkIn << endl;
			if (checkIn != 0)
			{
				cout << "Patients that need to be checked out.\n";
				for (int i = 0; i < checkIn; i++)
				{
					cout << "Last Name: " << checkIN[i].getLastName() << endl;
				}
			}
			else
				choice = 'a';
			break;
		}
		}
	}
	if (checkIn > 0)
	{
		for (int i = 0; i < checkIn; i++)
		{
			allPatient[totalPatients].setBirthDate(checkIN[i].getBirthDate());
			allPatient[totalPatients].setFirstName(checkIN[i].getFirstName());
			allPatient[totalPatients].setID(checkIN[i].getID());
			allPatient[totalPatients].setLastName(checkIN[i].getLastName());
			allPatient[totalPatients].setPrimaryDoctorId(checkIN[i].primaryDoctorID);
			totalPatients++;
		}
	}
	outFile.open("patients.bin", ios::binary | ios::out);
	outFile.write(reinterpret_cast<char *>(&allPatient), sizeof(allPatient));
	outFile.write(reinterpret_cast<char *>(&totalPatients), sizeof(totalPatients));
	outFile.close();
	
	
	
	

	return 0;
}
int searchID(char ID[], Patient allPatients[], int totalPatients)
{
	int location = 0;
	while ((strcmp(allPatients[location].getLastName(), ID) != 0) && (location < totalPatients))
		location++;
	if (strcmp(allPatients[location].getLastName(), ID) != 0)
		return -1;
	else/
		return location;
}
