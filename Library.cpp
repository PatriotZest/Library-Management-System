#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include <iomanip>

std::map<std::string, std::string> auth_book;


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

    auth_book.insert(std::make_pair(author, book));
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


int main() {
    get_books();
    print_books();
    return 0
}
