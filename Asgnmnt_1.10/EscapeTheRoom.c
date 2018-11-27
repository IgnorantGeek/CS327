#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "EscapeTheRoom.h"

int pickupItem(item_t *i)
{
    return 0;
}

int useItem(item_t *i)
{
    return 0;
}

int openContainer(container_t *c)
{
    //player gets prompted with what is in the container
    return 0;
}

container_t newContainer(char *name, item_t *i)
{
    //initialize a container.
    return NULL;
}

int putItem(container_t *c, item_t *i)
{
    //put the item in the container
    return 0;
}

int guessDoorway()
{
    
    return 0;
}

void readInput()
{

}

void lookWall(wall_t *w)
{

}

//make rooms text files. Parse descriptions of rooms and add that to game. Just like dungeons and stuff. Fuck.
//hmmmmmmmmmmmmmmmmmmmmm ok