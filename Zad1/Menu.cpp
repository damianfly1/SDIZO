#include "Menu.h"

void Menu::chooseStructure()
{
	boolean running = true;
	while (running) {
		cout << "Witaj w zadaniu projektowym nr 1!" << endl << endl;
		cout << "Wybierz strukture danych... " << endl << endl;
		cout << "1. Tablica" << endl;
		cout << "2. Lista dwukierunkowa" << endl;
		cout << "3. Kopiec binarny" << endl;
		cout << "4. Drzewo BST" << endl;
		cout << "5. Testuj" << endl;
		cout << "6. Wyjdz z programu" << endl;
		int choice;
		cin >> choice;
		switch (choice) {
		case 1:
			arrayMenu();
			break;
		case 2:
			doubleLinkedListMenu();
			break;
		case 3:
			heapMenu();
			break;
		case 4:
			treeMenu();
			break;
		case 5:
		{Tester tester = Tester();
		tester.testMenu(); }
		break;
		case 6:
			running = false;
			break;
		}
	}

}

void Menu::treeMenu()
{
	boolean running = true;
	while (running) {
		system("cls");
		cout << "Wybierz operacje ktora chcesz preprowadzic na drzewie" << endl << endl;
		cout << "1. Zbuduj z pliku" << endl;
		cout << "2. Usun wartosc" << endl;
		cout << "3. Dodaj element" << endl;
		cout << "4. Znajdz element" << endl;
		cout << "5. Utworz losowo" << endl;
		cout << "6. Wyswietl drzewo" << endl;
		cout << "7. Rownowazenie drzewa" << endl;
		cout << "8. Wroc do menu glownego" << endl;
		int choice;
		cin >> choice;
		switch (choice) {
		case 1:
			if (tree != NULL) {
				delete tree;
				tree = NULL;
			}
			tree = new MyBSTree();
			if (tree->createFromFile()) {
				tree->showAll();
				waitingScreen();
			}
			else {
				delete tree;
				tree = NULL;
				cout << "Nie udalo sie otworzyc pliku";
				waitingScreen();
			}
			break;
		case 2:
			if (tree) {
				if (tree->empty()) {
					cout << endl << "Drzewo jest puste";
					waitingScreen();
					break;
				}
				else {
					cout << "Podaj wartosc jaka chcesz usunac" << endl;
					int value;
					cin >> value;
					clock.start();
					tree->deleteKey(value); // kod ktorego czas wykonania mierzymy
					clock.stop();
					clock.printResult();
					if (tree->empty()) cout << endl << "Drzewo jest puste";
					else tree->showAll();
					waitingScreen();
					break;
				}
			}
			else {
				cout << "Brak stworzonego drzewa";
				waitingScreen();
			}
			break;
		case 3:
			if (tree) {
				cout << "Podaj liczbe ktora chcesz wstawic" << endl;
				int number;
				cin >> number;
				if (tree->findElement(number)) {
					cout << "Element juz w drzewie";
					waitingScreen();
					break;
				}
				else {
					clock.start();
					tree->insertNode(number);
					clock.stop();
					clock.printResult();
					tree->showAll();
					waitingScreen();
				}
			}
			else {
				cout << "Brak stworzonego drzewa";
				waitingScreen();
			}
			break;
		case 4:
			if (tree) {
				if (tree->empty()) {
					cout << "Drzewo jest puste";
					waitingScreen();
					break;
				}
				cout << "Podaj element jaki chcesz znalezc";
				int number;
				cin >> number;
				clock.start();
				if (tree->findElement(number)) cout << "Element znajduje sie w kopcu";
				else cout << "Elementu nie ma w kopcu";
				clock.stop();
				clock.printResult();
				tree->showAll();
				waitingScreen();
			}
			else {
				cout << "Brak stworzonego kopca";
				waitingScreen();
			}
			break;
		case 5:
			if (tree != NULL) {
				delete tree;
				tree = NULL;
			}
			tree = new MyBSTree();
			if (tree->createRandom()) {
				if (!tree->empty()) tree->showAll();
				else cout << "Drzewo jest puste";
				waitingScreen();
			}
			else {
				delete tree;
				cout << "Niedozwolna wartosc indeku" << endl;
				waitingScreen();
			}
			break;
		case 6:
			if (tree) {
				if (tree->empty()) cout << "Drzewo jest puste";
				else {
					system("cls");
					tree->showAll();
				}
				waitingScreen();
			}
			else {
				cout << "Brak stworzonego drzewa";
				waitingScreen();
			}
			break;
		case 7:
			if (tree) {
				if (tree->empty()) cout << "Drzewo jest puste";
				else {
					system("cls");
					clock.start();
					tree->createLinearTree();
					clock.stop();
					clock.printResult();
					tree->showAll();
					cout << endl << endl << "Wprowadz jeden aby przejsc do nastepnego etapu algorytmu" << endl << endl;
					int choice;
					cin >> choice;
					clock.start();
					tree->createBalancedTree();
					clock.stop();
					clock.printResult();
					tree->showAll();
				}
				waitingScreen();
			}
			else {
				cout << "Brak stworzonego drzewa";
				waitingScreen();
			}
			break;
		case 8:
			system("cls");
			if (tree != NULL) {
				delete tree;
				tree = NULL;
			}
			running = false;
			break;
		}
	}
}

void Menu::arrayMenu()
{
	boolean running = true;
	while (running)
	{
		system("cls");
		cout << "Wybierz operacje ktora chcesz preprowadzic na tablicy" << endl << endl;
		cout << "1. Zbuduj z pliku" << endl;
		cout << "2. Usun element" << endl;
		cout << "3. Dodaj element" << endl;
		cout << "4. Znajdz element" << endl;
		cout << "5. Utworz losowo" << endl;
		cout << "6. Wyswietl tablice" << endl;
		cout << "7. Wroc do menu glownego" << endl;
		int choice;
		cin >> choice;
		switch (choice) {
		case 1:
			if (dynamicArray != NULL) {
				delete dynamicArray;
				dynamicArray = NULL;
			}
			dynamicArray = new MyDynamicArray();
			if (dynamicArray->createFromFile()) {
				dynamicArray->showAll();
				waitingScreen();
			}
			else {
				delete dynamicArray;
				dynamicArray = NULL;
				cout << "Nie udalo sie otworzyc pliku";
				waitingScreen();
			}
			break;
		case 2:
			if (dynamicArray) {
				if (dynamicArray == 0) {
					cout << endl << "Tablica jest pusta";
					waitingScreen();
				}
				else {
					cout << "Podaj indeks elementu" << endl;
					int index;
					cin >> index;
					if (dynamicArray->getSize() - 1 < index || index < 0) {
						system("cls");
						cout << "Niedozwolona wartosc indeksu";
						waitingScreen();
						break;
					}
					clock.start();
					dynamicArray->deleteAtIndex(index); // kod ktorego czas wykonania mierzymy
					clock.stop();
					clock.printResult();
					if (dynamicArray->empty()) cout << endl << "Tablica jest pusta";
					else dynamicArray->showAll();
					waitingScreen();
				}

			}
			else {
				cout << "Brak stworzonej tablicy";
				waitingScreen();
			}
			break;
		case 3:
			if (dynamicArray) {
				cout << "Podaj liczbe ktora chcesz wstawic" << endl;
				int number;
				cin >> number;
				cout << "Podaj indeks w ktorym chcesz wstawic liczbe" << endl;
				int index;
				cin >> index;
				if (dynamicArray->getSize() < index || index < 0) {
					system("cls");
					cout << "Niedozwolona wartosc indeksu";
					waitingScreen();
					break;
				}
				clock.start();
				dynamicArray->addAtIndex(number, index);
				clock.stop();
				clock.printResult();
				dynamicArray->showAll();
				waitingScreen();
			}
			else {
				cout << "Brak stworzonej tablicy";
				waitingScreen();
			}
			break;
		case 4:
			if (dynamicArray) {
				if (dynamicArray->empty()) {
					cout << endl << "Tablica jest pusta";
					waitingScreen();
					break;
				}
				else {
					cout << "Podaj element jaki chcesz znalezc";
					int number;
					cin >> number;
					clock.start();
					if (dynamicArray->findElement(number)) cout << "Element znajduje sie w tablicy";
					else cout << "Elementu nie ma w tablicy" << endl;
					clock.stop();
					clock.printResult();
					dynamicArray->showAll();
					waitingScreen();
				}

			}
			else {
				cout << "Brak stworzonej tablicy";
				waitingScreen();
			}
			break;
		case 5:
			if (dynamicArray != NULL) {
				delete dynamicArray;
				dynamicArray = NULL;
			}
			dynamicArray = new MyDynamicArray();
			if (dynamicArray->generateRandom()) {
				if (!dynamicArray->empty()) dynamicArray->showAll();
				else cout << "Tablica jest puste";
				waitingScreen();
			}
			else {
				delete dynamicArray;
				dynamicArray = NULL;
				cout << "Zla wartosc indeksu";
				waitingScreen();
			}
			break;
		case 6:
			if (dynamicArray) {
				if (dynamicArray->empty()) cout << endl << "Tablica jest pusta";
				else dynamicArray->showAll();
				waitingScreen();
			}
			else {
				cout << "Brak stworzonej tablicy";
				waitingScreen();
			}
			break;
		case 7:
			if (dynamicArray != NULL) {
				delete dynamicArray;
				dynamicArray = NULL;
			}
			running = false;
			system("cls");
			break;
		}
	}

}

void Menu::doubleLinkedListMenu()
{
	boolean running = true;
	while (running) {
		system("cls");
		cout << "Wybierz operacje ktora chcesz preprowadzic na liscie" << endl << endl;
		cout << "1. Zbuduj z pliku" << endl;
		cout << "2. Usun wartosc" << endl;
		cout << "3. Dodaj element" << endl;
		cout << "4. Znajdz element" << endl;
		cout << "5. Utworz losowo" << endl;
		cout << "6. Wyswietl liste" << endl;
		cout << "7. Wroc do menu glownego" << endl;
		int choice;
		cin >> choice;
		switch (choice) {
		case 1:
			if (doubleLinkedList != NULL) {
				delete doubleLinkedList;
				doubleLinkedList = NULL;
			}
			doubleLinkedList = new MyDoubleLinkedList();
			if (doubleLinkedList->createFromFile()) {
				doubleLinkedList->showAll();
				waitingScreen();
			}
			else {
				delete doubleLinkedList;
				doubleLinkedList = NULL;
				cout << "Nie udalo sie otworzyc pliku";
				waitingScreen();
			}
			break;
		case 2:
			if (doubleLinkedList) {
				if (doubleLinkedList->empty()) {
					cout << endl << "Lista jest pusta";
					waitingScreen();
					break;
				}
				else {
					cout << "Podaj wartosc jaka chcesz usunac" << endl;
					int value;
					cin >> value;
					clock.start();
					doubleLinkedList->deleteValue(value); // kod ktorego czas wykonania mierzymy
					clock.stop();
					clock.printResult();
					if (doubleLinkedList->empty()) cout << endl << "Lista jest pusta";
					else doubleLinkedList->showAll();
					waitingScreen();
					break;
				}
			}
			else {
				cout << "Brak stworzonej listy";
				waitingScreen();
			}
			break;
		case 3:
			if (doubleLinkedList) {
				cout << "Podaj liczbe ktora chcesz wstawic" << endl;
				int number;
				cin >> number;
				cout << "Podaj indeks w ktorym chcesz wstawic liczbe" << endl;
				int index;
				cin >> index;
				if (doubleLinkedList->getSize() < index || index < 0) {
					system("cls");
					cout << "Niedozwolona wartosc indeksu";
					waitingScreen();
				}
				else {
					clock.start();
					doubleLinkedList->addAtIndex(number, index);
					clock.stop();
					clock.printResult();
					doubleLinkedList->showAll();
					waitingScreen();
				}
			}
			else {
				cout << "Brak stworzonej listy";
				waitingScreen();
			}
			break;
		case 4:
			if (doubleLinkedList) {
				if (doubleLinkedList->empty()) {
					cout << "Lista jest pusta";
					waitingScreen();
					break;
				}
				cout << "Podaj element jaki chcesz znalezc";
				int number;
				cin >> number;
				clock.start();
				if (doubleLinkedList->findElement(number)) cout << "Element znajduje sie w liscie";
				else cout << "Elementu nie ma w liscie";
				clock.stop();
				clock.printResult();
				doubleLinkedList->showAll();
				waitingScreen();
			}
			else {
				cout << "Brak stworzonej listy";
				waitingScreen();
			}
			break;
		case 5:
			if (doubleLinkedList != NULL) {
				delete doubleLinkedList;
				doubleLinkedList = NULL;
			}
			doubleLinkedList = new MyDoubleLinkedList();
			if (doubleLinkedList->generateRandom()) {
				if (!doubleLinkedList->empty()) doubleLinkedList->showAll();
				else cout << "Lista jest puste";
				waitingScreen();
			}
			else {
				delete doubleLinkedList;
				doubleLinkedList = NULL;
				cout << "Zla wartosc indeksu";
				waitingScreen();
			}
			break;
		case 6:
			if (doubleLinkedList) {
				if (doubleLinkedList->empty()) cout << "Lista jest pusta";
				else doubleLinkedList->showAll();
				waitingScreen();
			}
			else {
				cout << "Brak stworzonej listy";
				waitingScreen();
			}
			break;
		case 7:
			system("cls");
			if (doubleLinkedList != NULL) {
				delete doubleLinkedList;
				doubleLinkedList = NULL;
			}
			running = false;
			break;
		}
	}
}

void Menu::heapMenu()
{
	boolean running = true;
	while (running) {
		system("cls");
		cout << "Wybierz operacje ktora chcesz preprowadzic na kopcu" << endl << endl;
		cout << "1. Zbuduj z pliku" << endl;
		cout << "2. Usun wartosc" << endl;
		cout << "3. Dodaj element" << endl;
		cout << "4. Znajdz element" << endl;
		cout << "5. Utworz losowo" << endl;
		cout << "6. Wyswietl kopiec" << endl;
		cout << "7. Wroc do menu glownego" << endl;
		int choice;
		cin >> choice;
		switch (choice) {
		case 1:
			if (heap != NULL) {
				delete heap;
				heap = NULL;
			}
			heap = new MyHeap();
			if (heap->createFromFile()) {
				heap->showAll();
				waitingScreen();
			}
			else {
				delete heap;
				heap = NULL;
				cout << "Nie udalo sie otworzyc pliku";
				waitingScreen();
			}
			break;
		case 2:
			if (heap) {
				if (heap->empty()) {
					cout << endl << "Kopiec jest pusty";
					waitingScreen();
					break;
				}
				else {
					cout << "Podaj wartosc jaka chcesz usunac" << endl;
					int value;
					cin >> value;
					clock.start();
					heap->pop(value); // kod ktorego czas wykonania mierzymy
					clock.stop();
					clock.printResult();
					if (heap->empty()) cout << endl << "Kopiec jest pusty";
					else heap->showAll();
					waitingScreen();
					break;
				}
			}
			else {
				cout << "Brak stworzonego kopca";
				waitingScreen();
			}
			break;
		case 3:
			if (heap) {
				cout << "Podaj liczbe ktora chcesz wstawic" << endl;
				int number;
				cin >> number;
				clock.start();
				heap->push(number);
				clock.stop();
				clock.printResult();
				heap->showAll();
				waitingScreen();
			}
			else {
				cout << "Brak stworzonego kopca";
				waitingScreen();
			}
			break;
		case 4:
			if (heap) {
				if (heap->empty()) {
					cout << "Kopiec jest pusty";
					waitingScreen();
					break;
				}
				cout << "Podaj element jaki chcesz znalezc";
				int number;
				cin >> number;
				clock.start();
				if (heap->findElement(number)) cout << "Element znajduje sie w kopcu";
				else cout << "Elementu nie ma w kopcu";
				clock.stop();
				clock.printResult();
				heap->showAll();
				waitingScreen();
			}
			else {
				cout << "Brak stworzonego kopca";
				waitingScreen();
			}
			break;
		case 5:
			if (heap != NULL) {
				delete heap;
				heap = NULL;
			}
			heap = new MyHeap();
			if (heap->generateRandom()) {
				if (!heap->empty()) heap->showAll();
				else cout << "Kopiec jest pusty";
				waitingScreen();
			}
			else {
				delete heap;
				cout << "Zla wartosc indeksu";
				waitingScreen();
			}
			break;
		case 6:
			if (heap) {
				if (heap->empty()) cout << "Kopiec jest pusty";
				else {
					system("cls");
					heap->showAll();
				}
				waitingScreen();
			}
			else {
				cout << "Brak stworzonego kopca";
				waitingScreen();
			}
			break;
		case 7:
			system("cls");
			if (heap != NULL) {
				delete heap;
				heap = NULL;
			}
			running = false;
			break;
		}
	}
}

void Menu::waitingScreen()
{
	cout << endl << endl << "wprowadz 1 zeby wyjsc";
	int number;
	cin >> number;
}


