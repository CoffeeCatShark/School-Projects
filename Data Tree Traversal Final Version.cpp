#include <iostream>
#include <queue>
#include <string>
#include <limits>
using namespace std;

bool validInput(const string& input){
	if(input == "5" || input == "6" || input == "7" || input == "8" || input == "9" || input == "10" || input == "11" || input == "12" || input == "13" ||  input == "14" ||
	  input == "15"){
		return true;
	}
	else{
		return false;
	}
}

bool isNumeric(const string& str) {
    bool hasDecimal = false, hasDigit = false;
    int start = 0;

   
    if (!str.empty() && str[0] == '-') {
        start = 1;
    }

    for (int i = start; i < str.size(); i++) {
        if (str[i] == '.') {
            if (hasDecimal) return false;
            hasDecimal = true;
        } else if (isdigit(str[i])) {
            hasDigit = true;
        } else {
            return false;
        }
    }

    return hasDigit; 
}

struct Node {
    string data;
    Node* left;
    Node* right;

    Node(string data) {
        this->data = data;
        left = right = nullptr;
    }
};

Node* newNode(string data) {
    return new Node(data);
}

Node* buildTree(int numValues, bool isStringInput) {
    string rootValue;

        cout << "\nInput value for root node: ";
        getline(cin,rootValue);

        while (!isStringInput && !isNumeric(rootValue)) {
            cout << "Error: You entered an invalid number. Numbers can include decimals and negatives. Try again.\n";
            getline(cin,rootValue);
        } 


    Node* root = newNode(rootValue);
    queue<Node*> q;
    q.push(root);

    int count = 1;

    while (!q.empty() && count < numValues) {
        Node* current = q.front();
        q.pop();

        string leftInput;
        while (true) {
            cout << "\nInput value for left of " << current->data << " (NA/No/Wala for no node): ";
            getline(cin, leftInput);

            if (leftInput == "NA" || leftInput == "No" || leftInput == "Wala"||leftInput == "na" || leftInput == "no" || leftInput == "wala") {
                break;

            } else if (!isStringInput && !isNumeric(leftInput)) {
                cout << "Error: You entered an invalid number. Numbers can include decimals and negatives. Try again.\n";
            } else {
                current->left = newNode(leftInput);
                q.push(current->left);
                count++;
                break;
            }
        }

        if (count >= numValues) break;

        string rightInput;
        while (true) {
            cout << "\nInput value for right of " << current->data << " (NA/No/Wala for no node): ";
            getline(cin,rightInput);

            if (rightInput == "NA" || rightInput == "No" || rightInput == "Wala"||rightInput == "na" || rightInput == "no" || rightInput == "wala") {
                break;
            } else if (!isStringInput && !isNumeric(rightInput)) {
                cout << "Error: You entered an invalid number. Numbers can include decimals and negatives. Try again.\n";
            } else {
                current->right = newNode(rightInput);
                q.push(current->right);
                count++;
                break;
            }
        }
    }
    return root;
}

void levelOrder(Node* root) {
    if (root == nullptr) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();
        cout << current->data << ", ";

        if (current->left != nullptr) {
            q.push(current->left);
        }
        if (current->right != nullptr) {
            q.push(current->right);
        }
    }
}

void preOrder(Node* root) {
    if (root == nullptr) return;

    cout << root->data << ", ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node* root) {
    if (root == nullptr) return;

    inOrder(root->left);
    cout << root->data << ", ";
    inOrder(root->right);
}

void postOrder(Node* root) {
    if (root == nullptr) return;

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << ", ";
}

void deleteTree(Node* root) {
    if (root == nullptr) return;

    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

void showTree(Node* root) {
	cout<<endl<<"=======================";
	cout<<endl<<"Level Order Traversal:	";
	levelOrder(root);
	cout<<endl<<"In Order Traversal: 	";
	inOrder(root);
	cout<<endl<<"Pre-Order Traversal: 	";
	preOrder(root);
	cout<<endl<<"Post-Order Traversal:	";
	postOrder(root);
	cout<<endl<<"=======================";
}

bool repeatProgram(){
	string answer;
	cout<<endl<<"Repeat Program? [Y/Yes/N/No]";
	getline(cin, answer);
	while(answer != "Y" && answer != "y" && answer != "Yes" && answer != "yes" && answer != "N" && answer != "n" && answer != "No" && answer != "no"){
        cin.clear();
        cout<<"Input Error. Try Again: ";
        getline(cin,answer);
	}
	
	if (answer == "Y" || answer == "y" || answer == "Yes" || answer == "yes"){
		return true;
	}
	else if(answer == "N" || answer == "n" || answer == "No" || answer == "no") {
		cout<<"Exiting Program. . .";
		return false;
	}
	else return false;
}
	

bool console(int check){
	string numInput, inputValues;
	

	cout << "---------------------------------\n";
    cout << "Enter your choice for traversal:\n";
    cout << "1. Number\n";
    cout << "2. String\n";
    cout << "3. Exit\n";
    cout << "---------------------------------\n";
    cout << "Choice: ";
	getline(cin, numInput);
	
	while (numInput != "1" && numInput != "2" && numInput != "3") {
		cout << "\nError: Please enter a valid numeric choice (1, 2, or 3).\n";
		cin.clear();
        cout <<"Choice: ";
        getline(cin, numInput);
        }
	
	int choice = stoi(numInput);
	
	if(choice == 3){
		cout<<"Exiting Program. . .";
		return false;
	}
	
	if(choice == 2 || choice == 1){
		int numValues;
		
    cout << "\n---------------------------------\n";
    cout << "Input number of values (5-15): ";
    getline(cin,inputValues);
    
    while(validInput(inputValues) == false){
    	cout<<endl<<"Invalid Input. Try Again: ";
    	getline(cin,inputValues);
	}
	numValues = stoi(inputValues);
    while (numValues < 5 || numValues > 15) {
        cout << "Invalid input! Number of values must be between 5 and 15. Try again.\n";
        getline(cin,inputValues);
        numValues = stoi(inputValues);
    } 
    
    bool isStringInput = (choice == 2); 
    Node* root = buildTree(numValues, isStringInput);
		
	showTree(root);
	
	if(check == true){
		deleteTree(root);	
	}
	
	}
	
	return true;


}
	
 
	
int main(){
bool check = true;

do
{
	if(console(check) == false){
		break;
	}
	check = repeatProgram();
	
}while(check == true);


    return 0;
}
