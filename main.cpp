//
//  main.cpp
//  HW6
//
//  Created by Jordan Lance McMillan on 8/1/15.
//  Copyright (c) 2015 Jordan Lance McMillan. All rights reserved.
//

#include <iostream>

#include "Room.h"
#include "Thing.h"
#include "Agent.h"

int main() {
    
    srand(time(NULL));
    
    Room* entrance = new Room("ENTRANCE", "a wide open entrance to a house.", 100);
    Room* hallway = new Room("HALLWAY", "a long Hallway.", 55);
    Room* kitchen = new Room("KITCHEN", "the cook's Kitchen.", 150);
    Room* stairs = new Room("STAIRS", "a staircase", 50);
    Room* basement = new Room("BASEMENT", "a creepy basement", 160);
    
    //exit for the entrance
    entrance->link("south",hallway);
    
    //exits for the hallway
    hallway->link("north",entrance);
    hallway->link("east",kitchen);
    hallway->link("down",stairs);
    
    //exit for the stairs
    stairs->link("up",hallway);
    stairs->link("down",basement);
    
    //exit for the kitchen
    kitchen->link("west",hallway);
    
    //exit for the basement
    basement->link("up", stairs);
    
    //setting the key for the basement in the kitchen
    Thing *key = new Thing ("key", "can be used to unlock a locked door", 1);
    key->moveTo(hallway);
    //kitchen->printThings();
    //cout << endl;
    //basement->printThings();
    
    //setting a Thing called knife in the kitchen
    Thing *knife = new Thing ("knife", " can be used to cut things", 2);
    knife->moveTo(kitchen);
    
    // lock the basement
    basement->locked(1);
    //basement->checkLock();
    
    //Room* currRoom = entrance;
    
    // set up player(s) and monster(s)
    Grue* monster1 = new Grue("monster1", kitchen);
    Grue* monster2 = new Grue("monster2", hallway);
    Player* player1 = new Player("Jordan", entrance);
    
    // add player and monster to vector
    vector<Agent*> agents;
    agents.push_back(player1);
    agents.push_back(monster1);
    agents.push_back(monster2);

    cout << "Welcome!" << endl;
    cout << "-----------------------------------------------------------------------------------"<< endl;
    while(true)
    {
        for(int i = 0; i < agents.size(); i++)
        {
            
            bool ok = agents[i]->act();
            cout << "------------------------------------------------------------------------------------"<< endl;

            if(!ok)
            {
                cout << "Game quits." << endl;
                return 0;
            }
        }
    }

    /*
    
    cout << "Welcome!" << endl;
    cout << "--------------------------------------------------------------"<< endl;
    Room* currRoom = entrance;
    Room* prevRoom = entrance;
    string input;
    bool play = true;
    while (play) {
        cout <<"You are in the ";
        cout  <<currRoom->getName() <<", " << currRoom->getDescription() <<endl;
        currRoom->printThings();
        currRoom->printLinked();
        
        cout <<"Which direction would you like to go? " << endl;
        cin >> input;
        cout <<"you entered " << input << endl;
        
        cout << "--------------------------------------------------------------"<< endl;

        prevRoom = currRoom;
        currRoom= currRoom->getLinked(input);
        
    }
    */
    return 0;
}
