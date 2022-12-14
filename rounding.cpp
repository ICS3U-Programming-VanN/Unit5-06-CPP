// Copyright (c) 2022 Van Nguyen All rights reserved.
//
// Created by: Van Nguyen
// Created on: December 8, 2022
// This program asks the user for a number with decimals and rounds
// it to a specified number of decimals places using pass by reference


#include <iostream>
#include <cmath>
#include <string>


// This function rounds a number to the
// number of decimal places specified using pass by reference
void RoundDecimal(float &number, int numDecimals) {
    // Declared Variable
    int numberInt;

    // Rounds number
    // Multiplies the number by 10^numDecimals
    number *= pow(10, numDecimals);

    // Adds 0.5 to the number (to determine to round up or down)
    number += 0.5;

    // Casts the number to an integer to remove the decimals
    number = static_cast<int>(number);

    // Divides the number by 10^numDecimals
    number /= pow(10, numDecimals);
}


int main() {
    // Declared Variables
    std::string userNumberString, userNumDecimalsString;
    float userNumber, userNumDecimalsFloat;
    int userNumDecimals;

    // Asks user for the decimal number to round
    std::cout << "Enter a decimal number: ";
    std::getline(std::cin, userNumberString);

    // Asks the user for the number of decimal places to round
    std::cout << "Enter the number of decimal places to round to: ";
    std::getline(std::cin, userNumDecimalsString);

    // Checks for exceptions
    try {
        // Converts userNumberString to float
        userNumber = stof(userNumberString);

        // Converts userNumDecimalsString to a float
        userNumDecimalsFloat = stof(userNumDecimalsString);

        // Converts userNumDecimalsString to an integer
        // (to check for decimals in input)
        userNumDecimals = stoi(userNumDecimalsString);

        // Checks if the user entered a negative number
        // or a number with decimals for the number of decimal places
        if (userNumDecimals < 0 || userNumDecimals != userNumDecimalsFloat) {
            // Displays error message
            std::cout << "You must enter an integer for the "
            << "number of decimal places." << std::endl;
        // IF the user's inputs are all valid
        } else {
            // Calls function to round the user's number
            // to the specified number of places
            RoundDecimal(userNumber, userNumDecimals);

            // Displays the rounded number to the user
            std::cout << userNumberString << " rounded to " << userNumDecimals
            << " decimal places: " << userNumber << std::endl;
        }
    // In the event of an exception
    } catch (std::invalid_argument) {
        std::cout << "You entered invalid number(s)!" << std::endl;
    }
}
