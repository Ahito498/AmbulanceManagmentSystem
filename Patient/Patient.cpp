//
// Created by Rashwan's on 17/11/2024.
//
#include <iostream>
#include <string>
#include "Patient.h"
#include "..//Organizer/globals.h"
using namespace std;
/////
int Patient::ID_counter = 0;

int Patient::getPatientID() const {
   return  PatientID;
}

//////////////

Patient::Patient(int Rt, int hid, char t,double lon, double lat): PatientID(getPatientID()),longtude(lon),latitude(lat),finished(false)
{
    RTime = Rt;
    HID = hid;
    Type = t;
    PICKUPTime =-1;
    FinishTime = -1;
    PickedUp = false;
    PatientID = ++ID_counter;
}

double Patient::getLongitude() const
{
    return longtude;
}
double Patient::getLatitude() const
{
    return latitude;
}




/*int Patient::GetPrioritySeverity() const {
    if (Type == 'E') {
        return std::numeric_limits<int>::max() - Severity; // High priority for EP
    }
    return RTime; // For SP and NP, earlier requests have higher priority
}
*/
int Patient::GetRTime() const {
    return RTime;
}


////////////////

void Patient::printInfo() const
{
    std::cout << "Patient Type: " << Type << "\n" << ", Request Time: " << RTime << "\n" << ", Hospital ID: " << HID << "\n"
        << ", DistanceToHospital: " << DToHospital << "\n" << "Picked Up: " << (PickedUp ? "Y" : "N") << "\n"
        << "Pickup Time: " << (PICKUPTime == -1 ? "Not Picked Up" : std::to_string(PICKUPTime))
        << "\n" << ", Served: " << (finished ? "Yes" : "No") << "\n" << ", Waiting Time: " << GetWaitingTime()<<"\n";

}

void Patient::setPickUpTime(int picuptime)
{
    PICKUPTime = picuptime;
}

void Patient::SetPickedUp(bool status)
{
    PickedUp = status;
}

void Patient::SetDistanceToHospital(double dis)
{
    DToHospital = dis;
}

int Patient::getRTime() const {
    return RTime;
}

int Patient::getAssignmntTime() const {
    return AssignmntTime;
}




int Patient::getHospitalID() const
{
    return HID;
}

int Patient::GetPickUpTime() const
{
    return PICKUPTime;
}

void Patient::SetFinishTime(int ft)
{
    FinishTime = ft;
}

int Patient::GetFinishTime() const
{
    return FinishTime;
}

int Patient::GetWaitingTime() const
{
    return (PICKUPTime == -1) ? 0 : (PICKUPTime - RTime); ///////// condition ? value is true: value if false
}

bool Patient::IsPickedUp() const
{
    return PickedUp;
}

int Patient::GetRequestTime() const
{
    return RTime;
}


void Patient::markAsFinsished() {
    finished = true;
}

bool Patient::isFinished() const {
    return finished;
}

int Patient::calculatePriority()  {
    char type = GetPatientType();
    int requestTime = GetRequestTime();

    // Base priority is inversely proportional to the request time
    int basePriority = 1000 - requestTime;

    // Modify priority based on patient type
    switch (type) {
        case 'E':  // Emergency patients get the highest weight
            return basePriority + 500;
        case 'S':  // Special patients get medium weight
            return basePriority + 250;
        case 'N':  // Normal patients get no additional weight
            return basePriority;
        default:   // Handle unexpected types gracefully
            cerr << "Unexpected Patient Type: " << type <<endl;
        return basePriority;
    }
}

double Patient::GetDistanceToHospital() const
{
    return DToHospital;
}

void Patient::setHospitalID(int hosid) {
    HID = hosid;
}


Patient::~Patient()
= default;
