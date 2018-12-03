#ifndef KEY_D_H
 #define KEY_D_H

#include "data.h"
#include <rand.h>
#include <cstdlib>

class key_d : public data
{
    protected:
        int key;
    public:
        key_d(){
            key = rand();
        };
        key_d(int n){
            key  = n;
        };
        ~key_d();
        int getVal() {return key;}
        
};

#endif