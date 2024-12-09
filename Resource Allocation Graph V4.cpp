#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct process{
	string ID;
	int requiredResource;
	int resourceHeld;
	bool visited = false;
};
struct global{
	int resource;
	int constant_resource;
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
	global.constant_resource = global.resource;
}

void showSequence(int processCount){
int i=0;
int sequence[10] = {0,1,2,3,4,5,6,7,8,9};
	cout<<endl<<"Possible Combinations of Processes: ";
do{
	global.resource = global.constant_resource;
	i=0;
	cout<<endl;
	cout<<"Processes: ";
	for(int i=0;i<processCount;i++){
		cout<<process[sequence[i]].ID<<" ";
	}
	
	while (i<processCount){
		

		if((global.resource + process[sequence[i]].resourceHeld) > process[sequence[i]].requiredResource){
			global.resource += process[sequence[i]].resourceHeld;
			memory[sequence[i]].deadlock = false;
			i++;
		}
		else
			memory[sequence[i]].deadlock = true;
			break;
		}
	
	if (memory[sequence[i]].deadlock == true){
		cout<<" - UNSAFE";
	}
	else if(memory[sequence[i]].deadlock == false){
		cout<<" - SAFE";
	}


}while(next_permutation(sequence,sequence+processCount));
	
	
}

void deadlockTest(int processCount){
	
	showSequence(processCount);
	
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