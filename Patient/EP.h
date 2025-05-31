#pragma once
#include "Patient.h"
class EP :public Patient
{
private:
    int severity;
    static int severityCounter;
public:
    EP(int Rt, int hid, char t, double lon, double lat);




    void printInfo() const override;
    char GetPatientType () override ;
};