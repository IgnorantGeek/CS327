Tunneling and non-Tunneling distance maps
  This submission implements functionality for calculating and saving the dijkstra distance maps for
  the tunneling and non-tunneling monsters, which will be implemented in the next version. The code 
  has five new functions, dijkstra_non_tunnel, dijkstra_tunnel, printTunnel, and two comparator 
  functions for use inside the dijkstra functions. The function saves each type of map in an int array
  stored in the Dungeon type. 

  Algorithm logic:
  1) Main call to dijkstra
    Initializes all cells with cost of INT_MAX
    Sets the cost of the PC to 0
    for every point in the NonTunnel map
      if the hardness at that cell is 0
       -add NonTunnel at that cell to the heap
      else set the heap node at NonTunnel at that cell to null

    Remove min off the heap
      check every point around the current cell for the lowest cost
        update the cost of that cell with the new cost

  2) Print the NonTunnel and Tunnel maps


Notes: cloned profs code, now using his implementation of the roguelike game. Need to fix style 
