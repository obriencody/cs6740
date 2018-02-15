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

class employeeDirectory {
public:
	char lastName[22];
	char firstName[22];
	char position[22];
	int empID;
	char phoneNumber[22];
	employeeDirectory();
	~employeeDirectory();
};

employeeDirectory::employeeDirectory() {

}

employeeDirectory::~employeeDirectory() {
	delete lastName;
	delete firstName;
	delete position;
	delete phoneNumber;
}

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

bool does_file_exist() {
	ifstream directoryFile("directoryFile.txt");
	return directoryFile.good();
}

void createNewDirectory() {
	/*
		TODO:
		[X] comma delimited
		[X] last name, first name, position, Emp. Id, Phone Number
		[] offer option to edit directory
	*/
	//ofstream createDirectoryFile("directoryFile");
	char userDecideToFillDirectory;
	char lastName[20];
	char firstName[20];
	char position[20];
	int empID;
	int phoneNumber;

	cout << "Would you like to fill in the directory now? [y/n]: ";
	cin >> userDecideToFillDirectory;

	if ((userDecideToFillDirectory != 'y')) {
		cout << "An empty file has been created." << endl;
		ofstream createDirectoryFile("directoryFile.txt");
		createDirectoryFile.close();
	}
	else {
		cout << "The file is comma delimited with order: ";
		cout << "Last Name, First Name, Position, Employee Id, Phone Number" << endl;
		
		bool exitLoop = false; // use to stop inputting data in directory file
		while (!exitLoop) {
			ofstream createDirectoryFile("directoryFile.txt", std::ios::app | std::ios::out);

			cout << "Last Name: ";
			cin >> lastName;

			cout << "First Name: ";
			cin >> firstName;

			cout << "Position: ";
			cin >> position;

			cout << "Employee Id: ";
			cin >> empID;

			cout << "Phone Number: ";
			cin >> phoneNumber;

			createDirectoryFile << lastName << "," << firstName << "," << position
				<< "," << empID << "," << phoneNumber << endl;
			createDirectoryFile.close();
			
			char exitHere;
			cout << "Would you like to exit this program? [y/n]: ";
			cin >> exitHere;

			if ((exitHere == 'y')) {
				exitLoop = true;
			}
		}
	}


}

void passwordChange() { 
	// [X] request user input to modify password
	// [X] write new password to password file
	// [X] close the file with new password saved to file

	char newPassword[17];
	cout << "What is the new password: ";
	cin >> newPassword;
	
	cout << "Verify password: ";
	char passwordVerify[17];
	cin >> passwordVerify;
	
	if (std::strncmp(newPassword, passwordVerify, 17) == 0) {
		// TODO setuid
		ofstream modifyPasswordFile("accessFile.txt");
		// TODO unsetuid
		modifyPasswordFile.write(newPassword, std::strlen(newPassword));
		modifyPasswordFile.close(); // close the file
	}
	else {
		cout << "Your inputs do not match!" << endl;
	}
}

void editDirectory() {

	char lastName[20];
	char firstName[20];
	char position[20];
	int empID;
	int phoneNumber;

	cout << "The file is comma delimited with order: ";
	cout << "Last Name, First Name, Position, Employee Id, Phone Number" << endl;

	bool exitLoop = false; // use to stop inputting data in directory file
	while (!exitLoop) {
		ofstream createDirectoryFile("directoryFile.txt", std::ios::app | std::ios::out);

		cout << "Last Name: ";
		cin >> lastName;

		cout << "First Name: ";
		cin >> firstName;

		cout << "Position: ";
		cin >> position;

		cout << "Employee Id: ";
		cin >> empID;

		cout << "Phone Number: ";
		cin >> phoneNumber;

		createDirectoryFile << lastName << "," << firstName << "," << position
			<< "," << empID << "," << phoneNumber << endl;
		createDirectoryFile.close();

		char exitHere;
		cout << "Would you like to exit this program? [y/n]: ";
		cin >> exitHere;

		if ((exitHere == 'y')) {
			exitLoop = true;
		}
	}



}

void viewDirectory() {
	// TODO:
	// [] display the directory

	vector <char *> directoryContents;
	char testDirectory[256];

	ifstream directoryFile("directoryFile.txt");
	if (directoryFile.is_open()) {
		while (!directoryFile.eof()){
				directoryFile.getline(testDirectory, 256);
				//directoryFile.getline(directoryContents, 20);
				if (std::strncmp(testDirectory,"",1) == 0) {
				}
				else {
					cout << "contents are: " << testDirectory << endl;
				}
			}
		//directoryFile.open("directoryFile");
		//system("notepad.exe directoryFile");
		directoryFile.close();
	}
	else {
		cout << "Directory not found." << endl;
	}
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
				if (does_file_exist()) {
					editDirectory();
				}
				else {
					cout << "The file does not currently exist." << endl;
					cout << "Creating a directory file" << endl;
					createNewDirectory();
				}
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
		} while (modifyUserInput <= 0 || modifyUserInput != modifyExit || modifyUserInput > modifyOptionsMenu.size());
	}
	else {
		cout << "Sorry, incorrect password." << endl;
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
	vector <employeeDirectory> employeeData;

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