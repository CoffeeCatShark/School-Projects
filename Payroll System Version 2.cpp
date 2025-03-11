#include <iostream>
#include <string>
using namespace std;

struct Global{
	int x;
	int fullTime = 0;
	int partTime = 0;
	int contractual = 0;
};

struct AuthID{
	int idNum[30];
};

AuthID _id;
Global global;
class Employee{
	private:
	bool isRunning = true;
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
		while(cin.fail()){
			cin.clear();
			cin.ignore(1000,'\n');
			cout<<"Error: ID should only be a digit."<<endl;
			cin>>y;
		}
		isRunning = true;
		while(isRunning){
			for(int i=0;i<global.x;i++){
				if(y == _id.idNum[i]){
					cout<<"Error: ID has already been registered. Use a different value."<<endl;
					cout<<"Input: ";
					cin.ignore();
					cin>>y;
					while(cin.fail()){
				cin.clear();
				cin.ignore(1000,'\n');
				cout<<"Error: ID should only be a digit."<<endl;
				cout<<"Input: ";
				cin>>y;
				}
				}
			}
		isRunning = false;
		}
		cout<<"Salary: ";
		cin.ignore();
		cin>>z;
		while(cin.fail()){
				cin.clear();
				cin.ignore(1000,'\n');
				cout<<"Error: ID should only be a digit."<<endl;
				cout<<"Input: ";
				cin>>z;
				}
		setName(x);
		_id.idNum[global.x] = y;
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
		cin.ignore();
		cin>>x;
		while(cin.fail()){
				cin.clear();
				cin.ignore(100,'\n');
				cout<<"Error: ID should only be a digit."<<endl;
				cout<<"Input: ";
				x = 0;
				cin>>x;
				}
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
	cout<<"TOTAL Salary: $"<<totalSalary<<endl;
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
		cin.ignore();
		cin>>x;
		while(cin.fail()){
				cin.clear();
				cin.ignore(100,'\n');
				cout<<"Error: ID should only be a digit."<<endl;
				cout<<"Input: ";
				x = 0;
				cin>>x;
				}
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
	cout<<"TOTAL Salary: $"<<totalSalary<<endl;
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
while(input != 1 && input != 2 && input != 3 && input != 4 && input !=5 ||cin.fail()){
	cin.clear();
	cin.ignore(1000,'\n');
	cout<<"Error Input Try Again: ";
	cin>>input;
}
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