#include <cstdint>
#include <unordered_map>

#include "fileio.h"

vector<int64_t> process_blink(vector<int64_t> input, int blink);

#define BLINKS 6

unordered_map<pair<int64_t, int>, vector<int64_t>> cache;

int main()
{
  auto input = read_file("Day11_input.txt");
  input = split_line(input[0]);
  vector<int64_t> stones;

  for (const auto &s : input)
  {
    stones.push_back(stoll(s));
  }

  size_t result = 0;
  for (const auto &stone : stones)
  {
    result += process_blink({stone}, BLINKS).size();
  }

  cout << "Result is: " << stones.size() << endl;

  return 0;
}

vector<int64_t> process_blink(vector<int64_t> input, int blink)
{
  if (input.empty())
  {
    return {};
  }
  if (cache.find({input[0], blink}) != cache.end())
  {
    return cache[{input[0], blink}];
  }
  if (blink == 0 && input[0] == 0)
  {
    return {1};
  }
  if (blink == 0 && to_string(input[0]).size() % 2 == 0)
  {
    auto s = to_string(input[0]);
    return {stoll(s.substr(0, s.length() / 2)), stoll(s.substr(s.length() / 2))};
  }
  if (blink == 0)
  {
    return {input[0] * 2024};
  }
  vector<int64_t> input1 = {};
  vector<int64_t> input2 = {};
  if (input[0] == 0)
  {
    input1.push_back(1);
  }
  else if (to_string(input[0]).size() % 2 == 0)
  {
    auto s = to_string(input[0]);
    input1.push_back(stoll(s.substr(0, s.length() / 2)));
    input2.push_back(stoll(s.substr(s.length() / 2)));
  }
  else
  {
    input1.push_back(input[0] * 2024);
  }
  auto result1 = process_blink(input1, blink - 1);
  auto result2 = process_blink(input2, blink - 1);
  result1.insert(result1.end(), result2.begin(), result2.end());
  cache.insert({input[0], blink}, result1);
  return result1;
}