#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "EscapeTheRoom.h"

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

//might not be needed. Need to look at room creation
item newItem()
{
    //initialize a new item.
    item i;
    return i;
}

//might not be needed
container openContainer(container *c)
{
    //player gets prompted with what is in the container
    container d;
    return d;
}

container newContainer(char *name, item *i)
{
    //initialize a container with the given items inside.
    container c;    
    return c;
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

void lookWall(wall_t *w)
{

}

//make rooms text files. Parse descriptions of rooms and add that to game. Just like dungeons and stuff. Fuck.
//hmmmmmmmmmmmmmmmmmmmmm ok