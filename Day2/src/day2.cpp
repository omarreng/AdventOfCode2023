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

    for (string &s : input)
    {
        process_line(s);
    }

    cout << "Hello from day 2!" << endl;
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

    vector<string> processed_line = split_line(str, ':');
    result.at("ID") = std::stoi(split_line(processed_line.at(0), ' ').at(1));
    vector<string> game_instances = split_line(processed_line.at(1), ';');
    for (string &game : game_instances)
    {
        vector<string> game_result = split_line(game, ',');
        for (string &color : game_result)
        {
            vector<string> color_result = split_line(color, ' ');
            result.at(color_result.at(2)) = std::max(std::stoi(color_result.at(1)), result.at(color_result.at(2)));
        }
    }

    return result;
}