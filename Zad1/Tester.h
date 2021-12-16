#pragma once
#include <fstream>
#include "MyDynamicArray.h"
#include "MyDoubleLinkedList.h"
#include "Clock.h"
#include "MyHeap.h"
#include "MyBSTree.h"

using namespace std;

class Tester {

private:
	MyDynamicArray* dynamicArray;
	MyDoubleLinkedList* linkedList;
	MyHeap* heap;
	MyBSTree* tree;
	Clock clock;
	void linkedListTestMenu();
	void heapTestMenu();
	void treeTestMenu();
	void arrayTestMenu();
	void arrayAddTest(int, int);
	void arrayDeleteTest(int, int);
	void arraySearchTest(int);
	void listAddTest(int, int);
	void listDeleteTest(int, int);
	void listSearchTest(int);
	void treeAddTest(int);
	void treeDeleteTest(int);
	void treeSearchTest(int);
	void heapAddTest(int);
	void heapDeleteTest(int);
	void heapSearchTest(int);
	int chooseNumber();

public:
	void testMenu();
};