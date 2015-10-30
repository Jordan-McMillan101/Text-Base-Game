//
//  Thing.cpp
//  HW6
//
//  Created by Jordan Lance McMillan on 8/1/15.
//  Copyright (c) 2015 Jordan Lance McMillan. All rights reserved.
//

#include "Thing.h"
#include "Room.h"


Thing::Thing(string _name, string _description, int _size)
{
    name = _name;
    description = _description;
    size = _size;
}

//moves thing to new room
bool Thing::moveTo(Room * r)
{
    
    //if thing can be added to new room
    if (r->add(this))
    {
        if(current!=NULL)
        {
            current->remove(this);
        }
        current = r;
        //cout<<"moved"<<endl;
        return (true);
    }
    
    return (false);
}

string Thing::getName()//returns thing's name
{
    
    return (name);
}

string Thing::getDesc()//returns thing's description
{
    
    return (description);
}

int Thing::getSize()//returns thing's size
{
    
    return (size);
}

//returns current room of thing
Room * Thing::getCurrent()
{
    
    return (current);
}

//set current room
void Thing::setCurrent(Room * r)
{
    
    current = r;
}
