#ifndef WALL_H
 #define WALL_H

#include "container.h"

class wall : public container
{
    public:
        wall(); //default constructor is spitting out a compile error
        ~wall();
        wall(char *n, char *d){
            name = n;
            desc = d;
        }
};

int add_object(wall *w, object *obj);
#endif