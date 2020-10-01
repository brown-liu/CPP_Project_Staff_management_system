#include <iostream>

using namespace std;

#include "workermanager.h"
#include "worker.h"
#include "employee.h"

void test()
{
AbstractWorker* worker = NULL;
	worker = new Employee(1, "XXX", 1);
	worker->showInfo();
	delete worker;

	worker = new Manager(2, "YYY", 2);
	worker->showInfo();
	delete worker;

	worker = new Boss(3, "ZZZ", 3);
	worker->showInfo();
	delete worker;
}
void test02()
{
	ofstream ofs;
	ofs.open("test.txt", ios::out);
	ofs << "hellow" << endl;
	AbstractWorker *worker = new Manager(111,"brown",3);
	ofs << worker->m_departmentId << "+" << worker->m_Id << "+" << worker->m_Name << endl;
	ofs.close();


}

int main()
{
//	test();

	WorkerManager wm;
	
	int choice = 0;
	while (true)
	{	system("cls");
		wm.Show_Menu();
		cout << "please enter your choice" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:
			wm.exisSystem();
			break;

		case 1:
			wm.Add_emp();
			system("pause");
			break;
			
		case 2:
			wm.show_Emp();
			system("pause");
			break;

		case 3:
			wm.del_Emp();
			system("pause");
			break;

		case 4:
			wm.Modify_Emp();
			system("pause");
			break;

		case 5:
			wm.Find_Emp();
			system("pause");
			break;

		case 6:
			wm.Sort_Emp();
			cout << "Sorting completed" << endl;
			system("pause");
			break;

		case 7:
			cout << "this is 7" << endl;
			system("pause");
			break;

		default:
			cout << "Please Choose correct Number" << endl;
			system("pause");
			break;
		}


	}

	system("pause");
	return 0;
}