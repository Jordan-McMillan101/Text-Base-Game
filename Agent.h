//
//  Agent.cpp
//  HW6
//
//  Created by Jordan Lance McMillan on 8/2/15.
//  Copyright (c) 2015 Jordan Lance McMillan. All rights reserved.
//

#include "Agent.h"

string Agent::getName() {
    return (name);
};

bool Agent::act(){
    return true;
}

Player::Player(string _playerName, Room* starting_room)
{
    name = _playerName;
    currRoom = starting_room;
}

bool Player::act(){
    string input;
    /*
    cout <<" you are in: " << endl;
    cout  <<currRoom->getName() <<" , " << currRoom->getDescription() <<endl;
    currRoom->printLinked();
    cout <<"where do  you want to go? " << endl;
    cin >> input;
    if(input == "quit"){
        cout << "you have stopped the game!";
        return false;
    }
    cout <<"you entered: " << input << endl;
    currRoom= currRoom->getLinked(input);
    
    return true;
    */
    cout <<"You are in the ";
    cout  <<currRoom->getName() <<", " << currRoom->getDescription() <<endl;
    currRoom->printThings();
    currRoom->printLinked();
    
    cout <<"Which direction would you like to go? (or type \"quit\" to stop): " << endl;
    cin >> input;
    if (input == "quit")
    {
        return false;
    }
    cout <<"you entered " << input << endl;
    
    //cout << "--------------------------------------------------------------"<< endl;
    
    //prevRoom = currRoom;
    currRoom= currRoom->getLinked(input);
    return true;

}

//-------------------------------[Grue class funcitons]----------------------------

Grue::Grue(string _name, Room* starting_room)
{
    name = _name;
    currRoom = starting_room;
}
bool Grue::act(){
    //cout << "--------------------------------------------------------------"<< endl;

    cout << "rawr im "<< getName()<< endl;
    //cout <<"The monster is in the "<< endl;
    //cout  <<currRoom->getName() <<endl;
    //string direction = "west";
    
    int n = rand() % 6;
    string direction;
    switch(n)
    {
        case 0: direction = "north"; break;
        case 1: direction = "south"; break;
        case 2: direction = "west"; break;
        case 3: direction = "east"; break;
        case 4: direction = "up";   break;
        case 5: direction = "down"; break;
    }
    
    if(currRoom->getLinked(direction) != NULL)
    {
        currRoom = currRoom->getLinked(direction);
        cout << "the monster moved to the " << currRoom->getName()<< endl;
    }
    
    //currRoom = currRoom->getLinked(direction);
    //cout << "--------------------------------------------------------------"<< endl;

    return true;
}
