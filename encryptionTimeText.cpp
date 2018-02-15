// pre-programmed header files
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>

#include "encryptionTimeText.h"
#include "encryptDecrypt.h"
//#include "openFile.h"

using std::string;
using std::endl;
using std::cin;
using std::cout;
using std::ofstream;
using std::ifstream;
using std::getline;
using std::find;

void encryptionTimeText() {

	string selectedString;
		
	cout << "Enter the message you would like to encrypt: " << endl;
	getline(cin, selectedString);

	cout << "Input is: " << selectedString << endl;

	//string selectedString = openFile(); // This is the input that we would like to encrypt
	//ifstream input(selectedString);

	// create string of lowercase alphabet to search through
	string alphabet = "abcdefghijklmnopqrstuvwxyz";

	// create string of uppercase alphabet to search through
	string upperAlphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	char updateKey;
	char updateString;

	if (selectedString != "") { // TODO: change to if() and remove selectedString = ""; at end of method
			
		// prompt user for key-- may be a string of chars or a single char
		string key;
		cout << "Please enter a key (single character or a string of characters): ";
		cin >> key; // user input for the key
		cin.ignore(); // ignore anything trailing after input

						// convert key to lowercase
		std::transform(key.begin(), key.end(), key.begin(), ::tolower);

		//cout << "key transformed is: " << key << endl;
		//cout << "The key is: " + key << endl; // display the key for testing purposes

		// convert input to lowercase
		std::transform(selectedString.begin(), selectedString.end(), selectedString.begin(), ::tolower);

		//cout << "The string output is: " << selectedString << endl; // test the input has been converted to lowercase

		// create a string to output the filename of the encrypted file
		string outputFilename;
		cout << "Output Filename (will have .txt appended automatically): ";
		cin >> outputFilename;

		ofstream output(outputFilename + ".txt");
		unsigned int k_i = 0;

		// use the key to encrypt the file
		// logic for single character: replace all a's in the code with the key value and all other letters with the letter corresponding to the length from 
		// a = 0 to the key value. Ex. string = wallz, key = b -- xbmma. b is 1 from a. x is 1 from w. m is 1 from l. a is 1 from z.

		// output encrypted file

		// loop through selectedString
		for (int i = 0; i < selectedString.length(); i++) {
			if (isalpha(selectedString[i])) { // characters or not

												// compare the current value of selectedString against alpha and Upperalpha
												// wrap around key
												// wrap around selectedString

				if (k_i >= key.length()) {
					k_i = 0;
				}

				std::size_t foundKey = alphabet.find(key[k_i]);

				//cout << "found has value: " << foundKey << endl;
				//cout << "alphabet char: " << alphabet[foundKey] << endl;

				std::size_t foundSelection = alphabet.find(selectedString[i]);

				// create an integer to calculate the distance to travel in alphabet search and replace value in selectedString
				unsigned int alphaSearch = (foundKey + foundSelection) % 26;

				// update encrypted characters in selected string and store in correct location
				selectedString[i] = alphabet[alphaSearch];

				// output the character position value in 
				//cout << "foundSelection has value: " << foundSelection << endl;
				//cout << "alphabet char for string: " << selectedString[i] << endl;

				// create variables for old and new to encrypt the file

				if (i == selectedString.length() - 1) {
					cout << endl;
				}
				k_i++;
			}
			else { // if not a character, just display the value
				//cout << selectedString[i] << endl;
			}
		}

		output << selectedString;
		output.close();
	}
	encryptDecrypt();
}