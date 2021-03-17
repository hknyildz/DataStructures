/**      
  * @file  AVL.hpp  
  * @description AVL agacina dair header dosyasi.  
  * @course  Dersi ald���n�z e�itim t�r� ve grup  
  * @assignment  Ka��nc� �dev oldu�u   
  * @date  26.08.2020  
  * @author  ��rencinin Ad� Soyad�   */



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
