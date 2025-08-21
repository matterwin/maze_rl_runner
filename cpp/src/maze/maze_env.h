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

enum class Action
{
  UP = 0,
  DOWN,
  LEFT,
  RIGHT
};

namespace Reward 
{
  constexpr int TIME_STEP = -1;
  constexpr int OUT_OF_BOUNDS = -2;
  constexpr int OBSTACLE      = -2;
  constexpr int GOAL          = 100; 
};

struct Point 
{
  int r, c;
};

struct StepResult
{
  Point next_state;
  double reward;
  bool done;
  std::string info;
};

struct Maze
{
  std::vector<std::vector<char>> maze;
  Point start, goal;
};

struct MazeEnv
{
  Maze maze;
  Point agentPos;

  Point reset();
  StepResult step(Action action);
};

bool isGoal(const Maze* maze, int r, int c);
bool isStart(const Maze* maze, int r, int c);
bool isOffLimits(const Maze* maze, int r, int c);

Maze parse_maze_json(const std::string& path);

void printMaze(const Maze* maze);

CellType charToCellType(char c);
char cellTypeToChar(CellType type);

#endif
