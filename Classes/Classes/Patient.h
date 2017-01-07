#ifndef PATIENT_H
#define PATIENT_H
#include <iostream>
#include <string>
#include "Date.h"
#include "Procedure.h"
using namespace std;

class Patient 
{
public:
	Patient();
	Patient(const char*, const char*, const char*, Date, int);
	~Patient();
	
	Patient & setID(const char*);
	Patient & setFirstName(const char*);
	Patient & setLastName(const char*);
	Patient & setBirthDate(Date &);
	Patient & setPrimaryDoctorId(int);
	

	const char* getID();
	const char* getFirstName();
	const char* getLastName();
	Date getBirthDate();
	int primaryDoctorID;

	bool enterProcedure(Date _procedureDate, int _procedureID, int _procedureProviderID);
	bool copyProcedure(Patient & obj);
	
	void printAllProcededures();

	


private:
	char ID[33];
	char firstName[15];
	char lastName[15];
	Date birthDate;
	Procedure record[100];
	int currentCountProcedures;
};
#endif
