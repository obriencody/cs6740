
#include <iostream>
#include <cstring>
#include <vector>
#include <limits>

// custom made header files
#include "encryptDecrypt.h"
#include "toolSetOptionsMain.h"
#include "decryptionTime.h"
#include "encryptionTime.h"
#include "employeeDir.h"

using std::cin;
using std::cout;
using std::endl;
using std::vector;

void toolSetOptionsMain() {
	// Declare vector of string type for the toolset
	vector <char const*> toolSetOptions;

	// Initialize vector with strings using push_back command
	// This is for the toolSetOptions menu
	// Update future menu here!! 
	toolSetOptions.push_back("Encrypt/Decrypt");
	toolSetOptions.push_back("Employee Directory");
	toolSetOptions.push_back("Exit");

	unsigned int exitOption = toolSetOptions.size();

	// userInput for toolSetOptions
	unsigned int userInputToolSetOption;

	do {
		for (unsigned int i = 0; i < toolSetOptions.size(); i++) {
			unsigned int displayToolSetSize = i + 1;
			cout << displayToolSetSize << ") " << toolSetOptions[i] << endl;
		}

		cin >> userInputToolSetOption;

		// Clear cin
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		switch (userInputToolSetOption) {
		case 1:
			cout << toolSetOptions[userInputToolSetOption - 1] << endl;
			encryptDecrypt();
			break;
		case 2:
			cout << toolSetOptions[userInputToolSetOption - 1] << endl;
			employeeDir(); // go to employee directory
			break;
		case 3:
			cout << "Thank you for participating! Goodbye." << endl;
			return; // exiting the program
			break;
		default:
			cout << "The input value is invalid!" << endl;
			//toolSetOptionsMain();
			break;
		}
	} while (userInputToolSetOption <= 0 || userInputToolSetOption > toolSetOptions.size() || userInputToolSetOption != exitOption);

}