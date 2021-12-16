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
/// Klasa przechowuje graf w postaci listy s�siad�w
/// </summary>
class GraphList
{
private:
	/// <summary>
	/// Klasa b�d�ca elementem jednej listy przechowuj�cej s�siad�w danego wierzcho�ka
	/// </summary>
	class Node
	{
	public:
		//publiczy kostruktor
		Node(int verticeNum, int weight);
		//numer wierzcho�ka
		int verticeNum;
		//waga kraw�dzi do tego wierzcho�ka
		int weight;
	};
	//vector przechowuj�cy listy s�siad�w dla wierzcho�k�w
	std::vector<std::list<Node>> vec;
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
	~GraphList();
	/// <summary>
	/// Funkcja odpowiada za losowe wygenerowanie grafu
	/// Jako argumenty przyjmowane s� ilo�� wierzcho�k�w i jego g�sto�� w %
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
	/// Funkcja odpowiada za wy�wietlanie grafu w postaci listy s�siad�w
	/// </summary>
	void display();
	void PrimAlgorithm();
	void KruskalAlgorithm();
};
