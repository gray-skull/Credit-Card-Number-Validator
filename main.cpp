/* 
*	Credit Card Number Validator -
*	Validates a credit card number by using Luhn's algorithm
*/

#include <iostream>
#include <vector>
#include <string>

// Checks valid length and digits
static bool stringCheck(const std::string& s) {
	
	if (s.size() < 13 || s.size() > 16) {
		return false;
	}
	for (auto& i : s) {
		if (i < '0' || i > '9')
			return false;
	}
	return true;
}

// prints the entered card number
static void printNumber(const std::string& s) {
	for (auto& i : s) { std::cout << i; }
}

//uses Luhn's Algorithm to determine if card number is valid
static bool validCardCheck(const std::string s) {
	int sum1 = 0;
	int sum2 = 0;
	
	for (int i = s.size() - 1; i >= 0; i--) {
		int temp = 0;
		//double every other digit starting at the second from the right
		//if card has even number of digits, double the odd places
		if (s.size() % 2 == 0) {
			if (!(i % 2)) {
				// if doubling the digit results in a 2-digit number, add the sum of the two digits 
				// i.e. 8 * 2 = 16, 16 is a 2-digit number so add 1 and 6 to get 7, then add 7 to temp
				if (((s[i] - 48) * 2) > 9)
					temp = ((((s[i] - 48) * 2) % 10) + (((s[i] - 48) * 2) / 10));
				else
					temp = ((s[i] - 48) * 2);
				sum1 += temp;
			}
			else
				sum2 += (s[i]-48);
		}
		//if there's an odd number of digits, double the even places
		else {
			if (i % 2) {
				if (((s[i] - 48) * 2) > 9)
					temp = ((((s[i] - 48) * 2) % 10) + (((s[i] - 48) * 2) / 10));
				else
					temp = ((s[i] - 48) * 2);
				sum1 += temp;
			}
			else
				sum2 += (s[i]-48);
		}
	}
	// add the total of the doubled numbers with the total of the remaining numbers
	// if their sum is evenly divisible by 10, the card number is valid
	return (!((sum1 + sum2) % 10));
}

// returns card company based on user entered number
static std::string cardType(const std::string& s) {
	switch (s.size()) {
		case(13): {
			return "Visa";
			break;
		}
		case(14): {
			return "Diners Club";
			break;
		}
		case(15): {
			if (s[0] == '3')
				return "American Express";
			else
				return "JCB";
			break;
		}
		case(16): {
			if (s[0] == '5')
				return "Mastercard";
			else if (s[0] == '4')
				return "Visa";
			else if (s[0] == '3')
				return "JCB";
			else if (s[0] == '6')
				return "Discover";
			else
				return "UNKNOWN";
			break;
		}
		default:
			return "UNKNOWN";
	}
}

int main() {
	std::string inputNumber = "0";
	bool isInputValid = false;
	bool isInputConfirmed = false;
	bool isContinue = true;
	// while the input is not valid, keep asking for a valid number
    // while the user has not confirmed the number, keep asking for confirmation
	while (isContinue) {
		do {
			do {
				std::cout << "Please input the card number to validate : ";
				std::cin >> std::ws >> inputNumber;
				// clear input buffer
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				isInputValid = stringCheck(inputNumber);
				if (!isInputValid) {
					std::cout << "Please input a valid number!\n";
					inputNumber = "0";
				}
			} while (!(isInputValid));
			bool isValidChoice = false;
			char confirmNum = 'Z';
			do {
				std::cout << "You entered: ";
				printNumber(inputNumber);
				std::cout << std::endl << "Is this number correct? (1 - \"Yes\" / 0 - \"No\"): ";
				std::cin >> confirmNum;
				// clear input buffer
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				if (confirmNum == '1') {
					isValidChoice = true;
					isInputConfirmed = true;
				}
				else if (confirmNum == '0')
					isValidChoice = true;
				else
					std::cout << "**** Please enter 1 or 0 only ****\n";
			} while (!(isValidChoice));
		} while (!(isInputConfirmed));

		std::cout << (validCardCheck(inputNumber) ? "This card is valid\n" : "This card is NOT valid\n");
		std::cout << "This card is from " << cardType(inputNumber) << std::endl;
		std::cout << "Would you like to validate another card? (1 - \"Yes\" / 0 - \"No\"): ";
		char continueChoice = 'Z';
		std::cin >> continueChoice;
		// clear input buffer
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (continueChoice == '0')
			isContinue = false;
		else if (continueChoice == '1') {
			isInputValid = false;
			isInputConfirmed = false;
		}
		else {
			std::cout << "**** Please enter 1 or 0 only ****\n";
			isContinue = false;
		}
	}
	return 0;
}