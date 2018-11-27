#ifndef WALL_H
 #define WALL_H

#include "object.h"

class wall : public object
{
    private:
        object obj1;
        object obj2;
        object obj3;
        object obj4;
        object obj5;
    public:
        wall() ;
        wall(object *obj1, object *obj2, object *obj3, object *obj4, object *obj5); 
};

#endif