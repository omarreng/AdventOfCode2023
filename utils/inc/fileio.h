#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> read_file(string filePath);
vector<string> split_line(string str, char delimiter = ' ');
vector<vector<string>> split_vector(const vector<string> &vec, string delimiter = "\n");
