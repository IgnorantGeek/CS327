#ifndef BOOL_D_H
 #define BOOL_D_H

#include "data.h"
class bool_d : public data
{
    protected:
        bool state;
    public:
        bool_d(bool b)
        {
            state = b;
        }
        bool_d();
        ~bool_d();
        bool get_state() {return state;}
        int setFalse(){
            state = false;
            return 0;
        };
        int setTrue(){
            state = true;
            return 0;
        };
        
};
#endif