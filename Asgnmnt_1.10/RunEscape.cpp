#include <stdio.h>
#include <stdio.h>
#include <string.h>

#include "Game.h"

//Have this framework come with a game runner. So it will create an instance of the game
//is that customizable enough?? How can we form this into some sort of API/Framework interface?

//Maybe the thing you have to make is a cpp file with a main method. Then just call things like
//new game, start game. Can make it configurable in the method or from a read file.


int main(int argc, char *args[])
{
    printf("Ayooo \n");

    printf("New Game. In a dark room or whatever and there is a closet \n");
    printf("This will all get ported to ncurses.\n");

    return 0;
}