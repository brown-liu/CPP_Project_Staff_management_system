#include "workermanager.h"

WorkerManager::WorkerManager()
{
	//first possibility, file not exist
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		cout << "File does not exist" << endl;
		this->m_EmpArray = NULL;
		this->m_EmpNum = 0;
		this->m_FileIsEmpty = true;
		ifs.close();
		system("pause");
		return;
	
	}
	//second possibility, file exist but empty
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "file is empty" << endl;
		this->m_EmpArray = NULL;
		this->m_EmpNum = 0;
		this->m_FileIsEmpty = true;
		ifs.close();
		system("pause");
		return;
	}

	int num = this->get_EmpNum();
	cout << "number of staff is " << num << endl;
	this->m_EmpNum = num;
	this->m_EmpArray = new AbstractWorker*[this->m_EmpNum];
	this->init_Emp();
	for (int i = 0; i < this->m_EmpNum; i++)
	{

		cout << "Staff ID:  " << this->m_EmpArray[i]->m_Id
			<< "\tStaff Name:  " << this->m_EmpArray[i]->m_Name
			<< "\t Dprt ID:  " << this->m_EmpArray[i]->getDepartmentName()
			<< "\t JOb duty: Complete tasks assignment by Boss"
			<< endl;
	}
	system("pause");
	return;

}

void WorkerManager::Show_Menu()
{
	cout << "***********************************************" << endl;
	cout << "****   Welcome using management system  *******" << endl;
	cout << "****   0. Exit Program                  *******" << endl;
	cout << "****   1.Add Staff Information          *******" << endl;
	cout << "****   2.Display Staff Information      *******" << endl;
	cout << "****   3.Delete Staff                   *******" << endl;
	cout << "****   4.Edit Staff Information         *******" << endl;
	cout << "****   5.Search Staff Information       *******" << endl;
	cout << "****   6.Sort Staff using ID            *******" << endl;
	cout << "****   7.Delete all records             *******" << endl;
	cout << "***********************************************" << endl;
	cout <<  endl;



}

WorkerManager::~WorkerManager()
{
	if (this->m_EmpArray != NULL)
	{
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}

void WorkerManager::exisSystem()
{
	cout << "See you!!!" << endl;
	system("pause");
	exit(0);
}

void WorkerManager::Add_emp()
{
	cout << "Please enter number of staffs" << endl;
	int addNum = 0;
	cin >> addNum;
	if (addNum > 0)
	{
		int newSize = this->m_EmpNum + addNum;
		AbstractWorker ** newspace = new AbstractWorker *[newSize];
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
				newspace[i] = this->m_EmpArray[i];
		}
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int department;
			cout << "Please enter ID for No.\t"<<i+1 <<"\tstaff"<< endl;
			cin >> id;
			cout << "Please enter NAME for No."<<i+1 <<"staff"<< endl;
			cin >> name;
	
			cout << "Please choose Department for No."<<i <<"staff"<< endl;
			cout << "1. Employee" << endl;
			cout << "2. Manager" << endl;
			cout << "3. Boss" << endl;
			
			cin >> department;

			AbstractWorker *worker = NULL;
			switch (department)
			{
			case 1:
			{
			worker = new Employee(id,name,1);
				break;

			}
			case 2:
						{
					worker = new Manager(id, name, 2);
				break;	}
				
			case 3:
			{

				worker = new Boss(id,name, 3);
				break;

			}
						default:
				break;


			}
			newspace[this->m_EmpNum + i] = worker;
			cout << worker->m_Id << "+++"
				<< worker->m_Name << "+++"
				<< worker->m_departmentId << endl;
			system("pause");
			}
         	delete[] this->m_EmpArray;
			this->m_EmpArray = newspace;
			this->m_EmpNum = newSize;
			
	this->save();
	this->m_FileIsEmpty = false;
	
	cout << "Succesful added " << addNum <<"new staff" <<endl;

	}
	else {
		cout << "Incorrect" << endl;
	}
	system("pause");
	system("cls");

}


void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME,ios::out);
	for (int i = 0; i < this->m_EmpNum; i++)
	{

	

		ofs << this->m_EmpArray[i]->m_Id << " "<<
			this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_departmentId << endl;
		
	}
	ofs.close();
}


int WorkerManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int dId;
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		num++;
	}
	ifs.close();
	return num;
}


void WorkerManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id; 
	string name;
	int dId;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		AbstractWorker *worker = NULL;
		if (dId == 1) // employee
		{
			worker = new Employee(id, name, dId);
		}
		else if (dId == 2)
		{
			worker = new Manager(id, name, dId);
		}
		else if (dId==3)
		{
			worker = new Boss(id, name, dId);
		}
		this->m_EmpArray[index] = worker;
	index++;

	}
	ifs.close();

}


void WorkerManager::show_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "No record. Nothing to show" << endl;


	}
	else
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			this->m_EmpArray[i]->showInfo();
		}
	}
}

void WorkerManager::del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "No record to delete" << endl;
		system("pause");
		return;
	}

	int idNumber,result;
	cout << "Please enter the ID number to delete staff" << endl;
	cin >> idNumber;
	result = staffExists(idNumber);
	if (result == -1)
	{
		cout << "Can not find matching ID number" << endl;
	}
	else
	{
		for (int i = result; i < this->m_EmpNum-1; i++)
		{
			this->m_EmpArray[i] = this->m_EmpArray[i + 1];

		}
		this->m_EmpNum--;
		cout << "Staff Name:   " << this->m_EmpArray[result]->m_Name << "   is deleted" << endl;
		
	}
	this->save();
}

int WorkerManager::staffExists(int id)
{
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_Id == id)
		{
			return i;
		}
	
	}
	return -1;
}

void WorkerManager::Modify_Emp()
{
	int id;
	cout << "Please enter the staff ID number you want to edit" << endl;
	cin >> id;
	int result = staffExists(id);
		
	if (result== -1)
	{
		cout << "Staff with this ID does not exist" << endl;
		system("pause");
		return;
	}
	else
	{
		cout << "Locate staff ID: " << this->m_EmpArray[result]->m_Id
			<< "\tstaff Name:  " << this->m_EmpArray[result]->m_Name
			<< "\tstaff Position:  " << this->m_EmpArray[result]->getDepartmentName() << endl;
		char choice;
		cout << "\nKey in 'q' if dont want to change. or any other key to continue!" << endl;
		cin >> choice;
		if (choice == 'q')
		{

			return;
		}
		else
		{
			int position;
			string name;
			cout << "key in new Name: " << endl;
			cin >> name;
			cout << "Key in new position" << endl;
			cin >> position;
			this->m_EmpArray[result]->m_departmentId = position;
			this->m_EmpArray[result]->m_Name = name;
			cout << "Information updated" << endl;
			system("pause");
			this->save();
		}



	}



}

void WorkerManager::Find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "file Not exist" << endl;
	}
	else
	{
		cout << "Please specify search Methods" << endl;
		cout << "1. By ID " << endl;
		cout << "2. By Name" << endl;
		int select = 0;
		if (select == 1)
		{//by ID
			int id;
			cout << "Please enter staff ID" << endl;
			cin >> id;
			int result = staffExists(id);
			if (result != -1)
			{
				cout << "Found staff\n" << endl;
				this->m_EmpArray[result]->showInfo();
			}
			else
			{
				cout << "can not find this staff" << endl;
			}


		}
		else if (select == 2)
		{// by Name

		}
	}

}


void WorkerManager::Sort_Emp()
{
	int total=this->m_EmpNum;
	for (int i = 0; i < total; i++)
	{
		for (int j = 0; j < total-1; j++)
		{
			if (this->m_EmpArray[j]->m_Id > this->m_EmpArray[j + 1]->m_Id)
			{
				AbstractWorker *tempWorker;
				tempWorker = this->m_EmpArray[j+1];
				this->m_EmpArray[j + 1] = this->m_EmpArray[j];
				this->m_EmpArray[j] = tempWorker;
			}

		}
	}
} 


void WorkerManager::Clean_file()
{
	char choice;
	cout << "Are you sure to delete everything?, Press 'y' to confirm" << endl;
	cin >> choice;
	if (choice == 'y')
	{
		ofstream ofs;
		ofs.open(FILENAME,ios::trunc);
		ofs.close();
		for (int x = 0; x < this->m_EmpNum; x++)
		{
			delete this->m_EmpArray[x];
			this->m_EmpArray[x] = NULL;
		}
		this->m_EmpNum = 0;
		delete[] this->m_EmpArray;
		this->m_FileIsEmpty = true;
	}

	else {
		return;
	}
}
















