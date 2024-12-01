#pragma once
#include <string>
#include <iostream>
#include <sstream>
#include <limits>

class Transportation {
protected:
    std::string vehicleType;
    std::string departure;
    std::string destination;
    int transportationID;
    double duration;

public:
    Transportation()
        : vehicleType("None"), departure("None"), destination("None"), transportationID(0), duration(0.0) {}
    virtual ~Transportation() {}

    virtual void InputData() = 0;
    virtual void OutputData() const = 0;
    virtual void Calculate() const = 0;

    // Допоміжна функція для безпечного вводу цілих чисел
    static int SafeInputInt(const std::string& prompt, int minValue = 1) {
        int value;
        std::string input;

        while (true) {
            std::cout << prompt;
            std::getline(std::cin, input);
            std::stringstream ss(input);
            if (ss >> value && value >= minValue && ss.eof()) {
                return value;
            } else {
                std::cout << "Invalid input. Please enter a positive integer.\n";
            }
        }
    }

    // Допоміжна функція для безпечного вводу чисел з плаваючою крапкою
    static double SafeInputDouble(const std::string& prompt, double minValue = 0.0) {
        double value;
        std::string input;

        while (true) {
            std::cout << prompt;
            std::getline(std::cin, input);
            std::stringstream ss(input);
            if (ss >> value && value >= minValue && ss.eof()) {
                return value;
            } else {
                std::cout << "Invalid input. Please enter a number >= " << minValue << ".\n";
            }
        }
    }
};
