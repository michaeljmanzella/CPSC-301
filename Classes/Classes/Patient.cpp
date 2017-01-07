#include<iostream>
#include"Patient.h"
#include <string>

Patient::Patient()
{
	*ID = {};
	*firstName = {};
	*lastName = {};
	birthDate;
	primaryDoctorID = 0;
	currentCountProcedures = 0;

}
Patient::Patient(const char* _ID, const char* _firstName, const char* _lastName, Date _birthDate, int _primaryDoctorID)
{
	setID(_ID);
	setFirstName(_firstName);
	setLastName(_lastName);
	setBirthDate(_birthDate);
	setPrimaryDoctorId(_primaryDoctorID);
	currentCountProcedures = 0;
	//record;

}
Patient::~Patient() {}
Patient & Patient::setID(const char* _ID)
{
	strcpy_s(ID, _ID);
	return *this;
}
Patient & Patient::setFirstName(const char* _firstName)
{
	strcpy_s(firstName, _firstName);
	return *this;
}
Patient & Patient::setLastName(const char* _lastName)
{
	strcpy_s(lastName, _lastName);
	return *this;
}
Patient & Patient::setBirthDate(Date & _birthDate)
{
	birthDate = _birthDate;
	return *this;
}
Patient & Patient::setPrimaryDoctorId(int __primaryDoctorID)
{
	primaryDoctorID = __primaryDoctorID;
	return *this;
}
const char* Patient::getID()
{
	return ID;
}
const char* Patient::getFirstName()
{
	return firstName;
}
const char* Patient::getLastName()
{
	return lastName;
}
Date Patient::getBirthDate()
{
	return birthDate;
}
bool Patient::enterProcedure(Date _procedureDate, int _procedureID, int _procedureProviderID)
{
	record[currentCountProcedures].dateOfProcedure = _procedureDate;
	record[currentCountProcedures].procedureID = _procedureID;
	record[currentCountProcedures].procedureProviderID = _procedureProviderID;
	currentCountProcedures++;
	return true;
}
void Patient::printAllProcededures()
{
	for (int i = 0; i < currentCountProcedures; i++)
	{
		cout << "date: " << record[i].dateOfProcedure << endl;
		cout << "procedureID: " << record[i].procedureID << endl;
		cout << "providerID: " << record[i].procedureProviderID << endl;
	}
}
bool Patient::copyProcedure(Patient & obj)
{
	for (int i = 0; i < obj.currentCountProcedures; i++)
	{
		enterProcedure(obj.record[i].dateOfProcedure, obj.record[i].procedureID, obj.record[i].procedureProviderID);
	}
	return true;

}






