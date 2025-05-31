//
// Created by Rashwan's on 21/11/2024.
//
#ifndef NC_H
#define NC_H


#include "Car.h"
class NC :public Car
{
public:
    NC(int id, int HID);
     double GetSpeed() override;

     char GetType() override;
};
#endif