#pragma once
#include "Patient.h"
class NP :public Patient
{
    bool Cancelled;
public:
    NP(int Rt, int hid, char t,double lon,double lat);
    bool IsCancelled() const;
    void CancelRequest();

    void printInfo() const override;
    char GetPatientType () override;
};