#include <iostream>
#include <fstream>

int part1()
{
    return 0;
}

int part2()
{
    return 0;
}

int main()
{
    std::ifstream input("sample.txt");
    std::string line;

    while (std::getline(input, line))
    {
    }
    while (input >> line)
    {
    }

    std::cout << part1() << '\n';
    std::cout << part2() << '\n';

    return 0;
}
