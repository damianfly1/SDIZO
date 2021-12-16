#pragma once
#include <iostream>
#include <time.h>
#include <string>
#include <cmath>
#include <fstream>
#include <string>
#define COUNT 1

using namespace std;

class MyHeap {

private:
	int* tab = NULL; //wskaznik na tablice przechowujaca kopiec
	long int tabLen = NULL; //obecny rozmiar tablicy przechowujacej kopiec
	int currentSize = NULL; //obecny rozmiar kopca
	void fixDown(int tab[], int index, int tabLen); // naprawa kopca w dol
	void fixUp(int tab[], int index); // naprawa kopca w gore
	void increaseSize(); // tworzy wieksza tablice przechowujaca kopiec
	void printTree(int, int); // wyswietlanie kopca w formie drzewa
	void heap_create_down(); //napraw kopiec metoda floyda??
	void heap_create_up(); //napraw kopiec metoda dodawania kolejnych elementow??

public:
	~MyHeap();
	void createRandom(int);
	bool createFromFile(); //utworz z pliku
	bool generateRandom(); //utworz losowo
	bool empty(); //zwraca informacje czy kopiec jest pusty
	int getSize(); //zwraca rozmiar
	bool findElement(int); //znajdz element
	void pop(int); //usun element
	void push(int); //dodaj element
	void showAll(); //wyswietl
};