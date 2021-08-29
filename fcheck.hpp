// fcheck.h -- <lib> checking fstream objects for errors

#ifndef FCHECKHECK_HPP
#define FCHECKHECK_HPP

#include <fstream>
#include <iostream>

#include "messages/current.hpp"

			//...:::is_open start:::...//
bool is_open(std::ifstream & inFile, const char *filename, bool exit_if_closed) {		// is_open ifstream char*
	if (inFile.is_open())
		return true;
	else {
		std::cout << FCHECK_PREFIX << FCHECK_FAILED_TO_OPEN;
		if (exit_if_closed) exit(EXIT_FAILURE);
		return false;
	}
}

bool is_open(void (*funpt)(const char*), std::ifstream & inFile, const char *filename, const bool exit_if_closed) {	// is_open ifstream char*, function
	if (inFile.is_open())
		return true;
	else {
		(*funpt)(filename);
		if (exit_if_closed) exit(EXIT_FAILURE);
		return false;
	}
}

bool is_open(std::ofstream & outFile, const char *filename, bool exit_if_closed) {		// is_open ofstream char*
	if (outFile.is_open())
		return true;
	else {
		std::cout << FCHECK_PREFIX << FCHECK_FAILED_TO_OPEN;
		if (exit_if_closed) exit(EXIT_FAILURE);
		return false;
	}
}

bool is_open(void (*funpt)(const char*), std::ofstream & outFile, const char *filename, bool exit_if_closed) {		// is_open ofstream char*, function
	if (outFile.is_open())
		return true;
	else {
		(*funpt)(filename);
		if (exit_if_closed) exit(EXIT_FAILURE);
		return false;
	}
}
			//...:::is_open end:::...//

			//...:::ifstrm_status start:::...//

// ifstream status char*
short ifstrm_status(std::ifstream & inFile, const char *filename, bool exit_if_fail, bool eof_react, bool slient) {	
	if (inFile.good())
	       return 0;
	short rtrn;
	if (inFile.eof()) {
		if (!eof_react)
			return 0;
		rtrn = 1;
		if (!slient)
			std::cout << FCHECK_PREFIX << FCHECK_EOF;
	} else
	if (inFile.fail()) {
		rtrn = 2;
		if (!slient)
			std::cout << FCHECK_PREFIX << FCHECK_FAIL;
	} else {
		rtrn = 3;
		if (!slient)
			std::cout << FCHECK_PREFIX << FCHECK_BAD;
	}
	if (exit_if_fail) exit(EXIT_FAILURE);
	return rtrn;
}

// ifstream status char*, function
short ifstrm_status(void (*funpt[3])(const char*), std::ifstream & inFile, const char *filename, bool exit_if_fail, bool eof_react, bool slient) {
	if (inFile.good())
	       return 0;
	int rtrn;
	if (inFile.eof()) {
		if (!eof_react)
			return 0;
		rtrn = 1;
		if (!slient)
			funpt[0](filename);
	} else
	if (inFile.fail()) {
		rtrn = 2;
		if (!slient)
			funpt[1](filename);
	} else {
		rtrn = 3;
		if (!slient)
			(*funpt[2])(filename);
	}
	if (exit_if_fail) exit(EXIT_FAILURE);
	return rtrn;
}

			//...:::ifstrm_status end:::...//
#endif

// last edit: 25/08/2021
// developed by https://github.com/Dolfost
// license : https://github.com/Dolfost/fcheck-cpp/blob/main/COPYING
