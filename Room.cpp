//
//  Room.cpp
//  HW6
//
//  Created by Jordan Lance McMillan on 8/1/15.
//  Copyright (c) 2015 Jordan Lance McMillan. All rights reserved.
//

#include "Room.h"
#include "Agent.h"
#include <iostream>
using namespace std;


//constructs a room to parameters
Room::Room(string _name, string _description, int _size)
{
    name = _name;
    description = _description;
    size = _size;
}
//returns the name of the room
string Room::getName()
{
    return(name);
}
//returns the description of the room
string Room::getDescription()
{
    return(description);
}

//links an exit to a room
void Room::link(string direction, Room * r)
{
    //sets link between exit and room pointer
    exits[direction] = r;
}

//returns the pointer (used to switch rooms)
Room * Room::getLinked(string direction)
{
    auto it = exits.find(direction);
    
    
    
    if (it  == exits.end()) return this;
    
    
    
    return(it->second);
}

//prints all rooms linked to current room
void Room::printLinked()
{
    //iterates through all linked rooms
    map<string, Room*>::iterator it;
    
    int n = exits.size();//counts number of exits
    
    int i (0);//index of exits
    
    cout<<"There is an exit to the ";
    
    for (it = exits.begin(); it!= exits.end(); ++it)
    {
        //print out the direction and where it leads
        cout<<it->first<<" which leads to the " <<it->second->name;
        i++;
        //print something between list items
        if (i<(n))
        {
            //if more than 2 exits, use commas between exits
            if ((n > 2) && (i < (n-1)))
            {
                cout<<", ";
            }
            //if n = 2, then ignore the comma
            else
            {
                cout<<" and ";
            }
        }
    }
    //print a period at the end of the list
    cout<<"."<<endl;
}

//returns size of room
int Room::getSize()
{
    
    return(size);
}

//-------------------[Functions used in Thing]-------------------------------------------------------

//adds thing to room
bool Room::add(Thing * thing)
{
    //tries adding to the room
    things.insert(thing);
    return(true);
}

//removes thing from room
void Room::remove(Thing * thing)
{
    
    things.erase(thing);
}

//returns list of things
set <Thing*> Room::getThings()
{
    return(things);
}


//prints all items but specified ignored thing
void Room::printThings()
{
    int i(0);//index for things
    int n = things.size();//number of objects in room
    cout<<"In the room you find";
    
    set<Thing*>::iterator it;//iterator for list of things
    for (it = things.begin(); it!= things.end(); ++it)
    {
        //print the object and what it does
        cout<<" a "<<(*it)->getName()<<" which "<<(*it)->getDesc();
        i++;
        
        //print something between list items
        if (i<(n))
        {
            //if more than 2 exits, use commas between exits
            if (n > 2)
            {
                cout<<", ";
            }
            //if n = 2, then ignore the comma
            else
            {
                cout<<" and";
            }
        }
    }
    if (i==0)
    {
        cout<<" nothing you can take with you";
    }
    
    //period at the end of the list
    cout<<"."<<endl;
}

//locks or unlocks room
void Room::locked(int a)
{
    if (a)
    {
        lock = true;
    }
    else
    {
        lock = false;
    }
}

//checks the lock
bool Room::checkLock()
{
    return(lock);
}
//-------------------[Functions used is Agent]------------------------------------------------------

//returns occupants list
set <Agent*> Room::peeps(){
    return(occupants);
}
//returns list of exits
map <string,Room *> Room::getExits()
{
    
    return(exits);
}
