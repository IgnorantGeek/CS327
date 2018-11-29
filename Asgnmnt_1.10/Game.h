#ifndef GAME_H
 #define GAME_H

#include "wall.h"

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

//room environment
typedef struct room
{
    wall north;
    wall south;
    wall east;
    wall west;
    wall ceiling;
    wall fl;
} room_t;

//game environment
typedef struct game 
{
    //player, room content, stats, scores, stuff like that 
    std::vector<room_t*> rooms;
    player pc;
    item *items; //?
} game_t;

int initGame(game_t *g);
int newRoom(game_t *g); //initialize walls
int deleteGame(game_t *g); //clear everything and free all memory

#endif