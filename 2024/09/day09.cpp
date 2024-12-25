#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

ll part_1(string &disk_map)
{
    ll checksum = 0;

    int id = 0;
    bool file = true;

    vector<int> blocks;

    for (char c : disk_map)
    {
        if (file)
        {
            for (int _ = '0'; _ < c; ++_)
                blocks.push_back(id);
            ++id;
        }
        else
            for (int _ = '0'; _ < c; ++_)
                blocks.push_back(-1);

        file = !file;
    }

    size_t free_i = 0;
    size_t block_i = blocks.size() - 1;

    while (free_i < block_i)
    {
        while (blocks[free_i] != -1)
            ++free_i;
        while (blocks[block_i] == -1)
            --block_i;

        if (free_i < block_i)
        {
            blocks[free_i] = blocks[block_i];
            blocks[block_i] = -1;
        }

        ++free_i;
        --block_i;
    }

    for (size_t i = 0; i < blocks.size(); ++i)
        if (blocks[i] == -1)
            break;
        else
            checksum += i * blocks[i];

    return checksum;
}

ll part_2(string &disk_map)
{
    ll checksum = 0;

    int id = 0;
    bool file = true;

    vector<pair<int, int>> id_freq;

    for (char c : disk_map)
    {
        if (file)
            id_freq.push_back({id++, c - '0'});
        else
            id_freq.push_back({-1, c - '0'});

        file = !file;
    }

    for (size_t i = 0; i < id_freq.size(); ++i)
    {
        if (id_freq[i].first != -1)
            continue;

        for (size_t j = id_freq.size() - 1; j > i; --j)
        {
            if (id_freq[j].first == -1)
                continue;

            if (id_freq[i].second >= id_freq[j].second)
            {
                if (id_freq[i].second > id_freq[j].second)
                {
                    id_freq.insert(id_freq.begin() + i + 1, {-1, id_freq[i].second - id_freq[j].second});
                    ++j;
                    id_freq[i].second = id_freq[j].second;
                }

                id_freq[i].first = id_freq[j].first;
                id_freq[j].first = -1;
                break;
            }
        }
    }

    size_t i = 0;

    for (auto [id, freq] : id_freq)
    {
        i += freq;

        if (id == -1)
            continue;

        for (int j = 0; j < freq; ++j)
            checksum += (i - j - 1) * id;
    }

    return checksum;
}

int main()
{
    ifstream input("input.txt");
    string line;

    input >> line;

    cout << part_1(line) << '\n';
    cout << part_2(line) << '\n';

    return 0;
}
