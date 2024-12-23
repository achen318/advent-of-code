#include <fstream>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

using ll = long long;

ll split_stone(ll stone, unordered_map<ll, ll> &memo)
{
    ll result;

    if (memo.find(stone) != memo.end())
        return memo[stone];

    if (stone == 0)
        result = 1;
    else if (to_string(stone).size() % 2 == 0)
    {
        ll left = stoll(to_string(stone).substr(0, to_string(stone).size() / 2));
        ll right = stoll(to_string(stone).substr(to_string(stone).size() / 2));

        result = split_stone(left, memo) + split_stone(right, memo);
    }
    else
        result = 2024 * stone;

    memo[stone] = result;
    return result;
}

ll part_1(vector<ll> stones)
{
    vector<ll> new_stones;

    for (int i = 0; i < 25; ++i)
    {
        new_stones.clear();

        for (ll stone : stones)
        {
            if (stone == 0)
                new_stones.push_back(1);
            else if (to_string(stone).size() % 2 == 0)
            {
                ll left = stoll(to_string(stone).substr(0, to_string(stone).size() / 2));
                ll right = stoll(to_string(stone).substr(to_string(stone).size() / 2));

                new_stones.push_back(left);
                new_stones.push_back(right);
            }
            else
                new_stones.push_back(2024 * stone);
        }

        stones = new_stones;
    }

    return stones.size();
}

ll part_2(vector<ll> stones)
{
    unordered_map<ll, ll> memo;

    for (int i = 0; i < 75; ++i)
    {
        for (ll stone : stones)
            split_stone(stone, memo);
    }

    return 0;
}

int main()
{
    ifstream input("input.txt");
    string line;

    vector<ll> stones;

    while (getline(input, line, ' '))
        stones.push_back(stoi(line));

    cout << part_1(stones) << '\n';
    cout << part_2(stones) << '\n';

    return 0;
}
