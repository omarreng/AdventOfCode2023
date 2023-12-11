#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>

#include "fileio.hpp"

using namespace std;

vector<string> split_line(string str);
unordered_map<string, int> process_line(string str);

int main()
{
    vector<string> input = readFile("input_day2.txt");

    return 0;
}

vector<string> split_line(string str, char delimiter)
{
    istringstream iss(str);
    string token;
    vector<string> result;

    while (std::getline(iss, token, delimiter))
    {
        result.push_back(token);
    }

    return result;
}

unordered_map<string, int> process_line(string str)
{
    unordered_map<string, int> result{
        {"ID", -1},
        {"red", 0},
        {"green", 0},
        {"blue", 0}};

    return result;
}