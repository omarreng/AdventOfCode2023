#include <unordered_set>

#include "fileio.h"
#include "utils.h"

unordered_set<pair<int, int>, pair_hash> visited_plots;

int main()
{
  auto input = read_file_char("Day12_input_test.txt");

  for (int ix = 0; ix < input.size(); ix++)
  {
    for (int iy = 0; iy < input[0].size(); iy++)
    {
      if (visited_plots.find({ix, iy}) != visited_plots.end())
      {
      }
    }
  }

  return 0;
}