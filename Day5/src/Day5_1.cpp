#include <iostream>
#include <vector>
#include <string>
#include <stdint.h>
#include <map>

#include "fileio.hpp"

using namespace std;

vector<vector<int64_t>> parse_map(const vector<string> str);

int main()
{
    vector<string> input = readFile("input_day5.txt");
    vector<vector<string>> processed_input = split_vector(input, "");

    vector<string> seeds = split_line(processed_input.at(0).at(0), ' ');
    seeds.erase(seeds.begin());

    vector<vector<string>> maps;

    for (int i = 1; i < processed_input.size(); i++)
    {
        string name = processed_input.at(i).at(0);
        name = split_line(name, ' ').at(0);

        vector<string> vec;
        for (int j = 1; j < processed_input.at(i).size(); j++)
        {
            vec.push_back(processed_input.at(i).at(j));
        }
        maps.push_back(vec);
    }

    vector<vector<vector<int64_t>>> processed_maps;

    for (const vector<string> vec : maps)
    {
        vector<vector<int64_t>> temp = parse_map(vec);
        processed_maps.push_back(temp);
    }

    cout << "Hello from day 5!" << endl;

    return 0;
}

vector<vector<int64_t>> parse_map(const vector<string> vec)
{
    vector<vector<int64_t>> result;
    for (const string str : vec)
    {
        vector<string> temp_s = split_line(str, ' ');
        vector<int64_t> temp_i;
        for (const string str : temp_s)
        {
            temp_i.push_back(std::stoll(str));
        }
        result.push_back(temp_i);
    }
    return result;
}
