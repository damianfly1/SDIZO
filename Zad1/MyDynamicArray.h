#pragma once
#include <iostream>
#include <time.h>
#include <fstream>
#include <windows.h>
#include <string>

using namespace std;

class MyDynamicArray {

private:
	int size; //rozmiar tablicy
	int* arrayFirst = NULL; //wskaznik na poczatek tablicy

public:
	void createRandom(int); // do testowania
	~MyDynamicArray(); //dekonstruktor
	bool createFromFile(); //utworz z pliku
	bool generateRandom(); //utworz losowo
	bool empty(); //mowi czy tablica jest pusta
	int getSize(); //zwraca rozmiar tablicy
	void deleteAtIndex(int); // usuwanie z tablicy
	void addAtIndex(int, int); // wstawianie do tablicy w konkretne miejsce
	bool findElement(int); // szukanie w tablicy
	void showAll(); // wyswietlanie tablicy
	void pushFront(int); //wstawianie na poczatek
	void pushBack(int); //wstawianie na koniec
	void popFront(); //usuwanie z poczatku
	void popBack(); //usuwanie z konca
};
