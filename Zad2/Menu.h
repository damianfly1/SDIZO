#pragma once
#include "GraphMatrix.h"
#include "GraphList.h"
#include "Clock.h"
#include "FileReader.h"
#include "GraphGenerator.h"
#include "Tester.h"


/// <summary>
/// Klasa zawieraj¹ce w sobie wszystkie menu i wywo³uj¹ca operacje na grafach
/// </summary>
class Menu {

private:
	//wskaŸnik na obiekt klasy GraphMatrix
	GraphMatrix* matrix = nullptr;
	//wskaŸnik na obiekt klasy GraphList
	GraphList* list = nullptr;
	//zmienna przechowuj¹ca referencjê do obiektu klasy Clock
	Clock clock;
	GraphGenerator randGenerator;
	Tester tester;

public:
	/// <summary>
	/// Menu startowe odpowiedzialne za wybór rozpatrywanego problemu
	/// </summary>
	void chooseProblem();
	/// <summary>
	/// Menu dla problemu MST
	/// </summary>
	void menuMSTProblem();
	/// <summary>
	/// Menu dla problemu najkrótszej œcie¿ki w grafie
	/// </summary>
	void menuShortestPathProblem();
	/// <summary>
	/// Funkcja wprowadzaj¹ca ekran oczekiwania, pozwalaj¹cy u¿ytkownikowy na przeczytanie komunikatów
	/// </summary>
	void waitingScreen();
};