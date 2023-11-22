#include <iostream>
#include <string>

using namespace std;

// Structure to represent a flight ticket
struct FlightTicket {
    string destination;
    double price;
    FlightTicket* next;
};

// Function to add a new flight ticket to the collection
void addFlightTicket(FlightTicket*& head, string destination, double price) {
    FlightTicket* newTicket = new FlightTicket;
    newTicket->destination = destination;
    newTicket->price = price;
    newTicket->next = head;
    head = newTicket;
}

// Function to display all flight tickets in the collection
void displayAllTickets(FlightTicket* head) {
    FlightTicket* current = head;
    while (current != nullptr) {
        cout << "Destination: " << current->destination << ", Price: $" << current->price << endl;
        current = current->next;
    }
}

// Function to search for a flight ticket based on a certain condition
FlightTicket* searchTicket(FlightTicket* head, double maxPrice) {
    FlightTicket* current = head;
    while (current != nullptr) {
        if (current->price <= maxPrice) {
            return current;
        }
        current = current->next;
    }
    return nullptr; // Ticket not found
}

// Function to display flight tickets based on a given criteria (e.g., destination)
void displayTicketsByCriteria(FlightTicket* head, string criteria) {
    FlightTicket* current = head;
    while (current != nullptr) {
        if (current->destination == criteria) {
            cout << "Destination: " << current->destination << ", Price: $" << current->price << endl;
        }
        current = current->next;
    }
}

// Function to calculate the average price of all flight tickets
double calculateAveragePrice(FlightTicket* head) {
    if (head == nullptr) {
        return 0.0;
    }

    double total = 0.0;
    int count = 0;
    FlightTicket* current = head;
    while (current != nullptr) {
        total += current->price;
        count++;
        current = current->next;
    }

    if (count == 0) {
        return 0.0;
    }
    else {
        return total / count;
    }
}


// Function to find the minimum price among all flight tickets
double findMinPrice(FlightTicket* head) {
    if (head == nullptr) {
        return -1; // Assuming -1 represents no tickets in the list
    }

    double minPrice = head->price;
    FlightTicket* current = head->next;
    while (current != nullptr) {
        if (current->price < minPrice) {
            minPrice = current->price;
        }
        current = current->next;
    }
    return minPrice;
}



// Function to calculate the total price of all flight tickets
double calculateTotalPrice(FlightTicket* head) {
    double total = 0.0;
    FlightTicket* current = head;
    while (current != nullptr) {
        total += current->price;
        current = current->next;
    }
    return total;
}



// Main function to exemplify the use of the data structure and functionalities
int main() {
    FlightTicket* ticketList = nullptr;

    // Adding flight tickets to the collection
    addFlightTicket(ticketList, "New York", 500.0);
    addFlightTicket(ticketList, "London", 800.0);
    addFlightTicket(ticketList, "Paris", 700.0);
    addFlightTicket(ticketList, "Tokyo", 1200.0);

    // Displaying all flight tickets
    cout << "All Flight Tickets:" << endl;
    displayAllTickets(ticketList);
    cout << endl;

    // Searching for a flight ticket with a maximum price
    double maxPrice = 1000.0;
    FlightTicket* foundTicket = searchTicket(ticketList, maxPrice);
    if (foundTicket != nullptr) {
        cout << "Flight ticket found within the budget:" << endl;
        cout << "Destination: " << foundTicket->destination << ", Price: $" << foundTicket->price << endl;
    }
    else {
        cout << "No flight ticket found within the budget." << endl;
    }
    cout << endl;

    // Displaying flight tickets based on a given criteria
    string criteria = "London";
    cout << "Flight Tickets to " << criteria << ":" << endl;
    displayTicketsByCriteria(ticketList, criteria);
    cout << endl;

    // Calculating the average price of all flight tickets

    double average = calculateAveragePrice(ticketList);
    cout << "Average Price of All Flight Tickets: $" << average << endl;
    cout << endl;


    // Finding the minimum price among all flight tickets
    double minPrice = findMinPrice(ticketList);
    if (minPrice != -1) {
        cout << "Minimum Price of a Flight Ticket: $" << minPrice << endl;
    }
    else {
        cout << "No flight tickets available." << endl;
    }


    // Calculating the total price of all flight tickets
    double total = calculateTotalPrice(ticketList);
    cout << "Total Price of All Flight Tickets: $" << total << endl;
    cout << endl;


    // Clean up: Free allocated memory
    while (ticketList != nullptr) {
        FlightTicket* temp = ticketList;
        ticketList = ticketList->next;
        delete temp;
    }

    return 0;
}
