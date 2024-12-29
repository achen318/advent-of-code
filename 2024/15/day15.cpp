#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int part_1(vector<string> &map, vector<string> &seqs)
{
    pair<int, int> pos;
    pair<int, int> dir;

    bool found = false;
    for (size_t i = 0; i < map.size() && !found; ++i)
        for (size_t j = 0; j < map[0].size() && !found; ++j)
            if (map[i][j] == '@')
            {
                pos = {i, j};
                map[i][j] = '.';
                found = true;
            }

    char next;

    for (auto &seq : seqs)
        for (char move : seq)
        {
            if (move == '^')
                dir = {-1, 0};
            else if (move == 'v')
                dir = {1, 0};
            else if (move == '<')
                dir = {0, -1};
            else if (move == '>')
                dir = {0, 1};

            next = map[pos.first + dir.first][pos.second + dir.second];

            if (next == '.')
            {
                pos.first += dir.first;
                pos.second += dir.second;
            }
            else if (next == 'O')
            {
                int i = 2;

                while (next == 'O')
                {
                    next = map[pos.first + i * dir.first][pos.second + i * dir.second];

                    if (next == '.')
                    {
                        map[pos.first + dir.first][pos.second + dir.second] = '.';
                        map[pos.first + i * dir.first][pos.second + i * dir.second] = 'O';

                        pos.first += dir.first;
                        pos.second += dir.second;

                        break;
                    }

                    ++i;
                }
            }
        }

    int gps = 0;

    for (size_t i = 0; i < map.size(); ++i)
        for (size_t j = 0; j < map[0].size(); ++j)
            if (map[i][j] == 'O')
                gps += 100 * i + j;

    return gps;
}

int part_2(vector<string> &map, vector<string> &seqs)
{
    return 0;
}

int main()
{
    ifstream input("input.txt");
    string line;

    vector<string> map;
    vector<string> seqs;

    bool on_map = true;

    while (getline(input, line))
    {
        if (line.empty())
            on_map = false;
        else if (on_map)
            map.push_back(line);
        else
            seqs.push_back(line);
    }

    cout << part_1(map, seqs) << '\n';
    cout << part_2(map, seqs) << '\n';

    return 0;
}
