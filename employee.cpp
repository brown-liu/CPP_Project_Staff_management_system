#include<iostream>
#include "employee.h"
#include <string>
using namespace std;


	Employee::Employee(int id, string name, int dId)
	{
		this->m_Id = id;
		this->m_Name = name;
		this->m_departmentId = dId;
	}

	void Employee::showInfo()
	{
		cout << "Staff ID:  " << this->m_Id
			<< "\tStaff Name:  " << this->m_Name
			<< "\t Dprt ID:  " << this->getDepartmentName() 
			<<"\t JOb duty: Complete tasks assignment by Manager"
			<< endl;
	}
	string Employee::getDepartmentName()
	{
		return "Standard Staff";
	}
