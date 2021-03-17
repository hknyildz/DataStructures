/**      
  * @file  AVL.hpp  
  * @description AVL agacina dair header dosyasi.  
  * @course  Dersi aldýðýnýz eðitim türü ve grup  
  * @assignment  Kaçýncý ödev olduðu   
  * @date  26.08.2020  
  * @author  Öðrencinin Adý Soyadý   */



#ifndef AVL_hpp
#define AVL_hpp
#include "Dugum.hpp"
using namespace std;
class AVL
{
private:

public:
	Dugum* root;
	int height(Dugum *);
	int diff(Dugum *);
	Dugum *rr_rotation(Dugum *);
	Dugum *ll_rotation(Dugum *);
	Dugum *lr_rotation(Dugum *);
	Dugum *rl_rotation(Dugum *);
	Dugum* balance(Dugum *);
	Dugum* insert(Dugum *, int,Dugum*);
	void postorder(Dugum *,int,int);
	int max(int a, int b);
	AVL();
};

#endif
