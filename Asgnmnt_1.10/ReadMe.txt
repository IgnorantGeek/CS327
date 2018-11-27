This is a C/C++ framework for creating custom text-based adventure/puzzle games. Need to think about generalizing commands for creating several
types of adventure games. Maybe have code for characters and NPCs. Add features by necessity. Initial usability will be focused on creating games
in the style of "escape the whatever"

Goal: We have a base case object. Each object has a name and description. Sub-classes of objects are items, animates, inanimates, containers, 
and walls which are just another type of container. I want each type to have a base set of actions that can be performed on it, with the 
ability of adding custom actions for any given object type. 

Intangible environments (Game, rooms) cannot be changed by player (abstract)
Objects (walls, containers, items) can be changed or modified by player 
Actions (place, take, unlock) can be performed by the player on objects
    need to be definable, if a specific game calls for a multifunctional object, I want there to be a way
    to make custom actions for said object.