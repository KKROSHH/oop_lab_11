#pragma once
#include "Transportation.h"

class Passenger_T : public Transportation {
private:
    int seats;
    int ticketsSold;

public:
    Passenger_T() : seats(0), ticketsSold(0) {}
    ~Passenger_T() {}

    void InputData() override {
        vehicleType = "Bus"; // або отримайте від користувача
        departure = "City A"; // або отримайте від користувача
        destination = "City B"; // або отримайте від користувача

        transportationID = SafeInputInt("Enter transportation ID: ");
        duration = SafeInputDouble("Enter duration in hours: ");
        seats = SafeInputInt("Enter the number of seats: ");
        ticketsSold = SafeInputInt("Enter the number of tickets sold: ", 0);
    }

    void OutputData() const override {
        std::cout << "Vehicle: " << vehicleType << "\nDeparture: " << departure
                  << "\nDestination: " << destination << "\nID: " << transportationID
                  << "\nDuration: " << duration << " hours\nSeats: " << seats
                  << "\nTickets Sold: " << ticketsSold << "\n";
    }

    void Calculate() const override {
        int ticketsAvailable = seats - ticketsSold;
        std::cout << "Tickets available: " << ticketsAvailable << "\n";
    }
};
