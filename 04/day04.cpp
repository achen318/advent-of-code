#include <iostream>
#include <fstream>
#include <vector>

using vvi = std::vector<std::vector<int>>;

int part1(vvi first, vvi second)
{
    int sum = 0;

    for (std::size_t i = 0; i < first.size(); ++i)
        if ((first[i][0] <= second[i][0] && first[i][1] >= second[i][1]) ||
            (first[i][1] <= second[i][1] && first[i][0] >= second[i][0]))
            ++sum;

    return sum;
}

int part2(vvi first, vvi second)
{
    int sum = 0;

    for (std::size_t i = 0; i < first.size(); ++i)
        if (first[i][0] <= second[i][1] && first[i][1] >= second[i][0])
            ++sum;

    return sum;
}

int main()
{
    std::fstream input("input.txt");
    std::string pair;

    vvi firstNums;
    vvi secondNums;

    while (input >> pair)
    {
        int comma = pair.find(',');
        std::string elf0 = pair.substr(0, comma);
        std::string elf1 = pair.substr(comma + 1, pair.length());

        int dash0 = elf0.find('-');
        firstNums.push_back({std::stoi(elf0.substr(0, dash0)),
                             std::stoi(elf0.substr(dash0 + 1, elf0.length()))});

        int dash1 = elf1.find('-');
        secondNums.push_back({std::stoi(elf1.substr(0, dash1)),
                              std::stoi(elf1.substr(dash1 + 1, elf1.length()))});
    }

    std::cout << part1(firstNums, secondNums) << '\n';
    std::cout << part2(firstNums, secondNums) << '\n';

    return 0;
}
