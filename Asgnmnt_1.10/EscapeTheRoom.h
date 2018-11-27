#ifndef ESCAPETHEROOM_H
 #define ESCAPETHEROOM_H

//needs to be some stort of way to generalize what is stored in the item class
//some things may need other items to work, some may work only in a certain way.
//some items may have multiple uses. Just need to think about how they will be used and
//taylor that to my game.

typedef struct state 
{
    int key;
}state_t;

typedef struct item 
{
    char *name;
    int numstates;
    state_t *states;
} item_t;

typedef struct animate
{
    //something you can interact with but not pickup
} animate_t;

typedef struct inanimate
{
    //something you can look at but not move or touch
} inanimate_t;

typedef struct player
{
    int inventorySize;
    item_t *inventory;
} player_t;

typedef struct container
{
    item_t *inventory;
    char *Description;
} container_t;

typedef struct wall
{
    //have things on them like windows or posters
} wall_t;

typedef struct room
{

} room_t;

typedef struct game 
{
    container_t *cont;
    item_t *item;
    player_t *PC;
} game_t;

#endif