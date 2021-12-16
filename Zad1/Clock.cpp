#include "Clock.h"

void Clock::start()
{
	t1 = std::chrono::high_resolution_clock::now();
}

void Clock::stop()
{
	t2 = std::chrono::high_resolution_clock::now();
}

void Clock::printResult()
{
	std::cout << std::endl;
	std::cout << "Operacja zajela mi " << (std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1)).count() << " nanosekund";
	std::cout << std::endl;
}

void Clock::printToFile(std::ofstream& file) 
{
	// time = (std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1)).count()/200;
	file <<  (std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1)).count()/200 << '\n';
}
