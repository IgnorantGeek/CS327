#ifndef CONTAINER_H
 #define CONTAINER_H

#include "item.h"
#include <vector>

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
        int numobjects;
};

#endif