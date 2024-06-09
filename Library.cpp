#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "Member.h"
#include "Librarian.h"
void main_menu();
void log_in(std::string name, std::string password);
enum options{signup = 1, login  = 2};
options option;
std::map<std::string, std::string> auth_book;
std::map<std::string, std::string> target;

bool cleanf_string(const std::string& s) {
    std::string user;
    std::string pass;
    bool found_space = false;

    for (char c : s) {
        if (c == '|' && !found_space) {
            found_space = true;
        }
        else if (!found_space) {
            user += c;
        }
        else {
            pass += c;
        }
    }
    if (target.find(user) == target.end() && target[user] == pass) {
        target.insert(std::make_pair(user, pass));
        return true;
    }
    else {
        return false;
    }
}

void clean_string(const std::string& s) {
    std::string author;
    std::string book;
    bool found_space = false;

    for (char c : s) {
        if (c == '|' && !found_space) {
            found_space = true;
        }
        else if (!found_space) {
            author += c;
        }
        else {
            book += c;
        }
    }
    
}


void get_books() {
    std::string line;
    std::ifstream in_file{ "books.csv" };
    if (in_file) {
        while (getline(in_file, line)) {
            clean_string(line);
        }
        in_file.close();
    }
    else {
        std::cerr << "Unable to find file" << std::endl;
    }
}
void print_books() {
    using std::setw;
    std::cout << std::left;
    std::cout << setw(20) << "[Author]" << setw(30) << "[Title]" << '\n';
    for (const auto& it : auth_book) {
        std::cout << setw(20) << it.first << setw(30) << it.second << std::endl;
    }
}

void sign_up() {
    std::string name, password;
    std::cout << "Please type your name: ";
    std::cin >> name;
    std::cout << "Please type the password you want: ";
    std::cin >> password;
    target.insert(std::make_pair(name, password));
}

void log_in() {
    std::string name, password;
    std::cout << "Please type your username: ";
    std::cin >> name;
    std::cout << "Please type your password: ";
    std::cin >> password;

    auto it = target.find(name);
    if (it != target.end() && it->second == password) {
        std::cout << "Login successful!" << std::endl;
        // Proceed to menu or other actions
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

void other_menu() {

}
int main() {
    main_menu();
    return 0;
}