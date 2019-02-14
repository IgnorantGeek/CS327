#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <endian.h>
#include <string.h>

#define DUNGEON_WIDTH  80
#define DUNGEON_HEIGHT 21
#define MIN_ROOM_WIDTH 3
#define MAX_ROOM_WIDTH 10
#define MIN_ROOM_HEIGHT 2
#define MAX_ROOM_HEIGHT 10
#define MIN_NUMBER_OF_ROOMS 5
#define MAX_NUMBER_OF_ROOMS  10
#define MIN_HARDNESS 0
#define MAX_HARDNESS 255

#define TRUE  0
#define FALSE 1 

const char rockCell = ' ';
const char corridorCell = '#';
const char roomCell = '.';
const char playerCell = '@';

typedef struct
{
  int row;
  int col;
}Coordinate;

typedef struct
{
  Coordinate one;
  Coordinate two;
}Points;

/* Room with points one and two. width = 5, height = 4
  1 - - - -
  - - - - -
  - - - - -
  - - - - 2
 */
typedef struct
{
  Points point;
  int width;
  int height;
  int isConnected;
}Room;

typedef struct
{
  int numOfRooms;
  Coordinate PC;
  Room *rooms;
  char map[DUNGEON_HEIGHT][DUNGEON_WIDTH];
  int hardnessMap[DUNGEON_HEIGHT][DUNGEON_WIDTH];
} Dungeon;

int isLegalPlace(int row, int col, Dungeon *d, Room *r);
void generateRooms();
void placeRooms();
void fillMap(Dungeon *d, int roomNumber);
int generateRange(int min, int max);
void connectRoom();
void printMap(Dungeon *d);
void setDungeon(Dungeon *d);
void srand(unsigned seed);
void printRoomCoords(Dungeon *d);
void setSortedRoomArray(Dungeon *d);
void connectRooms(Dungeon *d);
void createDungeon(Dungeon *d);
int load(FILE *f, Dungeon *d); //loads the dungeon from save file located in .rlg327 in home
int save(FILE *f, Dungeon *d); //writes the dungeon to a save file located in .rlg327 in home

int main(int argc, char *argv[])
{
  int seed = time(NULL);
  if (argc > 1 && strcmp(argv[1], "--load") == 0) seed = atoi(argv[1]);
  printf("seed used: %d\n", seed);
  srand(seed);
  Dungeon d;
  char *dir = getenv("HOME");
  char *path = strcat(dir, "/.rlg327/");
  
  if(argv[1] == NULL)
  {
    createDungeon(&d);
    printMap(&d);
  }
  //default load
  else if(strcmp(argv[1], "--load") == 0)
  {
    char temp[200] = {0};
    strcpy(temp, path);
    strcat(temp, "dungeon");    
    FILE *file = fopen(temp, "r");
    load(file, &d);
    printMap(&d);
    fclose(file);
  }

  //save switch
  else if(strcmp(argv[1], "--save") == 0 && argv[2] == NULL)
  {
    FILE *file = fopen(strcat(path, "dungeon"), "w");
    createDungeon(&d);

    save(file, &d);
    printMap(&d);
    fclose(file);
  }

  //save and load
  else if(strcmp(argv[1], "--save") == 0 && strcmp(argv[2], "--load") == 0)
  {  
    FILE *saveFile = fopen(strcat(path, "dungeon"), "w");
    createDungeon(&d);
    save(saveFile, &d);
    fclose(saveFile);
    FILE *file = fopen(path, "r");
    load(file, &d);
    fclose(saveFile);
    printMap(&d);
  }
 
  //load and save
  else if(strcmp(argv[1], "--load") == 0 && strcmp(argv[2], "--save") == 0)
  {
    FILE *file = fopen(strcat(path, "dungeon"), "r");
    load(file, &d);
    printMap(&d);
    fclose(file);
    FILE *saveFile = fopen(strcat(path, "dungeon"), "w");
    save(saveFile, &d);
    fclose(saveFile);
  } 
  //load with file
  else if(strcmp(argv[1], "--load") == 0 && argv[2] != NULL && strcmp(argv[1], "--save") == 1) 
  {
    FILE *file = fopen(strcat(path, argv[2]), "r");
    load(file, &d);
    printMap(&d);
    fclose(file);

  }

  else
  {
    createDungeon(&d);
    printMap(&d);
  }
  
return 0;
}

void createDungeon(Dungeon *d)
{
  setDungeon(d);
  d->rooms = (Room*)malloc(MAX_NUMBER_OF_ROOMS * sizeof(Room));//possible bug? sizeof(d->rooms) after this call is 8
  generateRooms(d);
  placeRooms(d);
  setSortedRoomArray(d);
  connectRooms(d);
  //free(d->rooms);
}

void generateRooms(Dungeon *d)
{
  int qtyOfRooms = generateRange(MIN_NUMBER_OF_ROOMS, MAX_NUMBER_OF_ROOMS);
  d->numOfRooms = qtyOfRooms;
  
  int i;
  for(i = 0; i < qtyOfRooms; i++)
  {
    int rows = generateRange(MIN_ROOM_HEIGHT, MAX_ROOM_HEIGHT);
    int columns = generateRange(MIN_ROOM_WIDTH, MAX_ROOM_WIDTH);
    Room currRoom;
    currRoom.width = columns;
    currRoom.height = rows;
    currRoom.isConnected = FALSE;
    d->rooms[i] = currRoom;
  }
}

int isInBounds(int row, int col, Room *r)
{
  //check if in the immutable section
  if(row == 0 || row == 79 || col == 0 || col == 20) return FALSE;
  //check bounds
  if(row + r->height > 19) return FALSE;
  if(col + r->width > 78) return FALSE;
  return TRUE;
}

int checkAdjaceny(int row, int col,  Dungeon *d, char cellToLookFor)
{
  //visited order
  //    0 7 6
  //    1 - 5
  //    2 3 4
  int adjacentCells = 8;
  int xRoutes[] = {-1,  0,  1, 1, 1, 0, -1, -1};
  int yRoutes[] = {-1, -1, -1, 0, 1, 1,  1,  0};
  int i, j;
  for(i = 0; i < adjacentCells; i++)
  {
    for(j = 0; j < adjacentCells; j++)
    {
      if(d->map[row + xRoutes[j]][col + yRoutes[j]] == cellToLookFor) return FALSE;
    }
  }
  return TRUE;
}

int isLegalPlace(int row, int col, Dungeon *d, Room *r)
{
  if(isInBounds(row, col, r) == FALSE) return FALSE;
  Coordinate coord1;
  coord1.row = row;
  coord1.col = col;
  Coordinate coord2;
  coord2.row = row + r->height - 1;
  coord2.col = col + r->width - 1;
  Points pointTemp;
  pointTemp.one = coord1;
  pointTemp.two = coord2;
  r->point = pointTemp;
  int i, j;
  for(i = row; i < row + r->height; i++)
  {
    for(j = col; j < col + r->width; j++)
    {
      if(checkAdjaceny(i, j, d, roomCell) == FALSE) return FALSE;
    }
  }
  return TRUE;
}

void placeRooms(Dungeon *d)
{
  //printf("Placing Rooms inside Dungeon...\n");
  int roomNumber = 0;
  int attempts = 0;
  int attemptLimit = 2000;
  while(roomNumber < d->numOfRooms)
  {
    int randomRow = (rand() % 19) + 1;
    int randomCol = (rand() % 78) + 1;
    if(isLegalPlace(randomRow, randomCol, d, &(d->rooms[roomNumber])) == TRUE)
    {
      d->PC.row = d->rooms[0].point.one.row;
      d->PC.col = d->rooms[0].point.one.col;
      fillMap(d, roomNumber);
      roomNumber++;
    }
    attempts++;
    
    if(attempts > attemptLimit)
    {
      printf("FAILURE TO PLACE ALL ROOMS\n");
      break;
    }
  }
}
 
void fillMap(Dungeon *d, int roomNumber)
{
  int i, j;
  int row = d->rooms[roomNumber].point.one.row;
  int col = d->rooms[roomNumber].point.one.col;
  for(i = row; i < row + d->rooms[roomNumber].height; i++)
  {
    for(j = col; j < col + d->rooms[roomNumber].width; j++)
    {
      if (d->PC.row == i && d->PC.col == j) d->map[i][j] = playerCell;
      else
      {
        d->map[i][j] = roomCell;
        d->hardnessMap[i][j] = MIN_HARDNESS;
      }
    }    
  }
}

int generateRange(int min, int max)
{
  return rand() % (max - min) + min;
}

void printMap(Dungeon *d)
{
  int row, col;
  for(row = 0; row < DUNGEON_HEIGHT; row++)
  {
    for(col = 0; col < DUNGEON_WIDTH; col++)
    {
      printf("%c", d->map[row][col]);
    }
    printf("\n");
  }
}

void setDungeon(Dungeon *d)
{
  //printf("Initilizing Dungeon...\n");
  int row, col;
  char topBorder = '-';
  char sideBorder = '|';
  char cornerBorder = '+';
  for(row = 0; row < DUNGEON_HEIGHT; row++)
  {
    for(col = 0; col < DUNGEON_WIDTH; col++)
    {
      if(row == 0 || row == 20)
      {
	      d->map[row][col] = topBorder;
	      d->hardnessMap[row][col] = MAX_HARDNESS;
      }
      else if(col == 0 || col == 79)
      {
	      d->map[row][col] = sideBorder;
	      d->hardnessMap[row][col] = MAX_HARDNESS;
      }
      else
      {
	      d->map[row][col] = rockCell;
	      d->hardnessMap[row][col] = generateRange(MIN_HARDNESS+1, MAX_HARDNESS);
      }
      if((row == 0 && col == 0) || (row == 0 && col == 79) || (row == 20 && col == 0) || (row == 20 && col == 79))
      {
	      d->map[row][col] = cornerBorder;
	      d->hardnessMap[row][col] = MAX_HARDNESS;
      }
    }
  }
}

void connectRooms(Dungeon *d)
{
  int i;
  for(i = 0; i < d->numOfRooms - 1; i++)
  {
    Room currRoom = d->rooms[i];
    if(currRoom.isConnected == FALSE)
    {
      Room nextRoom = d->rooms[i + 1];
      Coordinate currCoord = currRoom.point.two;
      Coordinate destinationCoord = nextRoom.point.one;
      while((currCoord.row != destinationCoord.row) || (currCoord.col != destinationCoord.col))
      {
	      int rowDifference, colDifference;
      	rowDifference = abs(destinationCoord.row - currCoord.row);
	      colDifference = abs(destinationCoord.col - currCoord.col);
	      if(rowDifference > colDifference)
              {
	        if(currCoord.row < destinationCoord.row)
                {
	          currCoord.row += 1;
	        }
	        else
                {
	          currCoord.row -= 1;	  
                }
	      }
	      else 
              {
	        if(currCoord.col < destinationCoord.col)
                {
	          currCoord.col += 1;
	        }
	        else 
                {
	          currCoord.col -= 1;
	        }
	      }
	      if(d->map[currCoord.row][currCoord.col] == rockCell)
              {
	        d->map[currCoord.row][currCoord.col] = corridorCell;
	        d->hardnessMap[currCoord.row][currCoord.col] = MIN_HARDNESS;
	      }
      }
      d->rooms[i].isConnected = TRUE;
    }
  }
}

void setSortedRoomArray(Dungeon *d)
{
  int i;
  //sort from top left to bottom right
  for(i = 0; i < d->numOfRooms; i++)
  {
    int j;
    int minIndex = i;
    for(j = i + 1; j <  d->numOfRooms; j++)
    {
      if(d->rooms[minIndex].point.one.col == d->rooms[j].point.one.col)
      {
	      if(d->rooms[j].point.one.row < d->rooms[minIndex].point.one.row)
        {
	        minIndex = j;
	      }
      }
      else
      {
	      if(d->rooms[j].point.one.col < d->rooms[minIndex].point.one.col)
        {
	        minIndex = j;
	      }
      }
    }
    Room temp = d->rooms[minIndex];
    d->rooms[minIndex] = d->rooms[i];
    d->rooms[i] = temp;
  }
}

//done 
int load(FILE *f, Dungeon *d)
{
  fseek(f, 0, SEEK_SET);
  setDungeon(d);
  //d->rooms = (Room*)malloc(MAX_NUMBER_OF_ROOMS * sizeof(Room));//this initializes d->rooms
  //needs to pull from file, load the dungeon, and print the loaded dungeon
  //add support for throwing an error when the file doesn't exist
  char marker[12];//unused currently
  u_int32_t version, size;//unused currently
  u_int8_t PCrow, PCcol;//stores PC coordinates from file
  unsigned char *hardness;
  hardness = malloc(1680);

  //reads first 12 bytes
  fread(&marker, 1, 12, f);

  //reads bytes 12-15
  fread(&version, sizeof(version), 1, f);
  version = htobe32(version);

  //reads bytes 16-19
  fread(&size, sizeof(size), 1, f);
  size = htobe32(size);

  //reads bytes 20-21
  fread(&PCcol, sizeof(PCcol), 1, f);
  fread(&PCrow, sizeof(PCrow), 1, f);
  d->PC.row = PCrow;
  d->PC.col = PCcol;
  fseek(f, 22, SEEK_SET);

  //reads bytes 22-1701
  fread(hardness, 1680, 1, f);
  int i;
  for (i = 0; i < 1680; i++)
  {
    d->hardnessMap[i/80][i%80] = hardness[i];  
  }
  
  int row, col;
  for (row = 0; row < DUNGEON_HEIGHT; row++)
  {
    for (col = 0; col < DUNGEON_WIDTH; col++)
    {
      if (d->map[row][col] == '+' || d->map[row][col] == '-' || d->map[row][col] == '|');	    
      else if (d->hardnessMap[row][col] == 0)
	{
          d->map[row][col] = '#';
	}
      else 
      {
	      d->map[row][col] = ' ';
      }
    }
  }  
 
  //reads bytes 1702-end
  char *buffer;
  buffer = malloc(size-1702);
  fread(buffer, size-1702, 1, f);
  int count;
  d->rooms = malloc(size-1702);
  count = 0;
  for (int i = 0; i < size-1702; i+=4)
  {
    Room temp;
    temp.point.one.col = (int) buffer[i];
    temp.point.one.row = (int) buffer[i+1];
    temp.width = (int) buffer[i+2];
    temp.height = (int) buffer[i+3];
    temp.isConnected = 0;
    d->rooms[count] = temp;
    count++;
  }

  int g = 0;
  while(g<count)
  {
    fillMap(d, g);
    g++;
  }
  fclose(f);
  return 0;
}


int save(FILE *f, Dungeon *d)
{	
  //Will be doing the writes in blocks
  //Block one, bytes 0-11
  char *marker = "RLG327-F2018";
  fwrite(marker, 1, 12, f);

  //Block two, bytes 12-15
  u_int32_t version = 0;
  version = htobe32(version);
  fwrite(&version, sizeof(version), 1, f);

  //Block three, bytes 16-19
  u_int32_t size = 1702+(sizeof(Room) * d->numOfRooms);//this might not be right
  size = htobe32(size);
  fwrite(&size, sizeof(size), 1, f);

  //Block four, bytes 20-21
  u_int8_t PCcol, PCrow;
  PCcol = d->PC.col;
  PCrow = d->PC.row;
  fwrite(&PCcol, sizeof(PCcol), 1, f);
  fwrite(&PCrow, sizeof(PCrow), 1, f);

  //Block five, bytes 22-1701
  int writeRow, writeCol;
  int h; //hardness pointer
  for (writeRow = 0; writeRow < DUNGEON_HEIGHT; writeRow++)
  {
    for (writeCol = 0; writeCol < DUNGEON_WIDTH; writeCol++)
    {
      h = d->hardnessMap[writeRow][writeCol];
      fwrite(&h, sizeof(u_int8_t), 1, f);
    }
  }
      
  //Block six, bytes 1702-end
  int count;
  for (count = 0; count < d->numOfRooms; count++)
  {
    Room currRoom = d->rooms[count];
    u_int8_t col, row, width, height;
    col = currRoom.point.one.col;
    row = currRoom.point.one.row;
    width = currRoom.width;
    height = currRoom.height;
    fwrite(&col, sizeof(col), 1, f);
    fwrite(&row, sizeof(row), 1, f);
    fwrite(&width, sizeof(width), 1, f);
    fwrite(&height, sizeof(height), 1, f);
  }
  return 0;
}
