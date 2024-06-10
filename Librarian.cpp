#include "Librarian.h"
#include <iostream>
#include <string>
#include <map>

extern std::map<std::string, std::string> auth_book;
using namespace std;
string Librarian::get_password()
{
	return Librarian::password;
}

void Librarian::add_books(string author, string book) {
	auth_book.insert(make_pair(author, book));
	//cout << "Author: " << author << "\n" << "Book: " << book << " added";
}

void Librarian::add_books_no_author(string book)
{
	auth_book.insert(make_pair("N/A", book));
	//cout << "Author: N/A" << "\n" << "Book: " << book << " added";
}

void Librarian::update_password(string &old_password)
{
	string new_password;
	if (old_password == get_password()) {
		cout << "Enter the new password you want to add: ";
		cin >> new_password;
		old_password = new_password;
		cout << "\nPassword has been updated";
	}
	else {
		cout << "Current password is wrong";
	}
}

void Librarian::update_books(string book_to_be_removed)
{
	if (auth_book.find(book_to_be_removed) == auth_book.end()) {
		cout << "The book was not found bruv";
	}
	else {
		auth_book.erase(book_to_be_removed);
	}
}
Librarian::Librarian(string name, string password) : name{name}, password{password}
{

}

Librarian::~Librarian()
{
}
