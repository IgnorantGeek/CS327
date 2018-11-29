#ifndef CONTAINER_H
 #define CONTAINER_H

#include "item.h"
#include <vector>
/**Class for objects that can hold by other objects. Cannot be picked up by player
 * BUG: Should we allow containers to be picked up? What would be the benefit of that?
 */

class container : public object
{
    public:
        container();
        ~container();
        container(char *n, char *d, object *obj){
            name = n;
            desc = d;
            contents.push_back(obj);
        };
        int add_item(object *obj){
            contents.push_back(obj);
            return 0;
        };
        int remove_item(int slot){
            contents.erase(contents.begin() + slot);
            return 0;
        };
    protected:
        std::vector <object*> contents;
        std::vector <action*> actions;
        int numobjects;
};

#endif