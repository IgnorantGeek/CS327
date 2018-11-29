#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "Game.h"
#include "wall.h"

//devide up functions into the appropriate header files

int pickupItem(item *i)
{
    //object o = new object();
    return 0;
}

int useItem(item *i)
{
    return 0;
}

int putItem(container *c, item *i)
{
    //put the item in the container
    return 0;
}

int guessDoorway(char *s)
{
    //the player attempts to guess the password of the current room door
    return 0;
}

void readInput()
{
    //reads the input file and constructs rooms
}

void lookWall(wall *w)
{

}

//make rooms text files. Parse descriptions of rooms and add that to game. Just like dungeons and stuff. Fuck.
//hmmmmmmmmmmmmmmmmmmmmm ok

int newRoom(game_t *g)
{
    room a;
    g->rooms.push_back(&a);
    return 0;
}