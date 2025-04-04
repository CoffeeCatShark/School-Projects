using namespace std;
#include <iostream>
#include <string>
#include <vector>

class Products{
private: 
int quantity;
int productID;
string name;
float price;
public:
	Products(int _quantity, string _name, float _price, int _productID): quantity(_quantity), name(_name), price(_price), productID(_productID) {}

int getID(){
	return productID;
}

int getQuantity(){
	return quantity;
}

string getName(){
	return name;
}

float getPrice(){
	return price;
}

void updateItem(){
	
}

void updatePrice(){
	
}

};

class Cart{
private:
Products* products[100];
int quantity;
int productID;
string name;
float price;
public:
	

};

void addProduct(){
string input;
int id,quantity;
string name;
float price;


	cout<<"Product ID: ";
	cin>>input;														//change to getline
											//CONDITIONAL
	id = stoi(input);

	cout<<"Quantity: ";
	cin>>input;
											//CONDITIONAL
	quantity = stoi(input);
	
	cout<<"Name: ";
	getline(cin,input);
	name = input;
	
	cout<<"Price: ";
	getline(cin,input);
											//CONDITIONAL
											
	price = stoi(input);

	Products* product = new Products(quantity, name, price, id);
	
	
}



int main(){
	
	return 0;
}
