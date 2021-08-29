#include <iostream>
#include <fstream>
#include "../../fcheck.hpp"

void check_output(const char*);

int main(void) {
	char filename[4256];
	std::cout << "Enter file name: ";
	std::cin.get(filename, 4256);
	std::cout << "Calling function is_open() with check_output() as error out for " << filename << "...\n\n";
	std::ifstream file;
	file.open(filename);
	bool sts = is_open(check_output, file, filename, false);
	std::cout << "\n\nFunction returned " << sts << "\n";
}

void check_output(const char *filename) {
	std::cout << "Could not open a file \"" << filename << "\".\n";
}
