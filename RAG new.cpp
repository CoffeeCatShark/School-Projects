#include <iostream>
#include <string>
using namespace std;

struct process{
	string ID;
	int requiredResource;
	int resourceHeld;
	bool visited = false;
};
struct global{
	int resource;
};

struct memory{
	string data[10];
	bool deadlock;
};
process process[10];
memory memory[10];
global global;
void processIDGen(int processCount){
	string input;
	for(int i=0;i<processCount;i++){
		cout<<"Enter process ID for Process "<<i+1<<": ";
		cin>>input;
		process[i].ID = input;
	}	
}

void processRequirement(int processCount){
	int input;
	for(int i=0;i<processCount;i++){
		while(cout<<"Enter maximum need for Process "<<i+1<<": " && !(cin>>input) || input > 10){
		cin.clear();
		cin.ignore();
		cout<<"Input Error. Try Again"<<endl;
	}
		process[i].requiredResource = input;
	}
	
}

void currentlyHolding(int processCount){
	int input;
	for(int i=0;i<processCount;i++){
		cout<<endl<<"Current Resource Amount: "<<global.resource<<endl;
		cout<<"Enter the current held resource amount of Process "<<i+1<<": ";
		cin>>input;
		while(cin.fail() || global.resource < input){
			cout<<"Input Error. Try Again: ";
			cin.clear();
			cin.ignore();
			cin>>input;
		}
		process[i].resourceHeld = input;
		global.resource = global.resource - input;
	}
	
}

void showSequence(int processCount, int _count){
	
	cout<<endl<<"Possible Combinations of Processes: ";
	for(int i=0;i<_count;i++){
		for (int x=0;x<processCount;x++){
			cout<<memory[i].data[x]<<"\t";
		}
		if(memory[i].deadlock == true){
			cout<<"Has Deadlock"<<endl;
		}
		else{
			cout<<"No Deadlock"<<endl;
		}
	}
	
	
}

void deadlockTest(int processCount){
	int i=0;
	int count = 0, _count = 0;
	int pass=0, notPass=0;
while(count > processCount){
	for(int i=0;i<processCount;i++){
		process[i].visited == false;
	}
	
	
	while(i < processCount);{
		if((global.resource + process[i].resourceHeld) > process[i].requiredResource && process[i].visited == false){
			global.resource += process[i].resourceHeld;
			process[i].visited = true;
			i=0;
			memory[count].data[i] = process[i].ID;
			pass++;
			_count++;
			cout<<"ahola";
		}
		else{
			memory[count].data[i] = process[i].ID;
			i++;
			notPass++;
			_count++;
			cout<<"hello";
		}
		if(pass = processCount){
			memory[count].deadlock = false;
		}
		else{
			memory[count].deadlock = true;
		}
 	
	}
	
	count++;
}
	
	showSequence(processCount, _count);
	
}


void console(){	
int input;
int processCount;

	while(cout<<"Enter amount of Processes(min 3, max 10): " && !(cin>>input) || input > 10 || input < 3){
		cin.clear();
		cin.ignore();
		cout<<"Input Error. Try Again:"<<endl;
	}
		
		processCount = input;

	
	while(cout<<"Enter amount of Resources(min 3, max 10): " && !(cin>>input) || input > 10 || input < 3){
		cin.clear();
		cin.ignore();
		cout<<"Input Error. Try Again:"<<endl;
	}
	global.resource = input;

	processIDGen(processCount);
	
	processRequirement(processCount);
	
	currentlyHolding(processCount);
	
	deadlockTest(processCount);
}

bool repeatProgram(){
	char yesno;
	cout<<endl<<"Repeat Program?[Y/N]"<<endl;
	cin>>yesno;
	while(yesno != 'Y' && yesno != 'y' && yesno != 'N' && yesno != 'n' ){
		cin.clear();
		cin.ignore();
		cout<<"Invalid Input: Try Again: ";
	}
	
	if(yesno == 'Y' || yesno == 'y'){
		return true;
	}
	else{
		return false;
	}
}


int main(){
bool check = true;


	do{
	console();
	}while(repeatProgram() == true);

	
	
	return 0;
}