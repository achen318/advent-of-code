#include <iostream>
#include <fstream>
#include <vector>

using vs = std::vector<std::string>;

// Index of character == priority
const std::string priority = " abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

int part1(const vs &rucksacks)
{
    int sum = 0;

    int length;
    std::string firstComp;
    std::string secondComp;

    for (const auto &rucksack : rucksacks)
    {
        length = rucksack.length();
        firstComp = rucksack.substr(0, length / 2);
        secondComp = rucksack.substr(length / 2, length);

        for (const char item : firstComp)
            if (secondComp.find(item) != std::string::npos)
            {
                // Item is in both components, add priority to sum
                sum += priority.find(item);
                break;
            }
    }

    return sum;
}

int part2(const vs &input)
{
    int sum = 0;

    std::string rucksack_1;
    std::string rucksack_2;
    std::string rucksack_3;

    for (std::size_t i = 0; i < input.size(); i += 3)
    {
        rucksack_1 = input[i];
        rucksack_2 = input[i + 1];
        rucksack_3 = input[i + 2];

        for (const char item : rucksack_1)
            if (rucksack_2.find(item) != std::string::npos &&
                rucksack_3.find(item) != std::string::npos)
            {
                // Item is in all three components, add priority to sum
                sum += priority.find(item);
                break;
            }
    }

    return sum;
}

int main()
{
    std::ifstream input("input.txt");
    std::string rucksack;

    vs rucksacks;

    while (std::getline(input, rucksack))
        rucksacks.push_back(rucksack);

    std::cout << part1(rucksacks) << '\n';
    std::cout << part2(rucksacks) << '\n';

    return 0;
}
