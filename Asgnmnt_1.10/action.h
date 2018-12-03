#ifndef ACTION_H
 #define ACTION_H

 #include "data/data.h"
 #include "data/key_d.h"
 #include "data/bool_d.h"
 #include "object.h"
 
/* Holder class for actions
* Actions are inputs by the player. All actions (except for quit) are associated with an object. Every object (excluding inanimates) will have 
* at least one action with it. The trouble is dynamically being able to support new actions. Actions get tied to objects as specified by the developer
* need to add way to create some action, link it to an object, and make sure all functionality will work between the two. Probably a lookup table? 
*/
class action
{
    public:
        action();
        ~action();
        action(object *ref, data *d, char *k){
            reference = ref;
            data = d;
            keyword = k;
        };
        action(object *ref, int n, char *k){
            reference = ref;
            key_d key = key_d(n);
            keyword = k;
            data = &key;
        };
        action(object *ref, bool b, char *k){
            reference = ref;
            bool_d f = bool_d(b);
            data = &f;
            keyword = k;
        };
    protected:
        data *data; //stores whatever data is needed for action parameters. Such as the state of a light or an ID for a key
        char *keyword;
        object *reference;
};


int do_action(action *a);

//How can we make dependancies work?
/**Dependancies
 * */
#endif