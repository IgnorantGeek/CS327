#ifndef ITEM_H
 #define ITEM_H

#include "object.h"

/**Need to figure out this state thing
 * How will I create states? They will have to serve a specific purpose, like a boolean value,
 * or a keyID of some kind. Probably need a state class. Create states and give them a type. Have several
 * types to choose from and create constructors for each type of state.
 * */
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
        item() ;
        item(std::string &name, state_t *s) ; //constructor with a name and some state
};

#endif