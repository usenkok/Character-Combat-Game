/*********************************************************************
** Program name: menuProj3.cpp
** Author: Kelly Usenko
** Date: 5/13/2018
** Description: Implementation of menu allowing user to choose characters
** to battle.
*********************************************************************/

#include "menuProj3.hpp"


// Main menu display
void printMainMenuTitle()
{
	cout << "Welcome to the Character Combat Game!" << endl;
}

// Menu options for character choice
void printMenuOptions()
{

	string menuChoice1 = "1. Barbarian";
	string menuChoice2 = "2. Vampire";
	string menuChoice3 = "3. Bluemen";
	string menuChoice4 = "4. Medusa";
	string menuChoice5 = "5. Harry Potter";

	cout << menuChoice1 << endl;
	cout << menuChoice2 << endl;
	cout << menuChoice3 << endl;
	cout << menuChoice4 << endl;
	cout << menuChoice5 << endl;
}



// Menu to play again or exit
void printMenuPlayAgain()
{
	string menuPlayChoice1 = "1. Play again";
	string menuPlayChoice2 = "2. Exit the game";

	cout << menuPlayChoice1 << endl;
	cout << menuPlayChoice2 << endl;
}


// Function for getting valid integers
void getValidInteger(int *result)
{
	string requestText = "Please enter a positive integer.";
	string tryAgainText = "Invalid entry. Please try again.";
	string stringInput;
	bool isValid = false;

	cout << requestText << endl;

	do {
		getline(cin, stringInput);

		if (validateIntegerInput(stringInput, -1, 100000))
		{
			isValid = true;
		}
		else {

			cout << tryAgainText << endl;
		}

	} while (!isValid);

	*result = stoi(stringInput);
}


// Funciton for getting valid integers overloaded to allow entry of question
void getValidInteger(int *result, string promptForUser, int minInt, int maxInt)
{
	string requestText = promptForUser;
	string tryAgainText = "Invalid entry. Please try again.";
	string stringInput;
	bool isValid = false;

	cout << requestText << endl;

	do {
		getline(cin, stringInput);

		if (validateIntegerInput(stringInput, minInt, maxInt))
		{
			isValid = true;
		}
		else {

			cout << tryAgainText << endl;
		}
	} while (!isValid);

	*result = stoi(stringInput);
}


// Thorough function to validate string for integer input
bool validateIntegerInput(string userInput, int minVal, int maxVal)
{

	bool allDigits = false;             //Flag to if input is completely numerical
	bool withinRange = false;           //Flag to validate number within range required
	bool isInputValid = false;          //Flag indicating if input meets all criteria
	string maximumDigits = std::to_string(INT_MAX);
	int inputLength = userInput.length();

	for (int i = 0; i < inputLength; i++) {
		int nonDigitCount = 0;
		if (!isdigit(userInput[i])) {
			nonDigitCount++;
		}
		if (nonDigitCount == 0)
			allDigits = true;
	}
	//check if size within int limits
	if (allDigits && (userInput.length() < maximumDigits.length())) { //keep within integer range

		if (std::stoi(userInput) > minVal && std::stoi(userInput) < maxVal) {
			isInputValid = true;
		}
	}
	return isInputValid;
}

