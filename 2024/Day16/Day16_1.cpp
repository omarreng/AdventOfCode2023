#include <functional>
#include <limits>
#include <stack>

#include "fileio.h"
#include "strategies.h"

#define START 'S'
#define END 'E'
#define WALL '#'
#define FREE_SPACE '.'
#define INVALID_POS {-1, -1}

pair<int, int> find_position(const vector<vector<char>> &puzzle, const char position);
size_t find_optimal_score(const vector<vector<char>> &puzzle);

struct node
{
  int ix;
  int iy;
  size_t score;
  function<void(int &, int &)> direction;
};

int main()
{
  auto input = read_file_char("Day16_input_test.txt");

  auto start_pos = find_position(input, START);
  auto end_pos = find_position(input, END);

  return 0;
}

pair<int, int> find_position(const vector<vector<char>> &puzzle, const char position)
{
  for (int ix = 0; ix < puzzle.size(); ix++)
  {
    for (int iy = 0; iy < puzzle[ix].size(); iy++)
    {
      if (puzzle[ix][iy] == position)
      {
        return {ix, iy};
      }
    }
  }
  return INVALID_POS;
}

size_t find_optimal_score(const vector<vector<char>> &puzzle)
{
  size_t result = numeric_limits<size_t>::max();
  stack<node> tiles;

  auto start_pos = find_position(puzzle, START);

  tiles.push({start_pos.first, start_pos.second, 2000, W});
  tiles.push({start_pos.first, start_pos.second, 1000, N});
  tiles.push({start_pos.first, start_pos.second, 1000, S});
  tiles.push({start_pos.first, start_pos.second, 0, W});

  return result;
}