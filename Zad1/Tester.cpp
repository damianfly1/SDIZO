#include "Tester.h"

void Tester::linkedListTestMenu()
{
	system("cls");
	cout << "Jaka operacje chcesz sprawdzic?" << endl;
	cout << "1. Dodawanie na poczatek listy" << endl;
	cout << "2. Dodawanie na koniec listy" << endl;
	cout << "3. Dodawanie do listy" << endl;
	cout << "4. Usuwanie z poczatku listy" << endl;
	cout << "5. Usuwanie z konca listy" << endl;
	cout << "6. Usuwanie z listy" << endl;
	cout << "7. Wyszukiwanie w liscie" << endl;
	cout << "8. Wroc do menu" << endl << endl;
	int choice;
	cin >> choice;
	switch (choice) {
	case 1:
		listAddTest(1, 1000);
		listAddTest(1, 2000);
		listAddTest(1, 5000);
		listAddTest(1, 8000);
		listAddTest(1, 10000);
		listAddTest(1, 16000);
		listAddTest(1, 20000);
		listAddTest(1, 25000);
		break;
	case 2:
		listAddTest(2, 1000);
		listAddTest(2, 2000);
		listAddTest(2, 5000);
		listAddTest(2, 8000);
		listAddTest(2, 10000);
		listAddTest(2, 16000);
		listAddTest(2, 20000);
		break;
	case 3:
		listAddTest(2, 25000);
		listAddTest(3, 1000);
		listAddTest(3, 2000);
		listAddTest(3, 5000);
		listAddTest(3, 8000);
		listAddTest(3, 10000);
		listAddTest(3, 16000);
		listAddTest(3, 20000);
		listAddTest(3, 25000);
		break;
	case 4:
		listDeleteTest(1, 1000);
		listDeleteTest(1, 2000);
		listDeleteTest(1, 5000);
		listDeleteTest(1, 8000);
		listDeleteTest(1, 10000);
		listDeleteTest(1, 16000);
		listDeleteTest(1, 20000);
		listDeleteTest(1, 25000);
		break;
	case 5:
		listDeleteTest(2, 1000);
		listDeleteTest(2, 2000);
		listDeleteTest(2, 5000);
		listDeleteTest(2, 8000);
		listDeleteTest(2, 10000);
		listDeleteTest(2, 16000);
		listDeleteTest(2, 20000);
		listDeleteTest(2, 25000);
		break;
	case 6:
		listDeleteTest(3, 1000);
		listDeleteTest(3, 2000);
		listDeleteTest(3, 5000);
		listDeleteTest(3, 8000);
		listDeleteTest(3, 10000);
		listDeleteTest(3, 16000);
		listDeleteTest(3, 20000);
		listDeleteTest(3, 25000);
		break;
	case 7:
		listSearchTest(1000);
		listSearchTest(2000);
		listSearchTest(5000);
		listSearchTest(8000);
		listSearchTest(10000);
		listSearchTest(16000);
		listSearchTest(20000);
		listSearchTest(25000);
		break;
	case 8:
		return;
	}
}

void Tester::heapTestMenu()
{
	system("cls");
	cout << "Jaka operacje chcesz sprawdzic?" << endl;
	cout << "1. Dodawanie do kopca" << endl;
	cout << "2. Usuwanie z kopca" << endl;
	cout << "3. Wyszukiwanie w kopcu" << endl;
	cout << "4. Wroc do menu" << endl;
	int choice;
	cin >> choice;
	switch (choice) {
	case 1:
		heapAddTest(1000);
		heapAddTest(2000);
		heapAddTest(5000);
		heapAddTest(8000);
		heapAddTest(10000);
		heapAddTest(16000);
		heapAddTest(20000);
		heapAddTest(25000);
		break;
	case 2:
		heapDeleteTest(1000);
		heapDeleteTest(2000);
		heapDeleteTest(5000);
		heapDeleteTest(8000);
		heapDeleteTest(10000);
		heapDeleteTest(16000);
		heapDeleteTest(20000);
		heapDeleteTest(25000);
		break;
	case 3:
		heapSearchTest(1000);
		heapSearchTest(2000);
		heapSearchTest(5000);
		heapSearchTest(8000);
		heapSearchTest(10000);
		heapSearchTest(16000);
		heapSearchTest(20000);
		heapSearchTest(25000);
		break;
	case 4:
		return;
	}
}

void Tester::treeTestMenu()
{
	system("cls");
	cout << "Jaka operacje chcesz sprawdzic?" << endl;
	cout << "1. Dodawanie do drzewa" << endl;
	cout << "2. Usuwanie z drzewa" << endl;
	cout << "3. Wyszukiwanie w drzewie" << endl;
	cout << "4. Wroc do menu" << endl;
	int choice;
	cin >> choice;
	switch (choice) {
	case 1:
		treeAddTest(1000);
		treeAddTest(2000);
		treeAddTest(5000);
		treeAddTest(8000);
		treeAddTest(10000);
		treeAddTest(16000);
		treeAddTest(20000);
		treeAddTest(25000);
		break;
	case 2:
		treeDeleteTest(1000);
		treeDeleteTest(2000);
		treeDeleteTest(5000);
		treeDeleteTest(8000);
		treeDeleteTest(10000);
		treeDeleteTest(16000);
		treeDeleteTest(20000);
		treeDeleteTest(25000);
		break;
	case 3:
		treeSearchTest(1000);
		treeSearchTest(2000);
		treeSearchTest(5000);
		treeSearchTest(8000);
		treeSearchTest(10000);
		treeSearchTest(16000);
		treeSearchTest(20000);
		treeSearchTest(25000);
		break;
	case 4:
		return;
	}
}

void Tester::arrayTestMenu()
{
	system("cls");
	cout << "Jaka operacje chcesz sprawdzic?" << endl;
	cout << "1. Dodawanie na poczatek tablicy" << endl;
	cout << "2. Dodawanie na koniec tablicy" << endl;
	cout << "3. Dodawanie do tablicy" << endl;
	cout << "4. Usuwanie z poczatku tablicy" << endl;
	cout << "5. Usuwanie z konca tablicy" << endl;
	cout << "6. Usuwanie z tablicy" << endl;
	cout << "7. Wyszukiwanie w tablicy" << endl;
	cout << "8. Wroc do menu" << endl << endl;
	int choice;
	cin >> choice;
	switch (choice) {
	case 1:
		arrayAddTest(1, 1000);
		arrayAddTest(1, 2000);
		arrayAddTest(1, 5000);
		arrayAddTest(1, 8000);
		arrayAddTest(1, 10000);
		arrayAddTest(1, 16000);
		arrayAddTest(1, 20000);
		arrayAddTest(1, 25000);
		break;
	case 2:
		arrayAddTest(2, 1000);
		arrayAddTest(2, 2000);
		arrayAddTest(2, 5000);
		arrayAddTest(2, 8000);
		arrayAddTest(2, 10000);
		arrayAddTest(2, 16000);
		arrayAddTest(2, 20000);
		arrayAddTest(2, 25000);
		break;
	case 3:
		arrayAddTest(3, 1000);
		arrayAddTest(3, 2000);
		arrayAddTest(3, 5000);
		arrayAddTest(3, 8000);
		arrayAddTest(3, 10000);
		arrayAddTest(3, 16000);
		arrayAddTest(3, 20000);
		arrayAddTest(3, 25000);
		break;
	case 4:
		arrayDeleteTest(1, 1000);
		arrayDeleteTest(1, 2000);
		arrayDeleteTest(1, 5000);
		arrayDeleteTest(1, 8000);
		arrayDeleteTest(1, 10000);
		arrayDeleteTest(1, 16000);
		arrayDeleteTest(1, 20000);
		arrayDeleteTest(1, 25000);
		break;
	case 5:
		arrayDeleteTest(2, 1000);
		arrayDeleteTest(2, 2000);
		arrayDeleteTest(2, 5000);
		arrayDeleteTest(2, 8000);
		arrayDeleteTest(2, 10000);
		arrayDeleteTest(2, 16000);
		arrayDeleteTest(2, 20000);
		arrayDeleteTest(2, 25000);
		break;
	case 6:
		arrayDeleteTest(3, 1000);
		arrayDeleteTest(3, 2000);
		arrayDeleteTest(3, 5000);
		arrayDeleteTest(3, 8000);
		arrayDeleteTest(3, 10000);
		arrayDeleteTest(3, 16000);
		arrayDeleteTest(3, 20000);
		arrayDeleteTest(3, 25000);
		break;
	case 7:
		arraySearchTest(1000);
		arraySearchTest(2000);
		arraySearchTest(5000);
		arraySearchTest(8000);
		arraySearchTest(10000);
		arraySearchTest(16000);
		arraySearchTest(20000);
		arraySearchTest(25000);
		break;
	case 8:
		return;
	}
}

void Tester::arrayAddTest(int option, int number)
{
	ofstream file;
	//int number = chooseNumber();
	if (option == 1) file.open("tablicaAddStart" + to_string(number) + ".txt");
	else if (option == 2) file.open("tablicaAddKoniec" + to_string(number) + ".txt");
	else if (option == 3) file.open("tablicaAdd" + to_string(number) + ".txt");
	srand(time(NULL));
	if (option == 1) {
		for (int i = 0; i < 100; i++) {
			dynamicArray = new MyDynamicArray;
			dynamicArray->createRandom(number);
			clock.start();
			for (int i = 0; i < 200; i++) {
				int random = rand() % INT_MAX + (-INT_MAX);
				dynamicArray->pushFront(random);
			}
			clock.stop();
			clock.printToFile(file);
			delete dynamicArray;
		}
	}
	else if (option == 2) {
		for (int i = 0; i < 100; i++) {
			dynamicArray = new MyDynamicArray;
			dynamicArray->createRandom(number);
			clock.start();
			for (int i = 0; i < 200; i++) {
				int random = rand() % INT_MAX + (-INT_MAX);
				dynamicArray->pushBack(random);
			}
			clock.stop();
			clock.printToFile(file);
			delete dynamicArray;
		}
	}
	else if (option == 3) {
		int random;
		int index;
		for (int i = 0; i < 100; i++) {
			dynamicArray = new MyDynamicArray;
			dynamicArray->createRandom(number);
			clock.start();
			for (int i = 0; i < 200; i++) {
				random = rand() % INT_MAX + (-INT_MAX);
				index = rand() % number;
				dynamicArray->addAtIndex(random, index);
			}
			clock.stop();
			clock.printToFile(file);
			delete dynamicArray;
		}
	}
	file.close();
}

void Tester::arrayDeleteTest(int option, int number)
{
	ofstream file;
	//int number = chooseNumber();
	if (option == 1) file.open("tablicaDeleteStart" + to_string(number) + ".txt");
	else if (option == 2) file.open("tablicaDeleteKoniec" + to_string(number) + ".txt");
	else if (option == 3) file.open("tablicaDelete" + to_string(number) + ".txt");
	srand(time(NULL));
	if (option == 1) {
		for (int i = 0; i < 100; i++) {
			dynamicArray = new MyDynamicArray;
			dynamicArray->createRandom(number);
			clock.start();
			for (int i = 0; i < 200; i++) {
				dynamicArray->popFront();
			}
			clock.stop();
			clock.printToFile(file);
			delete dynamicArray;
		}
	}
	else if (option == 2) {
		for (int i = 0; i < 100; i++) {
			dynamicArray = new MyDynamicArray;
			dynamicArray->createRandom(number);
			clock.start();
			for (int i = 0; i < 200; i++) {
				dynamicArray->popBack();
			}
			clock.stop();
			clock.printToFile(file);
			delete dynamicArray;
		}
	}
	else if (option == 3) {
		for (int i = 0; i < 100; i++) {
			dynamicArray = new MyDynamicArray;
			dynamicArray->createRandom(number);
			clock.start();
			for (int i = 0; i < 200; i++) {
				int index = rand() % dynamicArray->getSize();
				dynamicArray->deleteAtIndex(index);
			}
			clock.stop();
			clock.printToFile(file);
			delete dynamicArray;
		}
	}
	file.close();
}

void Tester::arraySearchTest(int number)
{
	//int number = chooseNumber();
	ofstream file;
	int random;
	int i = 0;
	file.open("arraySearch" + to_string(number) + ".txt");
	srand(time(NULL));
	for (int i = 0; i < 100; i++) {
		dynamicArray = new MyDynamicArray;
		dynamicArray->createRandom(number);
		clock.start();
		for (int i = 0; i < 200; i++) {
			random = rand() % INT_MAX + (-INT_MAX);
			if (dynamicArray->findElement(random)) i++;
		}
		clock.stop();
		clock.printToFile(file);
		delete dynamicArray;
	}
	file.close();
}

void Tester::listAddTest(int option, int number)
{
	//int number = chooseNumber();
	ofstream file;
	if (option == 1) file.open("listaAddStart" + to_string(number) + ".txt");
	else if (option == 2) file.open("listaAddKoniec" + to_string(number) + ".txt");
	else if (option == 3) file.open("listaAdd" + to_string(number) + ".txt");
	srand(time(NULL));
	if (option == 1) {
		for (int i = 0; i < 100; i++) {
			linkedList = new MyDoubleLinkedList;
			linkedList->createRandom(number);
			clock.start();
			for (int i = 0; i < 200; i++) {
				int random = rand() % INT_MAX + (-INT_MAX);
				linkedList->pushFront(random);
			}
			clock.stop();
			clock.printToFile(file);
			delete linkedList;
		}
	}
	else if (option == 2) {
		for (int i = 0; i < 100; i++) {
			linkedList = new MyDoubleLinkedList;
			linkedList->createRandom(number);
			clock.start();
			for (int i = 0; i < 200; i++) {
				int random = rand() % INT_MAX + (-INT_MAX);
				linkedList->pushBack(number);
			}
			clock.stop();
			clock.printToFile(file);
			delete linkedList;
		}
	}
	else if (option == 3) {
		for (int i = 0; i < 100; i++) {
			linkedList = new MyDoubleLinkedList;
			linkedList->createRandom(number);
			clock.start();
			for (int i = 0; i < 200; i++) {
				int random = rand() % INT_MAX + (-INT_MAX);
				int index = rand() % linkedList->getSize();
				linkedList->addAtIndex(random, index);
			}
			clock.stop();
			clock.printToFile(file);
			delete linkedList;
		}
	}
	file.close();
}

void Tester::listDeleteTest(int option, int number)
{
	//int number = chooseNumber();
	ofstream file;
	if (option == 1) file.open("listaDeleteStart" + to_string(number) + ".txt");
	else if (option == 2) file.open("listaDeleteKoniec" + to_string(number) + ".txt");
	else if (option == 3) file.open("listaDelete" + to_string(number) + ".txt");
	srand(time(NULL));
	if (option == 1) {
		for (int i = 0; i < 100; i++) {
			linkedList = new MyDoubleLinkedList;
			linkedList->createRandom(number);
			clock.start();
			for (int i = 0; i < 200; i++) {
				int random = rand() % 50000 - 25000;
				linkedList->popFront();
			}
			clock.stop();
			clock.printToFile(file);
			delete linkedList;
		}
	}
	else if (option == 2) {
		for (int i = 0; i < 100; i++) {
			linkedList = new MyDoubleLinkedList;
			linkedList->createRandom(number);
			clock.start();
			for (int i = 0; i < 200; i++) {
				int random = rand() % 50000 - 25000;
				linkedList->popBack();
			}
			clock.stop();
			clock.printToFile(file);
			delete linkedList;
		}
	}
	else if (option == 3) {
		for (int i = 0; i < 100; i++) {
			linkedList = new MyDoubleLinkedList;
			linkedList->createRandom(number);
			clock.start();
			for (int i = 0; i < 200; i++) {
				int value = rand() % INT_MAX + (-INT_MAX);
				linkedList->deleteValue(value);
			}
			clock.stop();
			clock.printToFile(file);
			delete linkedList;
		}
	}
	file.close();
}

void Tester::listSearchTest(int number)
{
	//int number = chooseNumber();
	ofstream file;
	int i;
	file.open("listSearch" + to_string(number) + ".txt");
	srand(time(NULL));
	for (int i = 0; i < 100; i++) {
		linkedList = new MyDoubleLinkedList;
		linkedList->createRandom(number);
		clock.start();
		for (int i = 0; i < 200; i++) {
			int random = rand() % INT_MAX + (-INT_MAX);
			if (linkedList->findElement(random)) i++;
		}
		clock.stop();
		clock.printToFile(file);
		delete linkedList;
	}
	file.close();

}

void Tester::treeAddTest(int number)
{
	//int number = chooseNumber();
	ofstream file;
	file.open("treeAdd" + to_string(number) + ".txt");
	srand(time(NULL));
	for (int i = 0; i < 100; i++) {
		tree = new MyBSTree;
		tree->createRandom(number);
		clock.start();
		for (int i = 0; i < 200; i++) {
			int value = rand() % INT_MAX + (-INT_MAX);
			tree->insertNode(value);
			tree->createLinearTree();
			tree->createBalancedTree();
		}
		clock.stop();
		clock.printToFile(file);
		delete tree;
	}
	file.close();
}

void Tester::treeDeleteTest(int number)
{
	//int number = chooseNumber();
	ofstream file;
	file.open("treeDelete" + to_string(number) + ".txt");
	srand(time(NULL));
	for (int i = 0; i < 100; i++) {
		tree = new MyBSTree;
		tree->createRandom(number);
		clock.start();
		for (int i = 0; i < 200; i++) {
			int value = rand() % INT_MAX + (-INT_MAX);
			tree->deleteKey(value);
			tree->createLinearTree();
			tree->createBalancedTree();
		}
		clock.stop();
		clock.printToFile(file);
		delete tree;
	}
	file.close();
}

void Tester::treeSearchTest(int number)
{
	//int number = chooseNumber();
	ofstream file;
	int i = 0;
	file.open("treeSearch" + to_string(number) + ".txt");
	srand(time(NULL));
	for (int i = 0; i < 100; i++) {
		tree = new MyBSTree;
		tree->createRandom(number);
		clock.start();
		for (int i = 0; i < 200; i++) {
			int value = rand() % INT_MAX + (-INT_MAX);
			if (tree->findElement(value)) i++;
		}
		clock.stop();
		clock.printToFile(file);
		delete tree;
	}
	file.close();
}

void Tester::heapAddTest(int number)
{
	//int number = chooseNumber();
	ofstream file;
	file.open("heapAdd" + to_string(number) + ".txt");
	srand(time(NULL));
	for (int i = 0; i < 100; i++) {
		heap = new MyHeap;
		heap->createRandom(number);
		clock.start();
		for (int i = 0; i < 200; i++) {
			int value = rand() % INT_MAX + (-INT_MAX);
			heap->push(value);
		}
		clock.stop();
		clock.printToFile(file);
		delete heap;
	}
	file.close();
}

void Tester::heapDeleteTest(int number)
{
	//int number = chooseNumber();
	ofstream file;
	file.open("heapDelete" + to_string(number) + ".txt");
	srand(time(NULL));
	for (int i = 0; i < 100; i++) {
		heap = new MyHeap;
		heap->createRandom(number);
		clock.start();
		for (int i = 0; i < 200; i++) {
			int value = rand() % INT_MAX + (-INT_MAX);
			heap->pop(value);
		}
		clock.stop();
		clock.printToFile(file);
		delete heap;
	}
	file.close();
}

void Tester::heapSearchTest(int number)
{
	//int number = chooseNumber();
	ofstream file;
	file.open("heapSearch" + to_string(number) + ".txt");
	srand(time(NULL));
	for (int i = 0; i < 100; i++) {
		heap = new MyHeap;
		heap->createRandom(number);
		clock.start();
		for (int i = 0; i < 200; i++) {
			int value = rand() % INT_MAX + (-INT_MAX);
			if (heap->findElement(value)) i++;
		}
		clock.stop();
		clock.printToFile(file);
		delete heap;
	}
	file.close();
}

int Tester::chooseNumber()
{
	cout << endl << endl;
	cout << "Wybierz liczbe elementow w strkturze" << endl;
	cout << "1. 1000" << endl;
	cout << "2. 2000" << endl;
	cout << "3. 5000" << endl;
	cout << "4. 8000" << endl;
	cout << "5. 10000" << endl;
	cout << "6. 16000" << endl;
	cout << "7. 20000" << endl;
	cout << "8. 250000" << endl;
	int number;
	cin >> number;
	switch (number) {
	case 1:
		return 1000;
		break;
	case 2:
		return 2000;
		break;
	case 3:
		return 5000;
		break;
	case 4:
		return 8000;
		break;
	case 5:
		return 10000;
		break;
	case 6:
		return 16000;
		break;
	case 7:
		return 20000;
		break;
	case 8:
		return 25000;
		break;
	}

}

void Tester::testMenu()
{
	bool running = true;
	while (running) {
		system("cls");
		cout << "Wybierz strukture ktora chcesz testowac";
		cout << endl;
		cout << "1. Tablica" << endl;
		cout << "2. Lista dwukierunkowa" << endl;
		cout << "3. Kopiec" << endl;
		cout << "4. Drzewo BST" << endl;
		cout << "5. Wyjdz" << endl;
		int choice1;
		cin >> choice1;
		switch (choice1) {
		case 1:
			arrayTestMenu();
			break;
		case 2:
			linkedListTestMenu();
			break;
		case 3:
			heapTestMenu();
			break;
		case 4:
			treeTestMenu();
			break;
		case 5:
			running = false;
			break;
		}
	}
}
