
#include <iostream>
#include <string>
#include <vector>
#include <limits>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

// custom made header files
#include "encryptDecrypt.h"
#include "toolSetOptionsMain.h"
#include "decryptionTime.h"
#include "encryptionTime.h"
#include "encryptionTimeText.h"
#include "decryptionTimeText.h"

// define global variables
	int userInput;


void encryptDecrypt() {
	// Declare vector of String type
	vector <string> menuOptions;

	// Initialize vector with strings using push_back command
	// this allows the space to dynamically grow
	// update future menu here!!!!!!
	menuOptions.push_back("Encrypt text");
	menuOptions.push_back("Decrypt text");
	menuOptions.push_back("Encrypt a File");
	menuOptions.push_back("Decrypt a File");
	menuOptions.push_back("Main Menu");

	unsigned int exitOption = menuOptions.size();

	do {
		for (unsigned int i = 0; i < menuOptions.size(); i++) {
			unsigned int displayVal = i + 1;
			cout << displayVal << ") " << menuOptions[i] << endl;
		}

		// User input section
		// Update the max value the user may input as an option
		cin >> userInput;

		// Clear cin
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		// switch case for encrypt/decrypt menu
		switch (userInput) {
		case 1:
			cout << "The value you entered is " << userInput << endl;
			cout << "We are now going to... ";
			cout << menuOptions[userInput - 1] << "\n";
			encryptionTimeText();
			break;
		case 2:
			cout << "The value you entered is " << userInput << endl;
			cout << "We are now going to... ";
			cout << menuOptions[userInput - 1] << "\n";
			decryptionTimeText();
			break;
		case 3:
			cout << "The value you entered is " << userInput << endl;
			cout << "We are now going to... ";
			cout << menuOptions[userInput - 1] << "\n";
			encryptionTime();
			break;
		case 4:
			cout << "The value you entered is " << userInput << endl;
			cout << "We are now going to... ";
			cout << menuOptions[userInput - 1] << "\n";
			decryptionTime();
			break;
		case 5:
			cout << "The value you entered is " << userInput << endl;
			cout << "We are now going to... ";
			cout << menuOptions[userInput - 1] << "\n";
			break;
		default:
			cout << "Invalid input. Please try again." << endl;
			encryptDecrypt();
			break;
		}
	} while (userInput <= 0 || userInput > menuOptions.size() || userInput != exitOption);
}