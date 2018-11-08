This updated adds movement to the monsters. The code is a rough draft of what the final product should 
look like. It does not use a heap, and each character moves at the same speed, once per game turn. The PC
does not move, and the game ends when one of the monsters gets to the PC. Only produces two kinds of 
monster at the moment, 0 for non tunneling and f for tunneling. 

Known Bugs:
  Certain tunneling monsters move away from player before moving towards
  No implementation for smart/telepathic/or erratic monsters
  At the moment, tunneling and non_tunneling maps are not updated after tunnel move 
