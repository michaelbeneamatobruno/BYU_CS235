#include "Pathfinder.h"

using namespace std;

Pathfinder::Pathfinder()
{
  for (int depth = 0; depth < DEPTH_SIZE; depth++) {
		for(int row = 0; row < ROW_SIZE; row++) {
	     for(int col = 0; col < COL_SIZE; col++) {
         maze_grid[depth][row][col] = 1;
       }
    }
  }
}
Pathfinder::~Pathfinder(){}

void Pathfinder::CreateTemp()
{
  for (int depth = 0; depth < DEPTH_SIZE; depth++) {
    for(int row = 0; row < ROW_SIZE; row++) {
      for(int col = 0; col < COL_SIZE; col++) {
          temp[depth][row][col] = maze_grid[depth][row][col];
          // cout << "CreateTemp::" << endl;
          // cout << temp[0][0][0] << endl;
          // cout << maze_grid[0][0][0] << endl;
      }
    }
  }
  return;
}

bool Pathfinder::CheckMaze(string file_name)
{
  int count = 0;
  string value;
  ifstream file (file_name.c_str());
  if (file.is_open()) {
    while (file >> value) {
      if (count == 0 || count == 124) {
        if (value != "1") {
          return false;
        }
      }
      if (value != "1" && value != "0") {
        return false;
      }
      count++;
    }
  }
  if (count != 125) {
    return false;
  }
	return(true);
}

string Pathfinder::toString() const
{
  stringstream ss;
	for (int depth = 0; depth < DEPTH_SIZE; depth++) {
		for(int row = 0; row < ROW_SIZE; row++) {
	      for(int col = 0; col < COL_SIZE; col++) {
	          ss << maze_grid[depth][row][col] << " ";
	      }
        ss << endl;
		}
    if (depth == DEPTH_SIZE - 1) {
      break;
    }
    ss << endl;
  }
  return ss.str();
}

string Pathfinder::Showtemp()
{
  stringstream ss;
	for (int depth = 0; depth < DEPTH_SIZE; depth++) {
		for(int row = 0; row < ROW_SIZE; row++) {
	      for(int col = 0; col < COL_SIZE; col++) {
	          ss << temp[depth][row][col] << " ";
	      }
        ss << endl;
		}
    if (depth == DEPTH_SIZE - 1) {
      break;
    }
    ss << endl;
  }
  return ss.str();
}

void Pathfinder::createRandomMaze()
{
  // srand(time(NULL));
  for (int depth = 0; depth < DEPTH_SIZE; depth++) {
		for(int row = 0; row < ROW_SIZE; row++) {
	     for(int col = 0; col < COL_SIZE; col++) {
         if (depth == 0 && row == 0 && col == 0) {
           maze_grid[depth][row][col] = 1;
         }
         else if (depth == 4 && row == 4 && col == 4) {
           maze_grid[depth][row][col] = 1;
         }
         else {
           maze_grid[depth][row][col] = rand() % 2;
         }
       }
    }
  }
}

bool Pathfinder::importMaze(string file_name)
{
	cout << "importMaze from " << file_name << endl;
  if (!CheckMaze(file_name)) {
    cout << "Invalid Maze" << endl;
    return false;
  }
  ifstream file (file_name.c_str());
  if (file.is_open()) {
    string line;
  	for (int depth = 0; depth < DEPTH_SIZE; depth++) {
  		for(int row = 0; row < ROW_SIZE; row++) {
        getline(file, line);
        stringstream ss(line);
        for(int col = 0; col < COL_SIZE; col++) {
            int value;
            ss >> value;
            // cout << "[" << depth << "]["<< row << "][" << col << "]=" << value << endl;
            maze_grid[depth][row][col] = value;
        }
      }
      getline(file, line);
  	}
  }
	return(true);
}

bool Pathfinder::find_maze_path(int d, int r, int c)
{
  // cout << this->toString();
  if (d < 0 || r < 0 || c < 0 || d >= DEPTH_SIZE || r >= ROW_SIZE || c >= COL_SIZE) {
    // cout << "here01" << endl;
    return false;
  }     // Cell is out of bounds.
  else if (temp[d][r][c] != BACKGROUND) {
    // cout << temp[0][0][0] << endl;
    // cout << maze_grid[0][0][0] << endl;
    // cout << "here02" << endl;
    return false;      // Cell is on barrier or dead end.
  }
  // cout << "find_maze_path [" << d << "][" << r << "][" << c << "]" << endl;
  else if (d == DEPTH_SIZE - 1 && r == ROW_SIZE - 1 && c == COL_SIZE - 1) {
    // cout << "else if" << endl;
    temp[d][r][c] = PATH;         // Cell is on path
    solution.push_back("(" + to_string(c) + ", " + to_string(r) + ", " + to_string(d) + ")");
    return true;               // and is maze exit.
  }
  else {
    // Recursive case.
    // Attempt to find a path from each neighbor.
    // Tentatively mark cell as on path.
    temp[d][r][c] = PATH;
    if (find_maze_path(d - 1, r, c) //up in depth
        || find_maze_path(d + 1, r, c) //down in depth
        || find_maze_path(d, r - 1, c) // Up
        || find_maze_path(d, r + 1, c) // Down
        || find_maze_path(d, r, c - 1) // Left
        || find_maze_path(d, r, c + 1) ) { // Right
      solution.push_back("(" + to_string(c) + ", " + to_string(r) + ", " + to_string(d) + ")");
      return true;
    }
    else {
      temp[d][r][c] = TEMPORARY;  // Dead end.
      return false;
    }
  }
}

vector<string> Pathfinder::solveMaze()
{
  solution.clear();
  CreateTemp();
  vector<string> emptyVector;
  if (find_maze_path(0, 0, 0)) {
    reverse(solution.begin(), solution.end());
    return solution;
  }
  else {
    return emptyVector;
  }

}
