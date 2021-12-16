#pragma once
#include <iostream>
#include <string>
#include <numeric>
#include <chrono>
#include <windows.h>
#include <time.h>
#include <iomanip>
#include <fstream>
#include "MyDynamicArray.h"
#include "MyDoubleLinkedList.h"
#include "Clock.h"
#include "MyHeap.h"
#include "MyBSTree.h"
#include "Tester.h"

using namespace std;

class Menu {

private:
	MyDynamicArray* dynamicArray = NULL; //wskaznik na tablice dynamiczna
	MyDoubleLinkedList* doubleLinkedList = NULL; // wskaznik na liste 
	MyHeap* heap = NULL; //wskaznik na kopiec binarny
	MyBSTree* tree = NULL; //wskaznik na bst
	Clock clock; //zegar

public:
	void chooseStructure(); // ekran startowy, wybierz strukture
	void treeMenu(); // menu dla drzewa bst
	void arrayMenu(); // menu dla dynamicznej tablicy
	void doubleLinkedListMenu(); // menu dla listy dwukierunkowej
	void heapMenu(); // menu dla kopca
	void waitingScreen(); // wiadomosc wstrzymujaca wyswietlanie
};

