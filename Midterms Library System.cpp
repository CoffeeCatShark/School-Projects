#include <iostream>
#include <string>
#include <string>
#include <cctype>
using namespace std;


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
		void editTitle(string x){
			title = x;
			cout<<"Edit Successful"<<endl;
		}
		void editISBN(string x){
			isbn = x;
			cout<<"Edit Successful"<<endl;
		}
		void editAuthor(string x){
			author = x;
			cout<<"Edit Successful"<<endl;
		}
		void editEdition(string x){
			edition = x;
			cout<<"Edit Successful"<<endl;
		}
		void editPublication(string x){
			publication = x;
			cout<<"Edit Successful"<<endl;
		}
		void editCategory(string x){
			category = x;
			cout<<"Edit Successful"<<endl;
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
		if(count == 0){
		cout<<"No Books Found Registered.";
		return;
	}
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
		
			cout<<"WORK IN PROGRESS -- still needs to add remove function"<<endl;
			//https://www.geeksforgeeks.org/how-to-remove-an-element-from-array-in-cpp/
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
	int _input;
	cin>>_input;												//ADD VALIDATION
		switch(_input){
			case 1:{
				cout<<"Enter New ISBN: ";
				getline(cin,input);
				books[key]->editISBN(input);
				break;
			}
			case 2:{
				cout<<"Enter New Title: ";
				getline(cin,input);
				books[key]->editTitle(input);
				break;
			}
			case 3:{
				cout<<"Enter New Author: ";
				getline(cin,input);
				books[key]->editAuthor(input);
				break;
			}
			case 4:{
				cout<<"Enter New Edition: ";
				getline(cin,input);
				books[key]->editEdition(input);
				break;
			}
			case 5:{
				cout<<"Enter New Publication: ";
				getline(cin,input);
				books[key]->editPublication(input);
				break;
			}
			case 6:{
				cout<<"Enter New Category: "; 
				getline(cin,input);
				books[key]->editCategory(input);
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
	
};
Library library;


string getCategory(Library& library){
	string category;
	bool valid = false;
	
	while(!valid){
		cout<<"Enter Book Category: ";
		cin.ignore();
		getline(cin,category);
		
														//ADD CONDITIONALS
		
		
		valid = true;
	}
		//ADD BOOL FOR YES NO
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
		
														//ADD CONDITIONALS
		
		
		valid = true;
	}
	return publication;
}

void searchBook(Library& library){
		if(library.getCount() == 0){
		cout<<"No Books Found Registered.";
		return;
	}
string input;
	cout<<"Input Book ID: ";
	cin.ignore();
	getline(cin,input);
	library.findBook(input);
}

void deleteBook(Library& library){
	string input;
	cout<<"Input Book ID: ";
	cin.ignore();
	getline(cin,input);
	library.deleteBook(input);
}

void editBook(Library& library){
	if(library.getCount() == 0){
		cout<<"No Books Found Registered.";
		return;
	}
	string input;
	cout<<"Input Book ID: ";
	cin.ignore();
	getline(cin,input);
	if(library.validBook(input)==true){
	library.editBook(input);
	}
	else
	cout<<"Book ID Not Found."<<endl;
}

void viewByCategory(Library& library){
	string input;
	cout<<"Category: ";
	cin.ignore();
	getline(cin,input);
	//VALIDATION ALL CAPS
	while(input != "FICTION" || input != "NONFICTION"){
		cout<<"Error: Category Not Found."<<endl;
		cout<<"Input: ";
		getline(cin,input);
	}
	
	if(input == "FICTION"){
		library.displayFiction();
	}
	else
		library.displayNonFiction();
	
}




bool menu(){

int input;
	cout<<"\n===================="<<endl;
	cout<<"[1] - Add Book"<<endl;
	cout<<"[2] - Edit Book"<<endl;
	cout<<"[3] - Search Book"<<endl;
	cout<<"[4] - Delete Book"<<endl;
	cout<<"[5] - View Books by Category"<<endl;
	cout<<"[6] - View All Books"<<endl;
	cout<<"[7] - Exit"<<endl;
	cout<<"Input: ";
cin>>input;

	switch(input){
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