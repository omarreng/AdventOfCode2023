#include <iostream>
#include <string>
#include <vector>

#include "fileio.hpp"

using namespace std;

vector<vector<char>> process_input(vector<string> &vec);

int main()
{
    vector<string> input = readFile("input_day3.txt");
    vector<vector<char>> processed_input = process_input(input);

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