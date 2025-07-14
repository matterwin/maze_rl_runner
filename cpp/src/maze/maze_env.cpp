#include "maze_env.h"
#include <iostream>
#include <fstream>
#include "nlohmann/json.hpp"

using json = nlohmann::json;

CellType charToCellType(char c) 
{
  switch (c) 
  {
    case '.': return CellType::OPEN;
    case '#': return CellType::WALL;
    case 'S': return CellType::START;
    case 'G': return CellType::GOAL;
    default:  return CellType::UNKNOWN;
  }
}

char cellTypeToChar(CellType type)
{
  switch (type) 
  {
    case CellType::OPEN:   return '.';
    case CellType::WALL:   return '#';
    case CellType::START:  return 'S';
    case CellType::GOAL:   return 'G';
    case CellType::UNKNOWN:
    default:               return '?';
  }
}

bool isGoal(const Maze* maze, std::size_t r, std::size_t c)
{
  return charToCellType(maze->maze[r][c]) == CellType::GOAL;
}

bool isStart(const Maze* maze, std::size_t r, std::size_t c)
{
  return charToCellType(maze->maze[r][c]) == CellType::START;
}

bool isOffLimits(const Maze* maze, std::size_t r, std::size_t c)
{
  // Bounds Safety 
  if (r < 0 || r >= maze->maze.size() || c < 0 || c >= maze->maze[r].size())
    return true;

  CellType cell_type = charToCellType(maze->maze[r][c]);
  if (cell_type == CellType::UNKNOWN 
      || cell_type == CellType::START
      || cell_type == CellType::WALL)
    return true;

  return false;
}

/* Returns a Maze struct with populated
 * columns and rows, along with aux. data */
Maze parse_maze_json(const std::string& path)
{
  std::ifstream in(path);
  if (!in.is_open())
  {
    std::cerr << "Failed to open file: " << path << std::endl;
    exit(1);
  }

  json j;
  in >> j;

  Maze maze;

  auto maze_str = j["maze"].get<std::vector<std::vector<std::string>>>();

  /* std::cout << "Maze (raw JSON format):\n" << j["maze"].dump(2) << "\n\n"; */

  // Resize maze to match the number of rows of maze.json
  maze.maze.resize(maze_str.size());
  for (std::size_t i = 0; i < maze_str.size(); ++i)
  {
    // Resizes maze's ith row to match the dim of maze.json's ith row
    maze.maze[i].resize(maze_str[i].size());
    for (std::size_t j = 0; j < maze_str[i].size(); ++j)
    {
      if (maze_str[i][j].size() == 1)
        maze.maze[i][j] = maze_str[i][j][0];
      else
        maze.maze[i][j] = '?';
    }
  }

  maze.start = { j["start"][0], j["start"][1] };
  maze.goal = { j["goal"][0], j["goal"][1] };

  return maze;
}


void printMaze(const Maze* maze)
{
  std::cout << "Starter Maze:\n";
  for (std::size_t i = 0; i < maze->maze.size(); i++)
  {
    for (std::size_t j = 0; j < maze->maze[i].size(); j++)
    {
      std::cout << maze->maze[i][j] << "  "; 
    }
    std::cout << std::endl;
  }
}

bool move_to_cell_r_c(Maze *maze, std::size_t r, std::size_t c)
{
  if (isOffLimits(maze, r, c))
    return false;

  return true;
}
