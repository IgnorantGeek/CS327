#ifndef ITEM_H
 #define ITEM_H

#include "object.h"

/**Need to figure out this state thing
 * How will I create states? They will have to serve a specific purpose, like a boolean value,
 * or a keyID of some kind. Probably need a state class. Create states and give them a type. Have several
 * types to choose from and create constructors for each type of state.
 * 
 * When creating a new item, we want to create the 3 base actions, hold, use, drop
 * */

class item : public object
{
    protected:
        action *actions;
        int numActions;
    public:
        //item stuff
        item();
        item(char *n, char *d, action a) //constructor with a name and some state
        {
            name = n;
            desc = d;
            numActions = 1;
        };
};

#endif