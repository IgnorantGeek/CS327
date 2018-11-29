#ifndef OBJECT_H
 #define OBJECT_H

#include <stdio.h>
#include <string.h>
#include <iostream>
#include "action.h"

//base class for items, animates, inanimates, and containers
class object
{
    protected:
        char *name;
        char *desc; //text to display when interacting with item?? (think about what you would need to display for any given object)
        //what else can I generalize and put here?
    public:
        object();
        object(char *n, char *d)
        {
            name = (char *) malloc(sizeof(n));
            strcpy(name,n);
            desc = (char *) malloc(sizeof(d));
            strcpy(desc,d);
        }
        char * get_name() {return name;}
        char * get_desc() {return desc;}
        size_t sz_name() {return sizeof(name);}
        size_t sz_desc() {return sizeof(desc);}
        ~object();
};

#endif