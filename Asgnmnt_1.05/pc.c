#include <stdlib.h>
#include <curses.h>

#include "string.h"

#include "dungeon.h"
#include "pc.h"
#include "utils.h"
#include "move.h"
#include "path.h"

void pc_delete(pc_t *pc)
{
  if (pc) {
    free(pc);
  }
}

uint32_t pc_is_alive(dungeon_t *d)
{
  return d->pc.alive;
}

void place_pc(dungeon_t *d)
{
  d->pc.position[dim_y] = rand_range(d->rooms->position[dim_y],
                                     (d->rooms->position[dim_y] +
                                      d->rooms->size[dim_y] - 1));
  d->pc.position[dim_x] = rand_range(d->rooms->position[dim_x],
                                     (d->rooms->position[dim_x] +
                                      d->rooms->size[dim_x] - 1));
}

void config_pc(dungeon_t *d)
{
  memset(&d->pc, 0, sizeof (d->pc));
  d->pc.symbol = '@';

  place_pc(d);

  d->pc.speed = PC_SPEED;
  d->pc.alive = 1;
  d->pc.sequence_number = 0;
  d->pc.pc = calloc(1, sizeof (*d->pc.pc));
  d->pc.npc = NULL;
  d->pc.kills[kill_direct] = d->pc.kills[kill_avenged] = 0;

  d->character[d->pc.position[dim_y]][d->pc.position[dim_x]] = &d->pc;

  dijkstra(d);
  dijkstra_tunnel(d);
}


//pass in dir as the delta for the next pc move, use this code to calculate if that is valid
//move_character initiates the move
uint32_t pc_next_pos(dungeon_t *d, pair_t dir)
{
  dungeon_t new;
  //static uint32_t have_seen_corner = 0;
  static uint32_t count = 0;

  dir[dim_x] = dir[dim_y] = 0;
  if (in_corner(d, &d->pc)) 
  {
    if (!count) 
    {
      count = 1;
    }
    //have_seen_corner = 1;
  }
  //add code to check next position of pc. If it is a wall return with some error value
  //else return correct and make changes to dir accordingly
  //dir will be passed in as a delta move (-1,-1) and should be passed out as the actual next 
  //position, so do I need to return a pair? can you opperate on a pair_t that is passed in as a value?
  //Might need to go to help room or office hours
  char input = getch();
  switch (input)
  {
    case 'Q':
      ;
      //quit the game
    case 'y':
      dir[dim_x] = -1;
      dir[dim_y] = -1;
      break;
      //up and left
    case 'k':
      dir[dim_y] = -1;
      break;
      //up
    case 'u':
      dir[dim_x] = 1;
      dir[dim_y] = -1;
      break;
      //up and right
    case 'l':
      dir[dim_x] = 1;
      break;
      //right
    case 'h':
      dir[dim_x] = 1;
      dir[dim_y] = 1;
      break;
      //down and right 
    case 'b':
      dir[dim_y] = 1;
      break;
      //down
    case 'j':
      dir[dim_y] = 1;
      dir[dim_x] = -1;
      break;
      //down and left
    case 'n':
      dir[dim_x] = -1;
      break;
      //left
    case '<':
      if (mappair(d->pc.position) == '<')
      {
        new.max_monsters = MAX_MONSTERS;
        init_dungeon(&new);
        gen_dungeon(&new);
        d = &new;
        delete_dungeon(&new);
      }
      break;
      //go up stairs
    case '>':
      if (mappair(d->pc.position) == '>')
      {
        new.max_monsters = MAX_MONSTERS;
        init_dungeon(&new);
        gen_dungeon(&new);
        d = &new;
        delete_dungeon(&new);
      }
      break;
      //go down stairs
    case 'm':
      monsters_list(d);
      pc_next_pos(d, dir);
      break;
      //print a new screen with a list of monsters
  }
  pair_t actual;
  actual[dim_x] = dir[dim_x] + d->pc.position[dim_x];
  actual[dim_y] = dir[dim_y] + d->pc.position[dim_y];
  if (hardnesspair(actual) != 0)
  {
    dir[dim_y] = dir[dim_x] = 0;
  }
  return 0;
}

uint32_t pc_in_room(dungeon_t *d, uint32_t room)
{
  if ((room < d->num_rooms)                                     &&
      (d->pc.position[dim_x] >= d->rooms[room].position[dim_x]) &&
      (d->pc.position[dim_x] < (d->rooms[room].position[dim_x] +
                                d->rooms[room].size[dim_x]))    &&
      (d->pc.position[dim_y] >= d->rooms[room].position[dim_y]) &&
      (d->pc.position[dim_y] < (d->rooms[room].position[dim_y] +
                                d->rooms[room].size[dim_y]))) {
    return 1;
  }

  return 0;
}
