#include <iostream>
#include <fstream>
#include <vector>

using vvi = std::vector<std::vector<int>>;

int part1(const vvi &first, const vvi &second)
{
    int sum = 0;

    for (std::size_t i = 0; i < first.size(); ++i)
        if ((first[i][0] <= second[i][0] && first[i][1] >= second[i][1]) || // first contains second
            (first[i][1] <= second[i][1] && first[i][0] >= second[i][0]))   // second contains first
            ++sum;

    return sum;
}

int part2(const vvi &first, const vvi &second)
{
    int sum = 0;

    for (std::size_t i = 0; i < first.size(); ++i)
        if (first[i][0] <= second[i][1] && first[i][1] >= second[i][0]) // overlap
            ++sum;

    return sum;
}

int main()
{
    std::ifstream input("input.txt");
    std::string pair;

    vvi firstNums;
    vvi secondNums;

    int comma;
    int dash0;
    int dash1;

    std::string elf0;
    std::string elf1;

    while (input >> pair)
    {
        comma = pair.find(',');
        elf0 = pair.substr(0, comma);
        elf1 = pair.substr(comma + 1, pair.length());

        dash0 = elf0.find('-');
        // Push back start and end of first range
        firstNums.push_back({std::stoi(elf0.substr(0, dash0)),
                             std::stoi(elf0.substr(dash0 + 1, elf0.length()))});

        dash1 = elf1.find('-');
        // Push back start and end of second range
        secondNums.push_back({std::stoi(elf1.substr(0, dash1)),
                              std::stoi(elf1.substr(dash1 + 1, elf1.length()))});
    }

    std::cout << part1(firstNums, secondNums) << '\n';
    std::cout << part2(firstNums, secondNums) << '\n';

    return 0;
}
