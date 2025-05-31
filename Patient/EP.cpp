#include <iostream>
#include "EP.h"
int EP::severityCounter = 1;
EP::EP(int Rt, int hid, char t, double lon, double lat) :Patient(Rt, hid, 'E', lon, lat)
{
    severity = severityCounter++;
}








void EP::printInfo() const
{

    std::cout << "Severity: " << severity << "\n";
    Patient::printInfo();
}

char EP::GetPatientType() {
    return 'E';
}
