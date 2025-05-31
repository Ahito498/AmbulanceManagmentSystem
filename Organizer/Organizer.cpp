#include "Organizer.h"
#include <fstream>
#include <iostream>
#include <stdexcept>
#include "..//DerivedClasses/DerivedPriQueue.h"
#include"..//Patient/EP.h"
#include<cmath>
using namespace std;
int Organizer::currentTime =1;
int Organizer::carID = 1;
Organizer::Organizer() : hospitals(nullptr), numHospitals(0) {
    int initialCapacity = 10; // Set an initial capacity for the hospitals array
    hospitals = new hospital*[initialCapacity];

    // Initialize all pointers in the array to nullptr
    for (int i = 0; i < initialCapacity; ++i) {
        hospitals[i] = nullptr;
    }

    cout << "Organizer initialized with capacity: " << initialCapacity << endl;
}
Organizer::~Organizer() {
    for (int i = 0; i < numHospitals; ++i) {
        delete hospitals[i];  // Free each hospital
    }
    delete[] hospitals;
    }

void Organizer::incrementCarCount() {
    totalCars ++;
}

void Organizer::incrementFailedCarCount() {
    failedCars++;
}

void Organizer::handleCarFailures() {
         ExtendedCancellablePriorityQueue<Car*> updatedOutCars;

         while (!OutCars.isEmpty()) {
             Car* car;
             int priority;
             OutCars.dequeue(car, priority);

             // Generate a random number to simulate failure
             double randomValue = static_cast<double>(rand()) / RAND_MAX;

             if (randomValue < car->getFailureProbability()) {
                 // Log car failure
                 cout << "Car ID: " << car->getID() << " failed while OUT.\n";

                 // Move the car to BACK queue
                 BackCars.enqueue(car, currentTime + car->calculateArrivalTime(car->GetAssignedPatient()->GetDistanceToHospital()));

                 // Reassign patient to hospital queue
                 Patient* assignedPatient = car->GetAssignedPatient();
                 if (assignedPatient) {
                     int hospitalIndex = assignedPatient->getHospitalID() - 1;
                     hospitals[hospitalIndex]->addRequestToQueue(assignedPatient);
                     cout << "Patient ID: " << assignedPatient->getPatientID() << " reassigned to queue of Hospital ID: " << hospitalIndex + 1 << ".\n";
                 }

                 // Clear patient assignment
                 car->clearAssignedPatient();
             } else {
                 // If the car did not fail, reenqueue it
                 updatedOutCars.enqueue(car, priority);
             }
         }

    // Replace the OutCars queue with the updated one
         OutCars = updatedOutCars;

}


void Organizer::addFinishedPatient(Patient *p) {
    if (p) {
        finishedPatients.enqueue(p);
        cout<<"patient ID: "<<p->getPatientID()<<"has been added to the finished patients list.\n";
    }
}

void Organizer::setCurrentTime(int time) {
    if (time > currentTime) {
        currentTime = time;
    }
    else {
        throw runtime_error("Time is out of range");
    }
}

void Organizer::addHospital(hospital* newHospital) {
    if (!newHospital) {
        cerr << "Error: Attempted to add a null hospital to the organizer." << endl;
        return;
    }

    // Dynamically expand the array if necessary
    static int capacity = 10; // Initial capacity
    if (numHospitals == capacity) {
        // Double the capacity and reallocate memory
        capacity *= 2;
        hospital** newHospitals = new hospital*[capacity];
        for (int i = 0; i < numHospitals; ++i) {
            newHospitals[i] = hospitals[i];
        }
        delete[] hospitals;
        hospitals = newHospitals;
    }

    // Add the new hospital to the array
    hospitals[numHospitals++] = newHospital;

    cout << "Hospital with ID: " << newHospital->getHospitalID()
         << " has been added to the organizer." << endl;
}
////////////////Cars MANGAGNMENT FUNCTION////////////////

void Organizer::assignAmbulanceToPatient(Patient* patient) {
   int attempts = 0;
    int hospitalIndex = patient->getHospitalID()-1;
    while (attempts < numHospitals) {
        hospital* currentHospital = hospitals[hospitalIndex];
        if(currentHospital && currentHospital->tryAssignAbmulancetoPatient(patient,currentTime)) {
            return;
        }
        //Mov to the next hospital
        hospitalIndex = (hospitalIndex + 1) % numHospitals;
        patient->setHospitalID(hospitalIndex+1);
        attempts++;
    }
    cout << "Failed to assign Patient ID: " << patient->getPatientID()
         << " to any hospital.\n";
}

void Organizer::addCARToOutCarList(Car *car, int currentTime) {
    int priority =car->calculateOutPriority(currentTime,car->GetAssignedPatient()->GetDistanceToHospital());
    OutCars.enqueue(car, priority);
}



void Organizer::addCarToBackCarList(Car *car, int currentTime) {
    int priority = car->calculateBackPriority(currentTime, car->GetAssignedPatient()->GetDistanceToHospital());
    BackCars.enqueue(car, priority);
}


ExtendedCancellablePriorityQueue<Car*>& Organizer::getOutCarsQueue() {
    return OutCars;
}

Car * Organizer::getNextAvailableCar() {
    if (BackCars.isEmpty()) return nullptr; // No available cars

    Car* car;
    int priority;
    BackCars.dequeue(car, priority);
    return car;
}

void Organizer::recalculatePriorities() {
    ExtendedCancellablePriorityQueue<Car*> tempQueue;

    while (!OutCars.isEmpty()) {
        Car* car;
        int oldPriority;
        OutCars.dequeue(car, oldPriority);

        // Recalculate priority based on the car's assigned patient
        Patient* patient = car->GetAssignedPatient();
        if (patient) {
            int newPriority = patient->calculatePriority();
            tempQueue.enqueue(car, newPriority);
        } else {
            tempQueue.enqueue(car, oldPriority);  // If no patient, keep old priority
        }
    }

    OutCars = tempQueue;  // Replace old queue with the updated one
}

int Organizer::getCurrentTime() const {
    return currentTime;
}

int Organizer::getNumHospitals() const {
    return numHospitals;
}

int Organizer::getCarID() const {
    return carID;
}

// Return the list of hospitals

void Organizer::cancelAndHoldCar(int carID) {
    Car* canceledCar= nullptr;
    if (OutCars.cancelRequestAndHold(carID,canceledCar) ){
        cout << "Car " << carID << "'s request has been canceled and held temporarily.\n";
    } else {
        cout << "Car " << carID << " was not found in the OutCars queue.\n";
    }
}

void Organizer::reinstateCar() {
    if (OutCars.reinstateCanceledCar()) {
        cout << "A canceled car has been reinstated to the OutCars queue.\n";
    } else {
        cout << "No canceled cars to reinstate.\n";
    }
}

double Organizer::CalculateDistance(double lat1, double lon1, double lat2, double lon2)
{

    return  sqrt(pow(lat2 - lat1, 2) + pow(lon2 - lon1, 2));
}

void Organizer::assignDistacneToPatient(Patient *patient, hospital *hospital) {
    if (!patient || !hospital) {
        cerr << "Error: Invalid patient or hospital in assignDistanceToPatient.\n";
        return;
    }

    // Calculate distance
    double distance = CalculateDistance(
        patient->getLatitude(),
        patient->getLongitude(),
        hospital->getLatitude(),
        hospital->getLongitude()
    );

    // Round up the distance and set it in the patient
    int roundedDistance = static_cast<int>(ceil(distance));
    patient->SetDistanceToHospital(roundedDistance);

    cout << "Distance from Hospital ID: " << hospital->getHospitalID()
         << " to Patient ID: " << patient->getPatientID()
         << " is " << roundedDistance << " units.\n";
}

/*hospital* Organizer::findNearestHospitalForPatient(Patient* p) {
    //if (numHospitals == 0) {
      //  throw runtime_error("No hospitals available.");
    //}

    hospital* nearestHospital = nullptr;
    double minDistance = 99999999;
///////////
    std::cout << "Number of hospitals: " << numHospitals << std::endl;

    if (numHospitals <= 0) {
        throw std::runtime_error("No hospitals available.");
    }
    if (!hospitals) {
        throw std::runtime_error("Hospitals array is null.");
    }
    ///////////
    for (int i = 0; i < numHospitals; ++i) {
        hospital* h = hospitals[i];
        if (!h->hasAvailableAmbulances()) continue;

        double distance = CalculateDistance(p->getLatitude(), p->getLongitude(),
                                            h->getLatitude(), h->getLongitude());
        if (distance < minDistance) {
            minDistance = distance;
            nearestHospital = h;
        }
    }

    p->SetDistanceToHospital(minDistance);
    return nearestHospital;
}*/


            // If no cars are ready to transition, stop further checks


void Organizer::updateCarStates() {
    // Step 1: Handle OUT cars (OUT -> BACK)
   // cout << "[updateCarStates] currentTime=" << currentTime << endl;
    while (!OutCars.isEmpty()) {
        Car* car;
        int arrivalTime;
        OutCars.peek(car, arrivalTime);

        if  (arrivalTime <= currentTime) { // Check if car has reached the patient
            OutCars.dequeue(car, arrivalTime); // Remove car from OUT queue
            Patient* patient = car->GetAssignedPatient();
            if (!patient) {
                // Safety check (shouldn't happen if code is correct)
                std::cerr << "Error: Car " << car->getID()
                          << " arrived at patient, but has no assigned patient?\n";
            } else {
                // The ambulance has reached the patient
                std::cout << "Car " << car->getID()
                          << " has arrived to pick up Patient " << patient->getPatientID()
                          << " at time " << currentTime << ".\n"
                          << "Now heading back to the hospital...\n";
            }
            car->setStatus("BACK");

            //if (patient) {
              //  patient->markAsFinsished(); // Mark the patient as finished
             //   addFinishedPatient(patient); // Add to finished patients list
            //}
            //car->clearAssignedPatient();

            // Calculate return time to the hospital
            double distanceToHospital = 0.0;
            if(patient) {
               distanceToHospital = patient->GetDistanceToHospital();
            }
            int backArrivalTime = car->calculateBackPriority(currentTime,distanceToHospital);


            BackCars.enqueue(car, backArrivalTime); // Add car to BACK queue
            cout << "Enqueue car " << car->getID()
            << " into BACKCars with priority " << backArrivalTime << endl;

        } else {
            break; // No more cars ready to transition
        }
    }

    // Step 2: Handle BACK cars (BACK -> READY)
    while (!BackCars.isEmpty()) {
        Car* car;
        int arrivalTime;
        BackCars.peek(car, arrivalTime);

        if (arrivalTime <= currentTime) { // Check if car has returned to the hospital
            BackCars.dequeue(car, arrivalTime); // Remove car from BACK queue

            // Add the car back to its respective hospital
            Patient* patient = car->GetAssignedPatient();
            if (patient) {
                patient->markAsFinsished();
                addFinishedPatient(patient);
                cout << "Car " << car->getID()
                          << " has returned Patient " << patient->getPatientID()
                          << " to the hospital at time " << currentTime << ".\n"
                          << "Patient " << patient->getPatientID()
                          << " is now finished.\n";

                car->clearAssignedPatient();

            }
            int homeID = car->getHomeHospitalID();

            // If hospital IDs are 1-based and your array is 0-based, do `homeID - 1`
            hospital* homeHospital = hospitals[homeID - 1];

            // Return the car directly to its home hospital
            homeHospital->AmbulanceReturnToHospital(car);
            car->setStatus("READY"); // Update car status to READY
            cout << "Car " << car->getID() << " has returned to the hospital and is ready for a new assignment.\n";
        } else {
            break; // No more cars ready to transition
        }
    }
}


// Load input file containing data about hospitals, patients, and cars
/*void Organizer::loadInputFile(const std::string& filename) {
    std::ifstream file(filename);  // Open the input file
    if (!file.is_open()) {
        throw std::runtime_error("Unable to open input file: " + filename);
    }

    int numHospitals;
    file >> numHospitals;

    // Loop through the number of hospitals and load their data
    for (int i = 0; i < numHospitals; ++i) {
        int id, numOfSC,numOfNC;
        double lat, lon; // latitude & longitude
        string name;
        file >> id >> lat >> lon >> name>>numOfNC>>numOfSC;// Read hospital details: ID, latitude, longitude, and name

hospital* newHospital = new hospital(id , lat,lon ,name);
        // Add Normal Cars
        for (int j = 0; j < numOfNC; ++j) {
            NC* normalCar = new NC(carID++);  // Example ID and speed
            newHospital->addNC(normalCar);
        }

        // Add Special Cars
        for (int j = 0; j < numOfSC; ++j) {
            SC* specialCar = new SC(carID++);  // Example ID and speed
            newHospital->addSC(specialCar);
        }
        hospitals.enqueue(newHospital);  // Create a hospital object and store it in the list
    }

    int numRequests;file >> numRequests;

    // Loop through the requests and load patient data
    for (int i = 0; i < numRequests; ++i) {
        string type;  // Patient type: EP, SP, NP
        int rt, hid;  // Request time and hospital ID
        float lat,lon;  // Distance to the hospital
        file >> type >> rt >> hid >>lat>>lon;

        // Dynamically create the appropriate patient type based on the input
        Patient* patient = nullptr;
        if (type == "EP") {  // Emergency patient
            int severity;  // Additional field for EP patients
            patient = new EP(rt, hid, 'E', lon, lat);
        }
        else if (type == "SP") {  // Special patient
            patient = new SP(rt, hid, 'S', lon, lat);
        }
        else if (type == "NP") {  // Normal patient
            patient = new NP(rt, hid, 'N',lon , lat);
        }
        // Traverse the hospitals queue to find the matching hospital
        LinkedQueue<hospital*> tempQueue = hospitals; // Create a copy of the queue
        hospital* targetHospital = nullptr;

        while (!tempQueue.isEmpty()) {
            hospital* currentHospital;
            tempQueue.dequeue(currentHospital);
            if (currentHospital->getHospitalID() == hid) {
                targetHospital = currentHospital;
                break; // Found the matching hospital
            }
        }

        if (targetHospital) {
            targetHospital->addRequestToQueue(patient); // Add the patient to the correct hospital
        } else {
            cerr << "Error: No hospital found with ID: " << hid << endl;
            delete patient; // Clean up memory if the hospital is not found
        }

    }

    file.close();
}*/
// Load hospitals and patients from input file
void Organizer::loadInputFile(const std::string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        throw runtime_error("Unable to open input file: " + filename);
    }
    numHospitals =0;
    file >> numHospitals;

    // Allocate the hospital array
    hospitals = new hospital*[numHospitals];

    // Load hospital data
    for (int i = 0; i < numHospitals; ++i) {
        int id, numOfSC, numOfNC;
        double lat, lon;
        string name;
        file >> id >> lat >> lon >> name >> numOfNC >> numOfSC;

        hospital* newHospital = new hospital(id, lat, lon, name);

        // Add Normal Cars
        for (int j = 0; j < numOfNC; ++j) {
            NC* normalCar = new NC(carID++,i+1);
            // pick random prob in [0, 0.5]
            double randomProb = (rand() % 51) / 100.0; // e.g. 0.0 to 0.50
            normalCar->setFailureProbability(randomProb);
            newHospital->addNC(normalCar);
        }

        // Add Special Cars
        for (int j = 0; j < numOfSC; ++j) {
            SC* specialCar = new SC(carID++,i+1);
            // pick random prob in [0, 0.5]
            double randomProb = (rand() % 51) / 100.0; // e.g. 0.0 to 0.50
            specialCar->setFailureProbability(randomProb);
            newHospital->addSC(specialCar);
        }

        hospitals[i] = newHospital;  // Store the hospital in the array
    }

    // Load patient data
    int numRequests;
    file >> numRequests;
    for (int i = 0; i < numRequests; ++i) {
        string type;
        int rt, hid;
        float lat, lon;
        file >> type >> rt >> hid >> lat >> lon;

        Patient* patient = nullptr;
        if (type == "EP") {
            patient = new EP(rt, hid, 'E', lon, lat);
        } else if (type == "SP") {
            patient = new SP(rt, hid, 'S', lon, lat);
        } else if (type == "NP") {
            patient = new NP(rt, hid, 'N', lon, lat);
        }
        if (hid - 1 < 0 || hid - 1 >= numHospitals) {
            cerr << "Invalid hospital ID: " << hid << endl;
            continue;
        }
        hospitals[hid - 1]->addRequestToQueue(patient);
    }

    file.close();
}




// Run the entire simulation until all requests are processed

void Organizer::simulate(bool interactive) {
    cout << "Simulation started...\n";
    while (!isSimulationComplete()) {
        // Continue until all patients are served
        if (interactive) {
            cout << "\nCurrent Simulation Time: " << currentTime << "\n";
        }
        // Step 1: Update car states
        try {
            updateCarStates();
            handleCarFailures();
            // Step 2: Manage patient requests in each hospital
            for (int i = 0; i < numHospitals; ++i) {
                hospitals[i]->manageRequestsofPatients(currentTime);
            }
        }
        catch (const std::exception& e) {
            cerr <<"Error during simulation: "<< e.what() << endl;
        }
        // Step 3: Optional status output
        if (interactive) {
            cout << "\n--- Simulation Progress ---\n";
            for (int i = 0; i < numHospitals; ++i) {
               hospitals[i]->viewQueuestatus();
                hospitals[i]->viewAvailableAmbulances();
            }
            cout << "Press Enter to continue to the next timestep...";
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        // Step 4: Increment time step
        currentTime++;
    }
    if(!interactive) {

        cout << "Simulation complete! All patient requests have been handled.\n";
    }
        cout<<"Generating output file: 'simulation_results.txt'...\n";
        generateOutputFile("simulation_results.txt");
}
// Execute a single step in the simulation

// Simulate one step
void Organizer::simulateStep() {
    updateCarStates();

    for (int i = 0; i < numHospitals; ++i) {
        hospitals[i]->manageRequestsofPatients(currentTime);
    }
}

// Update car states (e.g., move cars from OUT to BACK, BACK to READY)

// Check if all patient requests are completed

// Check if simulation is complete
bool Organizer::isSimulationComplete() const {
    for (int i = 0; i < numHospitals; ++i) {
        if (hospitals[i]->getCheckCounter() > 0) {
            return false;
        }
    }
    // 2) Are there any ambulances still en route to patients?
    if (!OutCars.isEmpty()) {return false;}
    // 3) Are there any ambulances still returning to the hospital?
    if (!BackCars.isEmpty()) {return false;}
    // If none of the above are true, simulation is complete
    return true;
}


// Generate an output file containing the simulation results

//we don't need it now


 void Organizer::generateOutputFile(const std::string& filename) const {
    std::ofstream outputFile(filename);
    if (!outputFile.is_open()) {
        throw std::runtime_error("Unable to open output file: " + filename);
    }

    // Existing lines: (patient finish time, etc.)
    outputFile << "FT\tPID\tQT\tWT\n";
    LinkedQueue<Patient*> tempQueue = finishedPatients;
    while (!tempQueue.isEmpty()) {
        Patient* patient;
        tempQueue.dequeue(patient);
        outputFile << patient->GetFinishTime() << "\t"
                   << patient->getPatientID() << "\t"
                   << patient->GetRequestTime() << "\t"
                   << patient->GetWaitingTime() << "\n";
    }

    // Now print failure statistics
    outputFile << "\n--- Failure Statistics ---\n";
    outputFile << "Total Cars: " << totalCars << "\n";
    outputFile << "Failed Cars: " << failedCars << "\n";
    double failPercentage = (totalCars == 0)
        ? 0.0
        : (static_cast<double>(failedCars) / totalCars * 100.0);
    outputFile << "Failure Percentage: " << failPercentage << "%\n";

    // If you track actual failed car IDs in a list, print them here:
    // outputFile << "Failed Car IDs: ...\n";

    outputFile.close();
}


// Return the current simulation time

// Access the list of hospitals
hospital** Organizer::getHospitals() const {
    return hospitals;
}



void Organizer::runSimulation(const string& inputFileName) {
    // Step 1: Load the input data
    cout << "Loading input file: " << inputFileName << "...\n";
    loadInputFile(inputFileName);


}