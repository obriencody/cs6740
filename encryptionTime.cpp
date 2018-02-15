// pre-programmed header files
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>

// custom made header files
#include "encryptDecrypt.h"
#include "toolSetOptionsMain.h"
#include "decryptionTime.h"
#include "encryptionTime.h"
//#include "openFile.h"

using std::string;
using std::endl;
using std::cin;
using std::cout;
using std::ofstream;
using std::ifstream;
using std::getline;
using std::find;



void encryptionTime() {

	cout << "Input Filename (will have .txt appended automatically): ";
	string selectedString;
	cin >> selectedString;
	//string selectedString = openFile(); // This is the input that we would like to decrypt
	string line;

	// create string of lowercase alphabet to search through
	string alphabet = "abcdefghijklmnopqrstuvwxyz";

	// create string of uppercase alphabet to search through
	string upperAlphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	char updateKey;
	char updateString;

	// prompt user for key-- may be a string of chars or a single char
	string key;
	cout << "Please enter a key (single character or a string of characters): ";
	cin >> key; // user input for the key
	cin.ignore(); // ignore anything trailing after input

	// convert key to lowercase
	std::transform(key.begin(), key.end(), key.begin(), ::tolower);

	ifstream input;
	input.open(selectedString + ".txt");
	
	// create a string to output the filename of the encrypted file
	string outputFilename;
	cout << "Output Filename (will have .txt appended automatically): ";
	cin >> outputFilename;

	ofstream output(outputFilename + ".txt");

	unsigned int k_i = 0;

	if (!input) {
		cout << "Unable to open file." << endl;
		exit(1);
	}
	while (getline(input, line)) {
		//cout << "line: " << line << endl;

		// convert input to lowercase
		std::transform(line.begin(), line.end(), line.begin(), ::tolower);
		for (int i = 0; i < line.length(); i++) {
			if (isalpha(line[i])) { // characters or not

											  // compare the current value of selectedString against alpha and Upperalpha
											  // wrap around key
											  // wrap around selectedString

				if (k_i >= key.length()) {
					k_i = 0;
				}

				std::size_t foundKey = alphabet.find(key[k_i]);

				//cout << "found has value: " << foundKey << endl;
				//cout << "alphabet char: " << alphabet[foundKey] << endl;

				std::size_t foundSelection = alphabet.find(line[i]);

				// create an integer to calculate the distance to travel in alphabet search and replace value in selectedString
				unsigned int alphaSearch = (foundKey + foundSelection) % 26;

				// update encrypted characters in selected string and store in correct location
				line[i] = alphabet[alphaSearch];

				// output the character position value in 
				//cout << "foundSelection has value: " << foundSelection << endl;
				//cout << "alphabet char for string: " << selectedString[i] << endl;

				// create variables for old and new to encrypt the file

				if (i == line.length() - 1) {
					cout << endl;
				}
				k_i++;
			}
		}
		output << line << endl;
	}
	output.close();
	encryptDecrypt();
}