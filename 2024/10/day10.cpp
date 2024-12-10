#include <fstream>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>

using namespace std;

int part_1(vector<vector<int>> &map)
{
    int scores = 0;
    int val;

    vector<pair<int, int>> trailheads;

    for (size_t i = 0; i < map.size(); ++i)
        for (size_t j = 0; j < map[0].size(); ++j)
            if (map[i][j] == 0)
                trailheads.push_back({i, j});

    for (auto [i, j] : trailheads)
    {
        unordered_set<int> pos_9;
        queue<pair<int, int>> q;

        q.push({i, j});

        while (!q.empty())
        {
            i = q.front().first;
            j = q.front().second;

            val = map[i][j];

            if (val == 9)
                pos_9.insert(i * map[0].size() + j);

            // up
            if (0 < i && map[i - 1][j] == val + 1)
                q.push({i - 1, j});

            // down
            if (i < map.size() - 1 && map[i + 1][j] == val + 1)
                q.push({i + 1, j});

            // left
            if (0 < j && map[i][j - 1] == val + 1)
                q.push({i, j - 1});

            // right
            if (j < map[i].size() - 1 && map[i][j + 1] == val + 1)
                q.push({i, j + 1});

            q.pop();
        }

        scores += pos_9.size();
    }

    return scores;
}

int part_2(vector<vector<int>> &map)
{
    int rating = 0;
    int val;

    vector<pair<int, int>> trailheads;

    for (size_t i = 0; i < map.size(); ++i)
        for (size_t j = 0; j < map[0].size(); ++j)
            if (map[i][j] == 0)
                trailheads.push_back({i, j});

    for (auto [i, j] : trailheads)
    {
        queue<pair<int, int>> q;

        q.push({i, j});

        while (!q.empty())
        {
            i = q.front().first;
            j = q.front().second;

            val = map[i][j];

            if (val == 9)
                ++rating;

            // up
            if (0 < i && map[i - 1][j] == val + 1)
                q.push({i - 1, j});

            // down
            if (i < map.size() - 1 && map[i + 1][j] == val + 1)
                q.push({i + 1, j});

            // left
            if (0 < j && map[i][j - 1] == val + 1)
                q.push({i, j - 1});

            // right
            if (j < map[i].size() - 1 && map[i][j + 1] == val + 1)
                q.push({i, j + 1});

            q.pop();
        }
    }

    return rating;
}

int main()
{
    ifstream input("input.txt");
    string line;

    vector<vector<int>> map;
    while (getline(input, line))
    {
        vector<int> row;
        for (char c : line)
            row.push_back(c - '0');
        map.push_back(row);
    }

    cout << part_1(map) << '\n';
    cout << part_2(map) << '\n';

    return 0;
}
