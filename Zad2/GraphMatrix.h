#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include "Edge.h"
#include "KruskalVertice.h"

/// <summary>
/// Klasa przechowuje graf w postaci macierzy s¹siedztwa
/// </summary>
class GraphMatrix
{
private:
	//wskaznik na dwuwymiarow¹ tablicê przechowuj¹c¹ macierz s¹siedztwa
	int** tab;
	//zmienna przechowuj¹ca iloœæ wierzcho³ków grafu
	int numberOfVertices;
	//zmienna przechowuj¹ca iloœæ krawêdzi grafu
	int numberOfEdges;
	//vector przechowuj¹cy krawêdzie w algorytmie Kruskala
	std::vector<KruskalVertice> vertices;
	int startingVertice;
	int FindSet(int verticeNum);
	void Union(int verOne, int verTwo);
public:
	~GraphMatrix();
	/// <summary>
	/// Funkcja odpowiada za losowe wygenerowanie grafu
	/// Jako argumenty przyjmowane s¹ iloœæ wierzcho³ków i jego gêstoœæ w %
	/// </summary>
	/// <param name="numberOfVertives"></param>
	/// <param name="densityPercentage"></param>
	/// <returns></returns>
	bool generateRandomMST(std::vector<Edge> edges, int  numberOfVertices);
	bool generateRandomSP(std::vector<Edge> edges, int  numberOfVertices);
	bool createFromFileMST(std::vector<int> fileInfo);
	bool createFromFileSP(std::vector<int> fileInfo);
	void DijkstraAlgorithm();
	void BellmanFordAlgorithm();
	/// <summary>
	/// Funkcja odpowiada za wyœwietlenie grafu w postaci macierzy s¹siedztwa
	/// </summary>
	void display();
	void PrimAlgorithm();
	void KruskalAlgorithm();

};

