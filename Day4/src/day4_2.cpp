#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>

#include "fileio.hpp"

using namespace std;

int compute_score(const vector<string> &winning_numbers, const vector<string> &numbers);
void add_wins(int index, int score, std::priority_queue<int, vector<int>, std::greater<int>> &pq);
int process_line(int index, const vector<string> &winning_numbers, const vector<string> &numbers, std::priority_queue<int, vector<int>, std::greater<int>> &pq);

int main()
{
    vector<string> input = readFile("input_day4.txt");
    vector<std::pair<vector<string>, vector<string>>> processed_input;

    std::priority_queue<int, vector<int>, std::greater<int>> pq;

    int result = 0;

    for (const string &card : input)
    {
        int score = 0;
        vector<string> split_card = split_line(split_line(card, ':').at(1), '|');

        vector<string> winning_numbers = split_line(split_card.at(0), ' ');
        vector<string> numbers = split_line(split_card.at(1), ' ');

        winning_numbers.erase(std::remove(winning_numbers.begin(), winning_numbers.end(), ""), winning_numbers.end());
        numbers.erase(std::remove(numbers.begin(), numbers.end(), ""), numbers.end());

        processed_input.push_back(std::make_pair(winning_numbers, numbers));
    }

    int index = 0;

    do
    {
        result += process_line(index++, processed_input.at(index).first, processed_input.at(index).second, pq);
    } while (!pq.empty());

    cout << "Result : " << result << endl;

    return 0;
}

int compute_score(const vector<string> &winning_numbers, const vector<string> &numbers)
{
    int score = 0;

    for (const string &s : numbers)
    {
        if (std::find(winning_numbers.begin(), winning_numbers.end(), s) != winning_numbers.end())
        {
            score++;
        }
    }

    return score;
}

void add_wins(int index, int score, std::priority_queue<int, vector<int>, std::greater<int>> &pq)
{
    for (int i = 0; i < score; i++)
    {
        pq.push(index + i + 1);
    }
}

int process_line(int index, const vector<string> &winning_numbers, const vector<string> &numbers, std::priority_queue<int, vector<int>, std::greater<int>> &pq)
{
    int score = compute_score(winning_numbers, numbers);
    add_wins(index, score, pq);

    int result = 0;
    while (!pq.empty() && pq.top() == index)
    {
        pq.pop();
        result++;
    }
    return result + (score > 0) ? 1 : 0;
}