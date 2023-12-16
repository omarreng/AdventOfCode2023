#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> readFile(string filePath);
vector<string> split_line(string str, char delimiter);
vector<vector<string>> split_vector(const vector<string> &vec, string delimiter);
