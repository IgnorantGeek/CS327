//This is going to be a text based game, in the style of "escape the room" games.
//This only has to read input from the command line and print stuff. So it should be really easy
//implement theoretically. So I just need to make it read/write from terminal. Just need a story.

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <ncurses.h>

/*
What will be the best practice for this guy? Maybe have a text reader kinda like we did in rlg for the monsters
have it parse text files for the story. Then just write the story in a text doc or whatever. Make keywords to identify
responses, and inputs. Inputs can be like a range of things for any given step in the puzzle. I think that is going to be
the easiest way. We should make sure that the profs are cool with that, going to try to make sure it will run anywhere** 
*/

int main(int argc, char *argv[])
{
    //the main method
    //need separate methods to scan. main might just want to go in another file...
    printf("We did something!");
    return 0;
}