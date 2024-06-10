#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "Member.h"
#include "Librarian.h"
#include "functions.h"

void main_menu();
void log_in();
void other_menu(Member memb);
enum options{signup = 1, login  = 2};
enum class menu { print = 1, add = 2,quit = 3};
options option;
std::map<std::string, std::string> auth_book;
std::map<std::string, std::string> target;

void print_books() {
    using std::setw;
    std::cout << std::left;
    std::cout << setw(40) << "[Author]" << setw(30) << "[Title]" << '\n';
    for (const auto& it : auth_book) {
        std::cout << setw(40) << it.first << setw(50) << it.second << std::endl;
    }
}

void sign_up() {
    std::string name, password;
    std::cout << "Please type your name: ";
    getline(cin, name);
    std::cout << "Please type the password you want: ";
    getline(cin, password);
    target.insert(std::make_pair(name, password));
    Member memb(name, password);
    other_menu(memb);
}

void log_in() {
    std::string name, password;
    std::cout << "Please type your username: ";
    getline(cin, name);
    std::cout << "Please type your password: ";
    getline(cin, password);

    auto it = target.find(name);
    if (it != target.end() && it->second == password) {
        Member memb(name, password);
        std::cout << "Login successful!" << std::endl;
        other_menu(memb);
    }
    else {
        std::cout << "Invalid username or password. Please try again." << std::endl;
        main_menu();
    }
}

void main_menu() {
    int response;
    std::cout << "Welcome to the Library!" << std::endl;
    std::cout << "Please sign in or login" << std::endl;
    std::cout << "Choose 1 for signup and 2 for login: ";
    std::cin >> response;
    cin.ignore();
    if (response == signup) {
        sign_up();
    }
    else if (response == login) {
        log_in();
    }
    else {
        std::cout << "Invalid option. Please try again." << std::endl;
        main_menu();
    }
}

void other_menu(Member memb) {
    using namespace std;
    int response;
    string author, book;
    cout << "Press 1, to see all of our books\n";
    cout << "Press 2, to add a book\n";
    cout << "Press 3, to quit: ";
    cin >> response;
    cin.ignore();
    menu option = static_cast<menu>(response);

    switch (option) {
    case menu::print:
        get_books();
        print_books();
        other_menu(memb);
        break;
    case menu::add:
        cout << "Enter author: ";
        getline(cin,author);
        cout << "Enter book: ";
        getline(cin, book);
        memb.add_books(author, book);
        other_menu(memb);
        break;
    case menu::quit:
        refresh_books();
        refresh_users();
        cout << "Quitting..." << endl;
        break;
    default:
        cout << "Invalid option, please try again." << endl;
        other_menu(memb); 
        break;
    }
}
int main() {
    get_users();
    main_menu();
    return 0;
}