#include "env/env.h"
#include "nlohmann/json.hpp"

#include <iostream>
#include "env/env.h"
#include <fstream>

using json = nlohmann::json;

/* Returns a Maze struct with populated
 * columns and rows, along with aux. data */
bool parse_maze_json(struct Env *env, const std::string& path)
{
  std::ifstream in(path);
  if (!in.is_open())
  {
    std::cerr << "Failed to open file: " << path << std::endl;
    exit(1);
  }

  json j;
  in >> j;

  auto maze_str = j["maze"].get<std::vector<std::vector<std::string>>>();

  // Resize maze to match the number of rows of maze.json
  env->maze.resize(maze_str.size());
  for (std::size_t i = 0; i < maze_str.size(); ++i)
  {
    // Resizes maze's ith row to match the dim of maze.json's ith row
    env->maze[i].resize(maze_str[i].size());
    for (std::size_t j = 0; j < maze_str[i].size(); ++j)
    {
      if (maze_str[i][j].size() == 1)
        env->maze[i][j] = maze_str[i][j][0];
      else
        env->maze[i][j] = '?';
    }
  }

  env->start = { j["start"][0], j["start"][1] };
  env->goal = { j["goal"][0], j["goal"][1] };

  return false;
}

void printMaze(const Env* env)
{
  std::cout << "Starter Maze:\n";
  for (std::size_t i = 0; i < env->maze.size(); i++)
  {
    for (std::size_t j = 0; j < env->maze[i].size(); j++)
    {
      std::cout << env->maze[i][j] << "  ";
    }
    std::cout << std::endl;
  }
}



