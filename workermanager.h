#pragma once
#include "worker.h"
#include <iostream>
#include<fstream>
#define FILENAME "empfile.txt"
#include "employee.h"
#include "manager.h"
#include "boss.h"

using namespace std;
// H file only declare, do not detail




class WorkerManager
{
public:
	WorkerManager();

	void Show_Menu();

	~WorkerManager();

	void exisSystem();

	//record number of staff

	int m_EmpNum;

	AbstractWorker ** m_EmpArray;

	//add staff
	void Add_emp();

	//save staff obj to file
	void save();
	
	// check if FILENAME is empty
	bool m_FileIsEmpty;
	
	// get number of staff in txt
	int get_EmpNum();

	//initialize staff
	void init_Emp();

	void show_Emp();

	void del_Emp();

	int staffExists(int id);

	void Modify_Emp();

	void Find_Emp();
		
	void Sort_Emp();
};
