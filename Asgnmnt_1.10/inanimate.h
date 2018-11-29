#ifndef INANIMATE_H
 #define INANIMATE_H

#include "object.h"
#include <iostream>

class inanimate : public object
{
    protected:
        char *message; //contains what is on the poster/picture/etc.
    public:
        inanimate();
        inanimate(char *n, char *d, char *m){
            message = m;
            name = n;
            desc = d;
        }
        ~inanimate();
};

int update_message(inanimate *i, char *m);
#endif