//
// Created by Rashwan's on 21/11/2024.
//
#include <iostream>
#include "NP.h"

NP::NP(int Rt, int hid, char t, double lon, double lat) :Patient(Rt, hid, 'N', lon, lat) { Cancelled = false; }
bool NP::IsCancelled() const
{
    return Cancelled;
}
void NP::CancelRequest()
{
    Cancelled = true;
}



void NP::printInfo() const
{
    Patient::printInfo();
    std::cout << "Cancelled: " << (Cancelled ? "Y" : "N") << "\n";
}



char NP::GetPatientType() {
    return 'N';
};
