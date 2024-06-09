#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "Member.h"
#include "Librarian.h"
enum options{signup = 1, login  = 2};
options option;
std::map<std::string, std::string> auth_book;
std::map<std::string, std::string> target;

bool cleanf_string(const std::string& s) {
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
    if (target.find(author) == target.end() && target[author] == book) {
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

void sign_up(std::string name, std::string password) {
    Member them{ name, password };
    target.insert(std::make_pair(name, password));
}

void log_in(std::string name, std::string password) {
    std::string line;
    std::ifstream in_file{ "logins.txt" };
    if (in_file) {
        while (getline(in_file, line)) {
            if (cleanf_string(line)) {
                change_menu();
            }
            else {
                std::cout << "You went wrong please try again\n";
                main_menu();
            }
        }
        in_file.close();
    }
    else {
        std::cerr << "Unable to find file" << std::endl;
    }
}

void main_menu() {
    int response;
    std::string user, password;
    std::cout << "Welcome to the Library!" << "\n";
    std::cout << "Please sign in or login" << "\n";
    std::cout << "Choose 0 for signin and 1 for login" << "\n";
    std::cin >> response;
    if (response == signup) {
        std::cout << "Please type your name: " << "\n";
        std::cin >> user;
        std::cout << "Please type the password you want: " << "\n";
        std::cin >> password;
        sign_up(user,password);
    }
    else if (response == login) {
        std::cout << "Please type your username: " << "\n";
        std::cin >> user;
        std::cout << "Please type your password: " << "\n";
        std::cin >> password;
        log_in(user, password);
    }
}
void change_menu() {
    std::cout << "Welcome to the Library!" << "\n";
    std::cout << "Please sign in or login" << "\n";
    std::cout << "Choose 0 for signin and 1 for login" << "\n";
}
int main() {
    get_books();
    print_books();
    return 0;
}
