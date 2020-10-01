#include "manager.h"
#include <iostream>
# include <string>
using namespace std;

Manager::Manager(int id, string name, int dId)
	{
		this->m_Id = id;
		this->m_Name = name;
		this->m_departmentId = dId;
	}
void Manager::showInfo()
{

		cout << "Staff ID:  " << this->m_Id
			<< "\tStaff Name:  " << this->m_Name
			<< "\t Dprt ID:  " << this->getDepartmentName() 
			<<"\t JOb duty: Complete tasks assignment by Boss"
			<< endl;
}
string Manager::getDepartmentName()
{
	return string("Manager     ");
}