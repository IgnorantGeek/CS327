#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

//This program will generate dugeons for my roguelike game at random with given parameters.
//The dungeons will have a set number of rooms of a given size, a set number of corridors,
//and a set amount of white space (rock). This is gonna be hard.

char dungeon[21][80]; //not sure if this is right
int numRooms = -1;

struct Room
{
    int x, y, width, height;
};

struct Room rooms[5];

int newRand(int lower, int upper) 
{ 
    return (rand() % (upper - lower + 1)) + lower;
}
int printDungeon()
{
    //prints dungeon matrix to terminal, not sure about this implementation, if I print will 
    //I still be able to move the player around?
    int i, j;
    for (i = 0; i < 21; i++)
    {
        for (j = 0; j< 80; j++)
        {
            printf("%c", dungeon[i][j]);
        }
	printf("\n");
    }
    return 0;
}

//Should be done. Checks entire space for new room.
//never returns true
int isValid(struct Room newRoom)
{   
    int x, y, width, height;
    width = newRoom.width + 1;
    height = newRoom.height + 1;
    x = newRoom.x - 1;
    int xrange = width + x;
    while (x <= xrange)
    {
	y = newRoom.y - 1;
        int yrange = height + y;
	while (y <= yrange)
        {	
            if (dungeon[y][x] == '.')
            {
		 return 1;
	    }
	    y++;
        }
	x++;
    }
    return 0;
}

int createRoom(struct Room newRoom)
{
    if (isValid(newRoom) == 0)
    {
        rooms[numRooms] = newRoom;
        numRooms++;
        int i, j;
        for (i = newRoom.x; i < newRoom.x + newRoom.width; i++)
        {
            for (j = newRoom.y; j < newRoom.y + newRoom.height; j++)
            {
                dungeon[j][i] = '.';
            }
        }
        return 0;
    }
    else return 1;
}

//Untested
int fillCorr()
{
    int c, xbuildfrom, ybuildfrom;
    struct Room nextRoom, buildto;
    if (numRooms != -1)
    {
	for (c = 0; c < numRooms - 1; c++)
	{
		nextRoom = rooms[c];
		buildto = rooms[c+1];
		double shortest =  sqrt(((nextRoom.x-buildto.x)^2)+((nextRoom.y-buildto.y)^2));
		int i, xbound, ybound;
		xbound = nextRoom.x + nextRoom.width;
		ybound = nextRoom.y + nextRoom.height;
		xbuildfrom = nextRoom.x;
		ybuildfrom = nextRoom.y;
		for (int x = nextRoom.x; x<xbound; x++)
		{
			for (int y = nextRoom.y; y<ybound; y++)
			{
				//checks shortest distance to each room in the rooms array
				for (i = c+1; i<numRooms; i++)
				{
					double nextLength = sqrt(((x-rooms[i].x)^2)+((y-rooms[i].y)^2));
					if (nextLength < shortest)
						shortest = nextLength;
						buildto = rooms[i];	
						xbuildfrom = x;
						ybuildfrom = y;
				}
			}
		}
		//check next cell is rock
		int x, y;
		x = xbuildfrom;
		y = ybuildfrom;
		int xdist = buildto.x - x;
		int ydist = buildto.y - y;
		if (dungeon[y][x+1] == ' ')x = x+1;
		else if (dungeon[y][x-1] == ' ') x = x-1;
		else if (dungeon[y-1][x] == ' ') y = y-1;
	        else if (dungeon[y+1][x] == ' ') y = y+1;	
		while (dungeon[y][x] != '.')
		{
			dungeon[y][x] = '#';
			int catch = newRand(0,1);
			if (catch == 0 && xdist != 0 && ydist != 0)
			{
				xdist--;
				x++;
				//need to make sure I am moving towards next room
			}
			else if (catch == 1 && xdist!= 0 && ydist != 0)
			{
				ydist--;
				y++;
				//need to make sure I am moving towards next room
			}
		}
	}
    }

    return 0;
}


int main()
{
    //runs the whole thing
    int i = 0, j;
    srand(time(0));
    numRooms = 0;
    //makes border;
    while (i == 0)
    {
        for (j = 0; j < 80; j++)
        {
            dungeon[i][j] = '-';
        }
        i++;
    }
    while (i < 20)
    {
        for (j = 0; j<80;j++)
	{
		if (j == 0 || j == 79) dungeon[i][j] = '|';
		else dungeon[i][j] = ' ';
	}
        i++;
    }
    while (i == 20)
    {
        for (j = 0; j < 80; j++)
        {
            dungeon[i][j] = '-';
        }
	i++;
    }
    while (numRooms < 6)
    {
        struct Room newRoom;
        newRoom.height = newRand(2, 5);
        newRoom.width = newRand(3, 9);
        newRoom.y = newRand(1, 15);
        newRoom.x = newRand(1, 70);
        createRoom(newRoom);
    }
    printDungeon();
    return 0;
}
