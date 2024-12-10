#include <fstream>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>

using namespace std;

using ll = long long;

ll part_1(unordered_map<ll, vector<ll>> &equations)
{
    ll total = 0;
    ll temp;

    for (auto &[eq, operands] : equations)
    {
        for (int i = 0; i < pow(2, operands.size()); ++i)
        {
            temp = !(i & 1);

            for (int j = 0; j < operands.size(); ++j)
            {
                if ((i >> j) & 1)
                    temp += operands[j];
                else
                    temp *= operands[j];

                if (temp > eq)
                    break;
            }

            if (temp == eq)
            {
                total += eq;
                break;
            }
        }
    }

    return total;
}

ll part_2(unordered_map<ll, vector<ll>> &equations)
{
    ll total = 0;
    ll quo, mod, temp;

    for (auto &[eq, operands] : equations)
    {
        for (int i = 0; i < pow(3, operands.size()); ++i)
        {
            quo = i;
            mod = 0;

            temp = quo % 3 == 1;

            for (int j = 0; j < operands.size(); ++j)
            {
                mod = quo % 3;
                quo /= 3;

                if (mod == 0)
                    temp += operands[j];
                else if (mod == 1)
                    temp *= operands[j];
                else if (mod == 2)
                    temp = stoll(to_string(temp) + to_string(operands[j]));

                if (temp > eq)
                    break;
            }

            if (temp == eq)
            {
                total += eq;
                break;
            }
        }
    }

    return total;
}

int main()
{
    ifstream input("input.txt");
    string line;

    unordered_map<ll, vector<ll>> equations;

    string part;
    vector<ll> operands;
    ll eq;

    while (getline(input, line))
    {
        stringstream ss(line);
        operands.clear();

        getline(ss, part, ':');
        eq = stoll(part);

        getline(ss, part, ':');
        stringstream ss2(part);
        while (getline(ss2, part, ' '))
            if (part != "")
                operands.push_back(stoll(part));

        equations[eq] = operands;
    }

    cout << part_1(equations) << '\n';
    cout << part_2(equations) << '\n';

    return 0;
}
