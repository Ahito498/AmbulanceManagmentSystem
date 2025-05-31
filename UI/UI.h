#pragma once
#include "..//Organizer/Organizer.h"

#include <string>


class UI {
private:
    Organizer* organizer; // Pointer to the Organizer object

public:
    explicit UI(Organizer* organizer);
    void displayMainMenu();
    void displayInteractiveMode();
    void displaySilentMode();
};

































/*class UI {
private:
    std::string mode; // Stores the simulation mode

public:
    UI(); // Constructor to initialize the UI

    void setMode(); // Function to allow the user to set the simulation mode
    static void displayStatus(const Organizer &organizer) ; // Displays the current simulation status (Interactive mode)
    static void displayOutput(const LinkedQueue<Patient *> &finishedPatients);

    const std::string &getMode() const;
};
*/