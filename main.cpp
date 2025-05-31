#include <iostream>
#include "Organizer/Organizer.h"
#include "UI/UI.h"
#include "Patient/Patient.h"
#include "Hospital/hospital.h"
#include "Organizer/globals.h"

using namespace std;

int main() {
    Organizer organizer;
    UI ui(&organizer);
    try {
        organizer.runSimulation("Egypt.txt");  // Using relative path
    } catch (const std::exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1; //if the program loading fails exit!
    }
    ui.displayMainMenu();

    if (globalOrganizer) {  // Check if globalOrganizer exists before deleting
        delete globalOrganizer;
        globalOrganizer = nullptr;  // Set to nullptr after deletion
    }
    return 0;
}
