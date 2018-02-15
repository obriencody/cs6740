

#include <iostream>
#include <string>
#include <vector>
#include <limits>

// To prevent those using g++ from trying to use a library
// They don't have
#ifndef __GNUC__
#include <conio.h>
#endif

// custom made header files
//#include "encryptDecrypt.h"
#include "toolSetOptionsMain.h"
//#include "decryptionTime.h"
//#include "encryptionTime.h"


using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

// user menu array so inputs are fast and update easily
//string menuOptions[3] = { "Encrypt", "Decrypt", "Main Menu" };

void pressAnyKeyToContinue() { 
	cout << "Press any key to continue...";

	// Linux and Mac users with g++ don't need this
	// But everyone else will see this message.
#ifndef __GNUC__
	_getch();
#else
	int c;
	fflush(stdout);
	do c = getchar(); while ((c != '\n') && (c != EOF));
#endif
	cout << endl;
}

int main() {
	// State the options for the user to input
	// These options will grow as the semester progresses
	cout << "Please listen carefully as my menu may have changed." << endl;
	cout << "Press the corresponding number to the program you would like to execute." << endl;
	
	toolSetOptionsMain();

	pressAnyKeyToContinue();
}