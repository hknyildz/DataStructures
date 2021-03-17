#include "Stack.hpp"
#include<iostream>
#define max_size 100

using namespace std;

Stack::Stack()
{
		uzunluk = 0;
		top = NULL;
}


bool Stack::Bosmu(Stack* stk) // stack boþsa true döndürür.
{
	return(stk->uzunluk == 0);
}

bool Stack::Dolumu(Stack* stk) // stack doluysa true döndürür.
{
	return(stk->uzunluk == max_size);
}

void Stack::push(StackDugum* yeni, Stack* stk)
{
	if (!Dolumu(stk))
	{
		if (stk->top == NULL)
		{
			stk->uzunluk++;
			stk->top = yeni;
		}
		else
		{
			stk->uzunluk++;
			yeni->sonraki = stk->top;
			stk->top = yeni;
		}
	}
	else
	{
		cout << "Stack dolu. " << endl;
	}
}

string Stack::pop(Stack* stk)
{
	if (Bosmu(stk))
	{
		cout << "Stack zaten bos." << endl;
	}
	else
	{
		stk->uzunluk--;
		string silinecek = stk->top->veri;
		stk->top = stk->top->sonraki;
		return silinecek;
	}
}

void Stack::yazdir(Stack* stk)
{
	StackDugum* gezici = stk->top;
	while (gezici != NULL)
	{
		cout << gezici->veri << " " ;
		gezici = gezici->sonraki;
	}
}


