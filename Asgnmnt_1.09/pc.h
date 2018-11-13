#ifndef PC_H
# define PC_H

# include <stdint.h>

# include "dims.h"
# include "character.h"
# include "dungeon.h"

class pc : public character
{
 public:
  ~pc() {}
  terrain_type known_terrain[DUNGEON_Y][DUNGEON_X];
  uint8_t visible[DUNGEON_Y][DUNGEON_X];
	object *equipment[12]; //equipment slots, array should be 12 long
	/* equipment slots should have specific slots for each type
	 * ie it has 1 WEAPON slot, 1 OFFHAND, 2 RING, 1 RANGED, etc.
   * so when adding to equipment, check the type of the object, if the type
   * matches an open slot, fill it, if not, need to figure out what to do
   * probaby just add to carry or prompt a "swap" command I suppose
	 */
	object *carry[10]; //carry slots, array should be 10 long
	char eslots[13] = "abcdefghijkl"; //'marker' array for equipment slots
	//get the correct object in equipment by matching players input letter to the array position from this array
};

void pc_delete(pc *pc);
uint32_t pc_is_alive(dungeon *d);
void config_pc(dungeon *d);
uint32_t pc_next_pos(dungeon *d, pair_t dir);
void place_pc(dungeon *d);
uint32_t pc_in_room(dungeon *d, uint32_t room);
void pc_learn_terrain(pc *p, pair_t pos, terrain_type ter);
terrain_type pc_learned_terrain(pc *p, int16_t y, int16_t x);
void pc_init_known_terrain(pc *p);
void pc_observe_terrain(pc *p, dungeon *d);
int32_t is_illuminated(pc *p, int16_t y, int16_t x);
void pc_reset_visibility(pc *p);
int32_t wear_object(pc *p, int carryslot); //returns 0 if pickup successful, 1 otherwise
int32_t takeoff_object(pc *p, int equipslot); //returns 0 if pickup successful, 1 otherwise
#endif
