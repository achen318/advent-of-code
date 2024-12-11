#include <fstream>
#include <iostream>
#include <set>
#include <unordered_map>

using namespace std;

int part_1(vector<string> &map)
{
    set<pair<int, int>> antinodes;

    unordered_map<char, vector<pair<int, int>>> mapping;
    char c;
    pair<int, int> d, a, b;

    for (size_t i = 0; i < map.size(); ++i)
        for (size_t j = 0; j < map[0].size(); ++j)
        {
            c = map[i][j];

            if (c != '.')
            {
                if (mapping.find(c) == mapping.end())
                    mapping[c] = vector<pair<int, int>>();

                mapping[c].push_back({i, j});
            }
        }

    for (auto &[chr, coords] : mapping)
    {
        for (size_t i = 0; i < coords.size(); ++i)
        {
            for (size_t j = i + 1; j < coords.size(); ++j)
            {
                d = {coords[j].first - coords[i].first, coords[j].second - coords[i].second};
                a = {coords[i].first - d.first, coords[i].second - d.second};
                b = {coords[j].first + d.first, coords[j].second + d.second};

                if (0 <= a.first && a.first < map.size() && 0 <= a.second && a.second < map[0].size())
                    antinodes.insert(a);

                if (0 <= b.first && b.first < map.size() && 0 <= b.second && b.second < map[0].size())
                    antinodes.insert(b);
            }
        }
    }

    return antinodes.size();
}

int part_2(vector<string> &map)
{
    set<pair<int, int>> antinodes;

    unordered_map<char, vector<pair<int, int>>> mapping;
    char c;
    pair<int, int> d, a, b;

    for (size_t i = 0; i < map.size(); ++i)
        for (size_t j = 0; j < map[0].size(); ++j)
        {
            c = map[i][j];

            if (c != '.')
            {
                if (mapping.find(c) == mapping.end())
                    mapping[c] = vector<pair<int, int>>();

                mapping[c].push_back({i, j});
            }
        }

    for (auto &[chr, coords] : mapping)
    {
        for (size_t i = 0; i < coords.size(); ++i)
        {
            for (size_t j = i + 1; j < coords.size(); ++j)
            {
                a = {coords[i].first, coords[i].second};
                b = {coords[j].first, coords[j].second};
                d = {b.first - a.first, b.second - a.second};

                while (0 <= a.first && a.first < map.size() && 0 <= a.second && a.second < map[0].size())
                {
                    antinodes.insert(a);
                    a = {a.first - d.first, a.second - d.second};
                }

                while (0 <= b.first && b.first < map.size() && 0 <= b.second && b.second < map[0].size())
                {
                    antinodes.insert(b);
                    b = {b.first + d.first, b.second + d.second};
                }
            }
        }
    }

    return antinodes.size();
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
