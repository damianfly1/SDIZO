#pragma once
#include "GraphMatrix.h"
#include "GraphList.h"
#include "Clock.h"
#include "FileReader.h"
#include "GraphGenerator.h"
#include <fstream>

using namespace std;

class Tester {

private:
	//wskaźnik na obiekt klasy GraphMatrix
	GraphMatrix* matrix = nullptr;
	//wskaźnik na obiekt klasy GraphList
	GraphList* list = nullptr;
	//zmienna przechowująca referencję do obiektu klasy Clock
	Clock clock;
	GraphGenerator randGenerator;
	void primTest();
	void kruskalTest();
	void dijkstraTest();
	void bellmanTest();
	void primHelper(int numberOfVertices, int densityPercentage, string filenameMatrix, string filenameList);
	void kruskalHelper(int numberOfVertices, int densityPercentage, string filenameMatrix, string filenameList);
	void bellmanHelper(int numberOfVertices, int densityPercentage, string filenameMatrix, string filenameList);
	void dijkstraHelper(int numberOfVertices, int densityPercentage, string filenameMatrix, string filenameList);
public:
	void testMenu();
};

