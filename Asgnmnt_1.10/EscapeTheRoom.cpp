#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "EscapeTheRoom.h"

//devide up functions into the appropriate header files

int pickupItem(item_t *i)
{
    //object o = new object();
    return 0;
}

int useItem(item_t *i)
{
    return 0;
}

//might not be needed. Need to look at room creation
item_t newItem()
{
    //initialize a new item.
    item_t i;
    return i;
}

//might not be needed
container_t openContainer(container_t *c)
{
    //player gets prompted with what is in the container
    container_t d;
    return d;
}

container_t newContainer(char *name, item_t *i)
{
    //initialize a container with the given items inside.
    container_t c;
    return c;
}

int putItem(container_t *c, item_t *i)
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

void lookWall(wall_t *w)
{

}

//make rooms text files. Parse descriptions of rooms and add that to game. Just like dungeons and stuff. Fuck.
//hmmmmmmmmmmmmmmmmmmmmm ok