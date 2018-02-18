#include <iostream>
#include <string.h>
#include <vector>
#include <limits>
#include <fstream>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

// custom made header files
#include "employeeDir.h"

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::ofstream;
using std::ifstream;

// Save the current uid
static uid_t realUID = getuid();
static uid_t effectiveUID = geteuid();


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
//	ifstream getDirectoryData("directoryFile.txt");
//	std::strncpy(lastName, );
//	std::strncpy(firstName, );
//	std::strncpy(position, );
	// use this space to copy empID
//	std::strncpy(phoneNumber, );

}

employeeDirectory::~employeeDirectory() {
//	delete lastName;
//	delete firstName;
//	delete position;
//	delete phoneNumber;
}

/*
	TODO:
	[X]Add employee Directory to main menu
	[X]View or modify employee records.
		[X]If modify, require password
		[X]If view, output directory to screen
	[X]User to input password
	[X]Create records if not already present
		[X]file is comma delimited with one file per line
		[X]Last Name
		[X]First Name
		[X]Position
		[X]Employee ID (6 digits) --> use random number generator to create
		[X]Telephone Number
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

    // setuid, code snippet from
    // https://www.gnu.org/software/libc/manual/html_node/Setuid-Program-Example.html
    int status;
    #ifdef _POSIX_SAVED_IDS
    status = seteuid(effectiveUID);
    #else
    status = setreuid(realUID, effectiveUID);
    #endif
    if(status == 0){
        cout << "Error in elevating privileges!" << endl;
    }
    // open the file
	ifstream actualPasswordFile("accessFile.txt");
    
    // un-set UID
    // https://www.gnu.org/software/libc/manual/html_node/Setuid-Program-Example.html
    #ifdef _POSIX_SAVED_IDS
    status = seteuid(realUID);
    #else
    status = setreuid(effectiveUID,realUID);
    #endif
    if(status < 0){
        cout << "Error in dropping levels!" << endl;
    }
    
	char password[17];
	
	actualPasswordFile.get(password, 17);

	actualPasswordFile.close(); // close the file

	//cout << "Read from the file " << password << endl;
	if (strncmp(password, userInputPassword, 17) == 0) {
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
		[] offer option to edit directory (returns to menu any way)
	*/
	//ofstream createDirectoryFile("directoryFile");
	char userDecideToFillDirectory;
	char lastName[20];
	char firstName[20];
	char position[20];
	char empID[7];
	char phoneNumber[13];

	cout << "Would you like to fill in the directory now? [y/n]: ";
	cin >> userDecideToFillDirectory;

	if ((userDecideToFillDirectory != 'y')) {
		cout << "An empty file has been created." << endl;
            // setuid, code snippet from
    // https://www.gnu.org/software/libc/manual/html_node/Setuid-Program-Example.html
    int status;
    #ifdef _POSIX_SAVED_IDS
    status = seteuid(effectiveUID);
    #else
    status = setreuid(realUID, effectiveUID);
    #endif
		ofstream createDirectoryFile("directoryFile.txt");
            // un-set UID
    // https://www.gnu.org/software/libc/manual/html_node/Setuid-Program-Example.html
    #ifdef _POSIX_SAVED_IDS
    status = seteuid(realUID);
    #else
    status = setreuid(effectiveUID,realUID);
    #endif
    if(status < 0){
        cout << "Error in dropping levels!" << endl;
    }
		createDirectoryFile.close();
	}
	else {
		cout << "The file is comma delimited with order: ";
		cout << "Last Name, First Name, Position, Employee Id, Phone Number" << endl;
		
		bool exitLoop = false; // use to stop inputting data in directory file
		while (!exitLoop) {
            // setuid, code snippet from
    // https://www.gnu.org/software/libc/manual/html_node/Setuid-Program-Example.html
    int status;
    #ifdef _POSIX_SAVED_IDS
    status = seteuid(effectiveUID);
    #else
    status = setreuid(realUID, effectiveUID);
    #endif
			ofstream createDirectoryFile("directoryFile.txt", std::ios::app | std::ios::out);
            // un-set UID
            // https://www.gnu.org/software/libc/manual/html_node/Setuid-Program-Example.html
            #ifdef _POSIX_SAVED_IDS
            status = seteuid(realUID);
            #else
            status = setreuid(effectiveUID,realUID);
            #endif
            if(status < 0){
                cout << "Error in dropping levels!" << endl;
            }
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
	cout << "What is the new password(max length 16 chars): ";
	cin >> newPassword;
	
	cout << "Verify password: ";
	char passwordVerify[17];
	cin >> passwordVerify;
	
	if (strncmp(newPassword, passwordVerify, 17) == 0) {
    // setuid, code snippet from
    // https://www.gnu.org/software/libc/manual/html_node/Setuid-Program-Example.html
    int status;
    #ifdef _POSIX_SAVED_IDS
    status = seteuid(effectiveUID);
    #else
    status = setreuid(realUID, effectiveUID);
    #endif
		ofstream modifyPasswordFile("accessFile.txt");
            // un-set UID
            // https://www.gnu.org/software/libc/manual/html_node/Setuid-Program-Example.html
            #ifdef _POSIX_SAVED_IDS
            status = seteuid(realUID);
            #else
            status = setreuid(effectiveUID,realUID);
            #endif
            if(status < 0){
                cout << "Error in dropping levels!" << endl;
            }
		modifyPasswordFile.write(newPassword, strlen(newPassword));
		modifyPasswordFile.close(); // close the file
	}
	else {
		cout << "Your inputs do not match!" << endl;
	}
}

void editAccountDirectory() {
	/*
		[] look up user by name (decided this was not unique enough)
		[X] look up user by empid
		[X] look up user by phone number
		[X] modify account
		[X] output new information to account
	*/

	char lastName[20];
	char firstName[20];
	char position[20];
	char empID[7];
	char phoneNumber[13];

	char inputPhone[13];
	char inputEmpID[7];

	char testDirectory[256];

	unsigned int userSelection;

	cout << "Enter key to identify account holder: " << endl
		<< "1) Employee ID" << endl
		<< "2) Phone Number" << endl;
	cin >> userSelection;

	if (userSelection == 1) {
		cout << "Enter Employee ID: ";
		cin >> inputEmpID;
	}
	else {
		cout << "Enter the Employee's Phone Number: ";
		cin >> inputPhone;
	}

	ifstream readDirectory("directoryFile.txt");
	char delAccount;

	cout << "Would you like to delete this account?[y/n]: ";
	cin >> delAccount;

	while (!readDirectory.eof()) {
		readDirectory.getline(testDirectory, 256);
		if (strncmp(testDirectory, "", 1) == 0) {

		}
		else {
			strncpy(lastName, strtok(testDirectory, ","), 20);
			strncpy(firstName, strtok(NULL, ","), 20);
			strncpy(position, strtok(NULL, ","), 20);
			strncpy(empID, strtok(NULL, ","), 7);
			strncpy(phoneNumber, strtok(NULL, ","), 13);
			if ((strncmp(empID, inputEmpID, 7) == 0) && (delAccount == 'y')) {
    // setuid, code snippet from
    // https://www.gnu.org/software/libc/manual/html_node/Setuid-Program-Example.html
    int status;
    #ifdef _POSIX_SAVED_IDS
    status = seteuid(effectiveUID);
    #else
    status = setreuid(realUID, effectiveUID);
    #endif
				ofstream createDirectoryFile("directoryFileNew.txt", std::ios::app | std::ios::out);
            // un-set UID
            // https://www.gnu.org/software/libc/manual/html_node/Setuid-Program-Example.html
            #ifdef _POSIX_SAVED_IDS
            status = seteuid(realUID);
            #else
            status = setreuid(effectiveUID,realUID);
            #endif
            if(status < 0){
                cout << "Error in dropping levels!" << endl;
            }
				createDirectoryFile.close();
			}
			else if (strncmp(empID, inputEmpID, 7) == 0) {
    // setuid, code snippet from
    // https://www.gnu.org/software/libc/manual/html_node/Setuid-Program-Example.html
    int status;
    #ifdef _POSIX_SAVED_IDS
    status = seteuid(effectiveUID);
    #else
    status = setreuid(realUID, effectiveUID);
    #endif
				ofstream createDirectoryFile("directoryFileNew.txt", std::ios::app | std::ios::out);
            // un-set UID
            // https://www.gnu.org/software/libc/manual/html_node/Setuid-Program-Example.html
            #ifdef _POSIX_SAVED_IDS
            status = seteuid(realUID);
            #else
            status = setreuid(effectiveUID,realUID);
            #endif
            if(status < 0){
                cout << "Error in dropping levels!" << endl;
            }
				cout << "Last Name: ";
				cin >> lastName;

				cout << "First Name: ";
				cin >> firstName;

				cout << "Position: ";
				cin >> position;

				cout << "Employee Id (6 digit): ";
				cin >> empID;
				while (!strnlen(empID, 7)) {
					cout << "Employee Id (6 digits): ";
					cin >> empID;
				}
				cout << "Phone Number: ";
				cin >> phoneNumber;

				createDirectoryFile << lastName << "," << firstName << "," << position
					<< "," << empID << "," << phoneNumber << endl;
				createDirectoryFile.close();
			}
			else {
    // setuid, code snippet from
    // https://www.gnu.org/software/libc/manual/html_node/Setuid-Program-Example.html
    int status;
    #ifdef _POSIX_SAVED_IDS
    status = seteuid(effectiveUID);
    #else
    status = setreuid(realUID, effectiveUID);
    #endif
				ofstream createDirectoryFile("directoryFileNew.txt",std::ios::app | std::ios::out);
            // un-set UID
            // https://www.gnu.org/software/libc/manual/html_node/Setuid-Program-Example.html
            #ifdef _POSIX_SAVED_IDS
            status = seteuid(realUID);
            #else
            status = setreuid(effectiveUID,realUID);
            #endif
            if(status < 0){
                cout << "Error in dropping levels!" << endl;
            }
				createDirectoryFile << lastName << "," << firstName << "," << position
					<< "," << empID << "," << phoneNumber << endl;
				createDirectoryFile.close();
			}
		}
	}
	readDirectory.close();
	if (remove("directoryFile.txt") != 0) {
		perror("Error in deleting the file.");
	}
	else {
		puts("File successfully deleted.");
	}
	int result = rename("directoryFileNew.txt", "directoryFile.txt");
	if (result == 0) {
		cout << "Rename was successful!" << endl;
	}
	else {
		perror("Error renaming the file.");
	}
}

void editDirectory() {

	char lastName[20];
	char firstName[20];
	char position[20];
	char empID[7];
	char phoneNumber[13];

	cout << "The file is comma delimited with order: ";
	cout << "Last Name, First Name, Position, Employee Id, Phone Number" << endl;

	bool exitLoop = false; // use to stop inputting data in directory file
	while (!exitLoop) {
    // setuid, code snippet from
    // https://www.gnu.org/software/libc/manual/html_node/Setuid-Program-Example.html
    int status;
    #ifdef _POSIX_SAVED_IDS
    status = seteuid(effectiveUID);
    #else
    status = setreuid(realUID, effectiveUID);
    #endif
		ofstream createDirectoryFile("directoryFile.txt", std::ios::app | std::ios::out);
            // un-set UID
            // https://www.gnu.org/software/libc/manual/html_node/Setuid-Program-Example.html
            #ifdef _POSIX_SAVED_IDS
            status = seteuid(realUID);
            #else
            status = setreuid(effectiveUID,realUID);
            #endif
            if(status < 0){
                cout << "Error in dropping levels!" << endl;
            }

		cout << "Last Name: ";
		cin >> lastName;

		cout << "First Name: ";
		cin >> firstName;

		cout << "Position: ";
		cin >> position;

		cout << "Employee Id (6 digit): ";
		cin >> empID;
		while (!strnlen(empID,7)) {
			cout << "Employee Id (6 digits): ";
			cin >> empID;
		}
		cout << "Phone Number: ";
		cin >> phoneNumber;

		createDirectoryFile << lastName << "," << firstName << "," << position
			<< "," << empID << "," << phoneNumber << endl;
		createDirectoryFile.close();

		employeeDirectory();

		char exitHere;
		cout << "Would you like to exit this program? [y/n]: ";
		cin >> exitHere;

		if ((exitHere == 'y')) {
			exitLoop = true;
		}
	}



}

void viewDirectory() {
	// [X] display the directory

	vector <char *> directoryContents;
	char testDirectory[256];

	ifstream directoryFile("directoryFile.txt");
	if (directoryFile.is_open()) {
		while (!directoryFile.eof()){
				directoryFile.getline(testDirectory, 256);
				//directoryFile.getline(directoryContents, 20);
				if (strncmp(testDirectory,"",1) == 0) {
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
		[X] display directory?
		[] allow the user to modify the directory
		[X] save the directory
		[X] change password
	*/

	if (directoryPasswordCheck()) {
		vector <char const*> modifyOptionsMenu;
		
		modifyOptionsMenu.push_back("Change Password");
		modifyOptionsMenu.push_back("Append to the Directory");
		modifyOptionsMenu.push_back("View Directory");
		modifyOptionsMenu.push_back("Edit specific account in Directory");
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
				cout << "Append to the directory." << endl;
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
				cout << "Editing specific account in directory." << endl;
				editAccountDirectory();
				break;
			case 5:
				cout << "You are now exiting the menu." << endl;
				break;
			default:
				cout << "Invalid input." << endl;
				break;
			}
		} while (modifyUserInput <= 0 || modifyUserInput != modifyExit || modifyUserInput > modifyExit);
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
	//vector <employeeDirectory> employeeData;

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
