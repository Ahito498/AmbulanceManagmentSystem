#pragma once  
#include "..//Hospital/hospital.h"
#include <string>
#include "..//5-PriorityQueue/priQueue.h"

#include "..//DerivedClasses/DerivedPriQueue.h"
//#include "priQueue.h"

class Organizer {
private:
    int totalCars =0;
    int failedCars =0;

    hospital** hospitals;
    int numHospitals;
    LinkedQueue<Patient*> finishedPatients;  // A queue to store patients who have completed their service
    static int currentTime;  // Keeps track of the current simulation time
    ExtendedCancellablePriorityQueue<Car*> OutCars; // Priority queue for cars en route to patients
    priQueue<Car*>BackCars; //Priority queue for cars en route from patients
    void updateCarStates();  // Function to handle cars moving between different states (OUT, BACK, READY)
    static int carID;
public:
    Organizer();  
    ~Organizer();  
    //////
    void incrementCarCount();
    void incrementFailedCarCount();
    void handleCarFailures();
    void addFinishedPatient(Patient* p);        //Add a finished Patient
    //////
    void setCurrentTime(int time);
    int getCurrentTime() const;
    int getNumHospitals() const;
    int getCarID() const;
    void addHospital(hospital* newHospital); // Function to add a hospital
    void assignAmbulanceToPatient(Patient *p);

    void addCARToOutCarList(Car *car, int currentTime);    //add cars to out cars
    void processCARFromOutCarList();         //
    void addCarToBackCarList(Car *car, int currentTime);
    void ProcessCARFromBackCarList();

    ExtendedCancellablePriorityQueue<Car *> &getOutCarsQueue();

    //bool removeCARFromBackCarList(int carID,Car*& CarToReturn);
    Car* getNextAvailableCar();

    void recalculatePriorities();

    ////////////////
    void loadInputFile(const std::string& filename);  // Function to load all simulation data from an input file aka ( Function File Loading )
    void simulate(bool interactive);
    void simulateStep();  
    bool isSimulationComplete() const;  // Checks if all patient requests are processed
    void generateOutputFile(const std::string& filename) const;  // Function to write the simulation results to a file
    //double GetDistancToHospital(Patient*P,hospital*H);


    hospital** getHospitals() const;  // Provides access to the list of hospitals
    void runSimulation(const std::string &inputFileName);

    ///////////////////

    // Cancel a car request and hold it temporarily
    void cancelAndHoldCar(int carID);

    // Reinstate a canceled car back to the OutCars queue
    void reinstateCar();

    static double CalculateDistance(double lat1,double lon1,double lat2,double lon2);
    void assignDistacneToPatient(Patient* patient, hospital* hospital);
    //hospital* findNearestHospitalForPatient(Patient* p);
};
