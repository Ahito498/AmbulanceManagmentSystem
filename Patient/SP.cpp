//
// Created by Rashwan's on 21/11/2024.
//

#include "SP.h"

#include <iostream>
#include <ostream>
using namespace std;

SP::SP(int Rt, int hid, char t, double lon, double lat) :Patient(Rt, hid, 'S', lon, lat) {}



void SP::printInfo() const
{
    cout<< "Special Patient Information:" << endl;
    Patient::printInfo();
}

char SP::GetPatientType() {
    return 'S';
};
