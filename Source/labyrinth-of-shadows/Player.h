// Date: ??
// Auth: Christian Baack
// Desc: Class to represent the player in the game for movement and position.
#pragma once
#include "All_Includes.h"
#include "Map.h"

class Player
{
private:
    Map& map;
    int x, y; //Player's position
    int px, py; //Proposed position. Checking for walls

public:
    Player(Map& map, int initialX, int initialY) : map(map), x(initialX), y(initialY), px(initialX), py(initialY) {}

    void handleInput()
    {
        char input;
        cout << "Enter move (WASD): ";
        input = _getch();

        switch (input) {
        case 'W': case 'w':
            move(0, -1);
            break;
        case 'S': case 's':
            move(0, 1);
            break;
        case 'A': case 'a':
            move(-1, 0);
            break;
        case 'D': case 'd':
            move(1, 0);
            break;
            //Add more controls as needed
        //JPO: Add a default case to handle invalid input.
        }
    }

    //This will check if the proposed position is valid
    void move(int dx, int dy)
    {
        px += dx;
        py += dy;

        if (map.getGrid()[py][px] == 'A')
        {
            map.setLevel(map.getLevel() - 1);
            px = x = 25; // JPO: These assignments don't modify the "p" variables at all, so I changed to double assignment.
            py = y = 15;


        }
        if (map.getGrid()[py][px] == 'D')
        {
            map.setLevel(map.getLevel() + 1);
            px = x = 25;
            py = y = 15;
        }
        else if (map.getGrid()[py][px] != '#')
        {
            x += dx;
            y += dy;
        }

        px = x;
        py = y;

        cout << "X: " << x << "  Y: " << y;
    }

    void getPosition(int& outX, int& outY) const
    {
        outX = x;
        outY = y;
    }
};