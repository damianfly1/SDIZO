#pragma once
#include <time.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class MyDoubleLinkedList {

private:

	struct ListNode {
		ListNode* prev = NULL;
		ListNode* next = NULL;
		int data = NULL;
	};

	int size = NULL;
	ListNode* head = NULL;
	ListNode* tail = NULL;

public:
	void createRandom(int);
	~MyDoubleLinkedList(); //dekonstruktor
	bool createFromFile(); //utworz z pliku
	bool generateRandom(); //utworz losowo
	int getSize(); //zwraca rozmiar struktury
	bool empty(); //zwraca informacje czy struktura pusta
	void deleteValue(int); //usuwanie z listy
	void addAtIndex(int, int); //wstawianie do listy w konkretne miejsce
	bool findElement(int); //szukanie na liscie
	void showAll(); //wyswietlanie listy
	void popFront(); //usuwanie z poczatku
	void popBack(); //usuwanie z konca
	void pushFront(int); //wstawianie na poczatek
	void pushBack(int); //wstawianie na koniec
};


