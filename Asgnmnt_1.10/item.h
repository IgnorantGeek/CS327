#ifndef ITEM_H
 #define ITEM_H

#include "object.h"

typedef struct state 
{
    int key;
}state_t;

class item : public object
{
    public:
        //item stuff
        state_t *states;
        int numStates;
};

#endif