#include "UI.h"
#include <iostream>

using namespace std;

UI::UI(Organizer* organizer) : organizer(organizer) {}

void UI::displayMainMenu() {
    while (true) {
        cout << "\nSelect Simulation Mode:\n";
        cout << "1. Interactive Mode\n";
        cout << "2. Silent Mode\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";

        int mode;
        cin >> mode;

        switch (mode) {
            case 1: // Interactive Mode
                displayInteractiveMode();
            return; // Exit after simulation completes

            case 2: // Silent Mode
                displaySilentMode();
            return; // Exit after simulation completes

            case 3: // Exit
                cout << "Exiting the program. Goodbye!\n";
            return;

            default: // Invalid selection
                cout << "Invalid selection. Please enter a valid option (1, 2, or 3).\n";
            break;
        }
    }
}

void UI::displayInteractiveMode() {
    cout << "Interactive Mode: Simulation starts...\n";
    organizer->simulate(true); // Call the organizer's simulation logic
    cout << "Interactive Mode: Simulation completed!\n";
}

void UI::displaySilentMode() {
    cout << "Silent Mode: Simulation starts...\n";
    organizer->simulate(false); // Call the organizer's simulation logic
    cout << "Silent Mode: Output file created. Simulation completed!\n";
}



















































/*
// Constructor with default mode
UI::UI() : mode("silent") {
}

// The simulation mode build-up
void UI::setMode() {
    cout << "Enter simulation mode (Interactive/Silent): ";
    cin >> mode; // Take user input for the mode (e.g., "Interactive" or "Silent")

    // Convert the input to lowercase to allow case-insensitive input (e.g., "INTERACTIVE" works)
    transform(mode.begin(), mode.end(), mode.begin(), ::tolower);

    // Validation of the input
    if (mode != "interactive" && mode != "silent") {
        throw invalid_argument("Invalid mode entered. Please use 'Interactive' or 'Silent'.");
    }
}

// to display the current simulation status
void UI::displayStatus(const Organizer &organizer) {
    cout << "\nCurrent Simulation Time: " << organizer.getCurrentTime() << "\n";
    cout << "----------------------------------------------\n";

    // Get the array of hospitals and the number of hospitals
    hospital** hospitals = organizer.getHospitals();  // Retrieve the array
    int numHospitals = organizer.getNumHospitals();   // Retrieve the count

    for (int i = 0; i < numHospitals; ++i) {
        hospital* hospital = hospitals[i];  // Access the hospital

        cout << "Hospital ID: " << hospital->getHospitalID() << " (" << hospital->getHospitalName() << ")\n";
        cout << "Patient Queues:\n";
        hospital->viewQueuestatus(); // Display the patient queues (e.g., SP, EP, NP)
        cout << "Available Ambulances:\n";
        hospital->viewAvailableAmbulances(); // Display the available ambulances (e.g., SC, NC)
        cout << "----------------------------------------------\n";
    }
}

// @ the end of the simulation to display the results
void UI::displayOutput(const LinkedQueue<Patient*>& finishedPatients) {
    cout << "\nSimulation Results:\n";
    cout << "----------------------------------------------\n";
    cout << "FT\tPID\tQT\tWT\n";
    cout << "----------------------------------------------\n";

    // Create a copy of the finished patients queue to display them without modifying the original
    LinkedQueue<Patient*> tempQueue = finishedPatients;

    // Dequeue each patient from the temporary queue and print their data
    while (!tempQueue.isEmpty()) {
        Patient* patient;
        tempQueue.dequeue(patient);
        cout << patient->GetFinishTime() << "\t"
            << patient->getPatientID() << "\t"
            << patient->GetRequestTime() << "\t"
            << patient->GetWaitingTime() << "\n";
    }

    cout << "----------------------------------------------\n";
    cout << "End of Simulation Results.\n";
}

// to return the current mode (Interactive or Silent)
const string &UI::getMode() const {
    // This function give us access to the mode variable
    return mode;
}*/
