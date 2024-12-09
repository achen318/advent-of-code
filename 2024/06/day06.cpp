#include <fstream>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

bool inside(pair<int, int> &pos, pair<int, int> &dir, vector<string> &map)
{
    if (dir == make_pair(-1, 0)) // up
        return 0 <= pos.first;
    if (dir == make_pair(0, -1)) // left
        return 0 <= pos.second;
    if (dir == make_pair(1, 0)) // down
        return pos.first < map.size();
    if (dir == make_pair(0, 1)) // right
        return pos.second < map[0].size();

    return false;
}

int part_1(vector<string> map)
{
    int distinct = 0;

    pair<int, int> pos;
    pair<int, int> dir = {-1, 0};

    for (size_t i = 0; i < map.size(); ++i)
        for (size_t j = 0; j < map[0].size(); ++j)
            if (map[i][j] == '^')
            {
                pos = {i, j};
                break;
            }

    while (inside(pos, dir, map))
    {
        if (map[pos.first][pos.second] != 'X')
            ++distinct;
        map[pos.first][pos.second] = 'X';

        while (map[pos.first + dir.first][pos.second + dir.second] == '#')
            dir = {dir.second, -dir.first}; // rotate 90 deg CW

        pos.first += dir.first;
        pos.second += dir.second;
    }

    return distinct;
}

int part_2(vector<string> map)
{
    int obstructions = 0;

    pair<int, int> init_pos;
    pair<int, int> init_dir = {-1, 0};

    pair<int, int> pos;
    pair<int, int> dir;

    set<pair<pair<int, int>, pair<int, int>>> seen_pos_dir;
    bool seen;

    for (size_t i = 0; i < map.size(); ++i)
        for (size_t j = 0; j < map[0].size(); ++j)
            if (map[i][j] == '^')
            {
                init_pos = {i, j};
                break;
            }

    for (size_t i = 0; i < map.size(); ++i)
    {
        for (size_t j = 0; j < map[0].size(); ++j)
        {
            if (map[i][j] == '^')
                continue;

            pos = init_pos;
            dir = init_dir;

            seen_pos_dir.clear();
            seen = false;

            while (inside(pos, dir, map) && !seen)
            {
                while (map[pos.first + dir.first][pos.second + dir.second] == '#' ||
                       (pos.first + dir.first == i && pos.second + dir.second == j))
                {
                    if (seen_pos_dir.find({pos, dir}) != seen_pos_dir.end())
                    {
                        ++obstructions;
                        seen = true;
                        break;
                    }

                    seen_pos_dir.insert({pos, dir});

                    dir = {dir.second, -dir.first}; // rotate 90 deg CW
                }

                pos.first += dir.first;
                pos.second += dir.second;
            }
        }
    }

    return obstructions;
}

int main()
{
    ifstream input("input.txt");
    string line;

    vector<string> map;

    while (getline(input, line))
        map.push_back(line);

    cout << part_1(map) << '\n';
    cout << part_2(map) << '\n';

    return 0;
}
