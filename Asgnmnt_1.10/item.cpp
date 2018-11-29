#include "item.h"

//Might want to store a pointer to some item in the aciton
//store actions in some sort of array. Will have to have some way to 
//associate actions with the correct item. To differentiate them from other actions

char * actions2str(item *i)
{
    char *string = (char*) malloc(i->sz_name());
    //convert the item information into a string for printing or whatever
    strcpy(string,i->get_name());
    return string;
}