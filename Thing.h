//
//  Thing.h
//  HW6
//
//  Created by Jordan Lance McMillan on 8/1/15.
//  Copyright (c) 2015 Jordan Lance McMillan. All rights reserved.
//

#ifndef __HW6__Thing__
#define __HW6__Thing__

#include <stdio.h>

#include <iostream>
#include <cmath>
#include <map>
#include <string>
#include <set>
using namespace std;

class Room;

class Thing
{
public:
    Thing(string _name, string _description, int _size);//creates thing w/set values
    virtual bool moveTo(Room * r);//moves thing to new room -------- virtual?? ------------
    string getName();//returns thing's name
    string getDesc();//returns thing's description
    int getSize();//returns thing's size
    Room * getCurrent();//returns current room
    void setCurrent(Room * r);//set current room
protected:
    Room * current;//where the thing is
private:
    string name;//thing's name
    string description;//thing's description
    int size;//thing's size
};

#endif /* defined(__HW6__Thing__) */
