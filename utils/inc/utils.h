#include <iostream>
#include <vector>

using namespace std;

void print_map(const vector<vector<char>> &input);

template <typename T>
bool is_bound(const vector<vector<T>> &vec, int ix, int iy)
{
  return ix >= 0 && iy >= 0 && ix < vec.size() && iy < vec[0].size();
}