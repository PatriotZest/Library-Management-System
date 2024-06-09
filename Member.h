#pragma once
#include "Librarian.h"

class Member : public Librarian {
private:
	string password;
public:
	string name;
	Member(string name, string password);
	~Member();
	
};