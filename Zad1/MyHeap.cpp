#include "MyHeap.h"

MyHeap::~MyHeap()
{
	delete[] tab;
	tab = NULL;
}

void MyHeap::createRandom(int size1)
{
	tabLen = size1 + 100;
	currentSize = size1;
	tab = new int[tabLen] {0};
	srand(time(NULL));
	for (int i = 0; i < currentSize; i++) {
		int random = rand() % INT_MAX + (-INT_MAX);
		*(tab + i) = random;
	}
	heap_create_down();
}

bool MyHeap::createFromFile()
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
		currentSize = stoi(tmp);
		tabLen = currentSize + 10; //tablica jest wieksza o 10 elementow
		tab = new int[tabLen] {0};
		int licznik = 0;
		while (getline(myfile, tmp)) {
			if (tmp.length() == 0) break;
			*(tab + licznik) = stoi(tmp); //zamieniamy string na int
			licznik++;
		}
		myfile.close();
		heap_create_down(); //korzystamy z algorytmu Floyda
		return true;
	}
	else return false;
}

bool MyHeap::generateRandom()
{
	system("cls");
	cout << "Podaj rozmiar kopca";
	cin >> currentSize;
	if (currentSize == 0) {
		tabLen = 0;
		return true;
	}
	else if (currentSize > 0) {
		tabLen = currentSize + 10;
		tab = new int[tabLen] {0};
		srand(time(NULL));
		for (int i = 0; i < currentSize; i++) {
			int random = rand() % 2000 - 1000;
			*(tab + i) = random;
		}
		heap_create_down();
		return true;
	}
	else return false;
}

void MyHeap::heap_create_down() // algorytm Floyda
{
	//zaczynamy prace od ostatniego rodzica i naprawiamy w dol do poczatku tablicy
	for (int i = floor((currentSize - 2) / 2); i >= 0; i--) {
		fixDown(this->tab, i, this->currentSize);
	}
}

void MyHeap::heap_create_up()
{
	//naprawa w gore po kolejnych elementach w tablicy
	for (int i = 1; i < currentSize; ++i) {
		fixUp(this->tab, i);
	}
}

bool MyHeap::empty()
{
	if (currentSize) return false;
	return true;
}

int MyHeap::getSize()
{
	return currentSize;
}

bool MyHeap::findElement(int value)
{
	for (int i = 0; i < currentSize; i++) { //musimy przejrzec wszystkie elementy
		if (tab[i] == value) {
			return true;
		}
	}
	return false;
}

void MyHeap::pop(int key)
{
	int index = -1;
	for (int i = 0; i < currentSize; i++) { //szukamy wezla z wartoscia klucza
		if (tab[i] == key) {
			index = i;
		}
	}
	if (index != -1) { //jesli znalezlismy wezel
		if (currentSize == 1) { //jesli wezel jest korzeniem to kopiec jest pusty
			--currentSize;
			tab[0] = NULL;
		}
		else if (tab[index] == tab[currentSize - 1]) { //jesli usuwany element jest ostatnim lisciem to nie musimy naprawiac kopca
			tab[currentSize - 1] = 0;
			--currentSize;
		}
		else {
			tab[index] = tab[currentSize - 1]; //zamieniamy usuwany wierzcholek z ostatnim elementem 
			tab[currentSize - 1] = 0; //"usuwamy" ostatni element
			--currentSize;
			int parentIndex = (index - 1) / 2; //obliczamy index rodzica
			if (tab[parentIndex] < tab[index]) { //jesli element jest wiekszy od rodzica to naprawiamy kopiec w gore
				fixUp(this->tab, index);
			}
			else { //inaczej naprawiamy kopiec w dol
				fixDown(this->tab, index, this->currentSize); //naprawiamy w dol (funkcja fixDown sprawdza czy element jest lisciem czy nie)
			}
		}
	}
}

void MyHeap::push(int key)
{
	currentSize++;
	if (currentSize == 1) {
		tab = new int[10];
	}
	else if (currentSize > tabLen) { //jesli w tablicy nie ma miejsca zwiekszamy jej rozmiar
		increaseSize();
	}
	tab[currentSize - 1] = key;
	fixUp(this->tab, currentSize - 1); //naprawiamy w gore
}

void MyHeap::showAll()
{
	printTree(0, 0); //wyswietl kopiec w formie drzewa
	cout << endl << endl;
	for (int i = 0; i < currentSize; i++) { //wyswietl kopiec w formie tablicy
		cout << tab[i] << " ";
	}
}

void MyHeap::fixDown(int tab[], int index, int tabLen)
{
	int left, right; //lewy i prawy potomek
	while ((tabLen > 2 * index + 1)) { //dopoki wierzcholek nie jest lisciem (ma jedno lub dwojke dzieci)
		left = 2 * index + 1; //index lewego dziecka
		right = 2 * index + 2; //index prawego
		if (tabLen > 2 * index + 2) { //jesli ma dwojke dzieci
			int bigger;
			if (tab[left] > tab[right]) bigger = left; //szukamy wiekszego dziecka
			else bigger = right;
			if (tab[bigger] > tab[index]) { //jesli wierzcholek jest mniejszy od wiekszego dziecka zamieniamy je miejscami
				int tmp = tab[index];
				tab[index] = tab[bigger];
				tab[bigger] = tmp;
				index = bigger;
			}
			else return; //jesli zadne z dzieci nie jest wieksze to wychodzimy z petli
		}
		else if (tab[left] > tab[index]) { //jesli nie ma dwoch to ma tylko lewe dziecko, sprawdzamy czy jest wieksze
			int tmp = tab[index];
			tab[index] = tab[left];
			tab[left] = tmp;
			index = left;
		}
		else return;
	}
}

void MyHeap::fixUp(int tab[], int index)
{
	bool checking = true;
	int tmp;
	while (checking) {
		int parentIndex = (index - 1) / 2; //znajdujemy rodzica elementu
		if (tab[parentIndex] < tab[index]) { //jesli rodzic ma mniejsza wartosc zamieniamy elementy miejscami
			tmp = tab[parentIndex];
			tab[parentIndex] = tab[index];
			tab[index] = tmp;
		}
		else { //jesli rodzic jest wiekszy wychodzimy z petlo
			checking = false;
		}
		index = parentIndex; //jesli zmienilismy elementy miejscami powtarzamy procedure dla zmienionego elementu
		if (index == 0) { //zamieniony element jest korzeniem, konczymy naprawe
			checking = false;
		}
	}
}

void MyHeap::printTree(int index, int space)
{
	if (index >= currentSize) {
		return;
	}
	space += COUNT;
	if (tabLen > 2 * index + 2) printTree(2 * index + 2, space); //najpierw wyswietlamy prawe poddrzewa
	for (int i = COUNT; i < space; i++)
		cout << "\t";
	cout << tab[index] << "\n";
	if (tabLen > 2 * index + 1) printTree(2 * index + 1, space); //potem lewe
}

void MyHeap::increaseSize()
{
	int* newTab = new int[tabLen + 100]{ 0 }; //nowa tablica z rozmiarem wiekszym o 10
	for (int i = 0; i < currentSize; i++) { //kopiujemy obecne wartosci
		newTab[i] = tab[i];
	}
	tabLen += 10;
	//usuwamy stara tablice i przesuwamy wskaznik na nowa
	delete[] tab;
	tab = newTab;
	newTab = NULL;
}
