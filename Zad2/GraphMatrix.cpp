#include "GraphMatrix.h"

int GraphMatrix::FindSet(int verticeNum1)
{
	//std::cout << "Na poczatek rodzic " << vertices.at(verticeNum1).parent << " wierzcholka " << vertices.at(verticeNum1).verticeNum << std::endl;
	if (verticeNum1 != vertices.at(verticeNum1).parent) {
		vertices.at(verticeNum1).parent = FindSet(vertices.at(verticeNum1).parent);
	}
	//std::cout << "Zwracam rodzica " << vertices.at(verticeNum1).parent << " wierzcholka " << vertices.at(verticeNum1).verticeNum << std::endl;
	return vertices.at(verticeNum1).parent;
}

GraphMatrix::~GraphMatrix() {
	for (int i = 0; i < numberOfVertices; i++) {
		delete[] tab[i];
	}
	delete[] tab;
}

void GraphMatrix::Union(int a, int b)
{
	int aroot = FindSet(a);
	int broot = FindSet(b);
	if (vertices.at(aroot).rank < vertices.at(vertices.at(broot).parent).rank) {
		//std::cout << "zamieniam rodzica " << a << " z " << vertices.at(aroot).parent << " na " << broot << std::endl;
		vertices.at(aroot).parent = broot;
	}
	else {
		//std::cout << "zamieniam rodzica " << b << " z " << vertices.at(broot).parent << " na " << aroot << std::endl;
		vertices.at(broot).parent = aroot;
	}
	if (vertices.at(aroot).rank == vertices.at(broot).rank) {
		vertices.at(aroot).rank++;
	}
}

bool GraphMatrix::generateRandomMST(std::vector<Edge> edges, int numberOfVertices)
{
	this->numberOfVertices = numberOfVertices;
	tab = new int* [numberOfVertices] {0};
	tab = new int* [numberOfVertices];
	for (int i = 0; i < numberOfVertices; i++) {
		tab[i] = new int[numberOfVertices] {0};
	}
	for (int i = 0; i < edges.size(); i++) {
		tab[edges.at(i).startVertice][edges.at(i).endVertice] = edges.at(i).weight;
		tab[edges.at(i).endVertice][edges.at(i).startVertice] = edges.at(i).weight;
	}
}

bool GraphMatrix::generateRandomSP(std::vector<Edge> edges, int numberOfVertices)
{
	this->numberOfVertices = numberOfVertices;
	tab = new int* [numberOfVertices] {0};
	tab = new int* [numberOfVertices];
	for (int i = 0; i < numberOfVertices; i++) {
		tab[i] = new int[numberOfVertices] {0};
	}
	for (int i = 0; i < edges.size(); i++) {
		tab[edges.at(i).startVertice][edges.at(i).endVertice] = edges.at(i).weight;
	}
}

bool GraphMatrix::createFromFileMST(std::vector<int> fileInfo)
{
	numberOfEdges = fileInfo.at(0);
	numberOfVertices = fileInfo.at(1);
	tab = new int* [numberOfVertices];
	for (int i = 0; i < numberOfVertices; i++) {
		tab[i] = new int[numberOfVertices] {0};
	}
	int counter = 2;
	while (counter < fileInfo.size() - 2) {
		tab[fileInfo.at(counter)][fileInfo.at(counter + 1)] = fileInfo.at(counter + 2);
		tab[fileInfo.at(counter + 1)][fileInfo.at(counter)] = fileInfo.at(counter + 2);
		counter += 3;
	}
	return true;
}

bool GraphMatrix::createFromFileSP(std::vector<int> fileInfo)
{
	numberOfEdges = fileInfo.at(0);
	numberOfVertices = fileInfo.at(1);
	startingVertice = fileInfo.at(2);
	tab = new int* [numberOfVertices];
	for (int i = 0; i < numberOfVertices; i++) {
		tab[i] = new int[numberOfVertices] {0};
	}
	int counter = 3;
	while (counter < fileInfo.size() - 2) {
		tab[fileInfo.at(counter)][fileInfo.at(counter + 1)] = fileInfo.at(counter + 2);
		counter += 3;
	}
	return true;
}

void GraphMatrix::DijkstraAlgorithm()
{
	//tablica przechowujaca koncowego parent kazdego wierzcholka
	int* parent = new int[numberOfVertices] {-1};
	//tablica przechowujaca koncowe wartosci odleglosci wierzcho³ków od wierzcho³ka startowego
	std::vector<int> distance(numberOfVertices, INT_MAX);
	//vector wierzcho³ków nierozpatrzonych
	std::vector<std::pair<int, int>> queue;
	//dodajemy do kolejki wszystkie wierzcholki (para distance + numer wierzcho³ka)
	for (int i = 0; i < numberOfVertices; i++) {
		queue.push_back(std::make_pair(INT_MAX, i));
	}
	//ustawiamy dystans startowego wierzcholka na 0
	distance[startingVertice] = 0;
	parent[startingVertice] = -1;
	queue.at(startingVertice).first = 0;
	//tworzymy kopiec minimalny
	std::make_heap(queue.begin(), queue.end(), std::greater<>{});
	//wierzcho³ek z minimalnym key który bedzie rozpatrywany w danym obiegu
	std::pair<int, int> extractedVertice;
	while (!queue.empty()) {
		//wyjmujemy wierzcho³ek z minimalnym distance
		extractedVertice = queue.front();
		//usuwamy go z kolejki
		queue.erase(queue.begin());
		//szukamy s¹siadów extractedVertex
		//zczytujemy nr wierzcho³ka który wyjelismy z kopca
		int checkedVerticeNum = extractedVertice.second;
		//przegl¹damy vector s¹siadów i kolejkê wierzcho³ków nierozpatrzonych
		for (int i = 0; i < numberOfVertices; i++) {
			if (tab[checkedVerticeNum][i] != 0) {
				if (((tab[checkedVerticeNum][i]) + (extractedVertice.first)) < distance[i]) {
					distance[i] = tab[checkedVerticeNum][i] + extractedVertice.first;
					parent[i] = checkedVerticeNum;
					//wyszukujemy i zamieniamy distance wierzcho³ka w kolejce
					for (int j = 0; j < queue.size(); j++) {
						if (queue.at(j).second == i) {
							queue.at(j).first = distance[i];
							break;
						}
					}
				}
			}
		}
		std::make_heap(queue.begin(), queue.end(), std::greater<>{});
	}
	std::cout << "NAJKROTSZA SCIEZKA (reprezentacja macierzowa):" << std::endl;
	std::cout << std::endl << "START = " << startingVertice << std::endl;
	std::cout << "END  DIST  PATH" << std::endl;
	for (int i = 0; i < numberOfVertices; i++) {
		std::cout << i << "    |" << distance[i] << "    |";
		std::vector<int> path;
		//dodajemy "na koniec" wierzcholek
		path.push_back(i);
		int j = i;
		int counter = 0;
		while (j != startingVertice) {
			path.push_back(parent[j]);
			j = parent[j];
			counter++;
		}
		for (int k = path.size() - 1; k >= 0; --k) {
			std::cout << path.at(k) << " ";
		}
		std::cout << std::endl;
	}
	delete[] parent;
}

void GraphMatrix::BellmanFordAlgorithm()
{
	bool isNegativeCycle = false;
	//dla kazdej krawedzi tworzymy krawedz i dodajemy do wektora krawedzi
	std::vector<Edge> edges;
	//przegladamy po kolei ka¿dy wiersz macierzy i dodajemy krawêdzie
	for (int i = 0; i < numberOfVertices; i++) {
		for (int j = 0; j < numberOfVertices; j++) {
			if (tab[i][j] != 0) {
				edges.push_back(Edge(i, j, tab[i][j]));
			}
		}
	}
	//vector przechowujacy koncowego parent kazdego wierzcholka
	std::vector<int> parent(numberOfVertices, -1);
	//vector przechowujacy koncowe wartosci odleglosci wierzcho³ków od wierzcho³ka startowego
	std::vector<int> distance(numberOfVertices, INT_MAX);
	distance.at(startingVertice) = 0;
	//g³ówna pêtla
	for (int i = 0; i < numberOfVertices - 1; i++) {
		bool wasChanged = false;
		//dla wszystkich krawedzi
		for (int j = 0; j < edges.size(); j++) {
			if ((distance[edges.at(j).endVertice] > (distance[edges.at(j).startVertice] + edges.at(j).weight)) && (distance[edges.at(j).startVertice] != INT_MAX)) {
					distance[edges.at(j).endVertice] = distance[edges.at(j).startVertice] + edges.at(j).weight;
					parent[edges.at(j).endVertice] = edges.at(j).startVertice;
					wasChanged = true;
			}
		}
		//jeœli w danym obiegu nie by³o zmiany mo¿emy wyjœæ z pêtli
		if (!wasChanged) break;
	}
	//sprawdzamy czy nie by³o negatywnego cyklu
	for (int i = 0; i < edges.size(); i++) {
		if (distance[edges.at(i).endVertice] > distance[edges.at(i).startVertice] + edges.at(i).weight) {
			isNegativeCycle = true;
			break;
		}
	}
	if (!isNegativeCycle) {
		std::cout << "NAJKROTSZA SCIEZKA (reprezentacja macierzowa):" << std::endl;
		std::cout << std::endl << "START = " << startingVertice << std::endl;
		std::cout << "END  DIST  PATH" << std::endl;
		for (int i = 0; i < numberOfVertices; i++) {
			std::cout << i << "    |" << distance[i] << "    |";
			std::vector<int> path;
			//dodajemy "na koniec" wierzcholek
			path.push_back(i);
			int j = i;
			int counter = 0;
			while (j != startingVertice) {
				path.push_back(parent[j]);
				j = parent[j];
				counter++;
			}
			for (int k = path.size() - 1; k >= 0; --k) {
				std::cout << path.at(k) << " ";
			}
			std::cout << std::endl;
		}
	}
	else std::cout << "W grafie znajduje sie cykl ujemny!";
}

void GraphMatrix::display()
{
	std::cout << "Reprezentacja macierzowa:" << std::endl << std::endl;
	for (int i = 0; i < numberOfVertices; i++) {
		for (int j = 0; j < numberOfVertices; j++) {
			std::cout << tab[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void GraphMatrix::PrimAlgorithm()
{
	//tablica przechowujaca koncowego parent kazdego wierzcholka
	int* parent = new int[numberOfVertices] {-1};
	//tablica przechowujaca koncowe wartosci key kazdego wierzcholka
	int* key = new int[numberOfVertices] {INT_MAX};
	//vector wierzcho³ków nierozpatrzonych
	std::vector<std::pair<int, int>> queue;
	//dodajemy do kolejki wszystkie wierzcholki (para key + numer wierzcho³ka)
	for (int i = 0; i < numberOfVertices; i++) {
		queue.push_back(std::make_pair(INT_MAX, i));
	}
	srand(time(NULL));
	//losujemy startowy wierzcholek
	int startV = rand() % numberOfVertices;
	//rodzica startowego wierzcholka ustawiamy na NULL/-1
	parent[startV] = -1;
	//key startowego wierzcholka ustawiamy na 0
	queue.at(startV).first = 0;
	key[startV] = 0;
	//tworzymy kopiec minimalny
	std::make_heap(queue.begin(), queue.end(), std::greater<>{});
	//wierzcho³ek z minimalnym key który bedzie rozpatrywany w danym obiegu
	std::pair<int, int> extractedVertice;
	while (!queue.empty()) {
		//wyjmujemy wierzcho³ek z minimalnym key
		extractedVertice = queue.front();
		//usuwamy go z kolejki
		queue.erase(queue.begin());
		//szukamy s¹siadów extractedVertex
		//zczytujemy nr wierzcho³ka który wyjelismy z kopca
		int verticeNum = extractedVertice.second;
		//tworzymy vector s¹siadów
		std::vector<int> neighbours;
		for (int i = 0; i < numberOfVertices; i++) {
			if (tab[i][verticeNum] != 0) {
				neighbours.push_back(i);
			}
		}
		//przegl¹damy vector s¹siadów i kolejkê wierzcho³ków nierozpatrzonych
		for (int j = 0; j < queue.size(); j++) {
			for (int i = 0; i < neighbours.size(); i++) {
				if (neighbours.at(i) == queue.at(j).second && tab[neighbours.at(i)][verticeNum] < queue.at(j).first) {
					key[neighbours.at(i)] = tab[neighbours.at(i)][verticeNum];
					parent[neighbours.at(i)] = verticeNum;
					queue.at(j).first = key[neighbours.at(i)];
					break;
				}
			}
		}
		//przywracamy kopiec
		std::make_heap(queue.begin(), queue.end(), std::greater<>{});
	}
	std::cout << "DRZEWO MST (reprezentacja macierzowa):" << std::endl;
	std::cout << std::endl << "KRAWEDZ      WAGA" << std::endl;
	int sum = 0;
	for (int i = 0; i < numberOfVertices; i++) {
		if (parent[i] != -1) {
			std::cout << "(" << i << ", " << parent[i] << ")      " << key[i] << std::endl;
			sum += key[i];
		}
	}
	std::cout << std::endl << "SUMA KRAWEDZI: " << sum << std::endl;
	delete[] key;
	delete[] parent;
}

void GraphMatrix::KruskalAlgorithm()
{
	vertices.clear();
	//tworzymy wektor bedacy zbiorem krawedzi tworzacych rozwiazanie
	std::vector<Edge> result;
	//dla kazdego wierzcholka tworzymy graf z jednym wierzcholkiem wskazujacym na samego siebie i dodajemy do wektora wierzcholkow
	for (int i = 0; i < numberOfVertices; i++) {
		KruskalVertice kruskalVer(i, 0, i);
		vertices.push_back(kruskalVer);
	}
	//dla kazdej krawedzi tworzymy krawedz i dodajemy do wektora krawedzi
	std::vector<Edge> edges;
	//przegladamy po kolei ka¿dy wiersz macierzy i dodajemy krawêdzie
	for (int i = 0; i < numberOfVertices; i++) {
		for (int j = i + 1; j < numberOfVertices; j++) {
			if (tab[i][j] != 0) {
				edges.push_back(Edge(i, j, tab[i][j]));
			}
		}
	}
	//sortujemy liste krawedzi niemalejaco wedlug wagi
	std::sort(edges.begin(), edges.end(), std::greater<Edge>());
	//teraz pobieramy kolejne krawedzie dopoki nie znajdziemy liczba wierzcholkow - 1 krawedzi
	while (result.size() != (numberOfVertices - 1)) {
		Edge currentEdge = edges.at(0);
		if (FindSet(currentEdge.startVertice) != FindSet(currentEdge.endVertice)) {
			result.push_back(currentEdge);
			Union(currentEdge.startVertice, currentEdge.endVertice);
		}
		//usuwamy rozpatrzona krawedz
		edges.erase(edges.begin());
	}
	std::cout << std::endl << "DRZEWO MST (reprezentacja macierzowa):" << std::endl;
	std::cout << std::endl << "KRAWEDZ     WAGA" << std::endl;
	int sum = 0;
	for (int i = 0; i < result.size(); i++) {
		std::cout << "(" << result.at(i).startVertice << ", " << result.at(i).endVertice << ")      " << result.at(i).weight << std::endl;
		sum += result.at(i).weight;
	}
	std::cout << std::endl << "SUMA KRAWEDZI: " << sum << std::endl;
}
