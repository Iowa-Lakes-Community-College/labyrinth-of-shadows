//Auth: Will Brickner
//Date: 11/30/2023
//Desc: Creating a superclass for the player, npcs, and enemies
#pragma once
#include <iostream>
#include <string>
#include "Utility.h"
using namespace std;

class Character
{
private:
    //Fields
    int health;
    string name;

public:

    // JPO: add constructor

    //Setters
    void setHealth(int value)
    {
        health = value;
    }

    void setName(string n)
    {
        name = n;
    }

    //Getters
    int getHealth() const
    {
        return health;
    }

    string getName() const
    {
        return name;
    }
};