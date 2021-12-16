#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <string>
#include <fstream>
#include <queue>
#include "Edge.h"
#include "KruskalVertice.h"
/// <summary>
/// Klasa przechowuje graf w postaci listy s¹siadów
/// </summary>
class GraphList
{
private:
	/// <summary>
	/// Klasa bêd¹ca elementem jednej listy przechowuj¹cej s¹siadów danego wierzcho³ka
	/// </summary>
	class Node
	{
	public:
		//publiczy kostruktor
		Node(int verticeNum, int weight);
		//numer wierzcho³ka
		int verticeNum;
		//waga krawêdzi do tego wierzcho³ka
		int weight;
	};
	//vector przechowuj¹cy listy s¹siadów dla wierzcho³ków
	std::vector<std::list<Node>> vec;
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
	~GraphList();
	/// <summary>
	/// Funkcja odpowiada za losowe wygenerowanie grafu
	/// Jako argumenty przyjmowane s¹ iloœæ wierzcho³ków i jego gêstoœæ w %
	/// </summary>
	/// <param name="numberOfVertices"></param>
	/// <param name="densityPercentage"></param>
	/// <returns></returns>
	bool generateRandomMST(std::vector<Edge> edges, int  numberOfVertices);
	bool generateRandomSP(std::vector<Edge> edges, int  numberOfVertices);
	bool createFromFileMST(std::vector<int> fileInfo);
	bool createFromFileSP(std::vector<int> fileInfo);
	void DijkstraAlgorithm();
	void BellmanFordAlgorithm();
	/// <summary>
	/// Funkcja odpowiada za wyœwietlanie grafu w postaci listy s¹siadów
	/// </summary>
	void display();
	void PrimAlgorithm();
	void KruskalAlgorithm();
};
