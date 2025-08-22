#ifndef MAZE_H
#define MAZE_H

#include "actions.h"
#include <string>
#include <vector>

struct Point 
{
  int r, c;
};

struct Env
{
  std::string maze_str;
  std::vector<std::vector<char>> maze;
  Point start, goal;

  Point reset();
  std::tuple<Point, float, bool, int> step(Action action);
};

bool parse_maze_json(struct Env* env, const std::string& path);
void printMaze(const Env* env);

#endif
