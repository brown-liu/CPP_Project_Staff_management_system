#pragma once
#include <iostream>
using namespace std;
#include <string>
#include"boss.h"

Boss::Boss(int id, string name, int dId)
{
		this->m_Id = id;
		this->m_Name = name;
		this->m_departmentId = dId;
	}


void Boss::showInfo()
{

		cout << "Staff ID:  " << this->m_Id
			<< "\tStaff Name:  " << this->m_Name
			<< "\t Dprt ID:  " << this->getDepartmentName() 
			<<"\t JOb duty: Big Boss"
			<< endl;

}

string Boss::getDepartmentName() 
{
	return string("Boss");
}



