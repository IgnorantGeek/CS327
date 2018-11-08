#include "item.h"
#include "utils.h"

//randomizes the position of the given item
//broken: need to only place items in rooms or corridors (maybe)
void randomize_pos(item *i)
{
	pair_t pos;
	pos[dim_y] = rand_range(0, DUNGEON_Y - 1);
	pos[dim_x] = rand_range(0, DUNGEON_X - 1);
	memcpy(i->position, pos, sizeof(pair_t));
}
