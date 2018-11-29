#ifndef INANIMATE_H
 #define INANIMATE_H

#include "object.h"
/**Class for objects that cannot be interacted with and cannot be picked up by the player
 */
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