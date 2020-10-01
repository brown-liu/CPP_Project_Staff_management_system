#pragma once
#include <iostream>
using namespace std;
#include <string>
#include "worker.h"


class Boss :public AbstractWorker
{
public:
	Boss(int id,string name,int dId);
	virtual void showInfo();
	virtual string getDepartmentName();
	//	int m_Id;
	//string m_Name;
	//int m_departmentId;
};


