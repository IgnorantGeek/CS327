#ifndef ACTIONS_H
 #define ACTIONS_H
 
/* Holder class for actions
* Actions are inputs by the player. All actions (except for quit) are associated with an object. Every object (excluding inanimates) will have 
* at least one action with it. The trouble is dynamically being able to support new actions. Actions get tied to objects as specified by the developer
* need to add way to create some action, link it to an object, and make sure all functionality will work between the two. Probably a lookup table? 
*/
class action
{
    public:

    private:
};

#endif