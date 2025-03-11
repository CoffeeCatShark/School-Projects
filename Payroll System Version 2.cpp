#include <iostream>
using namespace std;

class Employee{
	private:
	string name;
	int id;
	int totalSalary;
	public: 

	void setName(string x){name = x;}
	void setID(int x){id = x;}
	void setSalary(int x){totalSalary = x;}
	
	string getName(){return name;}
	int getID(){return id;}
	int getSalary(){ return totalSalary;}
	
	void setAll(){
		string x;
		int y,z;
		cout<<"Name: ";
		cin>>x;
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
	string name;
	int id;
	int totalSalary;
	public:
	
	void display() override {
	cout<<"Employee: "<<getName()<<" (ID: "<<getID()<<")"<<endl;
	cout<<"Fixed Monthly Salary: "<<"$"<<getSalary()<<endl;
	}
	
};

class PartTime: public Employee{
	private: 
	string name;
	int id;
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
	
	void display() override {
	cout<<"Employee: "<<getName()<<" (ID: "<<getID()<<")"<<endl;
	cout<<"Fixed Monthly Salary: "<<"$"<<getSalary()<<endl;
	}
	
};


class Contractual: public Employee{
	private:
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
};

int main(){

	return 0;
}