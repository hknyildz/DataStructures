#ifndef Dugum_hpp
#define Dugum_hpp
#include "Stack.hpp"
#include <string>
using namespace std;
class Dugum
{
private:

public:
	string ad;
	int dogum_tarihi;
	int kilo;
	Dugum* sol;
	Dugum* sag;
	int yukseklik;
	Stack* stack;
	int id;
	int levelal(Dugum*, int id, int level);
	Dugum();
};

#endif
