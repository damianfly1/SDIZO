#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include "Edge.h"
#include "KruskalVertice.h"

/// <summary>
/// Klasa przechowuje graf w postaci macierzy s�siedztwa
/// </summary>
class GraphMatrix
{
private:
	//wskaznik na dwuwymiarow� tablic� przechowuj�c� macierz s�siedztwa
	int** tab;
	//zmienna przechowuj�ca ilo�� wierzcho�k�w grafu
	int numberOfVertices;
	//zmienna przechowuj�ca ilo�� kraw�dzi grafu
	int numberOfEdges;
	//vector przechowuj�cy kraw�dzie w algorytmie Kruskala
	std::vector<KruskalVertice> vertices;
	int startingVertice;
	int FindSet(int verticeNum);
	void Union(int verOne, int verTwo);
public:
	~GraphMatrix();
	/// <summary>
	/// Funkcja odpowiada za losowe wygenerowanie grafu
	/// Jako argumenty przyjmowane s� ilo�� wierzcho�k�w i jego g�sto�� w %
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
	/// Funkcja odpowiada za wy�wietlenie grafu w postaci macierzy s�siedztwa
	/// </summary>
	void display();
	void PrimAlgorithm();
	void KruskalAlgorithm();

};

