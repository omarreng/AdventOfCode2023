#include <iostream>
#include <sstream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <vector>

#include "fileio.hpp"

using namespace std;

vector<string> readFile(string filePath)
{
    ifstream inputFile(filePath, ifstream::in);

    if (!inputFile.is_open())
    {
        ostringstream error_message;
        error_message << "Error opening file: " << filePath;
        throw invalid_argument(error_message.str());
    }

    vector<string> result;
    string line;

    while (getline(inputFile, line))
    {
        result.push_back(line);
    }

    inputFile.close();

    return result;
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