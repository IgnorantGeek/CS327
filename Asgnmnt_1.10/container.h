#ifndef CONTAINER_H
 #define CONTAINER_H

#include "item.h"
#include <vector>

class container : public object
{
    public:
        container();
        ~container();
        container(object *obj);
        int add_item(object *obj);
        int remove_item(int slot);
    protected:
        std::vector <object> contents;
        int numobjects;
};

#endif