#include <iostream>
#pragma pack(1)
struct emp
{
private:

	int empno;
	char name[10];
	float sal;

public:

	void AcceptEmpInfo()
	{
		std::cout<<"\n Enter EmpNo :: ";
		std::cin>>empno;

		std::cout<<"\n Enter Name :: ";
		std::cin>>name;

		std::cout<<"\n Enter Sal ::";
		std::cin>>sal;
		return;
	}
	void DisplayEmpInfo()
	{
		std::cout<<"\n EmpNo     Name    Sal \n"<< empno<<"\t"<< name<<"\t"<< sal;
		return;
	}
	void SetSalary(float salary)
	{
		sal= salary;
		return;
	}
	float GetSalary()
	{
		return sal;
	}

};

int main(void)
{
	emp e1;
	float salary;

	std::cout<<"\n enter Emp Info :: \n";
	e1.AcceptEmpInfo();


	std::cout<<"\n Employee Info ::  in main \n";
	e1.DisplayEmpInfo();

	std::cout<<"\n Enter salary ::";
	std::cin>>salary;

	e1.SetSalary(salary);

	std::cout<<"\n Employee Info  updated::  in main \n";
	e1.DisplayEmpInfo();

	salary= e1.GetSalary();
	std::cout<<"\n salary is "<<salary;

	return 0;
}
