#include "object.h"

object::object(std::string &name, std::string &desc) :
    name(name),desc(desc)
{
    
}

const char *get_name()
{
    return name.c_str();
}