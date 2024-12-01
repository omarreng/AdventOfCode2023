#include <iostream>

#include "fileio.h"

vector<string> process_input();

int main()
{
    auto input = process_input();
    for (const auto& s : input)
    {
        cout << s << endl;
    }
    return 0;
}

vector<string> process_input()
{
    auto input = readFile("Day1_1_input.txt");
    return input;
}