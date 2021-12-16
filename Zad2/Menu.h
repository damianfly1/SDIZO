#pragma once
#include "GraphMatrix.h"
#include "GraphList.h"
#include "Clock.h"
#include "FileReader.h"
#include "GraphGenerator.h"
#include "Tester.h"


/// <summary>
/// Klasa zawieraj�ce w sobie wszystkie menu i wywo�uj�ca operacje na grafach
/// </summary>
class Menu {

private:
	//wska�nik na obiekt klasy GraphMatrix
	GraphMatrix* matrix = nullptr;
	//wska�nik na obiekt klasy GraphList
	GraphList* list = nullptr;
	//zmienna przechowuj�ca referencj� do obiektu klasy Clock
	Clock clock;
	GraphGenerator randGenerator;
	Tester tester;

public:
	/// <summary>
	/// Menu startowe odpowiedzialne za wyb�r rozpatrywanego problemu
	/// </summary>
	void chooseProblem();
	/// <summary>
	/// Menu dla problemu MST
	/// </summary>
	void menuMSTProblem();
	/// <summary>
	/// Menu dla problemu najkr�tszej �cie�ki w grafie
	/// </summary>
	void menuShortestPathProblem();
	/// <summary>
	/// Funkcja wprowadzaj�ca ekran oczekiwania, pozwalaj�cy u�ytkownikowy na przeczytanie komunikat�w
	/// </summary>
	void waitingScreen();
};