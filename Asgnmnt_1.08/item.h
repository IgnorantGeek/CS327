#ifndef ITEM_H
#define ITEM_H
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include "dims.h"
#include "dice.h"
#include "object_type.h"

#define DUNGEON_X   80
#define DUNGEON_Y   21

class item
{
	public:
		std::string name, description;
		object_type_t type;
		uint32_t color;
		int hit, dodge, defense, weight, speed, attribute, value;
		dice damage;
		bool artifact;
		uint32_t rarity;
		pair_t position;
		std::string getName() {return name;}
		char get_symbol(object_type obj);
};

void randomize_pos(item *i);
#endif
