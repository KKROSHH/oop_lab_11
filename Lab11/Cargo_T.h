#pragma once
#include "Transportation.h"

class Cargo_T : public Transportation {
private:
    double cargoWeight;

public:
    Cargo_T() : cargoWeight(0.0) {}
    ~Cargo_T() {}

    void InputData() override {
        vehicleType = "Truck"; // або отримайте від користувача
        departure = "City A"; // або отримайте від користувача
        destination = "City B"; // або отримайте від користувача

        transportationID = SafeInputInt("Enter transportation ID: ");
        duration = SafeInputDouble("Enter duration in hours: ");
        cargoWeight = SafeInputDouble("Enter cargo weight (kg): ");
    }

    void OutputData() const override {
        std::cout << "Vehicle: " << vehicleType << "\nDeparture: " << departure
                  << "\nDestination: " << destination << "\nID: " << transportationID
                  << "\nDuration: " << duration << " hours\nCargo Weight: " << cargoWeight << " kg\n";
    }

    void Calculate() const override {
        std::cout << "Cargo can be loaded within duration: " << duration << " hours\n";
    }
};
