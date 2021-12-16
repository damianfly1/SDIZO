#include "MyBSTree.h"

MyBSTree::~MyBSTree()
{
	if (root) deleteChildren(root);
	root = NULL;
}

void MyBSTree::createRandom(int size)
{
	srand(time(NULL));
	int random_number = rand() % INT_MAX + (-INT_MAX);
	root = new TreeNode(); //tworzymy korzen 
	root->key = random_number;
	for (int i = 0; i < size - 1; i++) {
		random_number = rand() % INT_MAX + (-INT_MAX);
		insertNode(random_number);
	}
	createLinearTree();
	createBalancedTree();
}

bool MyBSTree::createFromFile()
{
	system("cls");
	cout << "Podaj nazwe pliku z ktorego mamy zczytac dane (z rozszerzeniem)" << endl;
	string filename;
	cin >> filename;
	fstream myfile;
	myfile.open(filename, ios::in);
	ifstream MyReadFile(filename);
	if (myfile.is_open()) { // zczytujemy dane z pliku do tablicy 
		string tmp;
		getline(myfile, tmp);
		int size = stoi(tmp);
		int* p;
		p = new int[size] {0};
		int licznik = 0;
		while (getline(myfile, tmp)) {
			if (tmp.length() == 0) break;
			*(p + licznik) = stoi(tmp);
			licznik++;
		}
		myfile.close();
		for (int i = 0; i < size; i++) { //dodajem kolejne wezly
			insertNode(p[i]);
		}
		p = NULL;
		delete[] p;
		vec_left = new int[size] {0};
		return true;
	}
	else {
		return false;
	}
}

bool MyBSTree::createRandom()
{
	system("cls");
	cout << "Podaj ilosc elementow w drzewie BST";
	int size;
	cin >> size;
	if (size == 0) {
		return true;
	}
	else if (size > 0) {
		srand(time(NULL));
		int random_number = rand() % 2000 - 1000;
		root = new TreeNode(); //tworzymy korzen 
		root->key = random_number;
		for (int i = 0; i < size - 1; i++) {
			random_number = rand() % 2000 - 1000;
			insertNode(random_number);
		}
		vec_left = new int[size] {0}; //tablica uzywana przy wyswietlaniu
		return true;
	}
	else {
		cout << "Tablica musi miec rozmiar wiekszy od 0";
		return false;
	}
}

void MyBSTree::printTree(TreeNode* root, int ident) {
	if (ident > 0)
	{
		for (int i = 0; i < ident - 1; ++i)
		{
			printf(vec_left[i] ? "|   " : "    ");
		}
		printf(vec_left[ident - 1] ? "LEFT::" : "RIGHT::");
	}

	if (!root)
	{
		printf("(null)\n");
		return;
	}

	printf("%d\n", root->key);
	if (!root->left && !root->right)
	{
		return;
	}

	vec_left[ident] = 1;
	printTree(root->left, ident + 1);
	vec_left[ident] = 0;
	printTree(root->right, ident + 1);
}

void MyBSTree::showAll()
{
	cout << endl << endl;
	printTree(root, 0);
	cout << endl << endl;
}

bool MyBSTree::findElement(int key)
{
	TreeNode* tmp = root;
	while (tmp != NULL && tmp->key != key) { //dopoki nie znajdziemy klucza lub dojdziemy do liscia
		if (key < tmp->key) { //nie musimy przegladac calego drzewa 
			tmp = tmp->left;
		}
		else {
			tmp = tmp->right;
		}
	}
	if (tmp == NULL) return false;
	else return true;
}

void MyBSTree::insertNode(int key)
{
	if (root == NULL) {
		vec_left = new int[1];
	}
	TreeNode* node = new TreeNode(); //nowy wezel
	node->key = key; //przypisujemy klucz
	TreeNode* y = NULL; //wskaznik pomocniczy
	TreeNode* x = root; //wskaznik na wezel porownywany z node
	while (x) { //dopoki nie natrafilismy na wskaznik NULL
		y = x; //zapisujemy x do y bo x bedzie schodzil w dol drzewa
		if (node->key < x->key) x = x->left; //jesli klucz nowego wezla jest mniejsza x idziemy do lewego poddrzewa
		else x = x->right; //inaczej do prawego poddrzewa
	}
	node->parent = y; //nowy wezel staje sie potomkiem y
	if (y == NULL) { //jesli y jest null to znaczy ze nowy wezel jest korzeniem
		root = node;
	}
	else { //inaczej dodajemy lewego albo prawego potomka
		if (node->key < y->key) y->left = node;
		else y->right = node;
	}
}

void MyBSTree::deleteKey(int key)
{
	TreeNode* node = findNode(key); //szukamy wezla o danycm kluczu
	if (node) deleteNode(node); //jesli istnieje to go usuwamy
	else return;
}


void MyBSTree::deleteNode(TreeNode* node)
{
	if (node->left == NULL && node->right == NULL) //jesli node nie ma dzieci
	{
		if (node != root) //jesli nie jest korzeniem
		{
			if ((node->parent)->left == node) { //przed usunieciem ustaw rodzicowi node wskazniki na null
				(node->parent)->left = NULL;
			}
			else {
				(node->parent)->right = NULL;
			}
		}
		// jesli wierzcholek jest korzeniem bez synow usuwamy korzen
		else {
			root = NULL;
		}
		delete node; //zwalniamy pamiec wezla
	}
	else if (node->left && node->right) //jesli wierzcholek ma dwoch synow wyznaczamy nastepnika (minimalny element w prawym poddrzewie)
	{
		TreeNode* successor = findMinKey(node->right); //wyszukujemy nastepnika
		int sKey = successor->key; //zapisujemy wartosc nastepnika
		node->key = sKey; //zamieniamy obecna wartosc z wartosci zamiennika, "usuwamy" wezel
		deleteNode(successor); // usuwamy starego nastepnika
	}
	else { //usuwany wierzcholek ma jednego syna
		TreeNode* child = nullptr; //wskaznik na dziecko
		if (node->left) {
			child = node->left;
		}
		else {
			child = node->right;
		}
		if (node->parent != NULL) //jesli node nie jest korzeniem
		{
			if (node == (node->parent)->left) { //jesli jest lewym potomkiem
				(node->parent)->left = child; //jego dziecko staje sie nowym potomkiem
				child->parent = node->parent;
			}
			else {
				(node->parent)->right = child;
				child->parent = node->parent;
			}
		}
		else { //jesli node jest korzeniem to jego jedyny syn jest teraz korzeniem
			root = child;
			child->parent = NULL;
		}
		delete node; //zwalniamy pamiec
	}
}

bool MyBSTree::empty()
{
	if (root == NULL) return true;
	else return false;
}

void MyBSTree::deleteChildren(TreeNode* node)
{
	//rekurencyjnie usuwaj lewe poddzrewo
	if (node->left) deleteChildren(node->left);
	// rekurencyjnie usuwaj prawe poddrzewo
	if (node->right) deleteChildren(node->right);
	//zwolnij pamiec
	delete node;
}

TreeNode* MyBSTree::findNode(int key)
{
	TreeNode* tmp = root;
	while (tmp != NULL && tmp->key != key) {
		if (key < tmp->key) {
			tmp = tmp->left;
		}
		else {
			tmp = tmp->right;
		}
	}
	if (tmp == NULL) return NULL;
	else return tmp;
}

TreeNode* MyBSTree::findSuccessor(TreeNode* node)
{
	if (node->right != NULL) { //jesli node ma prawego potomka to jego nastepnik bedzie minimalnym elementem w prawym poddrzewie
		return findMinKey(node->right);
	}
	//jesli node nie ma prawego potomka to jego nastepnikiem jest idac w gore drzewa pierwszy ojciec dla ktorego wezel lezy w lewym poddrzewie
	TreeNode* tmp = node->parent; //tymczasowy wskaznik na rodzica
	while (tmp != NULL && tmp->left != node) { //dopoki nie doszlismy do korzenia lub nie doszlismy do jakiegos wezla od strony lewego syna
		node = tmp;
		tmp = tmp->parent;
	}
	return tmp;
}

TreeNode* MyBSTree::findPredecessor(TreeNode* node)
{
	if (node->left != NULL) { //jesli node na lewego potomka to jego poprzednik bedzie maksymalnym elementem w lewym poddrzewie
		return findMaxKey(node->left);
	}
	//jesli node nie ma lewego potomka to jego poprzednikiem jest idac w gore drzewa pierwszy ojciec dla ktorego node lezy w prawym poddrzewie
	TreeNode* tmp = node->parent;
	while (tmp != NULL && tmp->right != node) {
		node = tmp;
		tmp = tmp->parent;
	}
	return tmp;
}

TreeNode* MyBSTree::findMinKey(TreeNode* node)
{
	while (node->left) { //najmniejszy klucz jest elementem najbardziej wysunietym w lewo
		node = node->left;
	}
	return node;
}

TreeNode* MyBSTree::findMaxKey(TreeNode* node)
{
	while (node->right) { //najwiekszy klucz jest elementem najbardziej wysunietym w prawo
		node = node->right;
	}
	return node;
}

void MyBSTree::rotateRight(TreeNode* node)
{
	TreeNode* child = node->left; //wskaznik na lewe dziecko
	if (child) { //jesli lewe dziecko istenieje
		node->left = child->right; //po rotacji prawe dziecko dziecka bedzie lewym dzieckiem wezla
		if (child->right) { //jesli lewe dziecko ma prawe dziecko
			child->right->parent = node; //ustawiamy wskaznik rodzica prawego dziecka lewego dziecka na wezel
		}
		child->parent = node->parent; //ojcem lewego dziecka bedzie ojciec node
		if (node->parent == NULL) { //jesli ojciec byl korzeniem
			root = child; //dziecko staje sie korzeniem
			child->parent = NULL;
		}
		else if (node == node->parent->right) { //jesli node byl prawym dzieckiem 
			node->parent->right = child; //dziecko staje sie prawym dzieckiem
		}
		else node->parent->left = child; //inaczej dziecko staje sie lewym potomkiem rodzica node
		child->right = node; //wezel staje sie prawym potomkiem 
		node->parent = child;
	}
}

void MyBSTree::rotateLeft(TreeNode* node)
{
	TreeNode* child = node->right; //wskaznik na prawe dziecko
	if (child) { //jesli prawe dziecko istnieje
		node->right = child->left; //po rotacji lewe dziecko dziecka bedzie prawym dzieckiem wezla
		if (child->left) { //jesli prawe dziecko ma lewe dziecko
			child->left->parent = node; //ustawiamy wskaznik rodzica lewego dziecka prawego dziecka na wezel
		}
		child->parent = node->parent; //ojcem prawego dziecka bedzie ojciec node
		if (node->parent == NULL) { //jesli ojciec byl korzeniem
			root = child; //dziecko staje sie korzeniem
			child->parent == NULL;
		}
		else if (node == node->parent->left) { //jesli node byl lewym dzieckiem 
			node->parent->left = child; //dziecko node staje sie lewym dzieckiem rodzica node
		}
		else node->parent->right = child; //na odwrot
		child->left = node; //wezel staje sie lewym potomkiem dziecka
		node->parent = child;
	}
}

void MyBSTree::createLinearTree()
{
	TreeNode* tmp = root;
	while (tmp) { //dopoki nie doszlismy do ostatniego wezla bez lewego potomka
		if (tmp->left) {
			rotateRight(tmp); //rotujemy w lewo
			tmp = tmp->parent;
		}
		else {
			tmp = tmp->right;
		}
	}
}

void MyBSTree::createBalancedTree()
{
	int nodeCount = countNodes(); //liczymy ilosc wezlow n
	//liczymy wartosc m
	int log = floor(log2(nodeCount + 1));
	int m = pow(2.0, log) - 1;
	int numberOfRotations = nodeCount - m; //wykonujemy n-m rotacji w lewo startujac od poczatkowego wierzcholka co drugi wierzcholek
	TreeNode* tmp = root; //zaczynami od korzenia
	TreeNode* next; //next bedzie pelnilo role kolejnego wierzcholka do rotacji, potrzebujemy next bo po rotacji tmp ma inne dzieci
	for (int i = 0; i < numberOfRotations; i++) { //rotujemy w lewo dla kolejnych wierzcholkow
		next = tmp->right->right;
		rotateLeft(tmp);
		if (next == NULL) break;
		tmp = next;
	}
	//druga czesc algorytmu
	while (m > 1) {
		m = m / 2;
		//taki sam schemat wykonywania obrotu jak w pierwszej czesci algorytmu
		tmp = root; //dla kazdej kolejnego obieku petli zaczynamy od wierzcholka
		for (int i = 0; i < m; i++) {
			next = tmp->right->right;
			rotateLeft(tmp);
			if (next == NULL) break;
			tmp = next;
		}
	}
}

int MyBSTree::countNodes() //gdy drzewo jest wyprostowane
{
	int counter = 0;
	TreeNode* tmp = root;
	while (tmp) {
		counter++;
		tmp = tmp->right;
	}
	return counter;
}