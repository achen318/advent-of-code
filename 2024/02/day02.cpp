#include <fstream>
#include <iostream>
#include <set>
#include <sstream>
#include <vector>

using namespace std;

bool is_safe(vector<int> &report)
{
    bool inc = report[0] < report[1];
    bool unsafe = false;

    for (size_t i = 0; i < report.size() - 1 && !unsafe; ++i)
        if ((inc && report[i] >= report[i + 1]) || (!inc && report[i] <= report[i + 1]) || abs(report[i + 1] - report[i]) > 3)
            unsafe = true;

    return !unsafe;
}

int part_1(set<vector<int>> &reports)
{
    int safe = 0;

    for (vector<int> report : reports)
        if (is_safe(report))
            ++safe;

    return safe;
}

int part_2(set<vector<int>> &reports)
{
    int safe = 0;

    for (vector<int> report : reports)
        if (is_safe(report))
            ++safe;
        else
        {
            for (size_t i = 0; i < report.size(); ++i)
            {
                vector<int> temp(report.begin(), report.end());
                temp.erase(temp.begin() + i);

                if (is_safe(temp))
                {
                    ++safe;
                    break;
                }
            }
        }

    return safe;
}

int main()
{
    ifstream input("input.txt");
    string line;

    set<vector<int>> reports;
    int temp;

    while (getline(input, line))
    {
        vector<int> report;
        stringstream ss(line);

        while (ss >> temp)
            report.push_back(temp);

        reports.insert(report);
    }

    cout << part_1(reports) << '\n';
    cout << part_2(reports) << '\n';

    return 0;
}
