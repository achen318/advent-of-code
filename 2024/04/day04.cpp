#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int part_1(vector<string> &grid)
{
    int count = 0;
    char cur;

    for (size_t i = 0; i < grid.size(); ++i)
    {
        for (size_t j = 0; j < grid[0].size(); ++j)
        {
            cur = grid[i][j];

            if (cur == 'X')
            {
                if (i >= 3)
                {
                    // top left
                    if (j >= 3)
                        if (grid[i - 1][j - 1] == 'M' && grid[i - 2][j - 2] == 'A' && grid[i - 3][j - 3] == 'S')
                            ++count;

                    // top
                    if (grid[i - 1][j] == 'M' && grid[i - 2][j] == 'A' && grid[i - 3][j] == 'S')
                        ++count;

                    // top right
                    if (j < grid[0].size() - 3)
                        if (grid[i - 1][j + 1] == 'M' && grid[i - 2][j + 2] == 'A' && grid[i - 3][j + 3] == 'S')
                            ++count;
                }

                // left
                if (j >= 3)
                    if (grid[i][j - 1] == 'M' && grid[i][j - 2] == 'A' && grid[i][j - 3] == 'S')
                        ++count;

                // right
                if (j < grid[0].size() - 3)
                    if (grid[i][j + 1] == 'M' && grid[i][j + 2] == 'A' && grid[i][j + 3] == 'S')
                        ++count;

                if (i < grid.size() - 3)
                {
                    // bottom left
                    if (j >= 3)
                        if (grid[i + 1][j - 1] == 'M' && grid[i + 2][j - 2] == 'A' && grid[i + 3][j - 3] == 'S')
                            ++count;

                    // bottom
                    if (grid[i + 1][j] == 'M' && grid[i + 2][j] == 'A' && grid[i + 3][j] == 'S')
                        ++count;

                    // bottom right
                    if (j < grid[0].size() - 3)
                        if (grid[i + 1][j + 1] == 'M' && grid[i + 2][j + 2] == 'A' && grid[i + 3][j + 3] == 'S')
                            ++count;
                }
            }
        }
    }

    return count;
}

int part_2(vector<string> &grid)
{
    int count = 0;
    char cur;

    for (size_t i = 1; i < grid.size() - 1; ++i)
    {
        for (size_t j = 1; j < grid[0].size() - 1; ++j)
        {
            cur = grid[i][j];

            if (cur == 'A')
            {
                if (grid[i - 1][j - 1] == 'M' && grid[i + 1][j + 1] == 'S')
                {
                    if (grid[i - 1][j + 1] == 'M' && grid[i + 1][j - 1] == 'S')
                        ++count;
                    else if (grid[i - 1][j + 1] == 'S' && grid[i + 1][j - 1] == 'M')
                        ++count;
                }
                else if (grid[i - 1][j - 1] == 'S' && grid[i + 1][j + 1] == 'M')
                {
                    if (grid[i - 1][j + 1] == 'M' && grid[i + 1][j - 1] == 'S')
                        ++count;
                    else if (grid[i - 1][j + 1] == 'S' && grid[i + 1][j - 1] == 'M')
                        ++count;
                }
            }
        }
    }

    return count;
}

int main()
{
    ifstream input("input.txt");
    string line;
    vector<string> grid;

    while (getline(input, line))
        grid.push_back(line);

    cout << part_1(grid) << '\n';
    cout << part_2(grid) << '\n';

    return 0;
}
