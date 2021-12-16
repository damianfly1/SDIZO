#include "Tester.h"

void Tester::primTest()
{
	primHelper(25, 20, "prim-25-20-matrix", "prim-25-20-list");
	primHelper(25, 60, "prim-25-60-matrix", "prim-25-60-list");
	primHelper(25, 99, "prim-25-99-matrix", "prim-25-99-list");

	primHelper(50, 20, "prim-50-20-matrix", "prim-50-20-list");
	primHelper(50, 60, "prim-50-60-matrix", "prim-50-60-list");
	primHelper(50, 99, "prim-50-99-matrix", "prim-50-99-list");

	primHelper(100, 20, "prim-100-20-matrix", "prim-100-20-list");
	primHelper(100, 60, "prim-100-60-matrix", "prim-100-60-list");
	primHelper(100, 99, "prim-100-99-matrix", "prim-100-99-list");

	primHelper(150, 20, "prim-150-20-matrix", "prim-150-20-list");
	primHelper(150, 60, "prim-150-60-matrix", "prim-150-60-list");
	primHelper(150, 99, "prim-150-99-matrix", "prim-150-99-list");

	primHelper(200, 20, "prim-200-20-matrix", "prim-200-20-list");
	primHelper(200, 60, "prim-200-60-matrix", "prim-200-60-list");
	primHelper(200, 99, "prim-200-99-matrix", "prim-200-99-list");

	primHelper(250, 20, "prim-250-20-matrix", "prim-250-20-list");
	primHelper(250, 60, "prim-250-60-matrix", "prim-250-60-list");
	primHelper(250, 99, "prim-250-99-matrix", "prim-250-99-list");

	primHelper(300, 20, "prim-300-20-matrix", "prim-300-20-list");
	primHelper(300, 60, "prim-300-60-matrix", "prim-300-60-list");
	primHelper(300, 99, "prim-300-99-matrix", "prim-300-99-list");
}

void Tester::kruskalTest()
{
	kruskalHelper(25, 20, "kruskal-25-20-matrix", "kruskal-25-20-list");
	kruskalHelper(25, 60, "kruskal-25-60-matrix", "kruskal-25-60-list");
	kruskalHelper(25, 99, "kruskal-25-99-matrix", "kruskal-25-99-list");

	kruskalHelper(50, 20, "kruskal-50-20-matrix", "kruskal-50-20-list");
	kruskalHelper(50, 60, "kruskal-50-60-matrix", "kruskal-50-60-list");
	kruskalHelper(50, 99, "kruskal-50-99-matrix", "kruskal-50-99-list");

	kruskalHelper(100, 20, "kruskal-100-20-matrix", "kruskal-100-20-list");
	kruskalHelper(100, 60, "kruskal-100-60-matrix", "kruskal-100-60-list");
	kruskalHelper(100, 99, "kruskal-100-99-matrix", "kruskal-100-99-list");

	kruskalHelper(150, 20, "kruskal-150-20-matrix", "kruskal-150-20-list");
	kruskalHelper(150, 60, "kruskal-150-60-matrix", "kruskal-150-60-list");
	kruskalHelper(150, 99, "kruskal-150-99-matrix", "kruskal-150-99-list");

	kruskalHelper(200, 20, "kruskal-200-20-matrix", "kruskal-200-20-list");
	kruskalHelper(200, 60, "kruskal-200-60-matrix", "kruskal-200-60-list");
	kruskalHelper(200, 99, "kruskal-200-99-matrix", "kruskal-200-99-list");

	kruskalHelper(250, 20, "kruskal-250-20-matrix", "kruskal-250-20-list");
	kruskalHelper(250, 60, "kruskal-250-60-matrix", "kruskal-250-60-list");
	kruskalHelper(250, 99, "kruskal-250-99-matrix", "kruskal-250-99-list");

	kruskalHelper(300, 20, "kruskal-300-20-matrix", "kruskal-300-20-list");
	kruskalHelper(300, 60, "kruskal-300-60-matrix", "kruskal-300-60-list");
	kruskalHelper(300, 99, "kruskal-300-99-matrix", "kruskal-300-99-list");
}

void Tester::dijkstraTest()
{
	dijkstraHelper(25, 20, "dijkstra-25-20-matrix", "dijkstra-25-20-list");
	dijkstraHelper(25, 60, "dijkstra-25-60-matrix", "dijkstra-25-60-list");
	dijkstraHelper(25, 99, "dijkstra-25-99-matrix", "dijkstra-25-99-list");

	dijkstraHelper(50, 20, "dijkstra-50-20-matrix", "dijkstra-50-20-list");
	dijkstraHelper(50, 60, "dijkstra-50-60-matrix", "dijkstra-50-60-list");
	dijkstraHelper(50, 99, "dijkstra-50-99-matrix", "dijkstra-50-99-list");

	dijkstraHelper(100, 20, "dijkstra-100-20-matrix", "dijkstra-100-20-list");
	dijkstraHelper(100, 60, "dijkstra-100-60-matrix", "dijkstra-100-60-list");
	dijkstraHelper(100, 99, "dijkstra-100-99-matrix", "dijkstra-100-99-list");

	dijkstraHelper(150, 20, "dijkstra-150-20-matrix", "dijkstra-150-20-list");
	dijkstraHelper(150, 60, "dijkstra-150-60-matrix", "dijkstra-150-60-list");
	dijkstraHelper(150, 99, "dijkstra-150-99-matrix", "dijkstra-150-99-list");

	dijkstraHelper(200, 20, "dijkstra-200-20-matrix", "dijkstra-200-20-list");
	dijkstraHelper(200, 60, "dijkstra-200-60-matrix", "dijkstra-200-60-list");
	dijkstraHelper(200, 99, "dijkstra-200-99-matrix", "dijkstra-200-99-list");

	dijkstraHelper(250, 20, "dijkstra-250-20-matrix", "dijkstra-250-20-list");
	dijkstraHelper(250, 60, "dijkstra-250-60-matrix", "dijkstra-250-60-list");
	dijkstraHelper(250, 99, "dijkstra-250-99-matrix", "dijkstra-250-99-list");

	dijkstraHelper(300, 20, "dijkstra-300-20-matrix", "dijkstra-300-20-list");
	dijkstraHelper(300, 60, "dijkstra-300-60-matrix", "dijkstra-300-60-list");
	dijkstraHelper(300, 99, "dijkstra-300-99-matrix", "dijkstra-300-99-list");
}

void Tester::bellmanTest()
{
	bellmanHelper(25, 20, "bellman-25-20-matrix", "bellman-25-20-list");
	bellmanHelper(25, 60, "bellman-25-60-matrix", "bellman-25-60-list");
	bellmanHelper(25, 99, "bellman-25-99-matrix", "bellman-25-99-list");

	bellmanHelper(50, 20, "bellman-50-20-matrix", "bellman-50-20-list");
	bellmanHelper(50, 60, "bellman-50-60-matrix", "bellman-50-60-list");
	bellmanHelper(50, 99, "bellman-50-99-matrix", "bellman-50-99-list");

	bellmanHelper(100, 20, "bellman-100-20-matrix", "bellman-100-20-list");
	bellmanHelper(100, 60, "bellman-100-60-matrix", "bellman-100-60-list");
	bellmanHelper(100, 99, "bellman-100-99-matrix", "bellman-100-99-list");

	bellmanHelper(150, 20, "bellman-150-20-matrix", "bellman-150-20-list");
	bellmanHelper(150, 60, "bellman-150-60-matrix", "bellman-150-60-list");
	bellmanHelper(150, 99, "bellman-150-99-matrix", "bellman-150-99-list");

	bellmanHelper(200, 20, "bellman-200-20-matrix", "bellman-200-20-list");
	bellmanHelper(200, 60, "bellman-200-60-matrix", "bellman-200-60-list");
	bellmanHelper(200, 99, "bellman-200-99-matrix", "bellman-200-99-list");

	bellmanHelper(250, 20, "bellman-250-20-matrix", "bellman-250-20-list");
	bellmanHelper(250, 60, "bellman-250-60-matrix", "bellman-250-60-list");
	bellmanHelper(250, 99, "bellman-250-99-matrix", "bellman-250-99-list");

	bellmanHelper(300, 20, "bellman-300-20-matrix", "bellman-300-20-list");
	bellmanHelper(300, 60, "bellman-300-60-matrix", "bellman-300-60-list");
	bellmanHelper(300, 99, "bellman-300-99-matrix", "bellman-300-99-list");
}

void Tester::primHelper(int numberOfVertices, int densityPercentage, string filenameMatrix, string filenameList)
{
	long long listTime = 0, matrixTime = 0;
	for (int i = 0; i < 100; i++) {
		std::vector<Edge> edges = randGenerator.generateMST(numberOfVertices, densityPercentage);
		matrix = new GraphMatrix();
		list = new GraphList();
		matrix->generateRandomMST(edges, numberOfVertices);
		clock.start();
		matrix->PrimAlgorithm();
		clock.stop();
		matrixTime += clock.time;
		list->generateRandomMST(edges, numberOfVertices);
		clock.start();
		list->PrimAlgorithm();
		clock.stop();
		listTime += clock.time;
		delete matrix;
		delete list;
	}
	ofstream fileMatrix("matrix-prim.txt", std::ios_base::app);
	clock.printToFile(fileMatrix, matrixTime / 100, filenameMatrix);
	fileMatrix.close();
	ofstream fileList("list-prim.txt", std::ios_base::app);
	clock.printToFile(fileList, listTime / 100, filenameList);
	fileList.close();
}

void Tester::kruskalHelper(int numberOfVertices, int densityPercentage, string filenameMatrix, string filenameList)
{
	long long listTime = 0, matrixTime = 0;
	for (int i = 0; i < 100; i++) {
		std::vector<Edge> edges = randGenerator.generateMST(numberOfVertices, densityPercentage);
		matrix = new GraphMatrix();
		list = new GraphList();
		matrix->generateRandomMST(edges, numberOfVertices);
		clock.start();
		matrix->KruskalAlgorithm();
		clock.stop();
		matrixTime += clock.time;
		list->generateRandomMST(edges, numberOfVertices);
		clock.start();
		list->KruskalAlgorithm();
		clock.stop();
		listTime += clock.time;
		delete matrix;
		delete list;
	}
	ofstream fileMatrix("matrix-kruskal.txt", std::ios_base::app);
	clock.printToFile(fileMatrix, matrixTime / 100, filenameMatrix);
	fileMatrix.close();
	ofstream fileList("list-kruskal.txt", std::ios_base::app);
	clock.printToFile(fileList, listTime / 100, filenameList);
	fileList.close();
}

void Tester::bellmanHelper(int numberOfVertices, int densityPercentage, string filenameMatrix, string filenameList)
{
	long long listTime = 0, matrixTime = 0;
	for (int i = 0; i < 100; i++) {
		std::vector<Edge> edges = randGenerator.generateSP(numberOfVertices, densityPercentage);
		matrix = new GraphMatrix();
		list = new GraphList();
		matrix->generateRandomSP(edges, numberOfVertices);
		clock.start();
		matrix->BellmanFordAlgorithm();
		clock.stop();
		matrixTime += clock.time;
		list->generateRandomSP(edges, numberOfVertices);
		clock.start();
		list->BellmanFordAlgorithm();
		clock.stop();
		listTime += clock.time;
		delete matrix;
		delete list;
	}
	ofstream fileMatrix("matrix-bellman.txt", std::ios_base::app);
	clock.printToFile(fileMatrix, matrixTime / 100, filenameMatrix);
	fileMatrix.close();
	ofstream fileList("list-bellman.txt", std::ios_base::app);
	clock.printToFile(fileList, listTime / 100, filenameList);
	fileList.close();
}

void Tester::dijkstraHelper(int numberOfVertices, int densityPercentage, string filenameMatrix, string filenameList)
{
	long long listTime = 0, matrixTime = 0;
	for (int i = 0; i < 100; i++) {
		std::vector<Edge> edges = randGenerator.generateSP(numberOfVertices, densityPercentage);
		matrix = new GraphMatrix();
		list = new GraphList();
		matrix->generateRandomSP(edges, numberOfVertices);
		clock.start();
		matrix->DijkstraAlgorithm();
		clock.stop();
		matrixTime += clock.time;
		list->generateRandomMST(edges, numberOfVertices);
		clock.start();
		list->DijkstraAlgorithm();
		clock.stop();
		listTime += clock.time;
		delete matrix;
		delete list;
	}
	ofstream fileMatrix("matrix-dijkstra.txt", std::ios_base::app);
	clock.printToFile(fileMatrix, matrixTime / 100, filenameMatrix);
	fileMatrix.close();
	ofstream fileList("list-dijkstra.txt", std::ios_base::app);
	clock.printToFile(fileList, listTime / 100, filenameList);
	fileList.close();
}

void Tester::testMenu()
{
	system("cls");
	cout << "Jaki algorytm chcesz przetestowac?" << endl;
	cout << "1. Algorytm Prima" << endl;
	cout << "2. Algorytm Kruskala" << endl;
	cout << "3. Algorytm Dijkstry" << endl;
	cout << "4. Algorytm Forda-Bellmana" << endl;
	cout << "5. Wroc do menu" << endl << endl;
	int choice;
	cin >> choice;
	switch (choice) {
	case 1:
		primTest();
		break;
	case 2:
		kruskalTest();
		break;
	case 3:
		dijkstraTest();
		break;
	case 4:
		bellmanTest();
		break;
	case 5:
		if (matrix != nullptr) {
			delete matrix;
			delete list;
			matrix = nullptr;
			list = nullptr;
		}
		break;
		return;
	}
}
