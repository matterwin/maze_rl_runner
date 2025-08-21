#include "maze/maze_env.h"
#include <iostream>

int main()
{
  Maze maze = parse_maze_json("../data/maze1/maze1.json");
  printMaze(&maze);
  startAgent();
  return 0;
}
