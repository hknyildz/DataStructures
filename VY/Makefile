hepsi: program calistir

StackDugum.o:
	g++ -I "./include" -c ./src/StackDugum.cpp -o ./lib/StackDugum.o
Stack.o:
	g++ -I "./include" -c ./src/Stack.cpp -o ./lib/Stack.o
Dugum.o:
	g++ -I "./include" -c ./src/Dugum.cpp -o ./lib/Dugum.o
AVL.o:
	g++ -I "./include" -c ./src/AVL.cpp -o ./lib/AVL.o
VYapilariOdev.o:
	g++ -I "./include" -c ./src/VYapilariOdev.cpp -o ./lib/VYapilariOdev.o
program: StackDugum.o Stack.o Dugum.o AVL.o VYapilariOdev.o
	g++ ./lib/StackDugum.o ./lib/Stack.o ./lib/Dugum.o ./lib/AVL.o ./lib/VYapilariOdev.o -o ./bin/odev
calistir:
	./bin/odev.exe