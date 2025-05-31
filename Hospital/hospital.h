//
// Created by Rashwan's on 17/11/2024.
//
#ifndef HOSPITAL_H
#define HOSPITAL_H


#include "LinkedQueue.h"
#include "priQueue.h"
#include "ArrayStack.h"
#include<iostream>
//#include <cmath>
#include "..//DerivedClasses/CancellableQueue.h"
//#include "/Users/macstoreeg/Desktop/Y3S1/DS/Project/Ambulance/Car.h"
#include "/Users/macstoreeg/Desktop/study/Y3S1/DS/Project/Ambulance/NC.h"
#include "/Users/macstoreeg/Desktop/study/Y3S1/DS/Project/Ambulance/SC.h"
#include "/Users/macstoreeg/Desktop/study/Y3S1/DS/Project/Patient/Patient.h"
#include "/Users/macstoreeg/Desktop/study/Y3S1/DS/Project/Patient/NP.h"
#include "/Users/macstoreeg/Desktop/study/Y3S1/DS/Project/Patient/SP.h"
#include "/Users/macstoreeg/Desktop/study/Y3S1/DS/Project/Patient/EP.h"


using namespace std;


//////////////////////////////////*/

////////////////////////////////



class hospital {
private:
    int HospitalID;
    double latitude;        //Latitude of the hospital(for distance calculations)
    double longitude;       //Longitude of the hospital(for distance calculations)
    string HospitalName;
    int CheckCounter;
    //using int temporarly to test it using mock data until patient and ambulance classes finished
    //for patient lists
    LinkedQueue<SP*> SPRequestList;
    LinkedQueue<NP*> NPRequestList;
    priQueue<EP*>    EPRequestList;

    //for cars lists
    LinkedQueue<SC*> SCarsList;
    LinkedQueue<NC*> NCarsList;
   // LinkedQueue<Car*> OutCars;
    //LinkedQueue<Car*> BackCars;

    //for finished operations list
   // ArrayStack<Patient*> FinishedList;
    ////////////////////////////////////////////////////////////////

public:

    //getters for hospital info

    hospital(int id, double lat, double lon, string name);



    int getHospitalID() const;
    double getLatitude() const;
    double getLongitude() const;
    string getHospitalName() const;

    //Patient request management    // replaced all the patient datatype with int to make mock data and test the functions until finishing the other classes
    void addRequestToQueue(Patient* p);
    Car* getAvailableAmbulancesForPatient(Patient* p);
    bool tryAssignAbmulancetoPatient(Patient* patient, int currentTime);


    void viewQueuestatus() const;
    void addNC(NC* nc);
    void addSC(SC* sc);
    void viewAvailableAmbulances() const;
    bool isRequestQueueEmpty() const;
    void manageRequestsofPatients(int currentTime);        //processing all patient requests in queues
    bool cancelNormalPatientRequest(int PatientID);
    int getCheckCounter() const;

    //Ambulance management     //replaced all the ambulance data type with int to test it with mock data..
    bool ReturnCarOnCancellation(int carID,int cancellationTime);
    static void sendAmbulance();
    void AmbulanceReturnToHospital(Car* a);
    bool assignAmbulanceToPatient(Patient* p,int currentTime);

    /////

    ////

    static void updateAmbulanceStatus(Car* a);
    bool hasAvailableAmbulances() const;
    //view current status functions
   // void viewQueuestatus() const;
    //void viewAvailableAmbulances() const;
    //void viewAvailablePatints() const;

    LinkedQueue<NC*> getNCCarsList();
    LinkedQueue<SC*> getSCarsList();



};
#endif




