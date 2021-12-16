#include "Menu.h"
#include <iostream>

void Menu::chooseProblem()
{
	bool running = true;
	while (running) {
		system("cls");
		std::cout << "Witaj w 2 zad projektowym ze SDIZO!";
		std::cout << std::endl;
		std::cout << "Wybierz ktory z problemow chcesz rozwiazac:" << std::endl;
		std::cout << "1. Wyznaczanie minimalnego drzewa rozpinajacego MST" << std::endl;
		std::cout << "2. Wyznaczanie najkrotszej sciezki w grafie" << std::endl;
		std::cout << "3. Testy" << std::endl;
		std::cout << "4. Wyjdz z programu" << std::endl;
		int choice;
		std::cin >> choice;
		if (choice == 1) menuMSTProblem();
		else if (choice == 2) menuShortestPathProblem();
		else if (choice == 3) {
			system("cls");
			tester.testMenu();
		}
		else return;
	}
}

void Menu::menuMSTProblem()
{
	bool running = true;
	while (running) {
		system("cls");
		std::cout << "1. Wczytaj z pliku" << std::endl;
		std::cout << "2. Wygeneruj graf losowo" << std::endl;
		std::cout << "3. Wyswietl listowo i macierzowo" << std::endl;
		std::cout << "4. Algorytm Prima" << std::endl;
		std::cout << "5. Algorytm Kruskala" << std::endl;
		std::cout << "6. Wroc do menu" << std::endl;
		int choice;
		std::cin >> choice;
		switch (choice) {
		case 1:
		{
			if (matrix == nullptr) {
				matrix = new GraphMatrix();
				list = new GraphList();
			}
			else {
				delete matrix;
				delete list;
				matrix = new GraphMatrix();
				list = new GraphList();
			}
			std::cout << "Podaj nazwe pliku do wczytania: " << std::endl;
			std::string filename;
			std::cin >> filename;
			FileReader reader;
			std::vector<int> fileInfo = reader.readDataFromFileMST(filename);
			matrix->createFromFileMST(fileInfo);
			list->createFromFileMST(fileInfo);
			system("cls");
			matrix->display();
			list->display();
			waitingScreen();
		}
		break;
		case 2:
		{
			if (matrix == nullptr) {
				matrix = new GraphMatrix();
				list = new GraphList();
			}
			else {
				delete matrix;
				delete list;
				matrix = new GraphMatrix();
				list = new GraphList();
			}
			std::cout << "Podaj ilosc wierzcholkow grafu:" << std::endl;
			int numberOfVertices = -1;
			std::cin >> numberOfVertices;
			std::cout << "Podaj w procentach gestosc grafu:" << std::endl;
			int densityPercentage = -1;
			std::cin >> densityPercentage;
			std::vector<Edge> edges = randGenerator.generateMST(numberOfVertices, densityPercentage);
			matrix->generateRandomMST(edges, numberOfVertices);
			list->generateRandomMST(edges, numberOfVertices);
			matrix->display();
			list->display();
			waitingScreen();
		}
		break;
		case 3:
		{
			if (list != nullptr) {
				system("cls");
				list->display();
				matrix->display();
				waitingScreen();
			}
			else {
				system("cls");
				std::cout << "Brak stworzonego grafu";
				waitingScreen();
			}}
		break;
		case 4:
		{
			if (list != nullptr) {
				system("cls");
				clock.start();
				matrix->PrimAlgorithm();
				clock.stop();
				clock.printResult();
				clock.start();
				list->PrimAlgorithm();
				clock.stop();
				clock.printResult();
				waitingScreen();
			}
			else {
				system("cls");
				std::cout << "Brak stworzonego grafu";
				waitingScreen();
			}
		}
		break;
		case 5:
		{
			if (list != nullptr) {
				system("cls");
				clock.start();
				matrix->KruskalAlgorithm();
				clock.stop();
				clock.printResult();
				clock.start();
				list->KruskalAlgorithm();
				clock.stop();
				clock.printResult();
				waitingScreen();
			}
			else {
				system("cls");
				std::cout << "Brak stworzonego grafu";
				waitingScreen();
			}
		}
		break;
		case 6:
		{
			if (matrix != nullptr) {
				delete matrix;
				delete list;
				matrix = nullptr;
				list = nullptr;
			}
			running = false;
			break;
		}
		default:
		{
			break;
		}
		}
	}
}

void Menu::menuShortestPathProblem()
{
	bool running = true;
	while (running) {
		system("cls");
		std::cout << "1. Wczytaj z pliku" << std::endl;
		std::cout << "2. Wygeneruj graf losowo" << std::endl;
		std::cout << "3. Wyswietl listowo i macierzowo" << std::endl;
		std::cout << "4. Algorytm Dijkstry" << std::endl;
		std::cout << "5. Algorytm Bellmana Forda" << std::endl;
		std::cout << "6. Wroc do menu" << std::endl;
		int choice;
		std::cin >> choice;
		switch (choice) {
		case 1:
		{
			if (matrix = nullptr) {
				matrix = new GraphMatrix();
				list = new GraphList();
			}
			else {
				delete matrix;
				delete list;
				matrix = new GraphMatrix();
				list = new GraphList();
			}
			std::cout << "Podaj nazwe pliku do wczytania: " << std::endl;
			std::string filename;
			std::cin >> filename;
			FileReader reader;
			std::vector<int> fileInfo = reader.readDataFromFileSP(filename);
			matrix->createFromFileSP(fileInfo);
			list->createFromFileSP(fileInfo);
			system("cls");
			matrix->display();
			list->display();
			waitingScreen();
		}
		break;
		case 2:
		{
			if (matrix = nullptr) {
				matrix = new GraphMatrix();
				list = new GraphList();
			}
			else {
				delete matrix;
				delete list;
				matrix = new GraphMatrix();
				list = new GraphList();
			}
			std::cout << "Podaj ilosc wierzcholkow grafu:" << std::endl;
			int numberOfVertices = -1;
			std::cin >> numberOfVertices;
			std::cout << "Podaj w procentach gestosc grafu:" << std::endl;
			int densityPercentage = -1;
			std::cin >> densityPercentage;
			std::vector<Edge> edges = randGenerator.generateSP(numberOfVertices, densityPercentage);
			matrix->generateRandomSP(edges, numberOfVertices);
			list->generateRandomSP(edges, numberOfVertices);
			matrix->display();
			list->display();
			waitingScreen();
		}
		break;
		case 3:
		{
			if (list != nullptr) {
				system("cls");
				list->display();
				matrix->display();
				waitingScreen();
			}
			else {
				system("cls");
				std::cout << "Brak stworzonego grafu";
				waitingScreen();
			}
		}
		break;
		case 4:
		{
			if (matrix != nullptr) {
				system("cls");
				clock.start();
				matrix->DijkstraAlgorithm();
				clock.stop();
				clock.printResult();
				clock.start();
				list->DijkstraAlgorithm();
				clock.stop();
				clock.printResult();
				waitingScreen();
			}
			else {
				system("cls");
				std::cout << "Brak stworzonego grafu";
				waitingScreen();
			}
		}
		break;
		case 5:
		{
			if (matrix != nullptr) {
				system("cls");
				clock.start();
				matrix->BellmanFordAlgorithm();
				clock.stop();
				clock.printResult();
				clock.start();
				list->BellmanFordAlgorithm();
				clock.stop();
				clock.printResult();
				waitingScreen();
			}
			else {
				system("cls");
				std::cout << "Brak stworzonego grafu";
				waitingScreen();
			}
		}
		break;
		case 6:
		{
			if (matrix != nullptr) {
				delete matrix;
				delete list;
				matrix = nullptr;
				list = nullptr;
			}
			running = false;
			break;
		}
		default:
		{
			break;
		}
		}
	}
}

void Menu::waitingScreen()
{
	std::cout << std::endl << std::endl << "Wprowadz 1 zeby kontynuowac" << std::endl << std::endl;
	int choice;
	std::cin >> choice;
}
