//
// Created by Rashwan's on 21/11/2024.
//
#ifndef SC_H
#define SC_H
#include "Car.h"
class SC : public Car
{
public:


    SC(int id,int HID);
     double GetSpeed() override;

     char GetType() override;
};
#endif