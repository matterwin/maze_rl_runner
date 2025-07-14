#ifndef MAZE_ENV_H
#define MAZE_ENV_H

#include <vector>
#include <string>

enum class CellType
{
  OPEN = 0,
  WALL,
  START,
  GOAL,
  UNKNOWN
};

struct Point 
{
  int r, c;
};

struct Maze
{
  std::vector<std::vector<char>> maze;
  Point start, goal;
};

bool isGoal(const Maze* maze, int r, int c);
bool isStart(const Maze* maze, int r, int c);
bool isOffLimits(const Maze* maze, int r, int c);

Maze parse_maze_json(const std::string& path);

void printMaze(const Maze* maze);

CellType charToCellType(char c);
char cellTypeToChar(CellType type);

#endif
