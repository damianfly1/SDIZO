#include "GraphList.h"

GraphList::~GraphList() {
	vec.clear();
}

int GraphList::FindSet(int verticeNum1)
{
	if (verticeNum1 != vertices.at(verticeNum1).parent) {
		vertices.at(verticeNum1).parent = FindSet(vertices.at(verticeNum1).parent);
	}
	return vertices.at(verticeNum1).parent;
}

void GraphList::Union(int a, int b)
{
	int aroot = FindSet(a);
	int broot = FindSet(b);
	if (vertices.at(aroot).rank < vertices.at(vertices.at(broot).parent).rank) {
		vertices.at(aroot).parent = broot;
	}
	else {
		vertices.at(broot).parent = aroot;
	}
	if (vertices.at(aroot).rank == vertices.at(broot).rank) {
		vertices.at(aroot).rank++;
	}
}

bool GraphList::generateRandomMST(std::vector<Edge> edges, int numberOfVertices)
{
	this->numberOfVertices = numberOfVertices;
	for (int i = 0; i < numberOfVertices; i++) {
		std::list<Node> list;
		vec.push_back(list);
	}
	for (int i = 0; i < edges.size(); i++) {
		vec.at(edges.at(i).startVertice).push_back(Node(edges.at(i).endVertice, edges.at(i).weight));
		vec.at(edges.at(i).endVertice).push_back(Node(edges.at(i).startVertice, edges.at(i).weight));
	}
}

bool GraphList::generateRandomSP(std::vector<Edge> edges, int numberOfVertices)
{
	this->numberOfVertices = numberOfVertices;
	for (int i = 0; i < numberOfVertices; i++) {
		std::list<Node> list;
		vec.push_back(list);
	}
	for (int i = 0; i < edges.size(); i++) {
		vec.at(edges.at(i).startVertice).push_back(Node(edges.at(i).endVertice, edges.at(i).weight));
	}
}

bool GraphList::createFromFileMST(std::vector<int> fileInfo)
{
	vec.clear();
	numberOfEdges = fileInfo.at(0);
	numberOfVertices = fileInfo.at(1);
	for (int i = 0; i < numberOfVertices; i++) {
		std::list<Node> list;
		vec.push_back(list);
	}
	int counter = 2;
	while (counter < fileInfo.size() - 2) {
		(vec.at(fileInfo.at(counter))).push_back(Node(fileInfo.at(counter + 1), fileInfo.at(counter + 2)));
		(vec.at(fileInfo.at(counter + 1))).push_back(Node(fileInfo.at(counter), fileInfo.at(counter + 2)));
		counter += 3;
	}
	return true;
}

bool GraphList::createFromFileSP(std::vector<int> fileInfo)
{
	vec.clear();
	numberOfEdges = fileInfo.at(0);
	numberOfVertices = fileInfo.at(1);
	startingVertice = fileInfo.at(2);
	for (int i = 0; i < numberOfVertices; i++) {
		std::list<Node> list;
		vec.push_back(list);
	}
	int counter = 3;
	while (counter < fileInfo.size() - 2) {
		(vec.at(fileInfo.at(counter))).push_back(Node(fileInfo.at(counter + 1), fileInfo.at(counter + 2)));
		counter += 3;
	}
	return true;
}

void GraphList::DijkstraAlgorithm()
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
		std::list<Node> currentList = vec.at(checkedVerticeNum);
		for (auto it = currentList.begin(); it != currentList.end(); ++it) {
			//jak znajdziemy sasiada sprawdzamy warunek relaksacji
			if (distance[(*it).verticeNum] > (distance[checkedVerticeNum] + (*it).weight)) {
				distance[(*it).verticeNum] = distance[checkedVerticeNum] + (*it).weight;
				parent[(*it).verticeNum] = checkedVerticeNum;
				for (int j = 0; j < queue.size(); j++) {
					if (queue.at(j).second == (*it).verticeNum) {
						queue.at(j).first = distance[(*it).verticeNum];
						break;
					}
				}
			}
		}
		std::make_heap(queue.begin(), queue.end(), std::greater<>{});
	}
	std::cout << "NAJKROTSZA SCIEZKA (reprezentacja listowa):" << std::endl;
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

void GraphList::BellmanFordAlgorithm()
{
	bool isNegativeCycle = false;
	//dla kazdej krawedzi tworzymy krawedz i dodajemy do wektora krawedzi
	std::vector<Edge> edges;
	//dodajemy krawedzie
	for (int i = 0; i < numberOfVertices; i++) {
		std::list<Node> currentList = vec.at(i);
		for (auto it = currentList.begin(); it != currentList.end(); ++it) {
			edges.push_back(Edge(i, (*it).verticeNum, (*it).weight));
		}
	}
	//vector przechowujacy koncowego parent kazdego wierzcholka
	std::vector<int> parent(numberOfVertices, -1);
	//vector przechowujacy koncowe wartosci odleglosci wierzcho³ków od wierzcho³ka startowego
	std::vector<long> distance(numberOfVertices, INT_MAX);
	distance.at(startingVertice) = 0;
	//g³ówna pêtla
	for (int i = 0; i < numberOfVertices - 1; i++) {
		bool wasChanged = false;
		for (int j = 0; j < edges.size(); j++) {
			//std::cout << "Porownuje " << distance[edges.at(j).endVertice] << " z " << distance[edges.at(j).startVertice] + edges.at(j).weight << std::endl;
			if ((distance[edges.at(j).endVertice] > (distance[edges.at(j).startVertice] + edges.at(j).weight)) && (distance[edges.at(j).startVertice]!=INT_MAX)) {
					//std::cout << "Zmieniam dystans " << edges.at(j).endVertice << " z " << distance[edges.at(j).endVertice] << " na " << distance[edges.at(j).startVertice] + edges.at(j).weight << std::endl;
					distance[edges.at(j).endVertice] = distance[edges.at(j).startVertice] + edges.at(j).weight;
					parent[edges.at(j).endVertice] = edges.at(j).startVertice;
					wasChanged = true;
			}
		}
		//jeœli nie zrobiliœmy zmiany mo¿emy wyjœæ z pêtli
		if (!wasChanged) break;
	}
	//sprawdzamy czy nie by³o cyklu ujemnego
	for (int i = 0; i < edges.size(); i++) {
		if (distance[edges.at(i).endVertice] > distance[edges.at(i).startVertice] + edges.at(i).weight) {
			isNegativeCycle = true;
			break;
		}
	}
	if (!isNegativeCycle) {
		std::cout << "NAJKROTSZA SCIEZKA (reprezentacja listowa):" << std::endl;
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


void GraphList::display()
{
	std::cout << std::endl << std::endl << "Reprezentacja listowa:" << std::endl << std::endl;
	for (int i = 0; i < vec.size(); i++) {
		std::list<Node> currentList = vec.at(i);
		std::cout << "Wierzcholek " << i << ": ";
		for (auto it = currentList.begin(); it != currentList.end(); ++it) {
			std::cout << (*it).verticeNum << "|" << (*it).weight << "-->";
		}
		std::cout << std::endl;
	}
}


void GraphList::PrimAlgorithm()
{
	//tablica przechowujaca koncowego parent kazdego wierzcholka
	int* parent = new int[numberOfVertices] {-1};
	//tablica przechowujaca koncowe wartosci key kazdego wierzcholka
	int* key = new int[numberOfVertices] { INT_MAX };
	//vector wierzcho³ków nierozpatrzonych
	std::vector<std::pair<int, int>> queue;
	//dodajemy do kolejki wszystkie wierzcholki (para key + numer wierzcho³ka)
	for (int i = 0; i < numberOfVertices; i++) {
		queue.push_back(std::make_pair(INT_MAX, i));
	}
	//losujemy startowy wierzcholek
	int startV = rand() % numberOfVertices;
	//rodzica startowego wierzcholka ustawiamy na NULL
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
		//wypelniamy liste sasiadow
		std::list<Node> currentList = vec.at(verticeNum);
		for (auto it = currentList.begin(); it != currentList.end(); ++it) {
			neighbours.push_back((*it).verticeNum);
		}
		//przegl¹damy vector s¹siadów i kolejkê wierzcho³ków nierozpatrzonych
		for (int j = 0; j < queue.size(); j++) {
			for (int i = 0; i < neighbours.size(); i++) {
				//jesli znalezlismy sasiada w kolejce nierozpatrzonych wierzcholkow
				if (neighbours.at(i) == queue.at(j).second) {
					for (auto it = currentList.begin(); it != currentList.end(); ++it) {
						//jesli podczas przegladania listy trafimy na sasiada
						if ((*it).verticeNum == neighbours.at(i) && (*it).weight < queue.at(j).first) {
							key[neighbours.at(i)] = (*it).weight;
							parent[neighbours.at(i)] = verticeNum;
							queue.at(j).first = key[neighbours.at(i)];
							break;
						}
					}
				}
			}
		}
		std::make_heap(queue.begin(), queue.end(), std::greater<>{});
	}
	std::cout << std::endl << "DRZEWO MST (reprezentacja listowa):" << std::endl;
	std::cout << std::endl << "KRAWEDZ      WAGA" << std::endl;
	int sum = 0;
	for (int i = 0; i < numberOfVertices; i++) {
		if (parent[i] != -1) {
			std::cout << "(" << i << ", " << parent[i] << ")      " << key[i] << std::endl;
			sum += key[i];
		}
	}
	std::cout << std::endl << "SUMA KRAWEDZI: " << sum << std::endl;
	delete[] parent;
	delete[] key;
}

void GraphList::KruskalAlgorithm()
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
	//dla kazdego wierzcholka przegladamy liste sasiadow
	std::list<Node> currentList;
	for (int i = 0; i < numberOfVertices; i++) {
		currentList = vec.at(i);
		for (auto it = currentList.begin(); it != currentList.end(); ++it) {
			if ((*it).verticeNum > i) {
				edges.push_back(Edge(i, (*it).verticeNum, (*it).weight));
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
		edges.erase(edges.begin());
	}
	std::cout << std::endl << "DRZEWO MST (reprezentacja listowa):" << std::endl;
	std::cout << std::endl << "KRAWEDZ     WAGA" << std::endl;
	int sum = 0;
	for (int i = 0; i < result.size(); i++) {
		std::cout << "(" << result.at(i).startVertice << ", " << result.at(i).endVertice << ")      " << result.at(i).weight << std::endl;
		sum += result.at(i).weight;
	}
	std::cout << std::endl << "SUMA KRAWEDZI: " << sum << std::endl;
}

GraphList::Node::Node(int verticeNum, int weight)
{
	this->verticeNum = verticeNum;
	this->weight = weight;
}


