//
// Created by Rashwan's on 17/11/2024.
#pragma once


class Patient
{
private:
    ///////
    static int ID_counter;
    int PatientID;
    bool finished;      //finished or not
    double longtude;
    double latitude;
    ///////
    int Severity=0;
    ///////
    int RTime;
    int AssignmntTime;
    int PICKUPTime;
    int FinishTime;

    int HID;
    double DToHospital;
    char Type;
    bool PickedUp;          // variable to show if the patient is picked

public:
    Patient(int Rt, int hid, char t,double lon,double lat);
    //////
    int getPatientID() const;
    double getLongitude() const;
    double getLatitude() const;
   // virtual int GetSeverity() const;
    //virtual int GetPrioritySeverity() const;
    int GetRTime() const;
    //////
    virtual void printInfo() const;
    void SetPickedUp(bool status);
//////////////
    void SetDistanceToHospital(double dis);

    void setAssignmntTime(int AssignmntTime);

    int getRTime() const;
    int getAssignmntTime() const;

    int calculatePT(double speed);
    ///////
    void markAsFinsished();
    bool isFinished() const;

    int calculatePriority();
    ///
    double GetDistanceToHospital() const;

    void setHospitalID(int hosid) ;

    int getHospitalID() const;

    void setPickUpTime(int pickuptime);

    int GetPickUpTime() const;

    void SetFinishTime(int ft);

    int GetFinishTime() const;

    int GetWaitingTime() const;

    bool IsPickedUp() const;

    int GetRequestTime() const;

    virtual char GetPatientType () = 0;
    void SetIsServed(bool served);
    bool GetIsServed() const;
    virtual ~Patient();
};