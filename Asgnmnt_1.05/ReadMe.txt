This iteration of the RLG code has added player input functionality. The game now functions 
like an actual game. The user will input some movement command and the game will run until 
it is the PC's turn again, and will wait for another input. This iteration has also added stairs
which, when a PC goes up a set of stairs, will generate a new dungeon and put the PC in that. 
A monsters list has been added that shows the monsters type as well as its position in the dungeon.

Bugs:
After closing monsters screen, the user must press some key to get the screen to reprint. 
The monsters list will occasionally have monsters that are not on the map.
There are currently no stairs, code exits to process a stair move but I couldnt get the dungeon to generate stairs
