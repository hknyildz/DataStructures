#include "AVL.hpp"
#include "Dugum.hpp"
#include "StackDugum.hpp"
#include <iostream>
#include <fstream>
#include <string>
#define max_size 100


using namespace std;

AVL::AVL()
{
	root = NULL;
}

int AVL::height(Dugum *temp)
{
	int h = 0;
	if (temp != NULL)
	{
		int l_height = height(temp->sol);
		int r_height = height(temp->sag);
		int max_height = max(l_height, r_height);
		h = max_height + 1;
	}
	return h;
}

int AVL::diff(Dugum *temp)
{
	int l_height = height(temp->sol);
	int r_height = height(temp->sag);
	int b_factor = l_height - r_height;
	return b_factor;
}

Dugum *AVL::rr_rotation(Dugum *parent)
{
	//StackDugum* stackdugumu1 = new StackDugum();
	//StackDugum* stackdugumu2 = new StackDugum();
	//stackdugumu1->veri = "Y";
	//stackdugumu2->veri = "A";
	Dugum *temp;
	temp = parent->sag;// ahmete ulastim
	parent->sag = temp->sol;
	temp->sol = parent;
	//temp->stack->push(stackdugumu1, temp->stack);
	//temp->stack->push(stackdugumu2, parent->stack);
	return temp;
}

Dugum *AVL::ll_rotation(Dugum *parent)
{
	//StackDugum* stackdugumu1 = new StackDugum();
	//StackDugum* stackdugumu2 = new StackDugum();
	//stackdugumu1->veri = "Y"; 
	//stackdugumu2->veri = "A";
	Dugum *temp;
	temp = parent->sol; 
	parent->sol = temp->sag;
	temp->sag = parent;
	//temp->stack->push(stackdugumu1, temp->stack);
	//temp->stack->push(stackdugumu2, parent->stack);
	return temp;
}

Dugum *AVL::lr_rotation(Dugum *parent)
{

	Dugum *temp;
	temp = parent->sol;
	parent->sol = rr_rotation(temp);
	return ll_rotation(parent);
}

Dugum *AVL::rl_rotation(Dugum *parent)
{

	Dugum *temp;
	temp = parent->sag;
	parent->sag = ll_rotation(temp);
	return rr_rotation(parent);
}

Dugum *AVL::balance(Dugum *temp)
{
	int bal_factor = diff(temp);
	if (bal_factor > 1)
	{
		if (diff(temp->sol) > 0)
			temp = ll_rotation(temp);
		else
			temp = lr_rotation(temp);
	}
	else if (bal_factor < -1)
	{
		if (diff(temp->sag) > 0)
			temp = rl_rotation(temp);
		else
			temp = rr_rotation(temp);
	}

	return temp;
}

Dugum *AVL::insert(Dugum *dugum, int value,Dugum* root)
{
	if (root == NULL)
	{
		root = dugum;
		root->sol = NULL;
		root->sag = NULL;
		StackDugum* stackdugumu1 = new StackDugum();
		stackdugumu1->veri = "O";
		root->stack->push(stackdugumu1, root->stack);
		return root;
	}
	else if (value <= (2020 - root->dogum_tarihi))
	{
		if (root->sol == NULL)
		{
			root->sol = dugum;
			StackDugum* stackdugumu1 = new StackDugum();
			stackdugumu1->veri = "O";
			
			root->sol->stack->push(stackdugumu1, root->sol->stack);
		}
		else
		{
			root->sol =insert(dugum, value, root->sol);
			root = balance(root);
		}
	}
	else if (value > (2020 - root->dogum_tarihi))
	{
		if (root->sag == NULL)
		{
			root->sag = dugum;
			StackDugum* stackdugumu1 = new StackDugum();
			stackdugumu1->veri = "O";
			root->sag->stack->push(stackdugumu1, root->sag->stack);
		}
		else
		{
			root->sag = insert(dugum, value, root->sag);
			root = balance(root);
		}
	}
	return root;
}

void AVL::postorder(Dugum *tree, int type, int id)
{
	if (tree == NULL)
		return;
	postorder(tree->sol, type,id);
	postorder(tree->sag, type,id);
	if (type == 1) // 1 de yazdir, 0 da gez.
	{
		cout << tree->ad << "," << tree->dogum_tarihi << "," << tree->kilo<<" ";
		tree->stack->yazdir(tree->stack);
		cout << endl;
	}
	else if (type == 0)
	{
		if (id == tree->id)
		{
			StackDugum* stackdugum = new StackDugum();
			stackdugum->veri = "D";
			tree->stack->push(stackdugum, tree->stack);
		}
	}
	else if (type == 2)
	{
		if (id == tree->id)
		{
			StackDugum* stackdugum = new StackDugum();
			stackdugum->veri = "Y";
			tree->stack->push(stackdugum, tree->stack);
		}
	}
	else if (type == 3)
	{
		if (id == tree->id)
		{
			StackDugum* stackdugum = new StackDugum();
			stackdugum->veri = "A";
			tree->stack->push(stackdugum, tree->stack);
		}
	}
	
}

int AVL :: max(int a, int b)
{
	if (a > b)
	{
		return a;
	}
	else
	{
		return b;
	}
}
