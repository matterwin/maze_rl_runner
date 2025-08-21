#ifndef RL_AGENT_H
#define RL_AGENT_H

#include <vector>

/* Q-learning Agent:
 * Q(s_t, a_t) <- Q(s_t, a_t) + \alpha * (R_{t+1} + \gamma * max_a Q(s_{t+1}, a_t) - Q(s_t, a_t))
 * On-policy: epsilon-greedy
 */
struct RL_Agent 
{
  std::vector<std::vector<std::vector<double>>> Q;
  double alpha; // Learning rate
  double gamma; // discount rate
  double epsilon; // epsilon-greedy method
};

/* void allocQ(Maze &maze); */ 

#endif
