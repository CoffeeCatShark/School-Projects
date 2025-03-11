#include <iostream>
#include <string>
using namespace std;

struct Global{
	int x;
	int fullTime = 0;
	int partTime = 0;
	int contractual = 0;
};
Global global;
class Employee{
	private:
	int salary;
	int employeeCount;
	string name;
	int id;
	int totalSalary;
	public: 

	void setName(string x){name = x;}
	void setID(int x){id = x;}
	void setSalary(int x){salary = x;}
	
	string getName(){return name;}
	int getID(){return id;}
	int getSalary(){ return salary;}
	
	
	void setCount(int x){
		employeeCount+= x;
	}

	
	void setAll(){
		string x;
		int y,z;
		cin.ignore();
		cout<<"Name: ";
		getline(cin,x);
		cout<<"ID: ";
		cin>>y;
		cout<<"Salary: ";
		cin>>z;
		setName(x);
		setID(y);
		setSalary(z);
	}
	
	
virtual void display() = 0;
	
};

class FullTime: public Employee{
	private:
	int employeeCount;
	string name;
	int id;
	int salary;
	int totalSalary;
	public:
	
	void display() override {
	cout<<"Employee: "<<getName()<<" (ID: "<<getID()<<")"<<endl;
	cout<<"Fixed Monthly Salary: "<<"$"<<getSalary()<<endl;
	}
	
};

class PartTime: public Employee{
	private: 
	int employeeCount;
	string name;
	int id;
	int salary;
	int totalSalary;
	int hoursWorked;
	public:
		
	void _setHours(){
		int x;
		cout<<"Hours Worked: ";
		cin>>x;
		setHours(x);
	}
	void setHours(int x){hoursWorked = x;}
	
	void setNewSalary(int x, int y){
		totalSalary = x*y;
	}
	
	int getHours(){ return hoursWorked;} 
	
	void display() override {
	cout<<"Employee: "<<getName()<<" (ID: "<<getID()<<")"<<endl;
	cout<<"Hourly Wage: "<<"$"<<getSalary()<<endl;
	cout<<"Hours Worked: "<<getHours()<<endl;
	cout<<"TOTAL Salary: "<<totalSalary<<endl;
	}
	
};


class Contractual: public Employee{
	private:
	int employeeCount;
	int payment;
	string name;
	int id;
	int totalSalary;
	int projects;
	public:
		void _setProjects(){
		int x;
		cout<<"Projects: ";
		cin>>x;
		setProjects(x);
	}
	void setProjects(int x){projects = x;}
	
	int getProjects(){return projects;}
	
	
	void setNewSalary(int x, int y){
		totalSalary = x*y;
	}
	
	void display() override {
	cout<<"Employee: "<<getName()<<" (ID: "<<getID()<<")"<<endl;
	cout<<"Contract Payment Per Project: "<<"$"<<getSalary()<<endl;
	cout<<"Projects Completed: "<<getProjects()<<endl;
	cout<<"TOTAL Salary: "<<totalSalary<<endl;
	}
	
};
	FullTime fullTime[10];
	PartTime partTime[10];
	Contractual contractual[10];
	void menu();
	
	
void setFullTime(){
fullTime[global.fullTime].setAll();
fullTime[global.fullTime].setCount(global.fullTime);
global.x++;
global.fullTime++;


menu();
}

void setPartTime(){
partTime[global.partTime].setAll();
partTime[global.partTime]._setHours();
partTime[global.partTime].setCount(global.partTime);
partTime[global.partTime].setNewSalary(partTime[global.partTime].getSalary(),partTime[global.partTime].getHours());
global.x++;
global.partTime++;

menu();
}

void setContractual(){
	
contractual[global.contractual].setAll();
contractual[global.contractual]._setProjects();
contractual[global.contractual].setCount(global.contractual);
contractual[global.contractual].setNewSalary(contractual[global.contractual].getSalary(),contractual[global.contractual].getProjects());
global.x++;
global.contractual++;

menu();
}

void payrollReport(){
cout<<"-----Employee Payroll Report-----"<<endl;

cout<<"\t\tFull Time Employees"<<endl;
	if(global.fullTime == 0){
			cout<<"No Full Time Employees Registered."<<endl;
		}
	for(int x = 0;x<global.fullTime;x++){
		fullTime[x].display();
		cout<<endl;
	}

cout<<"\t\tPart Time Employees"<<endl;
		if(global.partTime == 0){
			cout<<"No Part Time Employees Registered."<<endl;
		}
	for(int y = 0;y<global.partTime;y++){
		partTime[y].display();
		cout<<endl;
	}
	
cout<<"\t\tContractual Employees"<<endl;
	if(global.contractual == 0){
			cout<<"No Part Time Employees Registered."<<endl;
		}
	for(int z=0;z<global.contractual;z++){
	
		contractual[z].display();
		cout<<endl;
	}
	
cout<<"========================================="<<endl;
menu();
}


void menu(){
int input;

	cout<<"\t\tMenu"<<endl;
	cout<<"============================"<<endl;
	cout<<"[1] - Full-Time Employee"<<endl;
	cout<<"[2] - Part-Time Employee"<<endl;
	cout<<"[3] - Contractual Employee"<<endl;
	cout<<"[4] - Display Payroll Report"<<endl;
	cout<<"[5] - Exit"<<endl;
cout<<"Input: ";
cin>>input;

switch(input){
	
	case 1: 
		setFullTime();
	break;
	
	case 2:
		setPartTime();
	break;
	
	case 3:
		setContractual();
	break;
	
	case 4:
		payrollReport();
	break;
	
	case 5:
	return;
	break;
	
}

}

int main(){
menu();
return 0;
}