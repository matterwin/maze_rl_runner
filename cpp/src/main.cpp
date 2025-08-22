#include "env/env.h"
#include "agent/agent.h"
#include <iostream>
#include <string>

int main()
{

  Env *env = new Env();
  Agent *agent = new Agent();

  const std::string _json = "../data/maze1/maze1.json";
  env->maze_str = _json;
  parse_maze_json(env, _json);

  printMaze(env);

  delete(env);
  delete(agent);
  return 0;
}
