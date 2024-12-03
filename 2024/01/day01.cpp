#include <fstream>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int part_1(vector<int> &left, vector<int> &right)
{
    int dist = 0;

    sort(left.begin(), left.end());
    sort(right.begin(), right.end());

    for (size_t i = 0; i < left.size(); ++i)
        dist += abs((right)[i] - (left)[i]);

    return dist;
}

int part_2(vector<int> &left, unordered_map<int, int> &right_freq)
{
    int sim = 0;

    for (int left_num : left)
    {
        sim += left_num * right_freq[left_num];
    }
    return sim;
}

int main()
{
    ifstream input("input.txt");
    string line;

    int num;
    bool isLeft = true;

    vector<int> left, right;
    unordered_map<int, int> right_freq;

    while (input >> line)
    {
        num = stoi(line);

        if (isLeft)
            left.push_back(num);
        else
        {
            right.push_back(num);

            if (right_freq.count(num))
                ++right_freq[num];
            else
                right_freq[num] = 1;
        }

        isLeft = !isLeft;
    }

    cout << part_1(left, right) << '\n';
    cout << part_2(left, right_freq) << '\n';

    return 0;
}
