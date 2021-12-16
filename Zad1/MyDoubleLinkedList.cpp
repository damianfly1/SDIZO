#include "MyDoubleLinkedList.h"

void MyDoubleLinkedList::createRandom(int size)
{
	srand(time(NULL));
	int random_number = rand() % INT_MAX + (-INT_MAX);
	this->size = size;
	head = new ListNode();
	head->data = random_number;
	ListNode* tmp_head;
	tmp_head = head;
	for (int i = 0; i < size - 1; i++) {
		random_number = rand() % INT_MAX + (-INT_MAX);
		tmp_head->next = new ListNode();
		tmp_head->next->prev = tmp_head;
		tmp_head->next->next = NULL;
		tmp_head->next->data = random_number;
		tmp_head = tmp_head->next;
	}
	tail = tmp_head;
	tmp_head->next = NULL;
	tmp_head = NULL;
}

MyDoubleLinkedList::~MyDoubleLinkedList()
{
	ListNode* p = tail;
	while (tail) {
		tail = tail->prev;
		delete p;
		p = tail;
	}
	head = NULL;
}

bool MyDoubleLinkedList::createFromFile()
{
	system("cls");
	cout << "Podaj nazwe pliku z ktorego mamy zczytac dane (z rozszerzeniem)" << endl;
	string filename;
	cin >> filename;
	fstream myfile;
	myfile.open(filename, ios::in);
	if (myfile.is_open()) { // zczytujemy dane z pliku do tablicy
		string tmp;
		getline(myfile, tmp);
		size = stoi(tmp);
		int* p;
		p = new int[size] {0};
		int licznik = 0;
		while (getline(myfile, tmp)) {
			if (tmp.length() == 0) break;
			*(p + licznik) = stoi(tmp);
			licznik++;
		}
		myfile.close();
		ListNode* tmpNode = new ListNode();
		tmpNode->data = *p;
		tmpNode->next = NULL;
		tmpNode->prev = NULL;
		head = tmpNode;
		for (int i = 1; i < size; i++) { //indeksujemy od 1 bo glowa juz jest stworzona
			tmpNode->next = new ListNode();
			tmpNode->next->prev = tmpNode;
			tmpNode->next->next = NULL;
			tmpNode->next->data = p[i];
			tmpNode = tmpNode->next;
		}
		tail = tmpNode;
		delete[] p;
		p = NULL;
		tmpNode = NULL;
		return true;
	}
	else return false;
}

bool MyDoubleLinkedList::generateRandom()
{
	system("cls");
	cout << "Podaj rozmiar listy";
	cin >> size;
	if (size == 0) {
		return true;
	}
	else if (size > 0) { //najpierw tworzymy glowe, potem reszte
		srand(time(NULL));
		int random_number = rand() % 2000 - 1000;
		head = new ListNode();
		head->data = random_number;
		ListNode* tmp_head;
		tmp_head = head;
		for (int i = 0; i < size - 1; i++) {
			random_number = rand() % 2000 - 1000;
			tmp_head->next = new ListNode();
			tmp_head->next->prev = tmp_head;
			tmp_head->next->next = NULL;
			tmp_head->next->data = random_number;
			tmp_head = tmp_head->next;
		}
		tail = tmp_head;
		tmp_head->next = NULL;
		tmp_head = NULL;
		return true;
	}
	else return false;
}

int MyDoubleLinkedList::getSize()
{
	return size;
}

bool MyDoubleLinkedList::empty()
{
	if (size) return false;
	else return true;
}

void MyDoubleLinkedList::popFront()
{
	ListNode* tmp = head; //ustawiamy wskaznik na glowe
	(head->next)->prev = NULL; //drugi node bedzie teraz glowa wiec ustawiamy jego poprzednika na null
	head = head->next; //ustawiamy wskaznik glowy na drugi node
	delete tmp; //zwalniamy pamiec
	--size; //zmniejszamy rozmiar
}

void MyDoubleLinkedList::popBack()
{
	ListNode* tmp = tail; //ustawiamy wskaznik na ogon
	(tail->prev)->next = NULL; //przedostatni node bedzie teraz ogonem wiec ustawiamy jego nastepce na null
	tail = tail->prev; //zmieniamy wskaznik ogona na przedostatni node
	delete tmp; //zwalniamy pamiec
	--size; //zmniejszamy rozmiar
}

void MyDoubleLinkedList::deleteValue(int value)
{
	ListNode* p = head; //wskaznik na glowe
	while (p) { //jesli glowa istnieje powtarzamy
		if (p->data == value) { //jesli znalezlismy node
			if (size == 1) { //jesli istnieje tylko glowa
				delete head; //zwalniamy pamiec glowy
				head = NULL;
				tail = NULL;
				p = NULL;
				--size; //zmniejszamy rozmiar
			}
			else {
				if (p->prev == NULL) { //jesli usuwamy glowe
					p = p->next;
					popFront();
				}
				else if (p->next == NULL) { //jesli usuwamy ogon
					p = p->next;
					popBack();
				}
				else { //ustawiamy odpowiednio wskazniki i zwalniamy pamiec elementu
					ListNode* tmp;
					p->prev->next = p->next;
					p->next->prev = p->prev;
					tmp = p;
					p = p->next;
					delete tmp;
					--size;
				}
			}
		}
		else p = p->next;
	}
}

void MyDoubleLinkedList::addAtIndex(int value, int index)
{
	ListNode* p = head; //wskaznik tymczasowy na glowe
	if (index == 0) pushFront(value); //jesli wstawiamy na poczatek
	else if (index == size) pushBack(value); //jesli wsawiamy na koniec
	else {
		for (int i = 0; i < index; i++) { //dochodzimy do miejsca gdzie chcemy wstawic nowy node
			p = p->next;
		}
		ListNode* new_node = new ListNode();
		//ustawiamy odpowiednio wskazniki next i prev nowych sasiadow
		new_node->prev = p->prev;
		new_node->next = p;
		new_node->data = value;
		(p->prev)->next = new_node;
		p->prev = new_node;
		p = NULL;
		new_node = NULL;
		++size; //zwiekszamy rozmiar
	}
}

void MyDoubleLinkedList::pushFront(int value)
{
	if (size == 0) { //jesli lista jest pusta tworzymy nowa glowe i ustawiamy odpowiednio wskazniki
		ListNode* new_head = new ListNode();
		new_head->data = value;
		new_head->prev = NULL;
		new_head->next = NULL;
		head = new_head;
		tail = new_head;
		++size;
	}
	else { //inaczej tworzymy nowa glowe i ustawiamy odpowiednio ze wskaznikami starej glowy
		ListNode* new_head = new ListNode();
		new_head->data = value;
		new_head->prev = NULL;
		new_head->next = head;
		head->prev = new_head;
		head = new_head;
		new_head = NULL;
		++size;
	}
}

void MyDoubleLinkedList::pushBack(int value)
{
	ListNode* new_tail = new ListNode(); //tworzymy nowe wezel 
	//ustawiamy odpowiednio wskazniki
	new_tail->data = value;
	new_tail->prev = tail;
	new_tail->next = NULL;
	tail->next = new_tail;
	tail = new_tail;
	new_tail = NULL;
	++size;
}

bool MyDoubleLinkedList::findElement(int data1)
{
	ListNode* p = head;
	while (p) { //idziemy od pierwszego elementu do ostatniego
		if (p->data == data1) {
			return true;
		}
		p = p->next;
	}
	return false;
}

void MyDoubleLinkedList::showAll()
{
	if (tail == head) {
		cout << "OD PRZODU: " << head->data << endl;
		cout << "OD TYLU : " << tail->data << endl;
	}
	else {
		ListNode* p;
		p = head;
		cout << "OD PRZODU: " << endl;
		while (p) {
			cout << p->data << " ";
			p = p->next;
		}
		cout << endl << "OD KONCA: " << endl;
		p = tail;
		while (p) {
			cout << p->data << " ";
			p = p->prev;
		}
	}

}
