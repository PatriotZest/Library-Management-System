#pragma once
#include <iostream>
#include <string>

using namespace std;

class Librarian {
private:
	string password;
public:
	string name;
	string get_password();

	// Functions
	void update_password(string &old_password);
	inline void update_books(string book_to_be_removed);
	virtual void add_books(string author, string book);
	virtual void add_books_no_author(string book);

	// Constructors and Destructors
	Librarian(string name, string password);
	~Librarian();

};
