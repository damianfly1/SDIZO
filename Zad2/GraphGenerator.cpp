#include "GraphGenerator.h"

std::vector<Edge> GraphGenerator::generateMST(int numberOfVertices, int densityPercentage)
{
	std::vector<Edge> edges;
	srand(time(NULL));
	int weight = 0;
	int maxEdgeNum = ((numberOfVertices) * (numberOfVertices - 1)) / 2;
	//najpierw tworzymy drzewo o gestosci 100%
	for (int i = 0; i < numberOfVertices; i++) {
		//dla kazdego wierzcholka dodajemy krawedzi do kazdego
		for (int j = i + 1; j < numberOfVertices; j++) {
			weight = (rand() % 100) + 1;
			edges.push_back(Edge(i, j, weight));
		}
	}
	//sprawdzamy ile krawedzi musimy usunac zeby uzyskac odpowiednia gestosc grafu
	//dla grafu nieskierowanego
	float currentDensity = 100;
	//ilosc krawedzi ktorych potrzebujemy
	int edgesNeeded = (((float)densityPercentage / (float)100) * (float)(numberOfVertices) * (float)(numberOfVertices - 1)) / 2;
	//minimalna ilosc krawedzi
	int minimalEdgeCount = numberOfVertices - 1;
	int deleteEdgesCount = maxEdgeNum - edgesNeeded;
	//jesli 
	if (maxEdgeNum - deleteEdgesCount < minimalEdgeCount) {
		deleteEdgesCount = maxEdgeNum - minimalEdgeCount;
	}
	//przegl¹damy listê krawêdzi
	for (auto it = edges.begin(); it != edges.end();) {
		//jesli krawedz nie jest czescia tworzy drzewa rozpinajacego
		if (((*it).startVertice != (*it).endVertice - 1)) {
			if (deleteEdgesCount == 0) {
				return edges;
			}
			edges.erase(it);
			deleteEdgesCount--;
		}
		else {
			++it;
		}
	}
	return edges;
}

std::vector<Edge> GraphGenerator::generateSP(int numberOfVertices, int densityPercentage)
{
	std::vector<Edge> edges;
	srand(time(NULL));
	int weight = 0;
	int maxEdgeNum = ((numberOfVertices) * (numberOfVertices - 1));
	//najpierw tworzymy drzewo o gestosci 100%
	for (int i = 0; i < numberOfVertices; i++) {
		//dla kazdego wierzcholka dodajemy krawedzi do kazdego
		for (int j = i + 1; j < numberOfVertices; j++) {
			weight = (rand() % 100) + 1;
			edges.push_back(Edge(i, j, weight));
		}
		for (int j = i - 1; j >= 0; j--) {
			weight = (rand() % 100) + 1;
			edges.push_back(Edge(i, j, weight));
		}
	}
	//sprawdzamy ile krawedzi musimy usunac zeby uzyskac odpowiednia gestosc grafu
	//dla grafu nieskierowanego
	float currentDensity = 100;
	//ilosc krawedzi ktorych potrzebujemy
	int edgesNeeded = (((float)densityPercentage / (float)100) * (float)(numberOfVertices) * (float)(numberOfVertices - 1));
	//minimalna ilosc krawedzi
	int minimalEdgeCount = numberOfVertices - 1;
	int deleteEdgesCount = maxEdgeNum - edgesNeeded;
	//jesli 
	if (maxEdgeNum - deleteEdgesCount < minimalEdgeCount) {
		deleteEdgesCount = maxEdgeNum - minimalEdgeCount;
	}
	//przegl¹damy listê krawêdzi
	for (auto it = edges.begin(); it != edges.end();) {
		//jesli krawedz nie jest czescia tworzy drzewa rozpinajacego
		if (((*it).startVertice != (*it).endVertice - 1)) {
			if (deleteEdgesCount == 0) {
				return edges;
			}
			edges.erase(it);
			deleteEdgesCount--;
		}
		else {
			++it;
		}
	}
	return edges;
}
