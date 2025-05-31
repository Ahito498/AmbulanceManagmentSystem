#ifndef CAR_H
#define CAR_H

#include <string>
using namespace std;
#include "/Users/macstoreeg/Desktop/study/Y3S1/DS/Project/Patient/Patient.h"
//#include "..//Organizer/globals.h"
class Car
{
private:
    int CarID;
    char Type;
    string Status; //Ready Out Back
    double Speed;
    int PatientID;
    int BTime;      // the total busy time of the car
    int AssignmentTime;
    int PicupTime;
    int FinishTime;     //time reached to hospital
    Patient* assignedPatient;
    int HomeHospitalID;
    double failureProbability;
public:

    Car(int id, char t, string stat, double s,int homeHospital);

    void SetCarID(int& carid);
    int getID() const;
    int getHomeHospitalID() const;
    void setFailureProbability(double f);
    double getFailureProbability() const;

    /////Speed Functions//////
    virtual double GetSpeed() =0;

    virtual char GetType() =0;

    // void setStatus(string& s);

    string GetStatus() const;

    int calculateArrivalTime(double distance) const;
    void setAssignmentTime(int currentTimeStep, double distance);
    int getAssignmentTime() const;

    int getPickupTime();

    void SetBusyTime(int& time);

    int GetBusyTime() const;
    void UpdateBusyTime(int& time);
    bool hasReachedPatient(int currentTime) const;
    bool hasReturnedToHospital(int currentTime) const;
    virtual void printInfo() const;
    void SetAssignPatient(Patient* p, int CurrTime);
    Patient* GetAssignedPatient() const;
    void setPID(int pid);
    void ReadyPatient();
    void clearAssignedPatient();
    int calculateOutPriority(int currentTime, double distance) const;

    int calculateBackPriority(int currentTime, double distanceToHospital) const;

    virtual ~Car();
    void setStatus(const char * s);//see it later
};
#endif