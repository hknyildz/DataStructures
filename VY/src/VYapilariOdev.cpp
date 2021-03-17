#include <iostream>
#include "AVL.hpp"
#include "Dugum.hpp"
#include "StackDugum.hpp"
#include "Stack.hpp"
#include <fstream>
#include <string>
#include <string.h>
#include <sstream>
#define max_size 100
using namespace std;

int main()
{
	int* dizi;
	int* dizi2;
	int satir = 0;
	int id = 0;
	string line;
	ifstream Dosya("Kisiler.txt");
	ifstream Dosya2("Kisiler.txt");
	while (getline(Dosya2, line))
	{ 
		satir++;
	}
	Dosya2.close();
	dizi = new int[satir];
	dizi2 = new int[satir];
	AVL* avl = new AVL();
	int sayac = 0;
	
	while (!(Dosya.eof()))
	{
		Dugum* dugum = new Dugum();
		Stack* stack = new Stack();
		dugum->stack = stack;
		getline(Dosya, line);
		string seperator = "#";
		size_t pos = 0;
		string siradaki;
		while ((pos = line.find(seperator)) != string::npos)
		{
			siradaki = line.substr(0, pos);
			if (sayac == 0)
			{
				dugum->ad = siradaki;
			}
			if (sayac == 1)
			{

				stringstream geek(siradaki);
				int x = 0;
				geek >> x;
				dugum->dogum_tarihi = x;
			}
			line.erase(0, pos + seperator.length());
			sayac++;
		}
		stringstream geek2(line);
		int x = 0;
		geek2 >> x;
		dugum->kilo = x;
		for (int i = 0; i < id; i++)
		{
			dizi[i] = avl->root->levelal(avl->root, i, 1);
		}
		avl->root = avl->insert(dugum, (2020 - dugum->dogum_tarihi),avl->root);
		dugum->id = id;
		for (int i = 0; i < id; i++)
		{
			dizi2[i] = avl->root->levelal(avl->root, i, 1);
		}
		for (int i = 0; i < id; i++)
		{
			if (dizi[i] == dizi2[i])
			{
				avl->postorder(avl->root, 0, i);
			}
			else if (dizi[i] > dizi2[i])
			{
				avl->postorder(avl->root, 2, i);
			}
			else if (dizi[i] < dizi2[i])
			{
				avl->postorder(avl->root, 3, i);
			}
		}
		id++;
		sayac = 0;
	}

	avl->postorder(avl->root,1,id);

	

	return 0;
}

