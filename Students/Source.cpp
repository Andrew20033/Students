#include <iostream>
#include <Windows.h>
#include <time.h>
#define N 128

using namespace std;

class Student
{
protected:
	char* secName;
	char* name;
	char* otch;
	char* pulpit;
public:
	Student()
	{
		secName = new char('\0');
		name = new char('\0');
		otch = new char('\0');
		pulpit = new char('\0');
	}
	~Student()
	{
		delete[]secName;
		delete[]name;
		delete[]otch;
		delete[]pulpit;
	}
	void get(char* secname, char* name, char* otch, char* kaf);
	void show();
};
void Student::get(char* secname, char* name, char* otch, char* kaf)
{
	secName = new char[strlen(secname) + 1];
	this->name = new char[strlen(name) + 1];
	this->otch = new char[strlen(otch) + 1];
	pulpit = new char[strlen(kaf) + 1];
	strcpy(secName, secname);
	strcpy(this->name, name);
	strcpy(this->otch, otch);
	strcpy(pulpit, kaf);
}
void Student::show()
{
	cout << " Surname : " << secName << endl;
	cout << " Name : " << name << endl;
	cout << "middle name : " << otch << endl;
	cout << " Chair : " << pulpit << endl;
}
class Aspirant :public Student
{
	bool exam1;
	bool exam2;
	bool exam3;
public:
	Aspirant()
	{
		exam1 = false;
		exam2 = false;
		exam3 = false;
	}
	bool getExam1()
	{
		return exam1;
	}
	bool getExam2()
	{
		return exam2;
	}
	bool getExam3()
	{
		return exam3;
	}
	void exam();
};
void Aspirant::exam()
{
	exam1 = rand() % 2;
	exam2 = rand() % 2;
	exam3 = rand() % 2;
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand((unsigned)time(0));
	int count;
	int menu;
	bool flag = false;
	bool aspir;
	char secname[N];
	char name[N];
	char otch[N];
	char kaf[N];
	Aspirant* stud;
	system("cls");
	do
	{
		system("cls");
		cout << " 1 - Complete a group of students \n";
		cout << " 2 - Display the group\n";
		cout << " 3 - Bring graduate students to the screen \n";
		cout << " 0 - Exit \n";
		cout << " Your choise : ";
		cin >> menu;
		switch (menu)
		{
		case 1:
			system("cls");
			if (flag == true)
			{
				cout << " Group is full \n";
				system("pause");
				break;
			}
			else
			{
				cout << " Enter number of students : ";
				cin >> count;
				cin.ignore();
				stud = new Aspirant[count];
				for (int i = 0; i < count; i++)
				{
					system("cls");
					cout << " Student ¹ " << i + 1 << endl;
					cout << " Enter last name : ";
					gets_s(secname, N);
					cout << " Enter name : ";
					gets_s(name, N);
					cout << " Enter middle name : ";
					gets_s(otch, N);
					cout << " Enter the pulpit : ";
					gets_s(kaf, N);
					stud[i].get(secname, name, otch, kaf);
				}
				flag = true;
				break;
			}
		case 2:
			system("cls");
			if (flag == false)
			{
				cout << " Group not formed \n";
				system("pause");
				break;
			}
			else
			{
				cout << " Group of students \n";
				for (int i = 0; i < count; i++)
				{
					cout << "============\n";
					stud[i].show();
					cout << "============\n";
				}
				system("pause");
				break;
			}
		case 3:
			system("cls");
			if (flag == false)
			{
				cout << " The group is not formed, there is no one to become graduate students \n";
				system("pause");
				break;
			}
			else
			{
				aspir = false;
				for (int i = 0; i < count; i++)
				{
					stud[i].exam();
				}
				cout << " Congratulations to the following students on passing the exam and being promoted to graduate students \n";
				for (int i = 0; i < count; i++)
				{
					if (stud[i].getExam1() && stud[i].getExam2() && stud[i].getExam3())
					{
						cout << "==========\n";
						stud[i].show();
						cout << "==========\n";
						aspir = true;
					}
				}
				if (!aspir)
				{
					cout << " Alas, there is no one to congratulate \n";
				}
				system("pause");
				break;
			}
		case 0:
			cout << " Goodbye \n";
			break;
		default:
			cout << " Error wrong menu selected \n";
		}
	} while (menu != 0);
	system("pause");
}