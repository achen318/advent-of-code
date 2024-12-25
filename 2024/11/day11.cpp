#include <fstream>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

using ll = long long;

ll part_1(vector<ll> stones)
{
    vector<ll> new_stones;

    for (int _ = 0; _ < 25; ++_)
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
    unordered_map<ll, ll> stone_freq;
    unordered_map<ll, ll> new_stone_freq;
    ll num_stones = 0;

    for (ll stone : stones)
        ++stone_freq[stone];

    for (int _ = 0; _ < 75; ++_)
    {
        new_stone_freq.clear();

        for (auto [stone, freq] : stone_freq)
        {
            if (stone == 0)
                new_stone_freq[1] += freq;
            else if (to_string(stone).size() % 2 == 0)
            {
                ll left = stoll(to_string(stone).substr(0, to_string(stone).size() / 2));
                ll right = stoll(to_string(stone).substr(to_string(stone).size() / 2));

                new_stone_freq[left] += freq;
                new_stone_freq[right] += freq;
            }
            else
                new_stone_freq[2024 * stone] += freq;
        }

        stone_freq = new_stone_freq;
    }

    for (auto [_, freq] : stone_freq)
        num_stones += freq;

    return num_stones;
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
