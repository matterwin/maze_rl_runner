# maze_rl_runner

Let user iterate for certain number of runs for the agent to figure out maze (batches),
and then also provide previous stuff,etc.

Episode ends upon agent going out of bounds or lands in a obstacle.
Could potentially reset it to it's last position, but that complicates things.

Allow real-time edition of maze to confuse agent.



reward system is apart of the env. make it the best way adn edxperiment.

user can upload maze picture and have maze be printed out on screen and have agent train on this


rewards are always single numbers.
have states and actions be vectorized
like state[0] refers to x pos, state[1] refers to y pos in maze
action is a vector of the 4 directions agent is allowed to go

In making a robot learn how to escape from a maze, the reward is often -1 for every
time step that passes prior to escape; this encourages the agent to escape as quickly as possible

terminal states are out of bounds and hitting obstacles which we reward agent of -2

then we do env.reset()


I want this done in real time so its more about td learning
