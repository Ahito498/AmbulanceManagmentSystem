//
// Created by Rashwan's on 21/11/2024.
//

#include "SC.h"



SC::SC(int id,int HID): Car(id,'S',"Ready",7.0,HID){}

double SC::GetSpeed() {
    return 7.0;
}

char SC::GetType() {
    return 'S';
}
