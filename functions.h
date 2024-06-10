#pragma once
#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <utility>

extern std::map<std::string, std::string> auth_book;
extern std::map<std::string, std::string> target;

void refresh_books() {
        std::string line;
        std::ofstream in_file{ "books.csv" };
        if (in_file) {
            for (auto& [key, value] : auth_book) {
                remove("books.csv");
                in_file << key << "|" << value << "\n";
                
            }
            in_file.close();
        }
        else {
            std::cerr << "Unable to find file" << std::endl;
        }
}

void refresh_users() {
    std::ofstream in_file{ "logins.txt" };
    remove("logins.txt");
    if (in_file) {
        for (auto& [key, value] : target) {
            in_file << key << "|" << value << "\n";
        }
        in_file.close();
    }
    else {
        std::cerr << "Unable to find file" << std::endl;
    }
}

// getters
std::pair<std::string, std::string> clean_string(const std::string& s) {
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
    return(std::make_pair(author, book));
}

void get_books() {
    std::string line;
    std::ifstream in_file{ "books.csv" };
    if (in_file) {
        while (getline(in_file, line)) {
            auth_book.insert(clean_string(line));
        }
        in_file.close();
    }
    else {
        std::cerr << "Unable to find file" << std::endl;
    }
}

void get_users() {
    std::string line;
    std::ifstream in_file{ "logins.txt" };
    if (in_file) {
        while (getline(in_file, line)) {
            target.insert(clean_string(line));
        }
        in_file.close();
    }
    else {
        std::cerr << "Unable to find file" << std::endl;
    }
}