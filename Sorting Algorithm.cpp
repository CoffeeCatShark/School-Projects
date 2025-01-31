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
	int temp =0, max=var.maxA+var.maxB;
	int x=0;
	while(x<var.maxA){
		var.c[x] = var.a[x];
		x++;
	}
	cout<<"X VALUE: "<<x<<" "<<endl;
	cout<<"MAX VALUE: "<<max<<" "<<endl;

	while(x<max){
		var.c[x]=var.b[temp];
		temp++;
		x++;
	}
	
	
	for(int x=0; x<var.maxA+var.maxB;x++){
		cout<<var.c[x]<<" ";
	}
	cout<<endl;
}

void sort(){
	int trueMax = var.maxA+var.maxB;
	for(int i=1;i<trueMax;i++){
		int key = var.c[i];
		int j = i - 1;
		
		while (j >= 0 && var.c[j] < key) {
            var.c[j + 1] = var.c[j];
            j = j - 1;
        }
        var.c[j + 1] = key;
	}
	
	for(int x=0;x<trueMax;x++){
		cout<<var.c[x]<<" ";
	}
}



int main(){
	
	inputA();
	inputB();
	merge();
	sort();
	
	
	return 0;
}