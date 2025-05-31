#include "NC.h"




NC::NC(int id,int HID): Car(id,'N',"Ready",5.0,HID){}

double NC::GetSpeed() {
    return 5.0;
}

char NC::GetType() {
    return 'N';
}
