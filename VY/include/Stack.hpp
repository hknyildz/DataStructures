#ifndef Stack_hpp
#define Stack_hpp
#include "StackDugum.hpp"
#include <string>

using namespace std;

class Stack
{
private:

public:
	Stack();
	bool Bosmu(Stack* stk);
	bool Dolumu(Stack* stk);
	void push(StackDugum*, Stack*);
	string pop(Stack* );
	void yazdir(Stack*);
	StackDugum* top;
	int uzunluk;
};


#endif
