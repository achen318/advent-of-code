#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

constexpr int TIME = 100;
constexpr int WIDTH = 101;
constexpr int HEIGHT = 103;

struct robot
{
    int px, py, vx, vy;
};

int part_1(vector<robot> &robots)
{
    vector<int> quads(4, 0);

    robot new_r;

    for (robot &r : robots)
    {
        new_r.vx = r.vx;
        new_r.vy = r.vy;

        if (r.vx < 0)
            new_r.vx = WIDTH + r.vx;
        if (r.vy < 0)
            new_r.vy = HEIGHT + r.vy;

        new_r.px = (r.px + TIME * new_r.vx) % WIDTH;
        new_r.py = (r.py + TIME * new_r.vy) % HEIGHT;

        if (new_r.px < WIDTH / 2 && new_r.py < HEIGHT / 2)
            ++quads[0];
        else if (new_r.px > WIDTH / 2 && new_r.py < HEIGHT / 2)
            ++quads[1];
        else if (new_r.px < WIDTH / 2 && new_r.py > HEIGHT / 2)
            ++quads[2];
        else if (new_r.px > WIDTH / 2 && new_r.py > HEIGHT / 2)
            ++quads[3];
    }

    return quads[0] * quads[1] * quads[2] * quads[3];
}

int part_2(vector<robot> robots)
{
    for (robot &r : robots)
    {
        if (r.vx < 0)
            r.vx = WIDTH + r.vx;
        if (r.vy < 0)
            r.vy = HEIGHT + r.vy;
    }

    vector<string> grid;
    int time = 0;
    bool found = false;

    while (!found)
    {
        grid = vector<string>(HEIGHT, string(WIDTH, '.'));

        for (robot &r : robots)
        {
            r.px += r.vx;
            r.py += r.vy;

            r.px %= WIDTH;
            r.py %= HEIGHT;

            grid[r.py][r.px] = '#';
        }

        for (string &line : grid)
            if (line.find("########") != string::npos)
            {
                found = true;
                break;
            }

        ++time;
    }

    // for (string &line : grid)
    //     cout << line << '\n';

    return time;
}

int main()
{
    ifstream input("input.txt");
    string line;

    vector<robot> robots;
    int px, py, vx, vy;

    while (getline(input, line))
    {
        sscanf(line.c_str(), "p=%d,%d v=%d,%d", &px, &py, &vx, &vy);
        robots.push_back({px, py, vx, vy});
    }

    cout << part_1(robots) << '\n';
    cout << part_2(robots) << '\n';

    return 0;
}
