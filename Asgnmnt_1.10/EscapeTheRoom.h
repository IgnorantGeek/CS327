#ifndef ESCAPETHEROOM_H
 #define ESCAPETHEROOM_H

#include "item.h"

//needs to be some stort of way to generalize what is stored in the item class
//some things may need other items to work, some may work only in a certain way.
//some items may have multiple uses. Just need to think about how they will be used and
//taylor that to my game.

class player
{
    public:
        int inventorySize; //should there be a limit to inventory size?
        item *inventory;
        int roomNum;
};

typedef struct wall
{
    //have things on them like windows or posters
    //wall can have animate object, inanimate, or container/items
    //rooms have walls, walls have objects. Need to classify objects and do inheritance
    object obj1;
    object obj2;
    object obj3;
    object obj4;
    //walls can hold 4 objects
} wall_t;

typedef struct room
{
    wall_t north;
    wall_t south;
    wall_t east;
    wall_t west;
    wall_t ceiling;
    wall_t floor;
} room_t;

typedef struct game 
{
    room_t *rooms;
    player pc;
} game_t;

#endif