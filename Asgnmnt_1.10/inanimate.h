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
        inanimate(char *m){message = m;} //make sure this is the right way to set the message. 
        //can we just change what the pointer points to?
        ~inanimate();
};

#endif