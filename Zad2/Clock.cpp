#include "Clock.h"

void Clock::start()
{
	t1 = std::chrono::high_resolution_clock::now();
}

void Clock::stop()
{
	t2 = std::chrono::high_resolution_clock::now();
	time = (std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1)).count();
}

void Clock::printResult()
{
	std::cout << std::endl;
	std::cout << "Operacja zajela mi " << (std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1)).count() << " mikrosekund";
	std::cout << std::endl;
}

void Clock::printToFile(std::ofstream& file, int time1, std::string text)
{
	file << text << " " << time1 << '\n';
}
