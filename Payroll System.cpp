#include <iostream>
using namespace std;

class Employee{
	private:
string name;
int id;
int totalSalary;

	protected: 
Employee(string _name, int _id, int _totalSalary): name(_name), id(_id), totalSalary(_totalSalary){}

	public:
string getName(){ return name;}
int getID(){ return id;}
int getSalary(){return totalSalary;}


virtual void setSalary(int x, int y) = 0;

	
virtual void display() = 0;
};


class FullTime: public Employee{
	public:
	FullTime(string name, int id, int salary) : Employee(name,id,salary) {}
	
	void display() override {
		cout<<"Employee: "<<getName()<<" (ID: "<<getID()<<")"<<endl;
		cout<<"Fixed Monthly Salary: "<<"$"<<getSalary()<<endl;
	}
	
};


class PartTime: public Employee{
	private:
int hoursWorked;
int salary;
	public:
PartTime(string name, int id, int totalSalary, int _hoursWorked): Employee(name,id,totalSalary) {hoursWorked = _hoursWorked;}

int getHours(){
	return hoursWorked;
}

void display() override{
		cout<<"Employee: "<<getName()<<" (ID: "<<getID()<<")"<<endl;
		cout<<"Hourly Wage: "<<"$"<<getSalary()<<endl;
		cout<<"Hours Worked: "<<getHours()<<endl;
		cout<<"Total Salary: "<<"$"<<(getSalary()*getHours())<<endl;
		
}


};

class Contractual: public Employee{
	private: 
int projects;
	public:
Contractual(string name, int id, int totalSalary, int _projects): Employee(name,id,totalSalary) {projects = _projects;}
	
int getProjects(){
	return projects;
}

void display() override{
		cout<<"Employee: "<<getName()<<" (ID: "<<getID()<<")"<<endl;
		cout<<"Contract Payment Per Project: "<<"$"<<getSalary()<<endl;
		cout<<"Projects Completed: "<<getProjects()<<endl;
		cout<<"Total Salary: "<<"$"<<(getSalary()*getProjects())<<endl;
		
}
	
};


void menu(){
	cout<<"Menu"<<endl;
	cout<<"1 - Full-Time Employee"<<endl;
	cout<<"2 - Part-Time Employee"<<endl;
	cout<<"3 - Contractual Employee"<<endl;
	cout<<"4 - Display Payroll Report"<<endl;
	cout<<"5 - Exit"<<endl;
}


int main(){
	menu();
	return 0;
}