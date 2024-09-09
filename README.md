# Credit Card Number Validator

## Overview

This project is a C++ program designed to validate credit card numbers and identify the type of the card using the Luhn Algorithm. The program supports multiple credit card types (Visa, MasterCard, American Express, etc.), providing both validation and card type detection. It can be used as a foundational tool for systems requiring credit card verification, such as e-commerce platforms or payment gateways.

## Features

- Credit Card Validation: Uses the Luhn Algorithm to check the validity of the credit card number.

- Card Type Detection: Identifies the card type based on the card number's prefix and length (supports Visa, MasterCard, American Express, and more).

- Input validation: Ensures that only numeric values are processed.

- Simple user interface: Text-based interface that prompts the user for input and returns validation results and the card type.


## Supported Card Types

- The program can detect the following card types:

-- Visa (starting with 4)

-- MasterCard (starting with 51–55)

-- American Express (starting with 34 or 37)

-- Discover (starting with 6011 or 65)

-- Other cards can also be added by extending the card detection logic.


## Getting Started

- Prerequisites

-- A C++ compiler (e.g., g++, Clang, or MSVC)

-- Basic knowledge of C++ syntax and command-line operations.


- Installation

-- To run the Credit Card Number Validator on your machine, follow these steps:

1. Clone the repository:

git clone https://github.com/gray-skull/Credit-Card-Number-Validator.git

2. Navigate to the project directory:

cd Credit-Card-Number-Validator

3. Compile the program:

Using g++:

g++ -o validator main.cpp

4. Run the program:

./validator



## Usage

- Once the program is running, the user is prompted to enter a credit card number. The program will then validate the card number and display the card type and whether the number is valid or not.

1. Run the program:

./validator

2. Enter the credit card number:

Please enter the credit card number: 4532015112830366

3. The program will output the card type and validity:

Card Type: Visa
The credit card number is valid.


## Example Input and Output

Please enter the credit card number: 4111111111111111
Card Type: Visa
The credit card number is valid.

Please enter the credit card number: 371449635398431
Card Type: American Express
The credit card number is valid.

Please enter the credit card number: 1234567812345670
Card Type: Unknown
The credit card number is invalid.

## Luhn Algorithm Explanation

The Luhn Algorithm is a simple checksum formula used to validate various identification numbers, such as credit card numbers. The algorithm works as follows:

1. Starting from the rightmost digit (the check digit), double every second digit.


2. If doubling results in a number greater than 9, subtract 9 from the result.


3. Sum all the digits together.


4. If the total sum is divisible by 10, the credit card number is valid; otherwise, it is invalid.



## Example:

- For the card number 4532015112830366:

1. Double every second digit:

4 5 3 2 0 1 5 1 1 2 8 3 0 3 6 6
becomes:
8 5 6 2 0 1 10 1 2 2 16 3 0 3 12 6

2. Subtract 9 from numbers greater than 9:

8 5 6 2 0 1 1 1 2 2 7 3 0 3 3 6

3. Sum all the digits:

8 + 5 + 6 + 2 + 0 + 1 + 1 + 1 + 2 + 2 + 7 + 3 + 0 + 3 + 3 + 6 = 50

4. Since 50 is divisible by 10, the number is valid.


## Extending the Project

- Support more card types: Extend the card type detection logic to support additional cards such as Diners Club, JCB, etc.

- Improve error handling: Add robust input validation to handle incorrect inputs (e.g., letters, symbols, and invalid lengths).

- GUI version: Consider implementing a graphical user interface (GUI) using a library like Qt or wxWidgets.


## Contributing

- Contributions are welcome! If you'd like to contribute, please:

1. Fork the repository.


2. Create a new feature branch (git checkout -b feature/NewFeature).


3. Commit your changes (git commit -m 'Add some NewFeature').


4. Push to the branch (git push origin feature/NewFeature).


5. Open a pull request.
