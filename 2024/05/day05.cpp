#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int part_1(vector<pair<int, int>> &rules, vector<vector<int>> &updates)
{
    int middles = 0;
    bool valid;

    for (vector<int> &update : updates)
    {
        valid = true;

        for (pair rule : rules)
        {
            auto a = find(update.begin(), update.end(), rule.first);
            auto b = find(update.begin(), update.end(), rule.second);

            if (b != update.end() && a != update.end() && a > b)
            {
                valid = false;
                break;
            }
        }

        if (valid)
            middles += update[update.size() / 2];
    }

    return middles;
}

int part_2(vector<pair<int, int>> &rules, vector<vector<int>> &updates)
{
    int middles = 0;
    bool valid;

    for (vector<int> &update : updates)
    {
        valid = true;

        for (pair rule : rules)
        {
            auto a = find(update.begin(), update.end(), rule.first);
            auto b = find(update.begin(), update.end(), rule.second);

            if (b != update.end() && a != update.end() && a > b)
            {
                valid = false;
                break;
            }
        }

        if (!valid)
        {
            sort(update.begin(), update.end(), [&rules](int a, int b)
                 {  for (pair rule : rules)
                         if (a == rule.first && b == rule.second)
                             return true;
                    return false; });
            middles += update[update.size() / 2];
        }
    }

    return middles;
}

int main()
{
    ifstream input("input.txt");
    string line;

    vector<pair<int, int>> rules;
    vector<vector<int>> updates;

    string part;
    bool section_2 = false;
    int a, b;

    while (getline(input, line))
    {
        stringstream ss(line);

        if (line.empty())
            section_2 = true;
        else if (!section_2)
        {
            getline(ss, part, '|');
            a = stoi(part);

            getline(ss, part, '|');
            b = stoi(part);

            rules.push_back({a, b});
        }
        else
        {
            vector<int> update;

            while (getline(ss, part, ','))
                update.push_back(stoi(part));

            updates.push_back(update);
        }
    }

    cout << part_1(rules, updates) << '\n';
    cout << part_2(rules, updates) << '\n';

    return 0;
}
