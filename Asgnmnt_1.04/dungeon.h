#ifndef DUNGEON_H
# define DUNGEON_H

# include "heap.h"
# include "macros.h"
# include "dims.h"

#define DUNGEON_X              80
#define DUNGEON_Y              21
#define MIN_ROOMS              5
#define MAX_ROOMS              9
#define ROOM_MIN_X             4
#define ROOM_MIN_Y             2
#define ROOM_MAX_X             14
#define ROOM_MAX_Y             8
#define SAVE_DIR               ".rlg327"
#define DUNGEON_SAVE_FILE      "dungeon"
#define DUNGEON_SAVE_SEMANTIC  "RLG327-F2018"
#define DUNGEON_SAVE_VERSION   0U

#define mappair(pair) (d->map[pair[dim_y]][pair[dim_x]])
#define mapxy(x, y) (d->map[y][x])
#define hardnesspair(pair) (d->hardness[pair[dim_y]][pair[dim_x]])
#define hardnessxy(x, y) (d->hardness[y][x])

typedef struct character char_t;
typedef enum __attribute__ ((__packed__)) terrain_type 
{
  ter_debug,
  ter_wall,
  ter_wall_immutable,
  ter_floor,
  ter_floor_room,
  ter_floor_hall,
} terrain_type_t;

typedef struct room 
{
  pair_t position;
  pair_t size;
} room_t;

typedef struct event
{
  time_t time;
  //pq node
  char_t *character;
  int turn;
} event_t;

struct character
{
  int speed;
  pair_t position;
  pair_t Intel; //stores previous known PC pos if monster is intelligent
  char type; //stores monster type
} ;

typedef struct dungeon 
{
  uint32_t num_rooms;
  int num_mon;
  room_t *rooms;
  char_t *monsters; //array of monsters
  terrain_type_t map[DUNGEON_Y][DUNGEON_X];
  /* Since hardness is usually not used, it would be expensive to pull it *
   * into cache every time we need a map cell, so we store it in a        *
   * parallel array, rather than using a structure to represent the       *
   * cells.  We may want a cell structure later, but from a performanace  *
   * perspective, it would be a bad idea to ever have the map be part of  *
   * that structure.  Pathfinding will require efficient use of the map,  *
   * and pulling in unnecessary data with each map cell would add a lot   *
   * of overhead to the memory system.                                    */
  uint8_t hardness[DUNGEON_Y][DUNGEON_X];
  uint8_t pc_distance[DUNGEON_Y][DUNGEON_X];
  uint8_t pc_tunnel[DUNGEON_Y][DUNGEON_X];
  char_t pc;
} dungeon_t;

void process_move(dungeon_t *d, char_t *character); 
int position_comp(pair_t pos1, pair_t pos2);
void init_dungeon(dungeon_t *d);
void delete_dungeon(dungeon_t *d);
int gen_dungeon(dungeon_t *d);
int get_room(dungeon_t *d, pair_t pos);
void gen_monsters(dungeon_t *d, int num_mon);
void render_dungeon(dungeon_t *d);
int write_dungeon(dungeon_t *d, char *file);
int read_dungeon(dungeon_t *d, char *file);
int read_pgm(dungeon_t *d, char *pgm);
void render_distance_map(dungeon_t *d);
void render_tunnel_distance_map(dungeon_t *d);
void render_hardness_map(dungeon_t *d);
void render_movement_cost_map(dungeon_t *d);

#endif
