#include <iostream>
using namespace std;

struct {
	int a[10],b[10], c[20], maxA, maxB;
	
} var;


void inputA(){
	int input;
	char max;
	
	cout<<"Array 1 Value Input"<<endl;;
	
	cout<<"Enter how many inputs in array 1(Max 10): ";
	cin>>input;
	while(input > 10){
		cout<<"Error: Max Input is 10: ";
		cin>>input;
	}
	max = input;
	var.maxA=max;
	
	for(int x=0;x<max;x++){
		cout<<endl<<"Input Value for Array["<<x+1<<"]: ";
		cin>>input;
		
		while(cin.fail()){
			cin.clear();
			cin.ignore();
			cout<<"Input Error: Please Try Again:";
			cin>>input;
		}
		var.a[x] = input;
		
	}
	
}

void inputB(){
	int input;
	char max;
	
	cout<<"Array 2 Value Input"<<endl;;
	
	cout<<"Enter how many inputs in array 2(Max 10): ";
	cin>>input;
	while(input > 10){
		cout<<"Error: Max Input is 10: ";
		cin>>input;
	}
	max = input;
	var.maxB=max;
	
	for(int x=0;x<max;x++){
		cout<<endl<<"Input Value for Array["<<x+1<<"]: ";
		cin>>input;
		
		while(cin.fail()){
			cin.clear();
			cin.ignore();
			cout<<"Input Error: Please Try Again:";
			cin>>input;
		}
		var.b[x] = input;
		
	}
	
}

void merge(){
	int temp;
	for(int x=0;x<var.maxA;x++){
		var.c[x] = var.a[x];
		cout<<var.c[x];
		x++;
		x=temp;
	}
	
	for(int x=temp;x<var.maxA+var.maxB;x++){
		var.c[x] = var.b[x];
	}
	
	for(int x=0; x<var.maxA+var.maxB-1;x++){
		cout<<var.c[x];
	}
}





int main(){
	
	inputA();
	inputB();
	merge();

	
	
	return 0;
}