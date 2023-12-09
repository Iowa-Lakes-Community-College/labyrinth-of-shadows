//Auth: Hunter Kauffman
//Date: 12/5/23
//Desc: Creating the subclass placeholder for the player.
#pragma once
#include "Character.h"
#include <conio.h> // This allows us to use _getch() which will automatically continue after the user enters a single character.

class placeholder : private Character
{
private:
    int maxHealth;
    int strength;
    int intelligence;
    int dexterity;
    int healthPotions;
    int level;
    int exp;
    int expNeeded;

    int placeThing;
    int numberTurns;

    bool isBlocking;
    bool isStunned;
    bool isEnemyStunned;
public:
    placeholder(int max, int hea, int  str, int intel, int  dex, int lev, int ex, int need, int potion, int turns)
    {
        maxHealth = max;
        //This is a placeholder because the playername
        setName("Rogue");
        setHealth(hea);
        strength = str;
        intelligence = intel;
        dexterity = dex;
        level = lev;
        numberTurns = turns;
        healthPotions = potion;
        exp = ex;
        expNeeded = need;

        
        // Since this an combat ability it will only be able to activated during combat so it starts off false

        isBlocking = false;
        isStunned = false;
        isEnemyStunned = false;

    }

    //Setters
    void setMaxHealth(int value)
    {
        maxHealth = value;
    }

    void setStrength(int value)
    {
        strength = value;
    }

    void setIntelligence(int value)
    {
        intelligence = value;
    }

    void setDexterity(int value)
    {
        dexterity = value;
    }

    void setLevel(int value)
    {
        level = value;
    }

    void setNumTurns(int value)
    {
        numberTurns = value;
    }

    void setHealthPotions(int value)
    {
        healthPotions = value;
    }

    void setExp(int value)
    {
        exp = value;
    }

    void setExpNeeded(int value)
    {
        expNeeded = value;
    }


    // Getters
    int getMaxHealth() const
    {
        return maxHealth;
    }

    int getStrength() const
    {
        return strength;
    }

    int getIntelligence() const
    {
        return intelligence;
    }

    int getDexterity() const
    {
        return dexterity;
    }

    int getLevel() const
    {
        return level;
    }

    int getNumTurns() const
    {
        return numberTurns;
    }

    int getHealthPotions() const
    {
        return healthPotions;
    }

    int getExp() const
    {
        return exp;
    }

    int getExpNeeded() const
    {
        return expNeeded;
    }



    // Leveling up the player
    void levelUp()
    {
        cout << "Congratulations you leveled up!";
        // Increasing the players max health and healing them to full.
        maxHealth += 5;
        setHealth(maxHealth);
        dexterity += 1;
        level += 1;
        if (level % 5 == 0) {
            // Increment the number of turns when the player's level is a multiple of 5
            numberTurns++;
            cout << "Congratulations! Your number of turns has increased to: " << numberTurns << endl;
        }

        expNeeded = level * 5;
        exp = expNeeded - exp;

        int choice;

        // Displaying the level up message
        cout << "What Spell would you like to level up\n"
            << "Rain of Arrows per level will do an additional 5 damage. Starts with doing 10 damage.\n"
            << "Charged Shot for the first unlock will allow the Ranger to stun their enemy for a turn.  \n"
            << "Then every upgrade after that increases the number of turns per stun. Then the cooldown will increase a turn by one as well.\n"
            << "Repulsion will reflect the next damage that is taken back at the opponent base can only be used once per a fight.\n"
            << "But every level after number one you can use it an additional time per combat\n"
            << "1. Rain of Arrows " << "placeholder" << endl
            << "2. Charged Shot " << "placeholder" << endl
            << "3. Repulsion " << "placeholder" << endl << endl << endl;

        do {
            cout << "Enter your choice: ";
            // Here is the use of getch.
            choice = _getch();
            if (choice < 0 || choice > 3) {
                cout << "Incorrect value. Please enter a valid value.\n";
            }
        } while (choice < 0 || choice > 3);

        switch (choice)
        {
        case 1:
        {
            placeThing += 1;
            cout << "Rain of Arrows is now level " << "placeholder" << endl;
            break;
        }
        case 2:
        {
            placeThing += 1;
            cout << "Charged Shot is now level " << "placeholder" << endl;
            break;
        }
        case 3:
        {
            placeThing += 1;
            cout << "Repulsion is now level " << "placeholder" << endl;
            break;
        }
        // JPO: this should have a default, even if it is never used.
        }
        //Seeing if they enough exp for a second level up.
        //This will go to the utility class to check.
        //checkForLevelUp();
    }
};