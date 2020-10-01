#pragma once
#include <iostream>
using namespace std;
#include <string>
#include "worker.h"


class Manager :public AbstractWorker
{
public:
	Manager(int id,string name,int dId);
	virtual void showInfo();
	virtual string getDepartmentName();
	/*int m_Id;
	string m_Name;
	int m_departmentId;
	*/
};


