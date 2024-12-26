#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

using ll = long long;
using vvp = vector<vector<pair<int, int>>>;

int part_1(vvp &configs)
{
    int tokens = 0;

    int det, det_a, det_b, a, b;

    for (auto &config : configs)
    {
        det = config[0].first * config[1].second - config[1].first * config[0].second;
        det_a = config[2].first * config[1].second - config[1].first * config[2].second;
        det_b = config[0].first * config[2].second - config[2].first * config[0].second;

        if (det == 0 || det_a % det || det_b % det)
            continue;

        a = 3 * det_a / det;
        b = det_b / det;

        tokens += a + b;
    }

    return tokens;
}

ll part_2(vvp &configs)
{
    ll tokens = 0;

    ll det, det_a, det_b, a, b;
    const ll adjust = 10000000000000;

    for (auto &config : configs)
    {
        det = config[0].first * config[1].second - config[1].first * config[0].second;
        det_a = (config[2].first + adjust) * config[1].second - config[1].first * (config[2].second + adjust);
        det_b = config[0].first * (config[2].second + adjust) - (config[2].first + adjust) * config[0].second;

        if (det == 0 || det_a % det || det_b % det)
            continue;

        a = 3 * det_a / det;
        b = det_b / det;

        tokens += a + b;
    }

    return tokens;
}

int main()
{
    ifstream input("input.txt");
    string line;

    vvp configs;
    int ax, ay, bx, by, px, py;

    while (getline(input, line))
    {
        sscanf(line.c_str(), "Button A: X+%d, Y+%d", &ax, &ay);

        getline(input, line);
        sscanf(line.c_str(), "Button B: X+%d, Y+%d", &bx, &by);

        getline(input, line);
        sscanf(line.c_str(), "Prize: X=%d, Y=%d", &px, &py);

        configs.push_back({{ax, ay}, {bx, by}, {px, py}});

        getline(input, line); // consume the empty line
    }

    cout << part_1(configs) << '\n';
    cout << part_2(configs) << '\n';

    return 0;
}
