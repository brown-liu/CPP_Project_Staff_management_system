#pragma once
# include<iostream>
# include<string>
using namespace std;
class AbstractWorker
{

public:
	virtual void showInfo() = 0;
	virtual string getDepartmentName() = 0;

	int m_Id;
	string m_Name;
	int m_departmentId;
};