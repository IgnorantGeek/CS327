#ifndef ITEM_H
 #define ITEM_H

#include "object.h"

#include <vector>

/**Need to figure out this state thing
 * How will I create states? They will have to serve a specific purpose, like a boolean value,
 * or a keyID of some kind. Probably need a state class. Create states and give them a type. Have several
 * types to choose from and create constructors for each type of state.
 * 
 * When creating a new item, we want to create the 3 base actions, hold, use, drop
 * */

//TODO :: Test the constructor with the action
class item : public object
{
    protected:
        std::vector<action*> actions;
    public:
        //item stuff
        item();
        item(char *n, char *d, action *a) //constructor with a name and some state
        {
            name = n;
            desc = d;
            //need to malloc actions
            actions.push_back(a); //is this the correct way to store an action?
            
        };
        size_t sz_name() {return sizeof(name);}
        int num_actions() {return actions.size();}
        int new_action(action *a){
            actions.push_back(a);
            return 0;
        }
        int clear_actions(){
            for (action* a : actions)
            {
                delete a;
                free(a);
            }
            actions.clear();
            return 0;
        };
};

 char * actions2str(item *i); //return item as string
#endif