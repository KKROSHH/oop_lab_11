#include "Passenger_T.h"
#include "Cargo_T.h"

int main() {
    Passenger_T passenger;
    Cargo_T cargo;

    std::cout << "Passenger Transportation:\n";
    passenger.InputData();
    passenger.OutputData();
    passenger.Calculate();

    std::cout << "\nCargo Transportation:\n";
    cargo.InputData();
    cargo.OutputData();
    cargo.Calculate();

    return 0;
}
