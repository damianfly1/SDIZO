#include "MyDynamicArray.h"

void MyDynamicArray::createRandom(int size1)
{
	arrayFirst = new int[size1];
	this->size = size1;
	srand(time(NULL));
	for (int i = 0; i < size; i++) {
		arrayFirst[i] = rand() % INT_MAX + (-INT_MAX);
	}
}

MyDynamicArray::~MyDynamicArray()
{
	delete[] arrayFirst;
	arrayFirst = NULL;
}

bool MyDynamicArray::createFromFile()
{
	system("cls");
	cout << "Podaj nazwe pliku z ktorego mamy zczytac dane (z rozszerzeniem)" << endl;
	string filename;
	cin >> filename;
	fstream myfile;
	myfile.open(filename, ios::in);
	if (myfile.is_open()) {
		string tmp;
		getline(myfile, tmp);
		size = stoi(tmp);
		arrayFirst = new int[size];
		int licznik = 0;
		while (getline(myfile, tmp)) {
			if (tmp.length() == 0) break;
			*(arrayFirst + licznik) = stoi(tmp);
			licznik++;
		}
		myfile.close();
		return true;
	}
	else return false;
}

bool MyDynamicArray::generateRandom()
{
	system("cls");
	cout << "Podaj rozmiar tablicy";
	cin >> size;
	if (size == 0) {
		return true;
	}
	else if (size > 0) {
		arrayFirst = new int[size];
		srand(time(NULL));
		for (int i = 0; i < size; i++) {
			arrayFirst[i] = rand() % 2000 - 1000;
		}
		return true;
	}
	else {
		return false;
	}
}

bool MyDynamicArray::empty()
{
	if (size) return false;
	else return true;
}

int MyDynamicArray::getSize()
{
	return (size);
}

void MyDynamicArray::showAll()
{
	for (int i = 0; i < size; i++) {
		cout << arrayFirst[i] << " ";
	}
}

void MyDynamicArray::pushFront(int value)
{
	if (size) {
		//tworzymy nowa tablice z rozmiarem o jeden wiekszym
		int* new_array = new int[size + 1];
		memcpy(new_array + 1, arrayFirst, size * sizeof(int)); //przenosimy obecne wartosci do nowej tablicy
		*new_array = value; //wstawiamy nowy element
		delete[] arrayFirst; //usuwamy stara tablice
		arrayFirst = new_array; //zamieniamy wskazniki
		new_array = NULL;
		++size;
	}
	else { //jesli tablica byla pusta
		++size;
		arrayFirst = new int[size];
		*arrayFirst = value;
	}

}

void MyDynamicArray::pushBack(int value)
{
	int* new_array = new int[size + 1]; //tworze nowa tablice z rozmiarem o jeden wiekszym
	memcpy(new_array, arrayFirst, size * sizeof(int)); //przenosimy obecne wartosci do nowej tablicy
	*(new_array + size) = value; //dodajemy nowa wartosc
	delete[] arrayFirst; //usuwamy stara tablice
	arrayFirst = new_array;
	new_array = NULL;
	++size;
}

void MyDynamicArray::popFront()
{
	if (size > 1) { //jesli jest wiecej niz jeden element
		int* new_array = new int[size - 1]; //tworzymy nowa mniejsza tablice
		memcpy(new_array, arrayFirst + 1, (size - 1) * sizeof(int)); //przenosimy wartosci oprocz pierwszej
		delete[] arrayFirst; //usuwamy stara tablice
		arrayFirst = new_array;
		new_array = NULL;
		--size;
	}
	else {
		delete[] arrayFirst; //jesli element byl jeden to zwalniamy pamiec
		arrayFirst = NULL;
		--size;
	}
}

void MyDynamicArray::popBack()
{
	int* new_array = new int[size - 1]; //tworzymy nowa mniejsza tablice
	memcpy(new_array, arrayFirst, (size - 1) * sizeof(int)); //przenosimy wartosci oprocz ostatniej
	delete[] arrayFirst; //usuwamy stara tablice
	arrayFirst = new_array;
	new_array = NULL;
	--size;
}

void MyDynamicArray::addAtIndex(int value, int index)
{
	if (index == 0) { //jesli index zero dodajemy przod
		pushFront(value);
	}
	else if (index == size) { //jesli ostatni index dodajemy tyl
		pushBack(value);
	}
	else { //inaczej tworzymy tablice z rozmiarem o jeden wieksza, rozsuwamy tablice, wstawiamy element i uswamy stara tablice
		int* new_array = new int[size + 1];
		new_array[index] = value;
		memcpy(new_array, arrayFirst, (index) * sizeof(int));
		memcpy(new_array + index + 1, arrayFirst + index, size * sizeof(int) - index * sizeof(int));
		delete[] arrayFirst;
		arrayFirst = new_array;
		new_array = NULL;
		++size;
	}
}

bool MyDynamicArray::findElement(int element)
{
	for (int i = 0; i < size; i++) { //iterujemy po kolejnych indeksach
		if (arrayFirst[i] == element) {
			//cout << "Znalazlem element!";
			return true;
		}
	}
	//cout << endl << "Nie znalazlem elementu!" << endl;
	return false;
}

void MyDynamicArray::deleteAtIndex(int index)
{
	if (index == 0) { //jesli index zero usuwamy przod
		popFront();
	}
	else if (index == size - 1) { //jesli index ostatni usuwamy tyl
		popBack();
	}
	else { //inaczej tworzymy tablice z rozmiarem o jeden mniejszym i kopiujemy wszystkie elementy oprocz wybranego, po czym zwalniamy pamiec
		int* new_array = new int[size - 1];
		memcpy(new_array, arrayFirst, (index) * sizeof(int));
		memcpy(new_array + index, arrayFirst + index + 1, (size - 1) * sizeof(int) - index * sizeof(int));// wazne zeby uzyc size-1
		delete[] arrayFirst;
		arrayFirst = new_array;
		new_array = NULL;
		--size;
	}
}
