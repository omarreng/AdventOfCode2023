#include <iostream>
#include <string>
#include <vector>

#include "fileio.hpp"

using namespace std;

vector<vector<char>> process_input(vector<string> &vec);
std::pair<int, int> parse_number(vector<char> &vec, int index);

int main()
{
    vector<string> input = readFile("input_day3.txt");
    vector<vector<char>> processed_input = process_input(input);

    for (int i = 0; i < processed_input.size(); i++)
    {
        for (int j = 0; j < processed_input.at(i).size(); j++)
        {
            if (std::isdigit(processed_input.at(i).at(j)))
            {
                parse_number(processed_input.at(i), j);
            }
        }
    }

    cout << "Hello from Day 3!" << endl;

    return 0;
}

vector<vector<char>> process_input(vector<string> &vec)
{
    vector<vector<char>> result;
    for (string &str : vec)
    {
        vector<char> temp_vec;
        for (char &c : str)
        {
            temp_vec.push_back(c);
        }
        result.push_back(temp_vec);
    }
    return result;
}

std::pair<int, int> parse_number(vector<char> &vec, int index)
{
    int result = 0;
    while (index < vec.size() && std::isdigit(vec.at(index)))
    {
        result = result * 10 + vec.at(index++) - '0';
    }
    return std::make_pair(result, index);
}