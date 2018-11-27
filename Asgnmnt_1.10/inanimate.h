#ifndef INANIMATE_H
 #define INANIMATE_H

#include "object.h"
#include <iostream>

class inanimate : public object
{
    public:
        std::string &content; //contains what is on the poster/picture/etc.

};

#endif