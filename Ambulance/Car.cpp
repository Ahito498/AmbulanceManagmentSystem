#include "Car.h"
#include "..//Hospital/hospital.h"
#include <string>

#include "../Organizer/globals.h"
using namespace std;

Car::Car(int id, char t, string stat,double s, int homeHospital): CarID(id), Type(t), Status(stat), Speed(s),PatientID(-1),assignedPatient(nullptr),BTime(0),AssignmentTime(0),PicupTime(-1),FinishTime(-1),HomeHospitalID(homeHospital),failureProbability(0.0)    //we have to set a car speed for each inherited car
{}



int Car::getID() const
{
    return CarID;
}

int Car::getHomeHospitalID() const {
    return HomeHospitalID;
}

void Car::setFailureProbability(double f) {
    failureProbability = f;
}

double Car::getFailureProbability() const {
    return failureProbability;
}


//void Car::setStatus(string& s)
//{
  //  Status = s;
//}

string Car::GetStatus() const
{
    return Status;  //READY , OUT , BACK
}



int Car::calculateArrivalTime(double distance) const
{
    return  static_cast<int>(ceil(distance/this->Speed));
}

void Car::setAssignmentTime(int currentTimeStep, double distance)
{
    this->AssignmentTime = currentTimeStep;
    this->PicupTime = currentTimeStep+ calculateArrivalTime(distance);
}

int Car::getAssignmentTime() const

{
    return AssignmentTime;
}
int Car::getPickupTime() {
    return PicupTime;
}

void Car::SetBusyTime(int& time)
{
    BTime = time;
}

int Car::GetBusyTime() const {
    return BTime;
}

void Car::UpdateBusyTime(int& time)
{
    BTime += time;
}

bool Car::hasReachedPatient(int currentTime) const {

    return currentTime >= PicupTime;    //checks if the current time greater than the pickup time return true else return false
}

bool Car::hasReturnedToHospital(int currentTime) const {
    return currentTime >= AssignmentTime;
}

void Car::printInfo()const
{
      cout << "Car Type: " << Type << "\n"
           << ", Speed: " << Speed << "\n"
           << ", Status: " << Status << "\n"
           << 'R' << ", Patient ID: " << PatientID << "\n"
           << ", Busy Time: " << BTime << "\n";
    if (assignedPatient)
    {
        cout << "Assigned Patient Details:\n";
        assignedPatient->printInfo();
    }
}

void Car::SetAssignPatient(Patient* p,int CurrTime)
{
   // AssignmentTime = CurrTime;
    assignedPatient = p;
   // Status = "ASS";
    //hospital* nearestHospital= globalOrganizer->findNearestHospitalForPatient(p);
    //double DistancetoHospital = p->GetDistanceToHospital();
   // FinishTime = CurrTime + static_cast<int>(DistancetoHospital/ Speed);
   // PicupTime = AssignmentTime + static_cast<int>(DistancetoHospital / Speed);
   // p->setPickUpTime(PicupTime);
   // p->SetFinishTime(FinishTime);
}

Patient* Car::GetAssignedPatient() const
{
    return assignedPatient;
}

void Car::setPID(int pid) {
    PatientID = pid;
}

void Car::ReadyPatient()
{
    assignedPatient = nullptr;
    Status = "Ready";
}

void Car::clearAssignedPatient() {
    assignedPatient = nullptr;
}

int Car::calculateOutPriority(int currentTime, double distance) const {
    return currentTime + static_cast<int>(ceil(distance / Speed));
}
int Car::calculateBackPriority(int currentTime, double distance) const {
    return currentTime + static_cast<int>(ceil(distance / Speed));
}
/*double Car::GetDistancToHospital(Patient *P)
{ double disPX= P->getLatitude();
    double disPy= P->getLatitude();
    double disHX=
    double disHy= H->getLatitude();
    return sqrt(pow(disPX-disHX,2)+pow(disPy-disHy,2));
}*/

Car::~Car()
= default;

void Car::setStatus(const char *s) {
    Status = s;
}
