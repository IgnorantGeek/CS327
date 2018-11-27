#ifndef OBJECT_H
 #define OBJECT_H

 #include <string>

//base class for items, animates, inanimates, and containers
class object
{
    public:
        std::string &name;
        std::string &desc; //text to display when interacting with item?? (think about what you would need to display for any given object)
        //what else can I generalize and put here?
};

#endif