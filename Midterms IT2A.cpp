using namespace std;
#include <string>
#include <vector>

Class Products{
private: 
int quantity;
int productID;
string name;
float price;
public:
	Products(int _quantity, string _name, float _price, int _productID): quantity(_quantity), name(_name), price(_price), productID(_productID)

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


};

Class Cart{
private:
Products* products[100];
int quantity;
int productID;
string name;
float price;
public:
	

};
