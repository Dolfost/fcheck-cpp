#include <iostream>
#include <fstream>
#include "../../fcheck.hpp"

void check_output0(const char*);
void check_output1(const char*);
void check_output2(const char*);
int main(void) {
	char filename[4256];
	std::cout << "Enter file name: ";
	std::cin.get(filename, 4256);
	std::cout << "Calling function ifstrm_status() with fc_pt[3]() as error out for " << filename << "...\n\n";
	std::ifstream file;
	file.open(filename);
	void (*fc_pt[3])(const char*) = {check_output0, check_output1, check_output2};
	bool sts = ifstrm_status(fc_pt, file, filename, false, true, false);
	std::cout << "\nFunction returned " << sts << "\n";
}

void check_output0(const char *filename) {
	std::cout << "Reached end of file \"" << filename << "\".\n"; // file.eof()
}
void check_output1(const char *filename) {
	std::cout << "Input from file \"" << filename << "\" terminated by data missmatch.\n"; // file.fail()
}
void check_output2(const char *filename) {
	std::cout << "Input from file \"" << filename << "\" terminated for unknown reason.\n"; // file.bad()
}
