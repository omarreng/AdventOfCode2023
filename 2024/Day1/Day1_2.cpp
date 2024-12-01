#include <algorithm>
#include <cstdint>
#include <string>

#include "fileio.h"

int main()
{
    auto input = read_file("Day1_input.txt"); 

    vector<int64_t> list_1, list_2;
    for (auto row : input)
    {
        auto numbers = split_line(row);
        list_1.push_back(stoi(numbers[0]));
        list_2.push_back(stoi(numbers[3]));
    }

    

    int result = 0;

    cout << "The result is: " << result << endl;

    return 0;
}