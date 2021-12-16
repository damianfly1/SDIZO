#pragma once
#include <chrono>
#include <iostream>
#include <fstream>

class Clock {

private:
	std::chrono::high_resolution_clock::time_point t1, t2; //punkt startowy i koncowy pomiaru

public:
	void start(); //uruchom zegar
	void stop(); //zatrzymaj zegar
	void printResult(); //wyswietl zmierzony czas
	void printToFile(std::ofstream&);
};