#pragma once
#include "PathfinderInterface.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <ctime>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>

using namespace std;


const int ROW_SIZE = 5;
const int COL_SIZE = 5;
const int DEPTH_SIZE = 5;
const int BACKGROUND = 1;
const int WALL = 0;
const int TEMPORARY = 2; // Used to show this path has been explored
const int PATH = 3;

class Pathfinder : public PathfinderInterface
{
protected:
  int temp[DEPTH_SIZE][ROW_SIZE][DEPTH_SIZE];
  int maze_grid[DEPTH_SIZE][ROW_SIZE][DEPTH_SIZE]; // To hold values
  vector<string> solution;

public:

	Pathfinder();

	~Pathfinder();

  void CreateTemp();

  string Showtemp();

  bool CheckMaze(string file_name);

  bool find_maze_path(int d, int r, int c);

	string toString() const;

	void createRandomMaze();

	bool importMaze(string file_name);

	vector<string> solveMaze();

};
