#include <iostream>
#include <string.h>
#include <vector>
#include <limits>
#include <fstream>

// custom made header files
#include "employeeDir.h"

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::ofstream;
using std::ifstream;

/*
	TODO:
	[X]Add employee Directory to main menu
	[]View or modify employee records.
		[]If modify, require password
		[]If view, output directory to screen
	[X]User to input password
	[]Create records if not already present
		[]file is comma delimited with one file per line
		[]Last Name
		[]First Name
		[]Position
		[]Employee ID (6 digits) --> use random number generator to create
		[]Telephone Number
	[]Allow the user to change the password if they are logged in to root
	[]Directory permissions--> 644(rw,r,r)
	[]Do not exit unless user prompts to quit
	[]Compile as user then
		[]chown
		[]chgrp to root
		[]change permissions to 4555


*/

bool directoryPasswordCheck() {
	cout << "What is the password?" << endl;

	char userInputPassword[17];
	cin >> userInputPassword;

	cout << "You typed: " << userInputPassword << endl;

	ifstream actualPasswordFile("accessFile.txt");
	char password[17];
	
	actualPasswordFile.get(password, 17);

	actualPasswordFile.close(); // close the file

	cout << "Read from the file " << password << endl;
	if (std::strncmp(password, userInputPassword, 17) == 0) {
		return true;
	}
	else return false;

}

void passwordChange() {
	// TODO: 
	// [] request user input to modify password
	// [] write new password to password file
	// [] close the file with new password saved to file

	char newPassword[17];
	cout << "What is the new password: ";
	cin >> newPassword;
	
	cout << "Verify password: ";
	char passwordVerify[17];
	cin >> passwordVerify;
	
	if (std::strncmp(newPassword, passwordVerify, 17) == 0) {
		ofstream modifyPasswordFile("accessFile.txt");
		modifyPasswordFile.write(newPassword, std::strlen(newPassword));
		modifyPasswordFile.close(); // close the file
	}
	else {
		cout << "Your inputs do not match!" << endl;
	}
}

void editDirectory() {

}

void viewDirectory() {
	// TODO:
	// display the directory

	ifstream directoryFile("directoryFile.txt");
	if (directoryFile.is_open()) {
		/*while (!directoryFile.eof()) {

			cout << endl;
		}*/
		//directoryFile.open("directoryFile");
		//system("notepad.exe directoryFile");
		directoryFile.close();
	}
	else {
		cout << "Directory not found." << endl;
	}
	cout << "display some shit" << endl;
}

void modifyDirectory() {
	/*
		TODO:
		[X] request and verify password
		[] display directory?
		[] allow the user to modify the directory
		[] save the directory
		[] change password
	*/

	if (directoryPasswordCheck()) {
		vector <char const*> modifyOptionsMenu;
		
		modifyOptionsMenu.push_back("Change Password");
		modifyOptionsMenu.push_back("Edit Directory");
		modifyOptionsMenu.push_back("View Directory");
		modifyOptionsMenu.push_back("Exit");
		const int modifyExit = modifyOptionsMenu.size();
		int modifyUserInput;

		do {
			// print options for modify menu
			for (int i = 0; i < modifyExit; i++) {
				unsigned int modifyOptionsDir = i + 1;
				cout << modifyOptionsDir << ") " << modifyOptionsMenu[i] << endl;
			}
			cin >> modifyUserInput;

			switch (modifyUserInput) {
			case 1:
				cout << "Change the password." << endl;
				passwordChange();
				break;
			case 2:
				cout << "Modify the directory." << endl;
				editDirectory();
				break;
			case 3:
				cout << "Viewing the Directory." << endl;
				viewDirectory();
				break;
			case 4:
				cout << "You are now exiting the menu." << endl;
				break;
			default:
				cout << "Invalid input." << endl;
				break;
			}
		} while (modifyUserInput <= 0 || modifyUserInput != modifyExit);
	}
	else {
		cout << "bad shit." << endl;
	}
}


void employeeDir() {
	// create output options for user to select from
	// make additions here!!
	// MODIFY SWITCH-CASE STATEMENTS 
	/*char dirOption1[15] = "View Directory";
	char dirOption2[17] = "Modify Directory";
	char dirOptionExit[5] = "Exit";*/

	vector <char const*> dirOptions;

	dirOptions.push_back("View Directory");
	dirOptions.push_back("Modify Directory");
	dirOptions.push_back("Exit");


	unsigned int exitOption = dirOptions.size(); // modify size for number of input options
	
	cout << "Welcome!" << endl;

	unsigned int userInputDirOption;


	do {
		// Display user options
		// make additions here!!
		/*cout << "Would you like to:" << endl;
		cout << " [1] " << dirOption1 << endl;
		cout << " [2] " << dirOption2 << endl;
		cout << " [3] " << dirOptionExit << endl;*/

		for (unsigned int i = 0; i < dirOptions.size(); i++) {
			unsigned int dirOptionsSize = i + 1;
			cout << dirOptionsSize << ") " << dirOptions[i] << endl;
		}
		cin >> userInputDirOption; // take in user input

		// Clear cin
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		switch (userInputDirOption)
		{
		case 1:
			cout << userInputDirOption << endl;
			viewDirectory(); // go to viewDirectory and print the directory
			break;
		case 2:
			cout << userInputDirOption << endl;
			modifyDirectory(); // go to modify directory
			break;
		case 3:
			cout << "Thank you for visiting the Directory. Goodbye." << endl;
			return; // exiting the program
			break;
		default:
			cout << "The input value is invalid!" << endl;
			break;
		}
	} while (userInputDirOption <= 0 || userInputDirOption != exitOption);
}