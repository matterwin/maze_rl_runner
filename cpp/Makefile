CXX = g++
CXXFLAGS = -std=c++17 -Wall -O2 -Iinclude

maze_SRC = src/maze/maze_env.cpp
main_SRC = src/main.cpp

SRC = $(main_SRC) $(maze_SRC)

OBJ = $(SRC:.cpp=.o)

# Executable output
TARGET = rl_maze

# Default build target
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)
