// #include <gtest/gtest.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cctype>

#define MULTIPLIER_TEN 10

int main(int argc, char **argv)
{
    // Open the file
    std::ifstream inputFile("../src/input.txt");

    if (!inputFile.is_open())
    {
        std::cerr << "Error opening the file." << '\n';
        return 1;
    }

    // Read every line of file
    std::string line;
    int calibration_sum = 0;
    while (std::getline(inputFile, line))
    {
        std::vector<int> numbers;

        // Take every number in the line and save it to an array
        for (char c : line)
        {
            if (std::isdigit(c))
            {
                int number = c - '0'; // Convert character to integer
                numbers.push_back(number);
            }
        }

        if (!numbers.empty())
        {
            // Take the first and last digit and build a number.
            int first_digit = numbers.front();
            int second_digit = numbers.back();
            std::cout << "first_digit: " << first_digit << '\n';
            std::cout << "second_digit: " << second_digit << '\n';

            int calibration_value = first_digit * MULTIPLIER_TEN + second_digit;

            // Sum that number to a variable
            calibration_sum += calibration_value;
        }
    }

    std::cout << "Calibraton value sum: " << calibration_sum << '\n';

    inputFile.close();
}
