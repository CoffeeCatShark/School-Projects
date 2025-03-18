#include <iostream>
#include <string>
#include <cctype>
#include <limits>
using namespace std;

bool isValidName(const string& name) {
    for (char ch : name) {
        if (!isalpha(ch) && ch != ' ') {
            return false;
        }
    }
    return !name.empty(); // Ensure the name is not empty
}

bool isDigits(const string& str) {
    for (char ch : str) {
        if (!isdigit(ch)) {
            return false;
        }
    }
    return true;
}

void buffer(){
	string input;
	cout<<endl<<"Press any key and Enter to Continue"<<endl;
	getline(cin,input);
}

string capital(string input){
	string _input;
	
    for (int i = 0; i < input.length(); i++)
        input[i] = toupper(input[i]);

	return input;
}


class Book {
	private:
		string id;			//ALPHANUMERIC ALL CAPS ONLY
		string isbn;
		string title;
		string author;
		string edition;
		string publication;
		string category;	//FICTION OR NON FICTION ONLY
		bool isFiction;
	public:
		Book(string _id, string _isbn, string _title, string _author, string _edition, string _publication, string _category):
			id(_id), isbn(_isbn), title(_title), author(_author), edition(_edition), publication(_publication), category(_category) {}
			
		void display() const{
			cout<<"ID: "<<id<<endl;
			cout<<"ISBN: "<<isbn<<endl;
			cout<<"Title: "<<title<<endl;
			cout<<"Author: "<<author<<endl;
			cout<<"Edition: "<<edition<<endl;
			cout<<"Publication: "<<publication<<endl;
			cout<<"Category: "<<category<<endl;
			cout<<"============================"<<endl;
		}

		string getID(){return id;}
		string getCategory(){return category;}
		string getISBN(){return isbn;}
		string getTitle(){return title;}
		string getAuthor(){return author;}
		string getEdition(){return edition;}
		string getPublication(){return publication;}
		
		bool checkCategory(){
			cout<<"WIP";
			return true;
		}
		void editID(string x){
			id = x;
		}
		
		void editTitle(string x){
			title = x;
		}
		void editISBN(string x){
			isbn = x;
		}
		void editAuthor(string x){
			author = x;
		}
		void editEdition(string x){
			edition = x;
		}
		void editPublication(string x){
			publication = x;
		}
		void editCategory(string x){
			category = x;
		}
		
};



class Library{
	private:
		Book* books[100];
	int count = 0;
	public: 
	int getCount(){
		return count;
	}
	int bookCount(){
		return count;
	}
	bool isDuplicateID(string id) const{
		for(int i=0;i<count;i++){
			if(id == books[i]->getID())
					return true;
		}
		return false;
	}
	
	void addBook(Book* book){
		books[count++] = book;
		cout<<"Book Added Successfully"<<endl;
	}
	
	void displayLibrary(){
	cout<<"\tLIBRARY LIST"<<endl;
	cout<<"============================"<<endl;
		if(count == 0){
			cout<<"No books Found in the Library List"<<endl;
		}
		else{
			for(int i=0;i<count;i++){
			books[i]->display();
			cout<<endl;
			}
		}
	}
	
	void findBook(string x){
		bool foundBook = false;	
		for(int i=0;i<count;i++){
			if(x == books[i]->getID()){
				books[i]->display();
				foundBook = true;
			}
			if(foundBook == false){
				cout<<"Book Not Found"<<endl;
				return;
			}
		}
	}
	
	void deleteBook(string x){
		string key;
		if(count == 0){
		cout<<"No Books Found Registered.";
		return;
	}
		bool foundBook = false;	
		for(int i=0;i<count;i++){
			if(x == books[i]->getID()){
				books[i]->display();
				key = books[i]->getID();
				foundBook = true;
			}
			if(foundBook == false){
				cout<<"Book Not Found"<<endl;
				return;
			}
		}

			for(int i=0;i<count;i++){
	
				if(books[i]->getID() == key){
					count = count - 1;
					for(int j=i;j<count;j++){
						books[j]->editID(books[j+1]->getID());
						books[j]->editAuthor(books[j+1]->getAuthor());
						books[j]->editCategory(books[j+1]->getCategory());
						books[j]->editEdition(books[j+1]->getEdition());
						books[j]->editISBN(books[j+1]->getISBN());
						books[j]->editPublication(books[j+1]->getPublication());
						books[j]->editTitle(books[j+1]->getTitle());
					}
					cout<<endl<<"Deletion Successful."<<endl;
				}
				
			}
			
	}
		
	bool validBook(string x){
	int input;
		bool foundBook = false;	
		for(int i=0;i<count;i++){
			if(x == books[i]->getID()){
				books[i]->display();
				foundBook = true;	
			}
			if(foundBook == false){
				cout<<"Book Not Found"<<endl;
				return false;
			}
		}
		return true;
	}
	
	void editBook(string input){
	int key;
	bool valid = false;
				for(int i=0;i<count;i++){
					if(books[i]->getID() == input){
						key = i;
					}
				}
		cout<<"[1] - ISBN"<<endl;
		cout<<"[2] - Title"<<endl;
		cout<<"[3] - Author"<<endl;
		cout<<"[4] - Edition"<<endl;
		cout<<"[5] - Publication"<<endl;
		cout<<"[6] - Category"<<endl;
	string x;
	int _input;
	cin>>x;
	while (!isDigits(x) || input.empty()) {
            cout << "ERROR: Invalid input. Please enter a valid number.\n";
            cout<<"Input: ";
			cin>>x;
        }
	_input = stoi(x);										
		switch(_input){
			case 1:{
				cout<<"Enter New ISBN: ";
				getline(cin,input);
				books[key]->editISBN(capital(input));
				cout<<endl<<"Edit Successful"<<endl;
				break;
			}
			case 2:{
				cout<<"Enter New Title: ";
				getline(cin,input);
				books[key]->editTitle(capital(input));
				cout<<endl<<"Edit Successful"<<endl;
				break;
			}
			case 3:{
				cout<<"Enter New Author: ";
				getline(cin,input);
				books[key]->editAuthor(capital(input));
				cout<<endl<<"Edit Successful"<<endl;
				break;
			}
			case 4:{
				cout<<"Enter New Edition: ";
				getline(cin,input);
				books[key]->editEdition(capital(input));
				cout<<endl<<"Edit Successful"<<endl;
				break;
			}
			case 5:{
				cout<<"Enter New Publication: ";
				getline(cin,input);
				books[key]->editPublication(capital(input));
				cout<<endl<<"Edit Successful"<<endl;
				break;
			}
			case 6:{
				cout<<"Enter New Category: "; 
				while(!valid){
				cout<<"Enter Book Category: ";
				getline(cin,input);
				input = capital(input);
				if(input != "FICTION" && input != "NONFICTION"){
				cout<<"Error: Category must be either FICTION or NONFICTION"<<endl;
				}
				else
				valid = true;
			}
				books[key]->editCategory(capital(input));
				cout<<endl<<"Edit Successful"<<endl;
				break;
			}
				
		}
	}
	
	void displayFiction(){
		if(count == 0){
			cout<<"No Books Registered"<<endl;
			return;
		}
		for(int i=0;i<count;i++){
			if(books[i]->getCategory() == "FICTION"){
				books[i]->display();
			}
		}
	}
	
	void displayNonFiction(){
		if(count == 0){
			cout<<"No Books Registered"<<endl;
			return;
		}
		for(int i=0;i<count;i++){
			if(books[i]->getCategory() == "NONFICTION"){
				books[i]->display();
			}
		}
	}
	buffer();
};
Library library;



string getCategory(Library& library){
	string category;
	bool valid = false;									//ADD ALLCAPS MODIFIER										
		while(!valid){
			cout<<"Enter Book Category: ";
			getline(cin,category);
			category = capital(category);
			if(category != "FICTION" && category != "NONFICTION"){
				cout<<"Error: Category must be either FICTION or NONFICTION"<<endl;
			}
			else
			valid = true;
		}
														//ADD CONDITIONALS
	return category;
}


string getValidID(Library& library){
	string id;
	bool valid = false;
	
	while(!valid){
		cout<<"Enter ID Value: ";
		getline(cin,id);
		if(library.isDuplicateID(id)){
			cout<<"Duplicate ID: Try Again"<<endl;			
		}
														//ADD CONDITIONALS
		
		else
		valid = true;
	}
	id = capital(id);
	return id;
}


string getISBN(){
	string isbn;
	bool valid = false;
	
	while(!valid){
		cout<<"Enter ISBN Value: ";
		getline(cin,isbn);
		
														//ADD CONDITIONALS
		
		
		valid = true;
	}
	

	return isbn;
}

string getTitle(){
	string title;
	bool valid = false;
	
	while(!valid){
		cout<<"Enter Book Title: ";
		getline(cin,title);
		
														//ADD CONDITIONALS
		
		
		valid = true;
	}
	return title;
}

string getAuthor(){
	string author;
	bool valid = false;
	
	while(!valid){
		cout<<"Enter Book Author: ";
		getline(cin,author);
		author = capital(author);
		
														//ADD CONDITIONALS
		
		
		valid = true;
	}
	return author;
}

string getEdition(){
	string edition;
	bool valid = false;
	
	while(!valid){
		cout<<"Enter Book Edition: ";
		getline(cin,edition);
		edition = capital(edition);
														//ADD CONDITIONALS
		
		
		valid = true;
	}
	return edition;
}

string getPublication(){
	string publication;
	bool valid = false;
	
	while(!valid){
		cout<<"Enter Book Publication: ";
		getline(cin,publication);
		publication = capital(publication);
		
														//ADD CONDITIONALS
		
		
		valid = true;
	}
	return publication;
}

void searchBook(Library& library){
		if(library.getCount() == 0){
		cout<<"No Books Found Registered.";
		buffer();
		return;
	}
string input;
	cout<<"Input Book ID: ";
	getline(cin,input);
	input = capital(input);
	library.findBook(input);
	buffer();
}

void deleteBook(Library& library){
	if(library.bookCount() == 0){
		cout<<endl<<"Library is Empty."<<endl;
		buffer();
		return;
	}
	string input;
	cout<<"Input Book ID: ";
	getline(cin,input);
	input = capital(input);
	library.deleteBook(input);
}

void editBook(Library& library){
	if(library.getCount() == 0){
		cout<<"No Books Found Registered.";
		buffer();
		return;
	}
	string input;
	cout<<"Input Book ID: ";
	getline(cin,input);
	if(library.validBook(input)==true){
	library.editBook(input);
	buffer();
	}
	else
	cout<<"Book ID Not Found."<<endl;
	buffer();
}

void viewByCategory(Library& library){
	if(library.getCount() == 0){
	cout<<"No Books Currently Registered.";
	buffer();
	return;
	}
	
	string input;
	cout<<"Category: ";
	getline(cin,input);
	input = capital(input);
	while(input != "FICTION" && input != "NONFICTION"){
		cout<<"Error: Category Not Found."<<endl;
		cout<<"Input: ";
		getline(cin,input);
	}
	
	if(input == "FICTION"){
		cout<<endl<<"\tFICTION CATEGORY"<<endl;
		library.displayFiction();
		buffer();
	}
	else if (input == "NONFICTION"){
		cout<<endl<<"\tNONFICTION CATEGORY"<<endl;
		library.displayNonFiction();
		buffer();
		}
}


void display(){
	cout<<"\n===================="<<endl;
	cout<<"[1] - Add Book"<<endl;
	cout<<"[2] - Edit Book"<<endl;
	cout<<"[3] - Search Book"<<endl;
	cout<<"[4] - Delete Book"<<endl;
	cout<<"[5] - View Books by Category"<<endl;
	cout<<"[6] - View All Books"<<endl;
	cout<<"[7] - Exit"<<endl;
}

bool menu(){

string input;
int _input;
	display();
	cout<<"Input: ";
	getline(cin,input);
	
	while (!isDigits(input) || input.empty()) {
            cout << "ERROR: Invalid input. Please enter a valid number.\n";
            cout<<"Input: ";
			getline(cin,input);
        }
        
	_input = stoi(input);
	if(_input < 1 || _input > 7 ){
		cout<<"ERROR: Invalid Input. Input Must only Be 1 - 7"<<endl;
		menu();
	}

	switch(_input){
		case 1: {
		string category = getCategory(library);
		string id = getValidID(library);
		string isbn = getISBN();
		string title = getTitle();
		string author = getAuthor();
		string edition = getEdition();
		string publication = getPublication();
		
		Book* book = new Book(id,isbn,title,author,edition,publication,category);
		library.addBook(book);
		break;
	}
		case 2:{
			editBook(library);
			break;
		}
		
		case 3:{
			searchBook(library);
			break;
		}
		case 4:{
			deleteBook(library);
			break;
		}
		case 5:{
			viewByCategory(library);
			break;
		}
		case 6:{
			library.displayLibrary();
			buffer();
			break;
		}
		case 7:{
			return false;
			break;
		}
	}

return true;
}


int main() {
bool running = true;
while(running){
	running = menu();
}
	return 0;
}