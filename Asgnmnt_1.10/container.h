#ifndef CONTAINER_H
 #define CONTAINER_H

#include "item.h"

class container : public object
{
    public:
        item *items;
        container();
};

#endif