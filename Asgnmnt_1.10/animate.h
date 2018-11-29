#ifndef ANIMATE_H
 #define ANIMATE_H

#include "item.h"

/** Class for objects that can be interacted with (have actions) but cannot be picked up by the player
 */

class animate : public object
{
    protected:
        std::vector<action *> actions;
    public: 
        int num_actions() {return actions.size();}
        int new_action(action *a){
            actions.push_back(a);
            return 0;
        }
        int remove_action(int slot){
            actions.erase(actions.begin() + slot);
            return 0;
        }
        //TODO: check that this is the proper way to remove stuff.
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

#endif