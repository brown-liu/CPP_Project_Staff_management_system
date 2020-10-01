#pragma once
#include<iostream>
#include "worker.h"
#include <string>
using namespace std;

class Employee : public AbstractWorker
{
public:
	Employee(int id, string name, int dId);
	virtual void showInfo();
	virtual string getDepartmentName();
};