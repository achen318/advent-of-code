#include <fstream>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int part_1(vector<string> &map)
{
    int price = 0;

    vector<vector<bool>> visited(map.size(), vector<bool>(map[0].size(), false));
    char target;
    stack<pair<int, int>> stk;
    size_t perimeter, area, x, y;

    for (size_t i = 0; i < map.size(); ++i)
        for (size_t j = 0; j < map[0].size(); ++j)
        {
            if (visited[i][j])
                continue;

            visited[i][j] = true;
            target = map[i][j];

            stk.push({i, j});

            perimeter = 0;
            area = 0;

            while (!stk.empty())
            {
                x = stk.top().first;
                y = stk.top().second;
                stk.pop();

                ++area;
                perimeter += 4;

                // up
                if (0 < x && map[x - 1][y] == target)
                {
                    --perimeter;

                    if (!visited[x - 1][y])
                    {
                        stk.push({x - 1, y});
                        visited[x - 1][y] = true;
                    }
                }

                // down
                if (x < map.size() - 1 && map[x + 1][y] == target)
                {
                    --perimeter;

                    if (!visited[x + 1][y])
                    {
                        stk.push({x + 1, y});
                        visited[x + 1][y] = true;
                    }
                }

                // left
                if (0 < y && map[x][y - 1] == target)
                {
                    --perimeter;

                    if (!visited[x][y - 1])
                    {
                        stk.push({x, y - 1});
                        visited[x][y - 1] = true;
                    }
                }

                // right
                if (y < map[0].size() - 1 && map[x][y + 1] == target)
                {
                    --perimeter;

                    if (!visited[x][y + 1])
                    {
                        stk.push({x, y + 1});
                        visited[x][y + 1] = true;
                    }
                }
            }

            price += perimeter * area;
        }

    return price;
}

int part_2(vector<string> &map)
{
    int price = 0;

    vector<vector<bool>> visited(map.size(), vector<bool>(map[0].size(), false));
    stack<pair<int, int>> stk;

    char target;
    size_t area, corners, x, y;
    bool n, ne, e, se, s, sw, w, nw;

    for (size_t i = 0; i < map.size(); ++i)
        for (size_t j = 0; j < map[0].size(); ++j)
        {
            if (visited[i][j])
                continue;

            visited[i][j] = true;
            target = map[i][j];

            stk.push({i, j});

            corners = 0;
            area = 0;

            while (!stk.empty())
            {
                x = stk.top().first;
                y = stk.top().second;
                stk.pop();

                n = 0 < x && map[x - 1][y] == target;
                e = y < map[0].size() - 1 && map[x][y + 1] == target;
                s = x < map.size() - 1 && map[x + 1][y] == target;
                w = 0 < y && map[x][y - 1] == target;
                ne = n && e && map[x - 1][y + 1] == target;
                se = s && e && map[x + 1][y + 1] == target;
                sw = s && w && map[x + 1][y - 1] == target;
                nw = n && w && map[x - 1][y - 1] == target;

                ++area;

                if (n + e + s + w == 0)
                    corners += 4;
                else if (n + e + s + w == 1)
                    corners += 2;
                else if (n + e + s + w == 2 && !(n && s) && !(e && w))
                    corners += 2 - (ne + se + sw + nw);
                else if (n + e + s + w == 3)
                    corners += 2 - (ne + se + sw + nw);
                else if (n + e + s + w == 4)
                    corners += 4 - (ne + se + sw + nw);

                if (n && !visited[x - 1][y])
                {
                    stk.push({x - 1, y});
                    visited[x - 1][y] = true;
                }
                if (e && !visited[x][y + 1])
                {
                    stk.push({x, y + 1});
                    visited[x][y + 1] = true;
                }
                if (s && !visited[x + 1][y])
                {
                    stk.push({x + 1, y});
                    visited[x + 1][y] = true;
                }
                if (w && !visited[x][y - 1])
                {
                    stk.push({x, y - 1});
                    visited[x][y - 1] = true;
                }
            }

            price += corners * area;
        }

    return price;
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
