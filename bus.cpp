#include <iostream>
#include <string>
using namespace std;

const int TOTAL_ROUTES = 3;
const int TOTAL_SEATS = 20;

void displayMainMenu() {
    cout << "\nETHIOPIAN BUS RESERVATION SYSTEM\n";
    cout << "1. View available routes\n";
    cout << "2. Select route and reserve seat\n";
    cout << "3. Cancel reservation\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
}

void displayRoutes() {
    cout << "\nAvailable Routes:\n";
    cout << "1. AA to Adama\n";
    cout << "2. Adama to Addis\n";
    cout << "3. Addis to Hawassa\n";
}

void displaySeats(const bool seats[]) {
    cout << "\nSeats: (X = reserved, O = available)\n";
    for (int i = 0; i < TOTAL_SEATS; i++) {
        cout << "[" << (seats[i] ? "X" : "O") << "]";
        if ((i + 1) % 5 == 0) cout << "  ";
    }
    cout << endl;
}

void reserveSeat(bool seats[]) {
    displaySeats(seats);
    int seatNumber;
    cout << "Enter seat number to reserve (1-" << TOTAL_SEATS << "): ";
    cin >> seatNumber;
    if (seatNumber < 1 || seatNumber > TOTAL_SEATS) {
        cout << "Invalid seat number.\n";
    } else if (seats[seatNumber - 1]) {
        cout << "Seat already reserved.\n";
    } else {
        seats[seatNumber - 1] = true;
        cout << "Seat " << seatNumber << " reserved successfully.\n";
    }
}

void cancelSeat(bool seats[]) {
    displaySeats(seats);
    int seatNumber;
    cout << "Enter seat number to cancel reservation (1-" << TOTAL_SEATS << "): ";
    cin >> seatNumber;
    if (seatNumber < 1 || seatNumber > TOTAL_SEATS) {
        cout << "Invalid seat number.\n";
    } else if (!seats[seatNumber - 1]) {
        cout << "Seat is already free.\n";
    } else {
        seats[seatNumber - 1] = false;
        cout << "Reservation for seat " << seatNumber << " canceled.\n";
    }
}

int main() {
    bool seats[TOTAL_ROUTES][TOTAL_SEATS] = { false };
    int choice, selectedRoute = -1;
    string routeNames[TOTAL_ROUTES] = {
        "AA to Adama",
        "Adama to Addis",
        "Addis to Hawassa"
    };

    do {
        displayMainMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                displayRoutes();  // ✅ Only shows available routes
                break;

            case 2:
                displayRoutes();
                cout << "Select route number: ";
                cin >> selectedRoute;
                if (selectedRoute >= 1 && selectedRoute <= TOTAL_ROUTES) {
                    cout << "You have chosen the route from " << routeNames[selectedRoute - 1] << endl;
                    reserveSeat(seats[selectedRoute - 1]);
                } else {
                    cout << "Invalid route number.\n";
                }
                break;

            case 3:
                displayRoutes();
                cout << "Select route number: ";
                cin >> selectedRoute;
                if (selectedRoute >= 1 && selectedRoute <= TOTAL_ROUTES) {
                    cout << "You selected route: " << routeNames[selectedRoute - 1] << endl;
                    cancelSeat(seats[selectedRoute - 1]);
                } else {
                    cout << "Invalid route number.\n";
                }
                break;

            case 4:
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (true);

    return 0;
}
