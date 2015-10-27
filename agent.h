//
//  Agent.h
//  HW6
//
//  Created by Jordan Lance McMillan on 8/2/15.
//  Copyright (c) 2015 Jordan Lance McMillan. All rights reserved.
//

#ifndef __HW6__Agent__
#define __HW6__Agent__

#include <iostream>
#include <stdio.h>
#include <vector>
#include "Room.h"
#include "Thing.h"

using namespace std;

//class Room;
//class Thing;

class Agent
{
protected:
    Room* currRoom;
    string name;
    
public:
    virtual bool act() = 0;
    string getName();// {return name;}
};

class Player : public Agent
{
public:
    Player(string _playerName, Room* starting_room);
    bool act();
};

class Grue : public Agent
{
public:
    Grue(string _name, Room* starting_room);
    bool act();
    
};



#endif /* defined(__HW6__Agent__) */
