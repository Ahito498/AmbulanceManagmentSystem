//
// Created by Rashwan's on 21/11/2024.
//
#pragma once
#include "Patient.h"
class SP :public Patient
{
public:
    SP(int Rt, int hid, char t,double lon,double lat);

    void printInfo() const override;
    char GetPatientType () override;

};