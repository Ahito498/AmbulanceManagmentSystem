//
// Created by Rashwan's on 17/11/2024.
//

#include "hospital.h"
#include "..//Organizer/globals.h"
#include "../Organizer/Organizer.h"


using namespace std;
//extern Organizer* globalOrganizer;
hospital::hospital(int id, double lat, double lon, string name): HospitalID(id), latitude(lat), longitude(lon),
                                                                  HospitalName(name), CheckCounter(0) {
}

int hospital::getHospitalID() const {
    return HospitalID;
}

double hospital::getLatitude() const {
    return latitude;
}

double hospital::getLongitude() const {
    return longitude;
}

string hospital::getHospitalName() const {
    return HospitalName;
}

//////////////////////////////////////////////////////
///
///
void hospital::addRequestToQueue(Patient *p)
{
    if(p->GetPatientType() == 'E')
    {
        EPRequestList.enqueue(dynamic_cast<EP*>(p),p->calculatePriority());
        CheckCounter++;
    }
    else if(p->GetPatientType()=='S')
    {
        SPRequestList.enqueue(dynamic_cast<SP*>(p));
        CheckCounter++;

    }
    else if(p->GetPatientType()=='N')
    {
        NPRequestList.enqueue(dynamic_cast<NP*>(p));
        CheckCounter++;

    }
}
////////////////////////////////////
Car* hospital::getAvailableAmbulancesForPatient(Patient* p) {
    Car* assignedAmbulance = nullptr;

    // Prioritize normal cars for emergencies
    if (p->GetPatientType() == 'E' && !NCarsList.isEmpty()) {
        NC* normalCar = nullptr;
        NCarsList.dequeue(normalCar);
        assignedAmbulance = normalCar;

    }

    else if ((p->GetPatientType() == 'E' || p->GetPatientType() == 'S') && !SCarsList.isEmpty()) {
        SC* specialCar = nullptr;
        SCarsList.dequeue(specialCar);
        assignedAmbulance = specialCar;
    }
    else if (p->GetPatientType() == 'N' && !NCarsList.isEmpty()) {
        NC* normalCar = nullptr;
        NCarsList.dequeue(normalCar);
        assignedAmbulance = normalCar;
    }

    if (assignedAmbulance) {
        CheckCounter--;
        cout << "Assigned Car ID: " << assignedAmbulance->getID() << " for Patient ID: " << p->getPatientID() << ".\n";
    } else {
        cout << "No available ambulances for Patient ID: " << p->getPatientID() << ".\n";
    }
    //globalOrganizer->addCARToOutCarList(assignedAmbulance,globalOrganizer->getCurrentTime());
    return assignedAmbulance;
}

bool hospital::tryAssignAbmulancetoPatient(Patient *patient, int currentTime) {
    return assignAmbulanceToPatient(patient, currentTime);
}


//////////////////////////////////////////*Done*////
    //here I have to assign the status of ambulance as "OUT"//Done
    //then add using the organizer pointer the assigned ambulance to outcars list
    //then print the ambulance ID and the Patient ID attached too
    //////////////////////////////////




void hospital::viewQueuestatus() const {
    cout << "========================================" << endl;
    cout << "Hospital: " << HospitalName << " (ID: " << HospitalID << ")" << endl;
    cout << "Total Requests in Queues: " << CheckCounter << endl;
    cout << "========================================" << endl;


    // View Emergency Patients Queue
    cout << "Emergency Patients Queue:" << endl;
    if (EPRequestList.isEmpty()) {
        cout << "  No emergency patients in the queue." << endl;
    } else {
        EP* patient;
        int severity;

        auto tempQueue = EPRequestList; // Create a temporary copy of the queue
        while (!tempQueue.isEmpty()) {
            tempQueue.dequeue(patient, severity);
            cout << "  Patient ID: " << patient->getPatientID()
                 << ", Severity: " << severity
                 << ", Type: Emergency" << endl;
        }
    }

    // View Special Patients Queue
    cout << "Special Patients Queue:" << endl;
    if (SPRequestList.isEmpty()) {
        cout << "  No special patients in the queue." << endl;
    } else {
        SP* patient;

        auto tempQueue = SPRequestList; // Create a temporary copy of the queue
        while (!tempQueue.isEmpty()) {
            tempQueue.dequeue(patient);
            cout << "  Patient ID: " << patient->getPatientID()
                 << ", Type: Special" << endl;
        }
    }

    // View Normal Patients Queue
    cout << "Normal Patients Queue:" << endl;
    if (NPRequestList.isEmpty()) {
        cout << "  No normal patients in the queue." << endl;
    } else {
        NP* patient;

        auto tempQueue = NPRequestList; // Create a temporary copy of the queue
        while (!tempQueue.isEmpty()) {
            tempQueue.dequeue(patient);
            cout << "  Patient ID: " << patient->getPatientID()
                 << ", Type: Normal" << endl;
        }
    }

    cout << "========================================" << endl;
}

void hospital::addNC(NC *nc) {
    NCarsList.enqueue(nc);
}

void hospital::addSC(SC *sc) {
    SCarsList.enqueue(sc);
}

void hospital::viewAvailableAmbulances() const
{
    cout << "========================================" << endl;
    cout << "Hospital: " << HospitalName << " (ID: " << HospitalID << ")" << endl;
    cout << "Available Ambulances:" << endl;
    cout << "========================================" << endl;


    // View Normal Cars
    cout << "Normal Cars:" << endl;
    if (NCarsList.isEmpty()) {
        cout << "  No normal ambulances available." << endl;
    } else {
        NC* car;

        auto tempQueue = NCarsList; // Create a temporary copy to iterate
        while (!tempQueue.isEmpty()) {
            tempQueue.dequeue(car);
            cout << "  Ambulance ID: " << car->getID()
                 << ", Status: " << car->GetStatus() << endl;
        }
    }
    // View Special Cars
    cout << "Special Cars:" << endl;
    if (SCarsList.isEmpty()) {
        cout << "  No special ambulances available." << endl;
    } else {
        SC* car;

        auto tempQueue = SCarsList; // Create a temporary copy to iterate
        while (!tempQueue.isEmpty()) {
            tempQueue.dequeue(car);
            cout << "  Ambulance ID: " << car->getID()
                 << ", Status: " << car->GetStatus() << endl;
        }
    }

    cout << "========================================" << endl;
}

bool hospital::isRequestQueueEmpty() const {
    if(CheckCounter == 0)
        return true;
    else
        return false;
}

void hospital::manageRequestsofPatients(int currentTime)  {
    while (!EPRequestList.isEmpty()) {
        EP* ep = nullptr;
        int priority;

        EPRequestList.dequeue(ep, priority);
       // globalOrganizer->assignDistacneToPatient(ep, this);
        if(ep->GetRequestTime() > currentTime) {  //If this patient's request time has not been reached yet
            EPRequestList.enqueue(ep, priority);
            break;
        }

        if (!assignAmbulanceToPatient(ep, currentTime)) {
            // If no ambulance is available, re-enqueue the patient
            EPRequestList.enqueue(ep, priority);
            break;
        }

        // Mark the patient as finished and add to the finished list
        //ep->markAsFinsished();
        //globalOrganizer->addFinishedPatient(ep);
    }

    // Repeat for SP and NP patients
    while (!SPRequestList.isEmpty()) {
        SP* sp = nullptr;

        SPRequestList.dequeue(sp);
      //  globalOrganizer->assignDistacneToPatient(sp, this);

        if(sp->GetRequestTime() > currentTime) {  //If this patient's request time has not been reached yet
            SPRequestList.enqueue(sp);
            break;
        }

        if (!assignAmbulanceToPatient(sp, currentTime)) {
            SPRequestList.enqueue(sp);
            break;
        }

       // sp->markAsFinsished();
        //globalOrganizer->addFinishedPatient(sp);
    }

    while (!NPRequestList.isEmpty()) {
        NP* np = nullptr;

        NPRequestList.dequeue(np);
        //globalOrganizer->assignDistacneToPatient(np, this);

        if(np->GetRequestTime() > currentTime) {  //If this patient's request time has not been reached yet
            NPRequestList.enqueue(np);
            break;
        }

        if (!assignAmbulanceToPatient(np, currentTime)) {
            NPRequestList.enqueue(np);
            break;
        }

       // np->markAsFinsished();
       // globalOrganizer->addFinishedPatient(np);
    }
}

/*bool hospital::cancelNormalPatientRequest(int PatientID) {
    if(NPRequestList.cancelRequest(PatientID)) {
        cout<<"Request of patient "<< PatientID<<" has been cancelled!"<<endl;
        return true;
    }
    else {
        cout<<"No request for normal patient to cancel"<<endl;
        return false;
    }
}*/

int hospital::getCheckCounter() const {
    return CheckCounter;
}

////////////////////////////
///Return a car if it's request was cancelled while it's on the way
///////////////////////////
/*bool hospital::ReturnCarOnCancellation(int carID, int cancellationTime) {
    Car* carToReturn = nullptr;

    // Check if the car exists in the OutCars list
    if (globalOrganizer->getOutCarsQueue().cancelRequestAndHold(carID,carToReturn)) {
        // Assume this function removes and retrieves the car
        int assignedTime = carToReturn->getAssignmentTime();  // Assume GetAssignedTime() returns the time car was assigned
        int returnTime = cancellationTime - assignedTime;
        if (returnTime > 0) {
            cout << "Ambulance: " << carID << " is returning due to cancellation. Return time: "
                 << returnTime << " timesteps." << endl;
            // Add the car to the BackCars list with priority as return time
            globalOrganizer->addCarToBackCarList(carToReturn, globalOrganizer->getCurrentTime() + returnTime);
        } else {
            cout << "Ambulance: " << carID << " has an invalid return time!" << endl;
            return false;
        }
        return true;
    } else
    {
        cout << "Ambulance: " << carID << " is not found in OutCars!" << endl;
        return false;
    }
}*/

void hospital::sendAmbulance() //Logic of this function is see if the Outcars list is not empty dequeue one of the out cars and send it to the desired patient
{
   Car* sentAmbulance=nullptr;
    int priority;
    if(globalOrganizer->getOutCarsQueue().isEmpty())
    {
       cout<<"No ambulances available to send!"<<endl;
        return;
      }
     if(globalOrganizer->getOutCarsQueue().dequeue(sentAmbulance, priority)) {
         cout << "Ambulance ID: " << sentAmbulance->getID()
              <<"is now sent to the desired patient."<<endl;
        // sentAmbulance->setStatus("ON_MISSION");
     }
}

void hospital::AmbulanceReturnToHospital(Car *a) {
    cout<<"Ambulance: "<<a->getID()<<" returned to the hospital"<<endl;
    a->setStatus("Ready");
    //Add it to the correct list
    if(a->GetType() == 'N') {
        NCarsList.enqueue(dynamic_cast<NC*>(a));
    }
    else {
        SCarsList.enqueue(dynamic_cast<SC*>(a));
    }
}

bool hospital::assignAmbulanceToPatient(Patient *patient, int currentTime) {

    globalOrganizer->assignDistacneToPatient(patient,this);  //take the patient and current

    Car* assignedCar = getAvailableAmbulancesForPatient(patient);

    if (!assignedCar) {
        // No ambulance available
        cout << "No ambulances available in Hospital ID: " << getHospitalID()
             << " for Patient ID: " << patient->getPatientID() << ".\n";
        return false;
    }
    double distanceToPatient = patient->GetDistanceToHospital();
    // Assign the ambulance
    assignedCar->setAssignmentTime(currentTime,distanceToPatient);
    assignedCar->SetAssignPatient(patient, currentTime);
    assignedCar->setStatus("OUT");
    assignedCar->setPID(patient->getPatientID());
    // Calculate and set the patient's arrival time
    patient->setPickUpTime(assignedCar->getPickupTime());
    globalOrganizer->addCARToOutCarList(assignedCar, currentTime);
    cout << "Assigned Car ID: " << assignedCar->getID()
         << " to Patient ID: " << patient->getPatientID()
         << " from Hospital ID: " << getHospitalID() << endl;

    return true;
}

void hospital::updateAmbulanceStatus(Car *a) {
    a->setStatus("Ready");
    cout<<"Ambulance: "<<a->getID()<<" is Ready now"<<endl;
}

bool hospital::hasAvailableAmbulances() const {
    return !NCarsList.isEmpty() || !SCarsList.isEmpty();
}

LinkedQueue<NC *> hospital::getNCCarsList() {
    return NCarsList;
}

LinkedQueue<SC *> hospital::getSCarsList() {
    return SCarsList;
}


////////////////////////view functions/////////////////////

//I Think it will be better to put them in the UI or Organizer.


//to make the cancel request if found return the car to back directly not to the cars list we need to make a cancelation time
//and set the return time = canelation time - assigned time then after the return time period add it to it's list