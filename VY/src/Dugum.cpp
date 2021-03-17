#include "Dugum.hpp"
using namespace std;
Dugum::Dugum()
{
	ad="ilk";
	dogum_tarihi=0;
	kilo=0;
	sol=NULL;
	sag=NULL;
	int yukseklik=0;
	stack=NULL;
	int id=0;
}


int Dugum::levelal(Dugum* dugum, int iD, int level)
{
	if (dugum == NULL)        
		return 0;      
	if (dugum->id == iD)         
		return level;      
	int downlevel = levelal(dugum->sol, iD, level + 1);
	if (downlevel != 0) 
		return downlevel;
		downlevel = levelal(dugum->sag, iD, level + 1);    
		return downlevel;
}
